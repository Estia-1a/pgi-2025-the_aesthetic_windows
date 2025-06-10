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