#include "obase.h"
#include "helpers.h"

Probe* ResizeDatabase() {
  Uninplemented(__func__);
}

Probe* AddProbe(Obase* o, Probe* probe) {
  if (o->capacity >= 1) {
    o->database[0] = (*probe);
    o->capacity -= 1;
    return probe;
  }
  ResizeDatabase();
  return probe;
}

void RemoveProbe(__attribute__((unused))Probe *probe) {
  Uninplemented(__func__);
}
