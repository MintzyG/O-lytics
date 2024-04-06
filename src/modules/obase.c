#include "obase.h"
#include "helpers.h"

#include <stdlib.h>

Probe* ResizeDatabase() {
  Uninplemented(__func__);
  return NULL;
}

Probe* AddProbe(Obase* O, Probe* probe) {
  if (O->capacity >= 1) {
    O->database[0] = (*probe);
    O->capacity -= 1;
    return probe;
  }
  ResizeDatabase();
  return probe;
}

void RemoveProbe(__attribute__((unused))Probe *probe) {
  Uninplemented(__func__);
}

// Why does initializing to a pointer using compound literals doens't initialize some variables?
// So I have to resort to calloc then use compound.
// Can compound literals even be used to allocate memory?
Obase* CreateDB() {
  Obase* db = (Obase*)calloc(1, sizeof(Obase));
  *db = (Obase) {
    .database = (Probe*)calloc(1, sizeof(Probe)),
    .ResizeDatabase = ResizeDatabase,
    .AddProbe = AddProbe,
    .RemoveProbe = RemoveProbe,
    .capacity = 1,
    .size = 1,
  };
  return db;
}
