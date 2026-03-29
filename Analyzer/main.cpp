#include "LogAnalyzer.h"
#include <iostream>

int main()
{
    LogAnalyzer analyzer;

    analyzer.loadLogs("sample_log.txt");
    analyzer.analyze();

    return 0;
}