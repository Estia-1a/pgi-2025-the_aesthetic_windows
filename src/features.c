#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}


void dimension(char* filename) {
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
    } else {
        printf("dimension: %d, %d\n", width, height);
        free_image_data(data);
    }
}

void first_pixel(char* filename) {
    unsigned char* data;
    int width, height, channels;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
    } else {
        unsigned char r = data[0];
        unsigned char g = data[1];
        unsigned char b = data[2];
        printf("first_pixel: %d, %d, %d\n", r, g, b);
        free_image_data(data);
    }
}

void tenth_pixel (char* filename) {
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
    }   if (width < 10) {
        printf("An image that has at least a width of 10 pixels.\n");
        free_image_data(data);
    }
    int index = 9 * channel_count;
    int r = data[index];
    int g = data[index + 1];
    int b = data[index + 2];
    printf("tenth_pixel: %d, %d, %d\n", r, g, b);
    free_image_data(data); 
}

void second_line(char* filename) {
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
    } if (height < 2) {
        printf("An image that has at least a height of 2 pixels.\n");
        free_image_data(data);
    }
    int index = width * 3;
    int r = data[index];
    int g = data[index + 1];
    int b = data[index + 2];
    printf("second_line: %d, %d, %d\n", r, g, b);
    free_image_data(data);
}

void print_pixel(char* filename, int x, int y) {
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);
    if (pixel == NULL) {
        printf("Coordonnées hors limites ou données invalides.\n");
        free_image_data(data);
        return;
    }

    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
    free_image_data(data);
}

void max_pixel(char* filename) {
    unsigned char* data;
    int width, height, n;

    if (read_image_data(filename, &data, &width, &height, &n) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    int max_sum = -1;
    int max_x = 0, max_y = 0;
    pixelRGB max_pixel;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* p = get_pixel(data, width, height, n, x, y);
            if (p == NULL) continue;

            int sum = p->R + p->G + p->B;
            if (sum > max_sum) {
                max_sum = sum;
                max_x = x;
                max_y = y;
                max_pixel = *p;
            }
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_pixel.R, max_pixel.G, max_pixel.B);
    free_image_data(data);
}


void keep_red_component(const unsigned char *input, unsigned char *output, int width, int height) {
    int num_pixels = width * height;
    for (int i = 0; i < num_pixels; ++i) {
        int index = i * 3;
        output[index] = input[index];       
        output[index + 1] = 0;             
        output[index + 2] = 0;              
    }
}

void min_pixel(char* filename) {
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    int min_sum = 255 * 3 + 1;
    int min_x = 0, min_y = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            if (!pixel) continue;

            int sum = pixel->R + pixel->G + pixel->B;
            if (sum < min_sum) {
                min_sum = sum;
                min_x = x;
                min_y = y;
            }
        }
    }

    pixelRGB* min_pixel = get_pixel(data, width, height, channel_count, min_x, min_y);
    printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_pixel->R, min_pixel->G, min_pixel->B);
    free_image_data(data);
}


void max_component(char* filename, char component) {
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    int max_value = -1;
    int max_x = 0, max_y = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            if (!pixel) continue;

            int value = 0;
            if (component == 'R') value = pixel->R;
            else if (component == 'G') value = pixel->G;
            else if (component == 'B') value = pixel->B;

            if (value > max_value) {
                max_value = value;
                max_x = x;
                max_y = y;
            }
        }
    }

    printf("max_component %c (%d, %d): %d\n", component, max_x, max_y, max_value);
    free_image_data(data);
}


void min_component(char* filename, char component) {
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    int min_value = 256;
    int min_x = 0, min_y = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            if (!pixel) continue;

            int value = 0;
            if (component == 'R') value = pixel->R;
            else if (component == 'G') value = pixel->G;
            else if (component == 'B') value = pixel->B;

            if (value < min_value) {
                min_value = value;
                min_x = x;
                min_y = y;
            }
        }
    }

    printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_value);
    free_image_data(data);
}

void color_red(char* filename) {
    int width, height, channel_count;
    unsigned char *data;
    
   
    read_image_data(filename, &data, &width, &height, &channel_count);
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            pixel->G = 0;
            pixel->B = 0;
            set_pixel(data, width, channel_count, x, y, pixel);
        }
    }
   
    free_image_data(data);
}

void color_green(char* filename) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            pixel->R = 0;  
            pixel->B = 0;  
            
            set_pixel(data, width, channel_count, x, y, *pixel);
        }
    }

    int result = write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_blue(char* filename) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            pixel->R = 0;  
            pixel->G = 0;  
            
            set_pixel(data, width, channel_count, x, y, *pixel);
        }
    }

    int result = write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_gray(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            
            unsigned char value = (pixel->R + pixel->G + pixel->B) / 3;
            
            pixel->R = value;
            pixel->G = value;
            pixel->B = value;
            
            set_pixel(data, width, channel_count, x, y, *pixel);
        }
    }

    int result = write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_invert(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            
            // Inverser chaque composante couleur : new_value = 255 - old_value
            pixel->R = 255 - pixel->R;
            pixel->G = 255 - pixel->G;
            pixel->B = 255 - pixel->B;
            
            set_pixel(data, width, channel_count, x, y, *pixel);
        }
    }

    int result = write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}
