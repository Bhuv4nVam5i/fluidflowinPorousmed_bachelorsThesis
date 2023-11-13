#pragma once
#include <vector>
#include <string>

class MatrixReader {
public:
    MatrixReader(const std::string& filename, int rows, int cols);
    bool readMatrix(std::vector<std::vector<double>>& matrix);

private:
    std::string filename;
    int rows;
    int cols;
};


