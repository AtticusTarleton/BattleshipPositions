//
// Created by Atticus Tarleton on 11/26/24.
//

#ifndef POSITIONSRECURSIVE_H
#define POSITIONSRECURSIVE_H
#include "board.h"
#include "ship.h"
#include <iostream>
int numOfChecks = 0;
int counter = 0;

void calculatePositions(std::vector<ship> ships, board gameBoard1, int location) {
        if (location <= ships.size()) {
                ships[location].setOrientationV(true);
                for (int q = 0; q < gameBoard1.getRows()-ships[location].getSize()+1; q++) {
                        int w=0;
                        for (w = 0; w < gameBoard1.getCols(); w++) {
                                numOfChecks++; //this is for seeing how many times my loop tries to do a thing
                                if (gameBoard1.checkShipSpot(q,w,ships[location].getSize(),ships[location].getOrientationV())) {
                                        if (location == ships.size()) {
                                                counter++;
                                        }
                                        gameBoard1.changeShipValues(q,w,ships[location].getSize(),location,ships[location].getOrientationV());
                                        calculatePositions(ships, gameBoard1, location+1);
                                        gameBoard1.printBoard();
                                        gameBoard1.resetBoard(location);
                                }
                        }
                }
                ships[location].setOrientationV(false);
                for (int q = 0; q < gameBoard1.getRows(); q++) {
                        int w=0;
                        for (w = 0; w < gameBoard1.getCols()-ships[location].getSize()+1; w++) {
                                numOfChecks++; //this is for seeing how many times my loop tries to do a thing
                                if (gameBoard1.checkShipSpot(q,w,ships[location].getSize(),ships[location].getOrientationV())) {
                                        if (location == ships.size()) {
                                                counter++;
                                        }
                                        gameBoard1.changeShipValues(q,w,ships[location].getSize(),location,ships[location].getOrientationV());
                                        calculatePositions(ships, gameBoard1, location+1);
                                        gameBoard1.printBoard();
                                        gameBoard1.resetBoard(location);
                                }
                        }
                }
        }

        std::cout <<"number of checks: "<< numOfChecks << std::endl;
        std::cout <<"number of positions: "<< counter << std::endl;

}
/*
// is not working right now
is for it i want to try again

//is really not working, give up on this. i think it was the passing the board by reference
//i did get this error though
   BattleshipPositions(34281,0x10073c580) malloc: Heap corruption detected, free list is damaged at 0x600000f0d160
*** Incorrect guard value: 112040028328192
BattleshipPositions(34281,0x10073c580) malloc: *** set a breakpoint in malloc_error_break to debug

   //testing the recursion
   int row=3,col=3;
   board gameBoard1 = board(row, col);
   ship ship1 = ship(2, true);
   ship ship2 = ship(2, true);
   std::vector<ship> ships;
   ships.push_back(ship1);
   ships.push_back(ship2);
   calculatePositions(ships,gameBoard1,0);
*/


#endif //POSITIONSRECURSIVE_H
