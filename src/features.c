#include <estia-image.h>
#include <stdio.h>

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

void run_feature(const char* feature, const char* filename, int x, int y) {
    if (strcmp(feature, "print_pixel") == 0) {
        print_pixel((char*)filename, x, y);
    }
}