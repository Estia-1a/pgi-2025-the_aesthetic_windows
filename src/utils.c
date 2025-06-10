#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "estia-image.h"

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ) {
        if (!data) {
        return NULL;
    } else {
        if (x >= width) {
            return NULL;
        } else {
            if (y >= height) {
                return NULL;
            }
        }
    }

    unsigned int index = (y * width + x) * n;
    pixelRGB* pixel = (pixelRGB*)malloc(sizeof(pixelRGB));
    if (!pixel) return NULL;

    pixel->R = data[index];
    pixel->G = data[index + 1];
    pixel->B = data[index + 2];

    return pixel;
}

void set_pixel(unsigned char* data, unsigned int width, unsigned int n, unsigned int x, unsigned int y, pixelRGB pixel) {
    if (data == NULL || n < 3) return;
    unsigned int i = (y * width + x) * n;
    data[i] = pixel.R;
    data[i + 1] = pixel.G;
    data[i + 2] = pixel.B;
}