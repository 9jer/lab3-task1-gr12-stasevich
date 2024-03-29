/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function for calculating the sum of digits of a number
int sum_of_digits(int number) {
  int sum = 0;
  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }
  return sum;
}

// Comparison function for sorting an array in descending order of the sums of
// digits of numbers
int compare(const void *a, const void *b) {
  int sum_a = sum_of_digits(*(int *)a);
  int sum_b = sum_of_digits(*(int *)b);
  return sum_b - sum_a;
}

int main(int argc, char *argv[]) {
  // Checking for the number of arguments
  if (argc != 2) {
    printf("Usage: %s <size_of_array>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]); // Array size

  // Checking for correct array size
  if (n <= 0) {
    printf("The size of the array must be greater than 0.\n");
    return 1;
  }

  // Creating an array and filling it with values from arguments
  int *array = (int *)malloc(n * sizeof(int));
  if (array == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Initializing random number generator
  srand(time(NULL));

  // Filling the array with random numbers
  for (int i = 0; i < n; i++) {
    array[i] = rand() % 1000; // Generating random numbers in the range [0, 999]
  }

  // Output of raw data
  printf("Source array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // Array sorting
  qsort(array, n, sizeof(int), compare);

  // Output sorted array
  printf("Sorted array in descending order of digit sums:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  free(array); // Freeing memory allocated for an array
  return 0;
}