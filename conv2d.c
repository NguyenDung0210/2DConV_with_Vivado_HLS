#include "conv2d.h"

void conv2d(image_t image[IMAGE_ROWS][IMAGE_COLS], kernel_t kernel[KERNEL_ROWS][KERNEL_COLS], output_t output[OUTPUT_ROWS][OUTPUT_COLS])
{
	int i, j, m, n;
	image_t lineBuffer[LINEBUFFER_ROWS][LINEBUFFER_COLS];

	#pragma HLS ARRAY_PARTITION variable=lineBuffer complete dim=1

	LOOP_BUFFER:
	for (i = 0; i < LINEBUFFER_ROWS; i++) {
		for (int j = 0; j < IMAGE_COLS; j++) {
			lineBuffer[i][j] = image[i][j];
		}
	}

	for (i = 0; i < OUTPUT_ROWS; i++) {
		for (j = 0; j < OUTPUT_COLS; j++) {
			output[i][j] = 0;

			#pragma HLS PIPELINE
			for (m = 0; m < KERNEL_ROWS; m++) {
				for (n = 0; n < KERNEL_COLS; n++) {
					output[i][j] += lineBuffer[m][n] * kernel[m][n];
				}
			}

			if (i + KERNEL_ROWS < IMAGE_ROWS) {
				for (m = 0; m < KERNEL_ROWS - 1; m++) {
					for (n = 0; n < IMAGE_COLS; n++) {
						lineBuffer[m][n] = lineBuffer[m + 1][n];
					}
				}

				for (n = 0; n < IMAGE_COLS; n++) {
					lineBuffer[KERNEL_ROWS - 1][n] = image[i + KERNEL_ROWS][n + j];
				}
			}
		}
	}
}
