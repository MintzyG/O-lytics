#pragma once

#include "probe.h"

clock_t ProbeStartClock(Probe *self);
clock_t ProbeEndClock(Probe *self);
double ExecutionTime(Probe *self);
void RegisterData(Probe *self, int* operations, int* comparissons, int* swaps);
void ProbeData(Probe *self);
