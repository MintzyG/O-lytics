typedef struct oLog oLog;
struct oLog {
  int log_level;

  void (*log)(int log_level, const char* context);
};

void Uninplemented();
