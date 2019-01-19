#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

typedef std::pair<int, std::string> PIS; // PIS(divisor, name)

void input(char** argv, int& startNum, int& endNum, std::vector<PIS>& factors) {
    std::ifstream input_file;
    input_file.open(argv[1]);
    if (!input_file) {
        std::cerr << "failed to open the input file" << std::endl;
        exit(1);
    }
    int factorNum;
    input_file >> startNum >> endNum >> factorNum;
    for (int i = 0; i < factorNum; i++) {
        int divisor;
        std::string name;
        input_file >> divisor >> name;

        factors.push_back(PIS(divisor, name));
    }
    input_file.close();
}

void checker(int startNum, int endNum, std::vector<PIS>& factors) {
    if (startNum > endNum) {
        std::cerr << "starts should be less than or equal to ends" << std::endl;
        exit(1);
    }
    for (PIS& factor : factors) {
        if (factor.first <= 0) {
            std::cerr << "divisors should be greater than 0" << std::endl;
            exit(1);
        }
    }
}

std::vector<std::string> solve(int startNum, int endNum, std::vector<PIS>& factors) {
    std::vector<std::string> ret(endNum - startNum + 1, "");
    for (PIS& factor : factors) {
        int i = startNum;
        if (startNum % factor.first) {
            i += factor.first - (startNum % factor.first);
        }
        for ( ; i <= endNum; i += factor.first) {
            ret[i-startNum] += factor.second;
        }
    }
    for (int i = 0; i < (int)ret.size(); i++) {
        if (ret[i] == "") ret[i] = std::to_string(i+startNum);
    }
    return ret;
}

void output(char** argv, std::vector<std::string>& results) {
    std::ofstream output_file;
    output_file.open(argv[2]);
    if (!output_file) {
        std::cerr << "failed to open the output file" << std::endl;
        exit(1);
    }
    for (std::string& result : results) {
        output_file << result << std::endl;
    }
    output_file.close();
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "usage: ./FizzBuzz input.txt output.txt" << std::endl;
        return 1;
    }

    int startNum, endNum;
    std::vector<PIS> factors;

    input(argv, startNum, endNum, factors);

    checker(startNum, endNum, factors);

    std::vector<std::string> results = solve(startNum, endNum, factors);

    output(argv, results);
    
    return 0;
}

