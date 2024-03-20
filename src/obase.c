#include "obase.h"

Probe* ResizeDatabase() {

}

Probe* AddProbe(Probe* database, Probe* probe) {
  database[0] = (*probe);
  return probe;
}

void RemoveProbe(__attribute__((unused))Probe *probe) {

}
