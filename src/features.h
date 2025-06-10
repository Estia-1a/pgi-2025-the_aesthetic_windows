#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void dimension(char* filename);

void first_pixel(char* filename);

void tenth_pixel (char* filename);

void second_line(char* filename);

void print_pixel(char* filename, int x, int y);

void max_pixel(char* filename);

<<<<<<< HEAD
void keep_red_component(const unsigned char *input, unsigned char *output, int width, int height);
void process_color_red(const char *filename);

=======
void min_pixel(char* filename);

void max_component(char* filename, char component);
>>>>>>> aebae97103631d1a7e7fe78a674d2a83f9c9a063

#endif
