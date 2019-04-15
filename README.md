# Image Noise Removal

## About
This program implements two types of filters commonly used for removing noise in an image. The two filters here are a Mean Filter and a Median Filter. These filters work by calculating the Mean or Median of surrounding pixels in an image and uses that data to produce a noise free output. The program works on the principle of parallelism wherein multiple processes perform these calculations on respective image pixels.

## Approach for parallelization
Here, we use two technologies to parallelize noise removal. The first approach uses Message Passing Interface(MPI) and the second uses CUDA. 