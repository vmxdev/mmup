#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "mmup_common.h"

#define MAX_FILES 1024
FILE *files[MAX_FILES];

int
main(int argc, char *argv[])
{
	int i;
	int nfiles = 0;
	int has_data;

	for (i=0; i<(argc - 1); i++) {
		const char *fn = argv[i + 1];

		files[nfiles] = fopen(fn, "r");
		if (!files[nfiles]) {
			fprintf(stderr, "Can't open %s: %s\n", argv[i + 1],
				strerror(errno));
			continue;
		}
		nfiles++;
		if (nfiles >= MAX_FILES) {
			fprintf(stderr, "Too many files (max %d allowed)\n",
				MAX_FILES);
			goto cleanup;
		}
	}

	do {
		int i;
		struct datum out = {.left = 0.0, .right = 0.0};
		has_data = 0;

		for (i=0; i<nfiles; i++) {
			struct datum d;

			if (fread(&d, sizeof(struct datum), 1, files[i]) == 1) {
				out.left += d.left;
				out.right += d.right;
				has_data = 1;
			}
		}
		fwrite(&out, sizeof(struct datum), 1, stdout);
	} while (has_data);

cleanup:
	for (i=0; i<nfiles; i++) {
		fclose(files[i]);
	}

	return EXIT_SUCCESS;
}

