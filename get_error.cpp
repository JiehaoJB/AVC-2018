#include "functions.h"

int get_error(){
    take_picture();

    int BLACK_THRESHOLD = 50;   //Threshold for detecting all black - adjustable - change to dynamically changed?
    int WHITE_THRESHOLD = 150;  //Threshold for detecting all white - adjustable - change to dynamically changed?

    int min = 255;
    int max = 0;
    for(int x = 0; x < 320; x++){
        int pixel = get_pixel(120, x, 3);
        if(pixel > max){
            max = pixel;
        }                               //Gets the maximum and minimum brightness level across the center line
        if(pixel < min){
            min = pixel;
        }
    }

    int average_brightness = ((max-min)/2) + min;

    if(average_brightness < BLACK_THRESHOLD){
        printf("average_brightness : %d\n", average_brightness);
        return -10000;                                             //Returns -10000 when detected all black
    }else if(average_brightness > WHITE_THRESHOLD){
        printf("average_brightness : %d\n", average_brightness);
        return 10000;                                              //Returns 10000 when detected all white
    }

    int np = 0;
    int error = 0;
    for(int x = 0; x < 320; x++){ //Scans the entire center row of the image
        int pixel = get_pixel(120, x, 3);
        // (pixels > average_brightness) will return 1 if the pixel is white or 0 of it's black
        if(pixel > average_brightness) {
            error += x-160;
            np++;
        }

    }

    error /= np; //Sets error to error value divided by number of white pixels detected

    return error;
}
