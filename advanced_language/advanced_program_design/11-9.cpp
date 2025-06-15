#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void addLineNumbersToFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file: " << inputFilePath << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << outputFilePath << std::endl;
        inputFile.close();
        return;
    }

    std::string line;
    int lineNumber = 1;
    while (std::getline(inputFile, line)) {
        outputFile << std::setw(4) << std::setfill('0') << lineNumber << " " << line << std::endl;
        lineNumber++;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    std::string inputFilePath;
    std::string outputFilePath;

    std::cout << "Enter the path of the input text file: ";
    std::getline(std::cin, inputFilePath);

    std::cout << "Enter the path of the output text file: ";
    std::getline(std::cin, outputFilePath);

    addLineNumbersToFile(inputFilePath, outputFilePath);

    std::cout << "Line numbers have been added and saved to " << outputFilePath << std::endl;

    return 0;
}