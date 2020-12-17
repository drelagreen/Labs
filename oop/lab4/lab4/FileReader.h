#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Elections.h"

class FileReader {
private:
    FileReader()= default;
public:
    static std::vector<Elections> read();
};
