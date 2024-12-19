#include <stdio.h>
#include "conv2d.h"

int main(int argc, char **argv)
{
   image_t in_image[5][5] = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10},
      {11, 12, 13, 14, 15},
      {16, 17, 18, 19, 20},
      {21, 22, 23, 24, 25}
   };
   kernel_t in_kernel[3][3] = {
      {1, 0, -1},
      {1, 0, -1},
      {1, 0, -1}
   };

   output_t sw_output[3][3], hw_output[3][3];
   int err_cnt = 0;

   for (int i = 0; i < OUTPUT_ROWS; i++) {
      for (int j = 0; j < OUTPUT_COLS; j++) {
         sw_output[i][j] = 0;
         for (int m = 0; m < KERNEL_ROWS; m++) {
            for (int n = 0; n < KERNEL_COLS; n++) {
               sw_output[i][j] += in_image[i + m][j + n] * in_kernel[m][n];
            }
         }
      }
   }

   conv2d(in_image, in_kernel, hw_output);

   for (int x = 0; x < OUTPUT_ROWS; x++) {
      for (int y = 0; y < OUTPUT_COLS; y++) {
         if (hw_output[x][y] != sw_output[x][y]) {
            err_cnt++;
         }
      }
   }

   if (err_cnt) {
      printf("ERROR: %d mismatches detected!\n", err_cnt);
   } else {
      printf("Test passed.\n");
   }

   return err_cnt;
}
