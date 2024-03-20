#include <stdio.h>
#include "olytics.h"
#include "probe.h"

int main() {
  OlyticsInstance* O = CreateInstance();
  Probe* P;
  P = O->NewProbe();
  
  printf("%s\n", P->nome);

  return 0;
}
