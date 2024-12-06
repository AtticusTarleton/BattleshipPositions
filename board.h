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
    std::vector<std::vector<int> > gameBoard;
    int rows, cols;
public:
    board(int rows, int cols) {
        this->rows = rows; //keep track of vertical
        this->cols = cols; //kep track of horizontal
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
    int getSquareValue(int i, int j) const{
        return gameBoard[i][j];
    }
    std::vector<std::vector<int> > getBoard() const {
        return gameBoard;
    }
    void printBoard() const {
        for (int i = 0; i < getRows(); i++) {
            for (int j = 0; j < getCols(); j++)
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
    //Still have to replace values back to 0 when done
    //have a loop function
    void resetBoard(int value) {
        for (int i = 0; i < getRows(); i++) {
            for (int j = 0; j < getCols(); j++) {
                if(gameBoard[i][j] == value) {
                    gameBoard[i][j] = 0;
                }
            }
        }
    }



    void changeShipValues(int rowStart, int colStart, int size,int value, bool orientation ) {
        if(orientation) {
            for(int i = 0; i < size; i++) {
                changeSquareValue(rowStart+i, colStart, value);
            }
        }
        else {
            for(int i = 0; i < size; i++) {
                changeSquareValue(rowStart, colStart+i, value);
            }
        }
    }





    //returns true if square is empty. this could let us move faster
    bool isSquareZero(int row, int col) const {
        bool result = false;;
        try {
            result= 0 == getSquareValue(row, col);
        } catch (...) {
            //not sure if this is the right response
        }
        return result;
    }
    //checks for out of bounds. true if out of bounds, false if not
    bool outOfBounds(int row, int col) const {
        bool result = true;
        if(col < getCols() && row < getRows()) {
            result = false;
        }

        return result;
    }
    bool checkSquare(int squareRow, int squareCol) const {

        if(outOfBounds(squareRow, squareCol)) {
            return false;
        }
        if(!isSquareZero(squareRow, squareCol)) {
            return false;
        }
        return true;
    }
    bool checkShipSpot(int rowStart, int colStart, int size, bool orientation) const {
        if(orientation) {
            for(int i = 0; i < size; i++) {
                if(!checkSquare(rowStart+i, colStart)) {
                    return false;
                }
            }
        }
        else {
            for(int i = 0; i < size; i++) {
                if(!checkSquare(rowStart, colStart+i)) {
                    return false;
                }
            }
        }
        return true;
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
