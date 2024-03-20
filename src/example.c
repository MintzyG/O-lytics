#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "olytics.h"
#include "probe.h"
#include "exampleFunc.h"

void printData(int* data) {
  for (int i = 0; i < 100; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
}

int* data() {
  int* ptr = (int*)calloc(100, sizeof(int));
  for (int i = 0; i < 100; i++) {
    ptr[i] = rand() % 100 + 1;
  }
  printData(ptr);
  return ptr;
}

// A single puzzle remains, how to get the lenght of a pointer, or will we have to implement something to pass the length?
int main() {
  OlyticsInstance* O = CreateInstance();
  int* ptr = (int*)O->OlyticsWrapper(O, bubble, data()); // bubble is what I want to test and Data is the data passed to oneUp
  printData(ptr); // Not needed, just here to show you can keep you data after benchmarking
  O->ProbeDataByIndex(O, 0); // Gets the probe data at index requested from obase database
  return 0;
}
