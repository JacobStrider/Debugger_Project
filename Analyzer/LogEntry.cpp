#include "LogEntry.h"
#include <sstream>
#include <vector>

LogEntry::LogEntry(std::string line) {
    std::stringstream ss(line);
    std::string word;
    std::vector<std::string> parts;

    while (ss >> word) {
        parts.push_back(word);
    }

    if (parts.size() < 5) {
        isValid = false;
        return;
    }

    timestamp = parts[0] + " " + parts[1];
    severeity = parts[2];
    module = parts[3];

    message = "";
    for (size_t i = 4; i < parts.size(); ++i) {
        message += parts[i] + " ";
    }

    isValid = true;
}