#include <time.h>
#include <stdio.h>

#include "probe.h"

clock_t ProbeStartClock(Probe *probe) {
  clock_t start = clock();
  probe->startClock = start;
  return start;
}

clock_t ProbeEndClock(Probe *probe) {
  clock_t end = clock();
  probe->endClock = end;
  return end;
}

double ExecutionTime(Probe *probe) {
  double totalTime = ((double)(probe->endClock - probe->startClock)) / CLOCKS_PER_SEC;
  probe->executionTime = totalTime;
  return totalTime;
}

void RegisterData(Probe *probe, int* ops, int* comps, int* swaps) {
  probe->comparissons = *comps;
  probe->swaps = *swaps;
  probe->operations = *ops;
}

void ProbeData(Probe *probe) {
  printf("Program Executed in: %f seconds\n", probe->executionTime);
  printf("%d Comparissons were done\n", probe->comparissons);
  printf("%d Swaps were done\n", probe->swaps);
  printf("%d Operations were done\n", probe->operations);
}
