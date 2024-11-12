//
// Created by Atticus Tarleton on 11/12/24.
//
#include <iostream>
#include <vector>

int main() {
//checking my vector board
    //it works
    std::vector<std::vector<int>> gameBoard;
    int rows=5,cols=4;
    for (int i = 0; i < rows; i++) {
        std::vector<int> v1;
        for (int j = 0; j < cols; j++) {
            v1.push_back(0);
        }
        gameBoard.push_back(v1);
    }
    gameBoard[3][2]=1; // shows that i is rows, j is cols

    for (int i = 0; i < gameBoard.size(); i++) {
        for (int j = 0; j < gameBoard[i].size(); j++)
            std::cout << gameBoard[i][j] << " ";
        std::cout << std::endl;
    }



    return 0;
}