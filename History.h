// History.h
#ifndef HISTORY_H
#define HISTORY_H

#include <string>

class History {
public:
    void saveHistory(std::string operation, int result);
    void readHistory();
    void deleteHistory();
};

#endif