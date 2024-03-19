#include <time.h>

typedef OlyticsInstance OlyticsInstance;
typedef Obase Obase;
typedef Probe Probe;

struct OlyticsInstance {
  Obase database;
  
  Probe* (*NewProbe)();
  void* (*OlyticsWrapper)();
};

struct Obase {
  Probe* database;
  int capacity, size;

  Probe* (*ResizeDatabase)();
  Probe* (*AddProbe)();
  void (*RemoveProbe)(Probe* probe);
};

struct Probe {
  int operations, comparissons, swaps;
  clock_t totalClock, startClock, endClock;

  int id;

  clock_t (*ProbeStartClock)(Probe *self);
  clock_t (*ProbeEndClock)(Probe *self);
  clock_t (*ExecutionTime)(Probe *self);

  void (*RegisterData)(Probe *self, int operations, int comparissons, int swaps);
};

OlyticsInstance* CreateInstance();
