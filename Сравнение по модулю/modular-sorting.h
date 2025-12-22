#pragma once

#include <vector>
#include <algorithm>
#include <cmath>

void ModularSort(std::vector<int>& v) {
    std::sort(v.begin(), v.end(), [](int a, int b){
        if (std::abs(a) == std::abs(b)) {
            return a < b; 
        }
        return std::abs(a) < std::abs(b);
    });
}