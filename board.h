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
    void printSquare(int row, int col) {
        std::cout << gameBoard[row][col] << std::endl;
    }
    //STUFF FOR THE NUMBER OF POSITIONS CHECK
    //this is a big deal for replacing stuff
    void changeSquareValue(int row, int col, int value) {
        gameBoard[row][col] = value;
    }
    //returns true if square is empty. this could let us move faster
    bool isSquareZero(int row, int col) const {
        bool result = false;;
        try {
            result = gameBoard[row][col] == 0;
        } catch (...) {
            result=false; //not sure if this is the right response
        }
        return result;
    }
    //checks for out of bounds. true if out of bounds, false if not
    bool outOfBounds(int row, int col) const {
        bool result = true;
        if(col <= 3)
            result = false;

        if (row <= 4)
            result = false;

        return result;
    }
    bool checkSquare(int squareRow, int squareCol) const {
        bool result = isSquareZero(squareRow, squareCol)&& !outOfBounds(squareRow, squareCol); //problem line
        return result;
    }
    bool checkShipSpot(int rowStart, int colStart, int size, bool orientation) const {
        bool result = false;
        if(orientation) {
            for(int i = 0; i < size; i++) {
                if(checkSquare(rowStart, colStart+i)) {
                    return true;
                }
            }
        }
        else {
            for(int i = 0; i < size; i++) {
                if(checkSquare(rowStart+i, colStart)) {
                    return true;
                }
            }
        }
        return false;
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
