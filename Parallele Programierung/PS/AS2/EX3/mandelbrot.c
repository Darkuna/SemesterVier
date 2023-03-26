#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Include that allows to print result as an image
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Default size of image
#define X 1280
#define Y 720
#define MAX_ITER 10000

void calc_mandelbrot(uint8_t image[Y][X]) {
	double x, complex_x, x_tmp,
           y, complex_y;

    int iteration, norm_iteration;
    for(int y_pxl_idx = 0; y_pxl_idx < Y; ++y_pxl_idx){
        for(int x_pxl_idx = 0; x_pxl_idx < X; ++x_pxl_idx){

            x = 0.0;
            y = 0.0;

            complex_x = (double) x_pxl_idx / X * 3.5 - 2.5;
            complex_y = (double) y_pxl_idx / Y * 2 - 1;

            iteration = 0;
            while (x*x + y*y <= 4 && iteration < MAX_ITER){
                x_tmp = x*x - y*y + complex_x;
                y = 2*x*y + complex_y;
                x = x_tmp;
                iteration += 1;
            }

            norm_iteration = iteration * 255 / MAX_ITER;
            image[y_pxl_idx][x_pxl_idx] = norm_iteration;
        }
    }
}

int main() {
	uint8_t image[Y][X];

	calc_mandelbrot(image);

	const int channel_nr = 1, stride_bytes = 0;
	stbi_write_png("mandelbrot.png", X, Y, channel_nr, image, stride_bytes);
	return EXIT_SUCCESS;
}