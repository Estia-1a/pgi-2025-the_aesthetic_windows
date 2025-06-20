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
    
    printf("Tenth Pixel Red : %d,0,0\n", r);
    printf("Tenth Pixel Green : 0,%d,0\n", g);
    printf("Tenth Pixel Blue : 0,0,%d\n", b);
    
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
    int result = write_image_data("image_out.bmp", data, width, height);
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
            
            
            pixel->R = 255 - pixel->R;
            pixel->G = 255 - pixel->G;
            pixel->B = 255 - pixel->B;
            
            set_pixel(data, width, channel_count, x, y, *pixel);
        }
    }

    int result = write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_gray_luminance(char* filename) {
    int width, height, channel_count;
    unsigned char *data;
    
    read_image_data(filename, &data, &width, &height, &channel_count);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            
            // Calcul de la luminance avec coefficients perceptuels
            int luminance = (int)(0.21 * pixel->R + 0.72 * pixel->G + 0.07 * pixel->B);
            
            // S'assurer que ça reste dans les limites
            if (luminance > 255) luminance = 255;
            if (luminance < 0) luminance = 0;
            
            pixel->R = (unsigned char)luminance;
            pixel->G = (unsigned char)luminance;
            pixel->B = (unsigned char)luminance;
            
            set_pixel(data, width, channel_count, x, y, *pixel);
        }
    }
    
    int result = write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void rotate_cw(char* filename) {
    int width, height, channel_count;
    unsigned char *data;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    int new_width = height;
    int new_height = width;
    unsigned char *rotated = malloc(new_width * new_height * channel_count);
    if (!rotated) {
        printf("Erreur d'allocation mémoire\n");
        free(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channel_count; c++) {
                int src_index = (y * width + x) * channel_count + c;
                int dst_index = (x * new_width + (new_width - 1 - y)) * channel_count + c;
                rotated[dst_index] = data[src_index];
            }
        }
    }

    write_image_data("image_out.bmp", rotated, new_width, new_height);

    free(data);
    free(rotated);
}


void rotate_acw(char* filename) {
    int width, height, channel_count;
    unsigned char *data;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    int new_width = height;
    int new_height = width;
    unsigned char *rotated = malloc(new_width * new_height * channel_count);
    if (!rotated) {
        printf("Erreur d'allocation mémoire\n");
        free(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channel_count; c++) {
                int src_index = (y * width + x) * channel_count + c;
                int dst_index = ((new_height - 1 - x) * new_width + y) * channel_count + c;
                rotated[dst_index] = data[src_index];
            }
        }
    }

    write_image_data("image_out.bmp", rotated, new_width, new_height);

    free(data);
    free(rotated);
}

void mirror_horizontal(char* filename) {
    int width, height, channel_count;
    unsigned char *data;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    unsigned char *mirrored = malloc(width * height * channel_count);
    if (!mirrored) {
        printf("Erreur d'allocation mémoire\n");
        free(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channel_count; c++) {
                int src_index = (y * width + x) * channel_count + c;
                int dst_index = (y * width + (width - 1 - x)) * channel_count + c;
                mirrored[dst_index] = data[src_index];
            }
        }
    }

    write_image_data("image_out.bmp", mirrored, width, height);

    free(data);
    free(mirrored);
}

void mirror_vertical(char* filename) {
    int width, height, channels;
    unsigned char *data;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    unsigned char *result = malloc(width * height * channels);
    if (result == NULL) {
        printf("Erreur mémoire\n");
        free(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        int src_y = height - 1 - y;
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int src_index = (src_y * width + x) * channels + c;
                int dst_index = (y * width + x) * channels + c;
                result[dst_index] = data[src_index];
            }
        }
    }

    write_image_data("image_out.bmp", result, width, height);

    free(data);
    free(result);
}

void mirror_total(char* filename) {
    int width, height, channels;
    unsigned char *data;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    unsigned char *mirrored = malloc(width * height * channels);
    if (mirrored == NULL) {
        printf("Erreur d’allocation mémoire\n");
        free(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        int inv_y = height - 1 - y; 
        for (int x = 0; x < width; x++) {
            int inv_x = width - 1 - x; 
            for (int c = 0; c < channels; c++) {
                int src_index = (inv_y * width + inv_x) * channels + c;
                int dst_index = (y * width + x) * channels + c;
                mirrored[dst_index] = data[src_index];
            }
        }
    }

    write_image_data("image_out.bmp", mirrored, width, height);

    free(data);
    free(mirrored);
}

void color_desaturate(char* filename) {
    int width, height, channel_count;
    unsigned char *data;

   
    read_image_data(filename, &data, &width, &height, &channel_count);

    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
           
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);
            
            
            unsigned char min_val = pixel->R;
            if (pixel->G < min_val) min_val = pixel->G;
            if (pixel->B < min_val) min_val = pixel->B;
            
            unsigned char max_val = pixel->R;
            if (pixel->G > max_val) max_val = pixel->G;
            if (pixel->B > max_val) max_val = pixel->B;
            
            unsigned char new_val = (min_val + max_val) / 2;
            
            
            pixel->R = new_val;
            pixel->G = new_val;
            pixel->B = new_val;
            
            
            set_pixel(data, width, channel_count, x, y, *pixel);
        }
    }

    
    int result = write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}


