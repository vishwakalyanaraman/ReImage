#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a1.h"

void quickSort(unsigned char *a, int l, int r );
unsigned char partition(unsigned char *a, int l, int r);
unsigned char mean(unsigned char *a, int size);


RGB *processImage(int width, int height, RGB *image, int windowSize, char* filterType){
    int i, j, k, l;

    if(windowSize == 1){
        return image;
    }


    //Process pixel by pixel

    RGB *filtered = (RGB*) malloc(sizeof(RGB) * width * height);
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){


            //Creating individual RGB channels

            unsigned char windowR* = (unsigned char*) malloc(sizeof(unsigned char) * windowSize * windowSize);
            unsigned char windowG* = (unsigned char*) malloc(sizeof(unsigned char) * windowSize * windowSize);
            unsigned char windowB* = (unsigned char*) malloc(sizeof(unsigned char) * windowSize * windowSize);

            int start = 0;
            int left = i - windowSize / 2;
            int right = i + windowSize / 2;
            int up = j - windowSize / 2;
            int down = j + windowSize / 2;


            //Transferring input image into individual RGB channels

            for(k = left; k < right; k++){
                for( l = up; l < down; l++){
                    if(k >= 0 && l >= 0 && k < height && l < width){
                        windowR[start] = image[k * width + l].r;
                        windowG[start] = image[k * width + l].g;
                        windowB[start] = image[k * width + l].b;
                        start++;
                    }
                }
            }

            unsigned char filteredElementR;            
            unsigned char filteredElementG;            
            unsigned char filteredElementB;

            if(!strcmp(filterType, "MEAN")){
                filteredElementR = mean(windowR, start);
                filteredElementG = mean(windowG, start);
                filteredElementB = mean(windowB, start);
            }

            if(!strcmp(filterType, "MEDIAN")){
                quickSort(windowR, 0, start);
                quickSort(windowG, 0, start);
                quickSort(windowB, 0, start);

                filteredElementR = windowR[start/2];
                filteredElementG = windowG[start/2];
                filteredElementB = windowB[start/2];
            }

            filtered[i * width + j].r = filteredElementR;
            filtered[i * width + j].g = filteredElementG;
            filtered[i * width + j].b = filteredElementB;
        }
    }

    //Transfer filtered images back to output array

    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            image[i * width + j] = filtered[i * width + j];
        }
    }

    return image;
}

            
