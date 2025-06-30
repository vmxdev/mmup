#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "mmup_common.h"

#define PAUSE_DEFAULT 1.0

int
main(int argc, char *argv[])
{
	struct datum silence = {.left = 0.0, .right = 0.0};
	double pause = PAUSE_DEFAULT;
	int t, tpause;

	if (argc > 1) {
		pause = atof(argv[1]);
	}

	tpause = R * pause;

	for (t=0; t<tpause; t++) {
		fwrite(&silence, sizeof(struct datum), 1, stdout);
	}

	/* copy rest */
	for (;;) {
		struct datum d;

		fread(&d, sizeof(struct datum), 1, stdin);
		if (feof(stdin)) {
			break;
		}

		fwrite(&d, sizeof(struct datum), 1, stdout);
	}

	return EXIT_SUCCESS;
}

