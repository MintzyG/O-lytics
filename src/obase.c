#include "obase.h"

Probe* ResizeDatabase() {

}

Probe* AddProbe(Obase* o, Probe* probe) {
  if (o->capacity >= 1) {
    o->database[0] = (*probe);
    o->capacity -= 1;
    return probe;
  }
  return probe;
  // ResizeDatabase();
}

void RemoveProbe(__attribute__((unused))Probe *probe) {

}
