typedef Probe Probe;

  struct Probe {
    int operations, comparissons, swaps;
    clock_t totalClock, startClock, endClock;

    int id;

  clock_t (*ProbeStartClock)(Probe *self);
  clock_t (*ProbeEndClock)(Probe *self);
  clock_t (*ExecutionTime)(Probe *self);

  void (*RegisterData)(Probe *self, int operations, int comparissons, int swaps);
};


