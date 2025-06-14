#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void dimension(char* filename);

void first_pixel(char* filename);

void tenth_pixel (char* filename);

void second_line(char* filename);

void print_pixel(char* filename, int x, int y);

void max_pixel(char* filename);

void keep_red_component(const unsigned char *input, unsigned char *output, int width, int height);

void process_color_red(const char *filename);

void min_pixel(char* filename);

void max_component(char* filename, char component);

void min_component(char* filename, char component);

void color_red(char *filename);

void color_green(char *filename);

void color_blue(char *filename);

void color_gray(char *filename);

void color_invert(char *filename);


#endif
