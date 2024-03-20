#include "olytics.h"
#include "obase.h"
#include "_probe.h"
#include <stdlib.h>
#include <time.h>

Probe* NewProbe() {
  Probe* p = (Probe*)calloc(1, sizeof(Probe));
  *p = (Probe) {
    .name = "defaultProbe",
    .comparissons = 0,
    .operations = 0,
    .swaps = 0,
    .executionTime = 0,
    .endClock = 0,
    .startClock = 0,
    .ProbeStartClock = ProbeStartClock,
    .ProbeEndClock = ProbeEndClock,
    .ExecutionTime = ExecutionTime,
    .RegisterData = RegisterData,
    .ProbeData = ProbeData,
  }; 
  return p;
}

// Why does initializing to a pointer using compound literals doens't initialize some variables?
// So I have to resort to calloc then use compound.
// Can compound literals even be used to allocate memory?
Obase* CreateDB() {
  Obase* db = (Obase*)calloc(1, sizeof(Obase));
  *db = (Obase) {
    .database = (Probe*)calloc(1, sizeof(Probe)),
    .ResizeDatabase = ResizeDatabase,
    .AddProbe = AddProbe,
    .RemoveProbe = RemoveProbe,
    .capacity = 1,
    .size = 1,
  };
  return db;
}
void* OlyticsWrapper(OlyticsInstance* O, void* (*function)(void* ptr, int* cmp, int* swp, int* ops), void* data) {
  Probe* P = O->NewProbe();

  int *cmp, *swp, *ops;
  cmp = (int*)calloc(1, sizeof(int));
  swp = (int*)calloc(1, sizeof(int));
  ops = (int*)calloc(1, sizeof(int));

  P->ProbeStartClock(P);

  void* ptr = function(data, cmp, swp, ops);

  P->ProbeEndClock(P);
  P->ExecutionTime(P);

  P->RegisterData(P, ops, cmp, swp);

  O->obase->AddProbe(O->obase, P);

  free(cmp);
  free(swp);
  free(ops);

  return ptr;
}

void ProbeDataByIndex(OlyticsInstance* O, int index) { 
  O->obase->database[index].ProbeData(&O->obase->database[index]);
}

OlyticsInstance* CreateInstance() {
  OlyticsInstance* O = (OlyticsInstance*)calloc(1, sizeof(OlyticsInstance));
  *O = (OlyticsInstance) {
    .id = 1,
    .NewProbe = NewProbe,
    .obase = CreateDB(),
    .OlyticsWrapper = OlyticsWrapper,
    .ProbeDataByIndex = ProbeDataByIndex,
  };
  return O;
}
