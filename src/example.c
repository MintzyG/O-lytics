#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "olytics.h"
#include "probe.h"
#include "exampleFunc.h"

void printData(int* data, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
}

// A single puzzle remains, what if I need multiple pieces of data for the function to work?
// I could just adapt the function to receive a single struct Package and then unpack it inside
// Or could take a look at c11 overloading like structure using _Generic and macros
// Or perhaps use variadic arguments to feed the function 
int main() {
  OlyticsInstance* O = CreateInstance();
  printf("Calling GTD()\n");
  int size = 50000;
  int* data = GenerateTestData(size, 1000);
  printData(data, 50);
  printf("running the wrapper\n");
  O->OlyticsWrapper(O, bubble, data, size); 
  // printf("\n\n\n\n");
  printData(data, size);
  O->ProbeDataByIndex(O, 0);
  return 0;
}
