#include "helpers.h"
#include "string.h"
#include "stdlib.h"

#include <stdio.h>
#include <errno.h>

void Uninplemented(const char* func) {
  errno = ENOSYS;
  printf("%s: %s\n Exiting!!!",func, strerror(errno));
  exit(1);
}
