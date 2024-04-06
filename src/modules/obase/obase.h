#pragma once

#include "probe.h"

typedef struct Obase Obase;

struct Obase {
  Probe* database;
  int capacity, size;

  Probe* (*ResizeDatabase)();
  Probe* (*AddProbe)(Obase* O, Probe* probe);
  void (*RemoveProbe)(Probe* probe);
};

Obase* CreateDB();
