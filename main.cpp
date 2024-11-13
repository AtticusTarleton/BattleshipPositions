//
// Created by Atticus Tarleton on 11/12/24.
//
#include <iostream>
#include <vector>
#include "board.h"
#include "ship.h"

int main() {
    /*
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
//    gameBoard[8][2]=1; // shows what happens with a bad address, fix this. do the fix in changeSquareValue
    //std::cout<< gameBoard[8][2]<<std::endl; //testing a bad address

    for (int i = 0; i < gameBoard.size(); i++) {
        for (int j = 0; j < gameBoard[i].size(); j++)
            std::cout << gameBoard[i][j] << " ";
        std::cout << std::endl;
    }
    */



    //3 by 4 board with a 2 by 2 ship
    //rows keep track of vertical, columns of horizontal
    int row=3,col=4;
    board gameBoard1 = board(row, col);
    ship ship1 = ship(3, true);;
    std::cout <<"num of cols "<< gameBoard1.getCols()<<std::endl;
    std::cout <<"num of rows "<< gameBoard1.getRows()<<std::endl;
    gameBoard1.printBoard();
    int counter = 0;

    for (int i = 0; i < gameBoard1.getRows(); i++) {
        int j=0;
        for (j = 0; j < gameBoard1.getCols(); j++) {
            if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                counter++;
            }
        }
    }
    std::cout <<"num of ways to put ship in "<< counter<<std::endl;




    return 0;
}