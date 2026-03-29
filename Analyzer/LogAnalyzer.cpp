#include "LogAnalyzer.h"
#include <fstream>
#include <iostream>

void LogAnalyzer::loadLogs(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while(getline(file, line)) {
        logs.push_back(LogEntry(line)); 
    }

    file.close();
}

void LogAnalyzer::analyze() {
    int info = 0, warning = 0, error = 0, invalid = 0;

    std::map<std::string, int> errorCount;
    std::map<std::string, int> moduleErrors;

    for (const auto& log : logs) {
        if (!log.isValid) {
            invalid++;
            continue;
        }

        if (log.severeity == "INFO") info++;
         else if (log.severeity == "WARNING") warning++;
         else if (log.severeity == "ERROR") {
            error++;
            errorCount[log.message]++;
            moduleErrors[log.module]++;
        }
    }

    std::cout << "=== LOG ANALYSIS ===\n\n";
    std::cout << "Total Entries: " << logs.size() << "\n";
    std::cout << "INFO: " << info << "\n";
    std::cout << "Warnings: " << warning << "\n";
    std::cout << "ERROR: " << error << "\n";
    std::cout << "Invalid: " << invalid << "\n";

    // For most frequeent errors
    std::string topError;
    int maxCount = 0;

    for(auto& pair : errorCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            topError = pair.first;
        }
    }

    std::cout << "Most Frequent Error:\n";
    std::cout << "_" <<topError << "(" << maxCount << " occurences)\n\n";

    std::cout << "Errors by Module:\n";
    for (auto& pair : moduleErrors) {
        std::cout << "- " << pair.first << ": " << pair.second << "\n";

}}