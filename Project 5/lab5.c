#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  srand(time(NULL));


  int dimension = 20; // Change this to 20, 200, and 2000
  int matrix[dimension][dimension];
  float summedMatrix = 0;

  for (int x = 0; x < dimension; x++) {
    for (int y = 0; y < dimension; y++) {
      matrix[x][y] = rand();
    }
  }

  clock_t begin = clock();

  for (int x = 0; x < dimension; x++) {
    for (int y = 0; y < dimension; y++) {
      summedMatrix += matrix[x][y];
    }
  }

  clock_t end = clock();

  double time = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Size= %d sum=%f \n time =%f", dimension, summedMatrix, time);

 dimension = 200; // Change this to 20, 200, and 2000
  matrix[dimension][dimension];
  summedMatrix = 0;

  for (int x = 0; x < dimension; x++) {
    for (int y = 0; y < dimension; y++) {
      matrix[x][y] = rand();
    }
  }

  begin = clock();

  for (int x = 0; x < dimension; x++) {
    for (int y = 0; y < dimension; y++) {
      summedMatrix += matrix[x][y];
    }
  }

  end = clock();

  time = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Size= %d sum=%f \n time =%f", dimension, summedMatrix, time);


  return 0;
}