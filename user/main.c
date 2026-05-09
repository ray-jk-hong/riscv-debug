// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2026 Jk Hong <zaiguang.hong@riscv-computing.com>
 */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <linux/rvd.h>

static void usage(const char *prog)
{
	fprintf(stderr, "usage: %s <hartid> <csr_name>\n", prog);
	fprintf(stderr, "  hartid:   decimal or 0x-prefixed hex\n");
	fprintf(stderr, "  csr_name: e.g. satp, mstatus (see kernel/driver docs)\n");
}

int main(int argc, char *argv[])
{
	int fd;
	struct rvd_csr_req req = {0};
	char *end;
	unsigned long hart;

	if (argc != 3) {
		usage(argv[0]);
		return 2;
	}

	errno = 0;
	hart = strtoul(argv[1], &end, 0);
	if (end == argv[1] || *end != '\0' || errno == ERANGE ||
	    hart > 0xffffffffUL) {
		fprintf(stderr, "invalid hartid: %s\n", argv[1]);
		return 2;
	}

	if (strlen(argv[2]) >= RVD_CSR_NAME_MAX) {
		fprintf(stderr, "csr name too long (max %d)\n", RVD_CSR_NAME_MAX - 1);
		return 2;
	}

	fd = open("/dev/rvd", O_RDWR);
	if (fd < 0) {
		perror("open /dev/rvd");
		return 1;
	}

	req.hartid = (__u32)hart;
	strncpy(req.name, argv[2], sizeof(req.name) - 1);

	if (ioctl(fd, RVD_IOCTL_CSR_READ, &req) < 0) {
		perror("ioctl");
		close(fd);
		return 1;
	}

	printf("%s hart%u (csr# %u) = 0x%llx\n", req.name, req.hartid, req.csrno,
	       (unsigned long long)req.value);

	close(fd);
	return 0;
}
