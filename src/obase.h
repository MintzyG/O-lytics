#pragma once

#include "probe.h"

typedef struct Obase Obase;

struct Obase {
  Probe* database;
  int capacity, size;

  Probe* (*ResizeDatabase)();
  Probe* (*AddProbe)();
  void (*RemoveProbe)(Probe* probe);
};

Probe* ResizeDatabase();
Probe* AddProbe();
void RemoveProbe(Probe* probe);
