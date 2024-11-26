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

void calculatePositions(std::vector<ship> ships, board& gameBoard1, int location) {
        if (location <= ships.size()) {
                ships[0].setOrientationV(true);
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
                                        gameBoard1.resetBoard(location);
                                }
                        }
                }
                ships[0].setOrientationV(false);
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
                                }
                        }
                }
        }
        std::cout <<"number of checks: "<< numOfChecks << std::endl;
        std::cout <<"number of positions: "<< counter << std::endl;
}


#endif //POSITIONSRECURSIVE_H
