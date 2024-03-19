#include <time.h>
#include "obase.h"
#include "probe.h"

typedef OlyticsInstance OlyticsInstance;

struct OlyticsInstance {
  Obase database;

  void* (functions[10])(void* ptr, int* cmp, int* swp, int* ops);

  Probe* (*NewProbe)();
  void* (*OlyticsWrapper)();
};

OlyticsInstance* CreateInstance();
