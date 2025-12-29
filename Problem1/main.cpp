//
// Created by Chris Eichert on 12/1/2025.
//

#include "main.h"


int main() {


    //Rotate around the dial from 0-99 and if we go left we subtract
    //and wrap around, if we go right we add and wrap around
    //count the number of times we land on zero

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

        //Add value if it starts with R, otherwise subtract value
        currentRotation += rawInput[0] == 'R' ? +value : -value;

        //Pass into modulus function
        currentRotation = Modulo(currentRotation, 100);
        currentRotation = std::abs(currentRotation);

        if (currentRotation == 0)
            numberOfZeros++;
    }

    input.close();
    return numberOfZeros;
}

///Takes in a number and constraints it from 0-maxNum
int Modulo(int currentNum, int maxNum) {
    return (currentNum % maxNum + maxNum) % maxNum;
}
