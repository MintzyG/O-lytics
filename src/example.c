#include "olytics.h"
#include "bubble.h"
#include "insertion.h"
#include "selection.h"

#define EXIT_SUCCESS 0

int main() {
  OlyticsInstance O = CreateInstance();

  // Olytics loop empty needs a function list
  Olytics.Functions = {Bubble, Selection, Insertion};
  OlyticsLoop();

  // Olytics loop full gets all functions from the get go
  OlyticsLoop(
    Bubble,
    Selection,
    Insertion,
    // Three modes "T"extual, "V"isual
    "V"
  );

  // Both looping versions are in "Showcase" mode
  // They don't use OlyticsWrapper, they use their own code runner

  // OlyticsWrapper is its own code runner and returns the functions results to you
  // in a void pointer so you can get both the results and benchmarks
  ptr = (int*)OlyticsWrapper(Bubble)

  return EXIT_SUCCESS;
}
