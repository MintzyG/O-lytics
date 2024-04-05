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
int main(int argc, char** argv) {

  int size = 0, ceiling = 0;

  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      switch (i) {
        case 1:
          size = strtoul(argv[1], NULL, 0);
          break;
        case 2:
          ceiling = strtoul(argv[2], NULL, 0);
          break;
      }
    }
  }

  OlyticsInstance* O = CreateInstance();
  printf("Calling GTD()\n");
  int* data = GenerateTestData(size, ceiling);
  printData(data, size);
  printf("running the wrapper\n");
  O->OlyticsWrapper(O, bubble, data, size); 
  // printf("\n\n\n\n");
  printData(data, size);
  O->ProbeDataByIndex(O, 0);
  return 0;
}