void scale_nearest(char* filename, float facteur) {
    unsigned char* image_originale;
    int largeur, hauteur, canaux;

    if (read_image_data(filename, &image_originale, &largeur, &hauteur, &canaux) == 0) {
        printf("Erreur de lecture du fichier : %s\n", filename);
        return;
    }

    int nouvelle_largeur = largeur * facteur;
    int nouvelle_hauteur = hauteur * facteur;

    if (nouvelle_largeur <= 0 || nouvelle_hauteur <= 0) {
        printf("Erreur : facteur d echelle invalide (%.2f)\n", facteur);
        free(image_originale);
        return;
    }

    unsigned char* image_redimensionnee = malloc(nouvelle_largeur * nouvelle_hauteur * canaux);
    if (image_redimensionnee == NULL) {
        printf("Erreur d'allocation mémoire\n");
        free(image_originale);
        return;
    }

    for (int y = 0; y < nouvelle_hauteur; y++) {
        for (int x = 0; x < nouvelle_largeur; x++) {

            int ancien_x = x / facteur;
            int ancien_y = y / facteur;

            int index_original = (ancien_y * largeur + ancien_x) * canaux;
            int index_nouveau = (y * nouvelle_largeur + x) * canaux;

            for (int c = 0; c < canaux; c++) {
                image_redimensionnee[index_nouveau + c] = image_originale[index_original + c];
            }
        }
    }

    write_image_data("image_out.bmp", image_redimensionnee, nouvelle_largeur, nouvelle_hauteur);

    free(image_originale);
    free(image_redimensionnee);
}

void scale_bilinear(char* filename, float scale_factor) {
    int width, height, channel_count;
    unsigned char* data;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    int new_width = (int)(width * scale_factor);
    int new_height = (int)(height * scale_factor);

    if (new_width <= 0 || new_height <= 0) {
        printf("Erreur : facteur d echelle invalide (%.2f)\n", scale_factor);
        free(data);
        return;
    }

    unsigned char* result = malloc(new_width * new_height * channel_count);
    if (result == NULL) {
        printf("Erreur d'allocation mémoire\n");
        free(data);
        return;
    }

    for (int y = 0; y < new_height; y++) {
        float gy = ((float)y / (float)(new_height)) * (height - 1);
        int y0 = (int)gy;
        int y1 = y0 + 1;
        if (y1 >= height) y1 = height - 1;
        float dy = gy - y0;

        for (int x = 0; x < new_width; x++) {
            float gx = ((float)x / (float)(new_width)) * (width - 1);
            int x0 = (int)gx;
            int x1 = x0 + 1;
            if (x1 >= width) x1 = width - 1;
            float dx = gx - x0;

            for (int c = 0; c < channel_count; c++) {
                int i00 = (y0 * width + x0) * channel_count + c;
                int i01 = (y0 * width + x1) * channel_count + c;
                int i10 = (y1 * width + x0) * channel_count + c;
                int i11 = (y1 * width + x1) * channel_count + c;

                float val = (1 - dx) * (1 - dy) * data[i00] +
                            dx * (1 - dy) * data[i01] +
                            (1 - dx) * dy * data[i10] +
                            dx * dy * data[i11];

                result[(y * new_width + x) * channel_count + c] = (unsigned char)val;
            }
        }
    }

    write_image_data("image_out.bmp", result, new_width, new_height);

    printf("Image redimensionnee par interpolation bilineaire : %dx%d -> %dx%d (facteur: %.2f)\n",
           width, height, new_width, new_height, scale_factor);

    free(data);
    free(result);
}


void scale_crop(char* filename, int center_x, int center_y, int crop_width, int crop_height) {
    int width, height, channel_count;
    unsigned char *data;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    int start_x = center_x - crop_width / 2;
    int start_y = center_y - crop_height / 2;

    if (start_x < 0) start_x = 0;
    if (start_y < 0) start_y = 0;
    if (start_x + crop_width > width) crop_width = width - start_x;
    if (start_y + crop_height > height) crop_height = height - start_y;

    unsigned char *cropped = malloc(crop_width * crop_height * channel_count);
    if (cropped == NULL) {
        printf("Erreur d'allocation mémoire\n");
        free(data);
        return;
    }

    for (int y = 0; y < crop_height; y++) {
        for (int x = 0; x < crop_width; x++) {
            for (int c = 0; c < channel_count; c++) {
                int src_index = ((y + start_y) * width + (x + start_x)) * channel_count + c;
                int dst_index = (y * crop_width + x) * channel_count + c;
                cropped[dst_index] = data[src_index];
            }
        }
    }

    write_image_data("image_out.bmp", cropped, crop_width, crop_height);

    free(data);
    free(cropped);
}
