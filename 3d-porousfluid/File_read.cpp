#include "File_read.h"
#include <iostream>
#include <fstream>
#include <sstream>

MatrixReader::MatrixReader(const std::string& filename, int rows, int cols)
    : filename(filename), rows(rows), cols(cols) {}

bool MatrixReader::readMatrix(std::vector<std::vector<double>>& matrix) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return false;
    }

    matrix.resize(rows, std::vector<double>(cols, 0.0));

    for (int i = 0; i < rows; ++i) {
        std::string line;
        if (std::getline(file, line)) {
            std::istringstream iss(line);
            for (int j = 0; j < cols; ++j) {
                if (!(iss >> matrix[i][j])) {
                    std::cerr << "Error: Invalid matrix format in file." << std::endl;
                    return false;
                }
            }
        }
        else {
            std::cerr << "Error: Insufficient rows in the file." << std::endl;
            return false;
        }
    }

    return true;
}

// main.cpp
#include "File_read.h"
#include <iostream>

int main() {
    int latticesize = 5; // Set the lattice size 
    int rows = latticesize - 1;
    int cols = 2;

    MatrixReader matrixReader("matrix.txt", rows, cols);

    std::vector<std::vector<double>> Radius;

    if (matrixReader.readMatrix(Radius)) {
        // Matrix
        std::cout << "Matrix Read from File:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << Radius[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
    else {
        std::cerr << "Failed to read the matrix." << std::endl;
    }

    return 0;
}








