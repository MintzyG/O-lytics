#include "helpers.h"
#include "string.h"
#include "stdlib.h"

#include <stdio.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat st = {0};



void Uninplemented(const char* func) {
  errno = ENOSYS;
  printf("%s: %s\n Exiting!!!",func, strerror(errno));
  exit(1);
}

void SetupLog() {
  if (stat("./logs", &st) == -1) {
    mkdir("./logs", 0700);
  }
}

void SetLevel(oLog* logger, enum LogLevel level) {
  logger->log_level = level;
}

void Log(oLog* log, char* message, char* func) {
  char* ptr = calloc(256, 1);
  switch (log->log_level) {
    case WARNING:
      sprintf(ptr, "[WARNING](%s): %s\n", func, message);
      fprintf(log->file, ptr);
      break;
    case TRACE:
    default:
    case OFF:
      break;
  }
  free(ptr);
}

void CloseLogs(oLog* logs) {
  fclose(logs->file);
}

oLog* InitLog(void) {
  oLog* l = calloc(1, sizeof *l);

  SetupLog();

  *l = (oLog) {
    .log_level = OFF,
    .Log = Log,
    .SetLevel = SetLevel,
    .file = fopen("./logs/log.txt", "w"),
    .CloseLogs = CloseLogs
  };
  return l;
}
