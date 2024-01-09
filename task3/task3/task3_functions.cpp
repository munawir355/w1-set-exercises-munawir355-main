#include "task3_functions.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

std::string findCorners(std::string filePath) {
    //Reading the data from file and find the coordinates of the first rectangle made of * characters
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        int row = 0;
        int col = 0;
        int topLeftRow = -1, topLeftCol = -1, bottomRightRow = -1, bottomRightCol = -1;

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            col = 0;

            char character;
            while (iss >> character) {
                if (character == '*') {
                    if (topLeftRow == -1) {
                        topLeftRow = row;
                        topLeftCol = col;
                    }
                    bottomRightRow = row;
                    bottomRightCol = col;
                }
                col++;
            }

            row++;
        }

        file.close();

        //Formatting the result as a JSON string
        std::ostringstream result;
        result << "{\n";
        result << " \"topLeft\" : [" << topLeftRow << "," << topLeftCol << "],\n";
        result << " \"bottomRight\" : [" << bottomRightRow << "," << bottomRightCol << "]\n";
        result << "}";

        return result.str();
    }
    else {
        return "{}"; //Returning an empty JSON string if the file cannot be opened
    }
}