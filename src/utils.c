#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "estia-image.h"


pixelRGB* getPixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {
    if (!data || x >= width || y >= height) {
        return NULL;
    }

    unsigned int index = (y * width + x) * n;
    pixelRGB* pixel = (pixelRGB*)malloc(sizeof(pixelRGB));
    if (!pixel) return NULL;

    pixel->R = data[index];
    pixel->G = data[index + 1];
    pixel->B = data[index + 2];

    return pixel;
}

void setPixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB pixel) {
    if (!data || x >= width || y >= height) {
        return;
    }

    unsigned int index = (y * width + x) * n;
    data[index] = pixel.R;
    data[index + 1] = pixel.G;
    data[index + 2] = pixel.B;
}

void print_pixel(char* filename, int x, int y) {
    unsigned char* data = NULL;
    int width, height, n;

    int result = read_image_data(filename, &data, &width, &height, &n);
    if (result != 0 || data == NULL) {
        printf("Failed to load image data.\n");
        return;
    }

    pixelRGB* pixel = getPixel(data, width, height, n, x, y);
    if (pixel == NULL) {
        printf("Invalid coordinates or data.\n");
        free(data);
        return;
    }

    printf("print_pixel(%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);

    free(pixel);
    free(data);
}