#pragma once
#include <time.h>
#include "obase.h"
#include "probe.h"

typedef struct OlyticsInstance OlyticsInstance;

struct OlyticsInstance {
  Obase obase;

  // void* (functions[10])(void* ptr, int* cmp, int* swp, int* ops);

  Probe* (*NewProbe)();
  void* (*OlyticsWrapper)();
};

OlyticsInstance* CreateInstance();
