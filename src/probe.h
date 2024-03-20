#pragma once

#include <time.h>

typedef struct Probe Probe;

struct Probe {
    __attribute__((unused))int operations, comparissons, swaps;
    __attribute__((unused))clock_t totalClock, startClock, endClock;

    __attribute__((unused))int id;
    __attribute__((unused))char* nome;

    __attribute__((unused))clock_t (*ProbeStartClock)(Probe *self);
    __attribute__((unused))clock_t (*ProbeEndClock)(Probe *self);
    __attribute__((unused))clock_t (*ExecutionTime)(Probe *self);

  void (*RegisterData)(Probe *self, int operations, int comparissons, int swaps);
};


