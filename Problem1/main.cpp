//
// Created by Chris Eichert on 12/1/2025.
//

#include "main.h"


int main() {

    //While rotating, if we pass 0 at all, increment the counter

    std::ifstream input("../../Problem1/input.txt");
    int currentRotation = 50;
    int numberOfZeros = 0;
    
    if (!input.is_open()) {
        return -1;
    }

    while (!input.eof()) {

        //read input
        std::string rawInput;
        std::getline(input, rawInput);

        //parse input
        int value = std::stoi(rawInput.substr(1, rawInput.size() - 1));

        int start = currentRotation;

        //Add value if it starts with R, otherwise subtract value
        currentRotation += rawInput[0] == 'R' ? +value : -value;

        //Pass into modulus function
        auto result = Modulo(start, currentRotation, 100);

        //Get modulated result and times it past zero
        currentRotation = result.first;
        numberOfZeros += result.second;
    }

    input.close();
    return numberOfZeros;
}

///Takes in a number and constraints it from 0-maxNum
std::pair<int,int> Modulo(int start, int currentNum, int maxNum) {
    int moduloValue = (currentNum % maxNum + maxNum) % maxNum;
    int differential = 0;

    if (start != 0) {
        //Get differential between current num and modulo value
        differential = std::abs(currentNum - moduloValue);

        //Divide differential by 100 to get number of times it has past 0
        differential /= 100;
    }

    if (currentNum == 0) {
        differential++;
    }

    return std::pair<int,int>(moduloValue, differential);
}
