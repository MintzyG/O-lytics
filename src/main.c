#include <stdio.h>
#include "olytics.h"
#include "probe.h"

int main() {
  OlyticsInstance* O = CreateInstance();
  Probe* P = O->NewProbe();
  O->obase->AddProbe(O->obase->database, P);
  O->obase->database[0].nome = "mark";
  printf("%s", O->obase->database[0].nome);

  return 0;
}
