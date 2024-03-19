#include "olytics.h"
#include <stdlib.h>
#include <time.h>

OlyticsInstance* CreateInstance() {
  OlyticsInstance* instance = (&OlyticsInstance) {
    .database = CreateDB(),
    .CreateProbe = CreateProbe
  };


}

Probe* NewProbe() {

}

Probe* ResizeDatabase() {

}

Probe* AddProbe() {

}

void RemoveProbe(Probe *probe) {

}

clock_t ProbeStartClock(Probe *probe) {

}

clock_t ProbeEndClock(Probe *probe) {

}

clock_t ExecutionTime(Probe *probe) {

}

void RegisterData(Probe *probe, int ops, int comps, int swaps) {

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
