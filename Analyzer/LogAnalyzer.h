#ifndef LOGANALYZER_H
#define LOGANALYZER_H

#include "LogEntry.h"
#include <vector>
#include <string>
#include <map>

class LogAnalyzer {
private:
    std::vector<LogEntry> logs;

public:
    void loadLogs(const std::string& filename);
    void analyze();
};

#endif // LOGANALYZER_H