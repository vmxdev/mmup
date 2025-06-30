#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "mmup_common.h"

int
main()
{
	for (;;) {
		struct datum d;
		int16_t ival;

		fread(&d, sizeof(struct datum), 1, stdin);
		if (feof(stdin)) {
			break;
		}

		if (d.left > 1.0) {
			d.left = 1.0;
		}
		if (d.right > 1.0) {
			d.right = 1.0;
		}

		ival = d.left * INT16_MAX;
		fwrite(&ival, sizeof(int16_t), 1, stdout);
		ival = d.right * INT16_MAX;
		fwrite(&ival, sizeof(int16_t), 1, stdout);

	}
	return EXIT_SUCCESS;
}

