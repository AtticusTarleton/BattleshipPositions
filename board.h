//
// Created by Atticus Tarleton on 11/12/24.
//

#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "ship.h"

//this will create the board
class board {
private:
    std::string type;
    std::vector<std::vector<int>> gameBoard;
    int rows, cols;
public:
    board(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        for (int i = 0; i < rows; i++) {
            std::vector<int> v1;
            for (int j = 0; j < cols; j++) {
                v1.push_back(0);
            }
            gameBoard.push_back(v1);
        }
    }

    //getters
    int getRows() const {
        return rows;
    }
    int getCols() const {
        return cols;
    }
    std::vector<std::vector<int>> getBoard() const {
        return gameBoard;
    }
    void printBoard() const {
        for (int i = 0; i < gameBoard.size(); i++) {
            for (int j = 0; j < gameBoard[i].size(); j++)
                std::cout << gameBoard[i][j] << " ";
            std::cout << std::endl;
        }
    }
    //STUFF FOR THE NUMBER OF POSITIONS CHECK
    //this is a big deal for replacing stuff
    void changeSquareValue(int row, int col, int value) {
        gameBoard[row][col] = value;
    }
    //returns true if square is empty
    bool isSquareZero(int row, int col) const {
        return gameBoard[row][col] == 0;
    }


    //setters
    void setRows(int rows) {
        this->rows = rows;
    }
    void setCols(int cols) {
        this->cols = cols;
    }

};



#endif //BOARD_H
