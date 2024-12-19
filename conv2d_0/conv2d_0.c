#include "conv2d.h"

void conv2d(image_t image[IMAGE_ROWS][IMAGE_COLS], kernel_t kernel[KERNEL_ROWS][KERNEL_COLS], output_t output[OUTPUT_ROWS][OUTPUT_COLS])
{
  for (int i = 0; i < OUTPUT_ROWS; i++) {
    for (int j = 0; j < OUTPUT_COLS; j++) {
      output[i][j] = 0;
      for (int m = 0; m < KERNEL_ROWS; m++) {
        for (int n = 0; n < KERNEL_COLS; n++) {
          output[i][j] += image[i + m][j + n] * kernel[m][n];
        }
      }
    }
  }
}
