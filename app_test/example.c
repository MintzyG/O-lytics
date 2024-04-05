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

// A single puzzle remains, what if I need multiple pieces of data for the function to work?
// I could just adapt the function to receive a single struct Package and then unpack it inside
// Or could take a look at c11 overloading like structure using _Generic and macros
// Or perhaps use variadic arguments to feed the function 
int main() {
  OlyticsInstance* O = CreateInstance();
  int* ptr = (int*)O->OlyticsWrapper(O, bubble, data()); 
  printData(ptr);
  O->ProbeDataByIndex(O, 0);
  return 0;
}
