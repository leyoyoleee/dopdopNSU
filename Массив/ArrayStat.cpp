#include "ArrayStat.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric> 
#include <cmath>   
#include <iostream>

ArrayStat::ArrayStat(const std::string& file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + file_name);
    }

    std::string line;
    if (!std::getline(file, line)) {
        throw std::runtime_error("File is empty or cannot read first line.");
    }
    std::istringstream iss(line);
    int N;
    if (!(iss >> N)) {
        throw std::runtime_error("Invalid format: first line must contain an integer N.");
    }

    if (N < 0) {
        throw std::runtime_error("N must be >= 0.");
    }

    if (!std::getline(file, line)) {
        if (N > 0) {
            throw std::runtime_error("Expected " + std::to_string(N) + " numbers on the second line.");
        }
    }

    std::istringstream data_iss(line);
    std::vector<int> temp_data;
    temp_data.reserve(N);

    for (int i = 0; i < N; ++i) {
        int num;
        if (!(data_iss >> num)) {
            throw std::runtime_error("Not enough numbers on the second line. Expected " + std::to_string(N) + ".");
        }
        temp_data.push_back(num);
    }

    if (temp_data.size() != static_cast<size_t>(N)) {
        throw std::runtime_error("Read " + std::to_string(temp_data.size()) + " numbers, but expected " + std::to_string(N) + ".");
    }

    data = std::move(temp_data);
    std::sort(data.begin(), data.end());
}

int ArrayStat::max() const {
    if (data.empty()) {
        throw std::runtime_error("Cannot get max from empty array.");
    }
    return data.back(); 
}

int ArrayStat::min() const {
    if (data.empty()) {
        throw std::runtime_error("Cannot get min from empty array.");
    }
    return data.front(); 
}

double ArrayStat::mean() const {
    if (data.empty()) {
        throw std::runtime_error("Cannot calculate mean of empty array.");
    }
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

double ArrayStat::stddev() const {
    if (data.size() <= 1) {
        throw std::runtime_error("Cannot calculate stddev for array with less than 2 elements.");
    }

    double m = mean();
    double variance = 0.0;

    std::for_each(data.begin(), data.end(), [&](int x) {
        variance += (x - m) * (x - m);
    });

    variance /= (data.size() - 1);
    return std::sqrt(variance);
}

size_t ArrayStat::countLarger(int a) const {
    auto it = std::upper_bound(data.begin(), data.end(), a);
    return std::distance(it, data.end());
}

void ArrayStat::print() const {
    for (size_t i = 0; i < data.size(); ++i) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << data[i];
    }
    std::cout << std::endl;
}