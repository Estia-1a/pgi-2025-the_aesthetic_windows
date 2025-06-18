# Daily Evaluation 18/06 - 15:35:21
You can find below how you did for each feature. 
 You should merge the pull request to keep the eval and automatically close and open the issues you have finished!
# Milestone  Tutorial
Score : 18/23 :  78%
## Detail by Feature
| Feature     | Score       | Missed tests                                                                                                                                          | Stdout                            |
| :---------- | :---------- | :---------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| dimension   | 4/4 :  100% |                                                                                                                                                       |                                   |
| first_pixel | 5/5 :  100% |                                                                                                                                                       |                                   |
| tenth_pixel | 0/5 :  0%   | Tenth Pixel 64x64 : 255,0,0<br>Tenth Pixel Red : 255,0,0<br>Tenth Pixel Green : 0,255,0<br>Tenth Pixel Blue : 0,0,255<br>Tenth Pixel 11 12 13 : 1,2,3 | Tenth Pixel Red : 255,0,0         |
                                                                                                                                                                                      Tenth Pixel Green : 0,0,0          
                                                                                                                                                                                      Tenth Pixel Blue : 0,0,0<br><br>…  
                                                                                                                                                                                      Tenth Pixel Green : 0,12,0         
                                                                                                                                                                                      Tenth Pixel Blue : 0,0,13          
| second_line | 5/5 :  100% |                                                                                                                                                       |                                   |
| print_pixel | 4/4 :  100% |                                                                                                                                                       |                                   |

# Milestone  statistiques
Score : 26/26 :  100%
## Detail by Feature
| Feature         | Score       | Missed tests | Stdout |
| :-------------- | :---------- | :----------- | :----- |
| max_pixel       | 4/4 :  100% |              |        |
| min_pixel       | 4/4 :  100% |              |        |
| min_component R | 3/3 :  100% |              |        |
| min_component G | 3/3 :  100% |              |        |
| min_component B | 3/3 :  100% |              |        |
| max_component R | 3/3 :  100% |              |        |
| max_component G | 3/3 :  100% |              |        |
| max_component B | 3/3 :  100% |              |        |

# Milestone  colors
Score : 33.08/35 :  94%
## Detail by Feature
| Feature              | Score         | Missed tests | Stdout |
| :------------------- | :------------ | :----------- | :----- |
| color_red            | 3.08/5 :  61% |              |        |
| color_blue           | 5/5 :  100%   |              |        |
| color_green          | 5/5 :  100%   |              |        |
| color_gray           | 5/5 :  100%   |              |        |
| color_invert         | 5/5 :  100%   |              |        |
| color_gray_luminance | 5/5 :  100%   |              |        |
| color_desaturate     | 5/5 :  100%   |              |        |

# Milestone  transform
Score : 15/15 :  100%
## Detail by Feature
| Feature           | Score       | Missed tests | Stdout |
| :---------------- | :---------- | :----------- | :----- |
| rotate_cw         | 3/3 :  100% |              |        |
| rotate_acw        | 3/3 :  100% |              |        |
| mirror_horizontal | 3/3 :  100% |              |        |
| mirror_vertical   | 3/3 :  100% |              |        |
| mirror_total      | 3/3 :  100% |              |        |

# Milestone  resize
Score : 35.730000000000004/60 :  59%
## Detail by Feature
| Feature        | Score                        | Missed tests                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Stdout                            |
| :------------- | :--------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| scale_nearest  | 17.25/20 :  86%              | scale_nearest 0.3                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      | Erreur : facteur d echelle inval… |
| scale_bilinear | 18.479999999999997/20 :  92% | scale_bilinear 0.21                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    | Erreur : facteur d echelle inval… |
| scale_crop     | 0/20 :  0%                   | scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10 | <br>Erreur d'allocation mémoire<… |

