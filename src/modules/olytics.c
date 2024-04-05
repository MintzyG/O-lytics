#include "olytics.h"
#include "obase.h"
#include "_probe.h"
#include "helpers.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

Probe* NewProbe() {
  Probe* p = (Probe*)calloc(1, sizeof(Probe));
  *p = (Probe) {
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
void* OlyticsWrapper(OlyticsInstance* O, void* (*function)(void* ptr, int size, int* cmp, int* swp, int* ops), void* data, int size) {
  printf("%s: Creating Probe\n", __func__);
  Probe* P = O->NewProbe();

  printf("%s: Allocating data spots\n", __func__);
  int *cmp, *swp, *ops;
  cmp = (int*)calloc(1, sizeof(int));
  swp = (int*)calloc(1, sizeof(int));
  ops = (int*)calloc(1, sizeof(int));

  printf("%s: Starting proccess\n", __func__);
  P->ProbeStartClock(P);

  function(data, size, cmp, swp, ops);

  P->ProbeEndClock(P);
  P->ExecutionTime(P);
  printf("%s: Finished proccess\n", __func__);

  P->RegisterData(P, ops, cmp, swp);

  O->obase->AddProbe(O->obase, P);

  free(cmp);
  free(swp);
  free(ops);
}

void ProbeDataByIndex(OlyticsInstance* O, int index) { 
  O->obase->database[index].ProbeData(&O->obase->database[index]);
}

int* GenerateTestData(int amount, int ceiling) {
  srand(time(NULL));
  printf("%s: Generating data\n-------------------\n", __func__);
  int* ptr = calloc(amount, sizeof(int));
  if (!ptr) {
    printf("Couldn't allocate enough memory");
    exit(1);
  }

  printf("%s: Test print\n", __func__);
  for (int i = 0; i < amount; i++) {
    printf("%d ", ptr[i]);
  }
  printf("\n\n");

  printf("%s: Filling ptr with data\n", __func__);
  for (int i = 0; i < amount; i++) {
    ptr[i] = rand() % ceiling + 1;
  }
  return ptr;
}

OlyticsInstance* CreateInstance() {
  OlyticsInstance* O = (OlyticsInstance*)calloc(1, sizeof(OlyticsInstance));
  *O = (OlyticsInstance) {
    .NewProbe = NewProbe,
    .obase = CreateDB(),
    .OlyticsWrapper = OlyticsWrapper,
    .ProbeDataByIndex = ProbeDataByIndex,
  };
  return O;
}


