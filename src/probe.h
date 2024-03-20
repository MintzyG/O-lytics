#pragma once

#include <time.h>

typedef struct Probe Probe;

struct Probe {
    int operations, comparissons, swaps;
    clock_t startClock, endClock;
    double executionTime;

    __attribute__((unused))int id;
    __attribute__((unused))char* name;

    clock_t (*ProbeStartClock)(Probe *self);
    clock_t (*ProbeEndClock)(Probe *self);
    double (*ExecutionTime)(Probe *self);

    void (*RegisterData)(Probe *self, int* operations, int* comparissons, int* swaps);
    void (*ProbeData)(Probe *self);
};


