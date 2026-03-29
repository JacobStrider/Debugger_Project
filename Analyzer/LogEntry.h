#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>

class LogEntry {
public:
        std::string timestamp;
        std::string severeity;
        std::string module;
        std::string message;
        bool isValid;

        LogEntry(std::string line);
    }; 

#endif // LOGENTRY_H