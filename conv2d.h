#ifndef __CONV2D_H__
#define __CONV2D_H__

#define IMAGE_ROWS 5
#define IMAGE_COLS 5
#define KERNEL_ROWS 3
#define KERNEL_COLS 3
#define OUTPUT_ROWS (IMAGE_ROWS - KERNEL_ROWS + 1)
#define OUTPUT_COLS (IMAGE_COLS - KERNEL_COLS + 1)

#define LINEBUFFER_ROWS KERNEL_ROWS
#define LINEBUFFER_COLS IMAGE_COLS

typedef int image_t;
typedef int kernel_t;
typedef int output_t;

void conv2d(image_t image[IMAGE_ROWS][IMAGE_COLS], kernel_t kernel[KERNEL_ROWS][KERNEL_COLS], output_t output[OUTPUT_ROWS][OUTPUT_COLS]);

#endif
