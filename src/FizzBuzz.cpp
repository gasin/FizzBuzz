#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

typedef std::pair<int, std::string> PIS; // PIS(divisor, name)

void input(char** argv, int& startNum, int& endNum, std::vector<PIS>& factors) {
    std::ifstream input_file;
    input_file.open(argv[1]);
    if (!input_file) {
        std::cerr << "failed to open input file" << std::endl;
        exit(0);
    }
    int factorNum;
    input_file >> startNum >> endNum >> factorNum;
    for (int i = 0; i < factorNum; i++) {
        int divisor;
        std::string name;
        input_file >> divisor >> name;

        if (divisor <= 0) {
            std::cerr << "divisor should be greater than 0" << std::endl;
            exit(0);
        }
        factors.push_back(PIS(divisor, name));
    }
    input_file.close();
}

std::vector<std::string> solve(int startNum, int endNum, std::vector<PIS>& factors) {
    std::vector<std::string> ret;
    for (int i = startNum; i <= endNum; i++) {
        std::string str = "";
        bool isNum = true;
        for (PIS& factor : factors) {
            if (i % factor.first == 0) {
                isNum = false;
                str += factor.second;
            }
        }
        if (isNum) {
            ret.push_back(std::to_string(i));
        } else {
            ret.push_back(str);
        }
    }
    return ret;
}

void output(std::vector<std::string>& results) {
    for (std::string& result : results) {
        std::cout << result << std::endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "usage: ./FizzBuzz input.txt" << std::endl;
        return 0;
    }

    int startNum, endNum;
    std::vector<PIS> factors;

    input(argv, startNum, endNum, factors);

    std::vector<std::string> results = solve(startNum, endNum, factors);

    output(results);
    
    return 0;
}

