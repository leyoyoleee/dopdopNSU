#pragma once

#include <vector>
#include <algorithm>

template<typename T>
class Table {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Table(size_t r, size_t c) : rows(r), cols(c) {
        data.resize(rows, std::vector<T>(cols));
    }

    std::vector<T>& operator[](size_t index) {
        return data[index];
    }

    const std::vector<T>& operator[](size_t index) const {
        return data[index];
    }

    void Resize(size_t new_rows, size_t new_cols) {
        std::vector<std::vector<T>> old_data = std::move(data);
        size_t old_rows = rows;
        size_t old_cols = cols;

        rows = new_rows;
        cols = new_cols;

        data.resize(rows, std::vector<T>(cols));

        for (size_t i = 0; i < std::min(old_rows, rows); ++i) {
            for (size_t j = 0; j < std::min(old_cols, cols); ++j) {
                data[i][j] = old_data[i][j];
            }
        }
    }

    std::pair<size_t, size_t> Size() const {
        return {rows, cols};
    }
};