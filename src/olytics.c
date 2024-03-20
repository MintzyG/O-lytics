#include "olytics.h"
#include "obase.h"
#include "_probe.h"
#include <stdlib.h>
#include <time.h>

Probe* NewProbe() {
  Probe* p = (Probe*)calloc(1, sizeof(Probe));
  *p = (Probe) {
    .nome = "juan",
    .comparissons = 0,
    .operations = 0,
    .swaps = 0,
    .totalClock = 0,
    .endClock = 0,
    .startClock = 0,
    .ProbeStartClock = ProbeStartClock,
    .ProbeEndClock = ProbeEndClock,
    .ExecutionTime = ExecutionTime,
    .RegisterData = RegisterData
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

OlyticsInstance* CreateInstance() {
  OlyticsInstance* O = (OlyticsInstance*)calloc(1, sizeof(OlyticsInstance));
  *O = (OlyticsInstance) {
    .id = 1,
    .NewProbe = NewProbe,
    .obase = CreateDB(),
  };
  return O;
}
