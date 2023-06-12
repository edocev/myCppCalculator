// History.cpp
#include "History.h"
#include <iostream>
#include <fstream>

void History::saveHistory(std::string operation, int result) {
    std::ofstream historyFile;
    historyFile.open("history.txt", std::ios_base::app);
    historyFile << operation << " = " << result << std::endl;
    historyFile.close();
}

void History::readHistory() {
    std::ifstream historyFile;
    historyFile.open("history.txt");
    std::string line;

    for (int i = 0; i < 20; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;

    while (std::getline(historyFile, line)) {
        std::cout << line << std::endl;
    }

    for (int i = 0; i < 20; i++) {
        std::cout << "-";
    }

    std::cout << "-------------" << std::endl;
    historyFile.close();
}

void History::deleteHistory() {
    std::ofstream historyFile;
    historyFile.open("history.txt", std::ofstream::out | std::ofstream::trunc);
    historyFile.close();
}