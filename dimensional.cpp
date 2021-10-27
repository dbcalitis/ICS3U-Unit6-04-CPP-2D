// Copyright (c) 2021 D.B. Calitis All rights reserved
//
// Created by: Daria Bernice Calitis
// Created on: Oct 2021
// This program determines the average

#include <iostream>
#include <array>
#include <random>
#include <string>

template <int userRows, int userColumns>

int Mean(int (&numArray)[userRows][userColumns]) {
    // This function determines the average of the 2D array
    float average = 0;

    for (size_t row = 0; row < userRows; row++) {
        for (size_t column = 0; column < userColumns; column++) {
            average += (numArray[row][column]);
        }
    }

    average = average / (userRows * userColumns);

    return average;
}

int main() {
    // This function is the main function
    std::string userRowsString;
    std::string userColumnsString;
    const int userRows = 5;
    const int userColumns = 4;
    int mainArray[userRows][userColumns];
    float average = 0.0;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(1, 50);

    // input - Ignore the commented code lines
    try {
        std::cout << "How many rows would you like: " << userRows
        << std::endl;
        // getline(std::cin, userRowsString);
        // userRows = std::stoi(userRowsString);

        if (/*userRows == std::stof(userRowsString)*/true) {
            std::cout << "How many columns would you like: "
            << userColumns << std::endl;
            // getline(std::cin, userColumnsString);
            // userColumns = std::stoi(userColumnsString);

            std::cout << "" << std::endl;

            // process & output
            if (/* userColumns == std::stof(userColumnsString) */true) {
                for (int row = 0; row < userRows; row++) {
                    for (int column = 0; column < userColumns; column++) {
                        int randomNumber = idist(rgen);
                        mainArray[row][column] = randomNumber;
                        if (randomNumber >= 10) {
                            std::cout << randomNumber << " ";
                        } else {
                            std::cout << randomNumber << "  ";
                        }
                    }
                    std::cout << "" << std::endl;
                }

                average += Mean(mainArray);

                std::cout << "\nThe average of all the numbers is: "
                << average << std::endl;
            } else {
                std::cout << "Invalid Input." << std::endl;
            }
        } else {
            std::cout << "Invalid Input." << std::endl;
        }
    } catch (...) {
        std::cout << "Invalid Input." << std::endl;
    }


    std::cout << "\nDone." << std::endl;
}
