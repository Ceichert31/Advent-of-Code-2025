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
    }


    input.close();
    return 0;
}