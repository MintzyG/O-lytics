#pragma once
#include <time.h>
#include "obase.h"
#include "_probe.h"
#include "_olytics.h"

typedef struct OlyticsInstance OlyticsInstance;

struct OlyticsInstance {
  Obase* obase;
  // void* (functions[10])(void* ptr, int* cmp, int* swp, int* ops);

  Probe* (*NewProbe)();
  void* (*OlyticsWrapper)(OlyticsInstance* O,void* (*function)(void* ptr, int size, int* cmp, int* swp, int* ops), void* data, int size);
  void (*ProbeDataByIndex)(OlyticsInstance* O, int index);
};

int* GenerateTestData(int amount, int ceiling);
OlyticsInstance* CreateInstance();
