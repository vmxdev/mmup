#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mmup_common.h"

#define FREQ_DEFAULT 440.0
#define DUR_DEFAULT 1.0

int
main(int argc, char *argv[])
{
	double freq, dur;

	double tone;
	int t, tdur;

	dur = DUR_DEFAULT;
	if (argc > 2) {
		dur = atof(argv[2]);
	}

	freq = FREQ_DEFAULT;
	if (argc > 1) {
		freq = atof(argv[1]);
	}

	tdur = R * dur;

	for (t=0; t<tdur; t++) {
		struct datum d;

		tone = sin(t * 2 * M_PI / R * freq);

		d.left = d.right = tone;
		fwrite(&d, sizeof(struct datum), 1, stdout);
	}

	return EXIT_SUCCESS;
}

