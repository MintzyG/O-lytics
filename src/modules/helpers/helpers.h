#pragma once

#include<stdio.h>

typedef struct oLog oLog;
typedef enum LogLevel LogLevel;

enum LogLevel {
  OFF,
  WARNING,
  TRACE
};

struct oLog {
  enum LogLevel log_level;

  FILE* file;

  void (*Log)(oLog* log, char* message, char* context);
  void (*SetLevel)(oLog* self, enum LogLevel);
  void (*CloseLogs)(oLog* self);
};

oLog* InitLog(void);
void Uninplemented(const char*);
