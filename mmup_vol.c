#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "mmup_common.h"

int
main(int argc, char *argv[])
{
	struct datum scale = {.left = 1.0, .right = 1.0};

	if (argc == 2) {
		scale.left = scale.right = atof(argv[1]);
	}

	if (argc > 2) {
		scale.left = atof(argv[1]);
		scale.right = atof(argv[2]);
	}

	for (;;) {
		struct datum in, out;

		fread(&in, sizeof(struct datum), 1, stdin);
		if (feof(stdin)) {
			break;
		}

		out.left = in.left * scale.left;
		out.right = in.right * scale.right;

		fwrite(&out, sizeof(struct datum), 1, stdout);
	}

	return EXIT_SUCCESS;
}

