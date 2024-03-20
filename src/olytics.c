#include "olytics.h"
#include "obase.h"
#include "probe.h"
#include <stdlib.h>
#include <time.h>

OlyticsInstance* CreateInstance() {
  OlyticsInstance* instance = (&OlyticsInstance) {
    .database = CreateDB(),
    .NewProbe = NewProbe
  };
  return instance;
}

Probe* NewProbe() {
  Probe* p = (&Probe) {
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

Obase* CreateDB() {
  Obase* db = (&Obase) {
    .database = (Probe*)calloc(1, sizeof(Probe)),
    .ResizeDatabase = ResizeDatabase,
    .AddProbe = AddProbe,
    .RemoveProbe = RemoveProbe,
    .capacity = 1,
    .size = 1
  };
  return db;
}
