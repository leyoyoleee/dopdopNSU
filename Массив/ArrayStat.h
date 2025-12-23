#pragma once

#include <vector>
#include <string>

class ArrayStat {
   std::vector<int> data;
public:
    ArrayStat(const std::string& file_name);

    int max() const;
    int min() const;

    double mean() const;
    double stddev() const;

    size_t countLarger(int a) const;

    void print() const;
};
