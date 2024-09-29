#include <iostream>
#include <fstream>
#include <sstream>
#include "Polygon/Polygon.h"
#include "SymmetryAxisesFinder/SymmetryAxisesFinder.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "input file name missed!" << std::endl;
        return -1;
    }
    std::fstream input_file{argv[1]};
    if (!input_file.is_open()) {
        std::cerr << "can't open input file!" << std::endl;
        return -1;
    }
    std::vector<Point> points;
    for (std::string line; getline(input_file, line);) {
        std::stringstream ss{line};
        long double x, y;
        ss >> x >> y;
        points.emplace_back(x, y);
    }
    const Polygon poly{points};
    if (const auto &axises = SymmetryAxisesFinder::find_symmetry_axises(poly); axises.empty()) {
        std::cout << "non-symmetric" << std::endl;
    } else {
        for (const auto &axis: axises) {
            std::cout << axis << std::endl;
        }
    }
    return 0;
}
