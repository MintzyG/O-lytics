#include "olytics.h"
#include <stdlib.h>
#include <time.h>

OlyticsInstance* CreateInstance() {
  OlyticsInstance* instance = (&OlyticsInstance) {
    .database = CreateDB(),
    .CreateProbe = CreateProbe
  };


}

Probe* NewProbe() {

}

Obase* CreateDB() {
  Obase* db = (&Obase) {
    .database = (Probe*)calloc(1, sizeof(Probe)),
    .ResizeDatabase = ResizeDatabase,
    .AddProbe = AddProbe,
    .RemoveProbe = RemoveProbe,
    .capacity = 1,
    .size = 1
  };

  return db;
}
