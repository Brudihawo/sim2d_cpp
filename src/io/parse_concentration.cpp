#include "parse_concentration.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>

bool parse_concentration(std::ifstream& infile, std::vector<double>& additional_params) {
    std::string line;

    std::regex d_regex("D\\s*=\\s*(\\d+.\\d+)\\s*");
    std::smatch m;

    // go to beginning
    infile.clear();
    infile.seekg(0, std::ios::beg);
    while (std::getline(infile, line)) {
        if (std::regex_match(line, m, d_regex)) {
            if (additional_params.size() < 1)
                additional_params.push_back(std::stod(m[1], nullptr));
            return true;
        }
    }

    std::cout << "Missing declaration of domain parameters:" << std::endl;
    std::cout << "D" << std::endl;

    return false;
}