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

void color_red(char* filename);

void color_green(char* filename);

void color_blue(char* filename);

void color_gray(char* filename);

void color_invert(char* filename);

void color_gray_luminance(char *filename);

void rotate_cw(char* filename);

void rotate_acw(char* filename);

void mirror_horizontal(char* filename);

void mirror_vertical(char* filename);

void mirror_total(char* filename);

void color_desaturate(char* filename);

void scale_nearest(char* filename, float scale_factor);

void scale_bilinear(char* filename, float scale_factor);

void scale_crop(char* filename, int center_x, int center_y, int crop_width, int crop_height);

#endif
