#include "probe.h"

typdef Obase Obase;

struct Obase {
  Probe* database;
  int capacity, size;

  Probe* (*ResizeDatabase)();
  Probe* (*AddProbe)();
  void (*RemoveProbe)(Probe* probe);
};
