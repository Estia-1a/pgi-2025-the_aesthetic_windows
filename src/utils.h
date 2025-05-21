#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>


typedef struct _pixelRGB {
    char R;
    char G;
    char B;
} pixelRGB;


pixelRGB* getPixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y);

void setPixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB pixel);

void print_pixel(char* filename, int x, int y);

#endif 
