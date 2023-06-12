#ifndef PAINT_H
#define PAINT_H

#include <string>

class Paint {
public:
    void resultsPaint(int result);
    void resultsPaint(float result);

private:
    void paintBox(const std::string& resultStr);
};

#endif