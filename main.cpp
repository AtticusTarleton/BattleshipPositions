//
// Created by Atticus Tarleton on 11/12/24.
//
#include <iostream>
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

/* prints out the board, works for small scale

    //3 by 4 board with a 2 by 2 ship
    //rows keep track of vertical, columns of horizontal
    int row=3,col=3;
    board gameBoard1 = board(row, col);
    ship ship1 = ship(3, true);
    ship ship2 = ship(2, true);
    std::cout <<"num of cols "<< gameBoard1.getCols()<<std::endl;
    std::cout <<"num of rows "<< gameBoard1.getRows()<<std::endl;
    gameBoard1.printBoard();
    std::cout<<""<<std::endl;
    int counter = 0;
    int numOfChecks = 0;
    //vertical both
    ship1.setOrientationV(true);
    for (int i = 0; i < gameBoard1.getRows()-ship1.getSize()+1; i++) {
        int j=0;
        for (j = 0; j < gameBoard1.getCols(); j++) {
            ship2.setOrientationV(true);
            numOfChecks++; //this is for seeing how many times my loop tries to do a thing
            if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                //counter++;
                gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                //the second embedded loop.  it works :)
                for (int q = 0; q < gameBoard1.getRows()-ship2.getSize()+1; q++) {
                    int w=0;
                    for (w = 0; w < gameBoard1.getCols(); w++) {
                        numOfChecks++;
                        if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                            counter++;
                            gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                            gameBoard1.printBoard();
                            std::cout<<counter<<std::endl;
                            gameBoard1.resetBoard(2);
                        }
                    }
                }
            //changing orientation
            ship2.setOrientationV(false);
                for (int q = 0; q < gameBoard1.getRows(); q++) {
                    int w=0;
                    for (w = 0; w < gameBoard1.getCols()-ship2.getSize()+1; w++) {
                        numOfChecks++;
                        if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                            counter++;
                            gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                            gameBoard1.printBoard();
                            std::cout<<counter<<std::endl;
                            gameBoard1.resetBoard(2);
                        }
                    }
                }
                gameBoard1.resetBoard(1);
            }
        }
    }
    ship1.setOrientationV(false);
    for (int i = 0; i < gameBoard1.getRows(); i++) { //to simplify things/reduce complexity: make it so its instead getCols()-ship size
        //(getCols because its horizontal), and then it won't ever have to worry about being out of bounds. this will reduce time complexity a bit
        int j=0;
        for (j = 0; j < gameBoard1.getCols()-ship1.getSize()+1; j++) { //The -ship1.getSize()+1  adjusts for how far the ship should be from
            //the right hand wall in this case. it reduces the number of iterations while keeping the program effective
            ship2.setOrientationV(true);
            numOfChecks++;
            if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                //counter++;
                gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                //the second embedded loop.  it works :)
                for (int q = 0; q < gameBoard1.getRows()-ship2.getSize()+1; q++) {
                    int w=0;
                    for (w = 0; w < gameBoard1.getCols(); w++) {
                        numOfChecks++;
                        if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                            counter++;
                            gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                            gameBoard1.printBoard();
                            std::cout<<counter<<std::endl;
                            gameBoard1.resetBoard(2);
                        }
                    }
                }
            //changing orientation
            ship2.setOrientationV(false);
                for (int q = 0; q < gameBoard1.getRows(); q++) {
                    int w=0;
                    for (w = 0; w < gameBoard1.getCols()-ship2.getSize()+1; w++) {
                        numOfChecks++;
                        if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                            counter++;
                            gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                            gameBoard1.printBoard();
                            std::cout<<counter<<std::endl;
                            gameBoard1.resetBoard(2);
                        }
                    }
                }
                gameBoard1.resetBoard(1);
            }

        }
    }

    std::cout <<"num of ways to put ship in "<< counter<<std::endl;
    std::cout <<"num of iterations tested in total "<< numOfChecks<<std::endl; //gotta get this number down overall
    // gameBoard1.printBoard();
*/


    //rows keep track of vertical, columns of horizontal
    int row=10,col=10;
    board gameBoard1 = board(row, col);
    ship ship1 = ship(3, true);
    ship ship2 = ship(4, true);
    ship ship3 = ship(3, true);
    ship ship4 = ship(5, true);
    long counter = 0;
    long numOfChecks = 0;
             //vertical for ship4
                ship4.setOrientationV(true);
                for (int z = 0; z < gameBoard1.getRows()-ship4.getSize()+1; z++) {
                    int x=0;
                    for (x = 0; x < gameBoard1.getCols(); x++) {
                        numOfChecks++;
                        if (gameBoard1.checkShipSpot(z,x,ship4.getSize(),ship4.getOrientationV())) {
                            gameBoard1.changeShipValues(z,x,ship4.getSize(),4,ship4.getOrientationV());
                            //vertical for ship 3 stop here for copying
                            ship3.setOrientationV(true);
                            for (int e = 0; e < gameBoard1.getRows()-ship3.getSize()+1; e++) {
                                int r=0;
                                for (r = 0; r < gameBoard1.getCols(); r++) {
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(e,r,ship3.getSize(),ship3.getOrientationV())) {
                                        gameBoard1.changeShipValues(e,r,ship3.getSize(),3,ship3.getOrientationV());
                            //the bit above this should be good for copying
                                        ship1.setOrientationV(true);
                                        for (int i = 0; i < gameBoard1.getRows()-ship1.getSize()+1; i++) {
                                            int j=0;
                                            for (j = 0; j < gameBoard1.getCols(); j++) {
                                                numOfChecks++; //this is for seeing how many times my loop tries to do a thing
                                                if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                                    gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                                    ship2.setOrientationV(true);
                                                    for (int q = 0; q < gameBoard1.getRows()-ship2.getSize()+1; q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols(); w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());

                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                //changing orientation
                                                    ship2.setOrientationV(false);
                                                    for (int q = 0; q < gameBoard1.getRows(); q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols()-ship2.getSize()+1; w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                    gameBoard1.resetBoard(1);
                                                }
                                            }
                                        }
                                        ship1.setOrientationV(false);
                                        for (int i = 0; i < gameBoard1.getRows(); i++) { //to simplify things/reduce complexity:
                                            //(getCols because its horizontal), and then it won't ever have to worry about being out of bounds. this will reduce time complexity a bit
                                            int j=0;
                                            for (j = 0; j < gameBoard1.getCols()-ship1.getSize()+1; j++) { //The -ship1.getSize()+1  adjusts for how far the ship should be from
                                                //the right hand wall in this case. it reduces the number of iterations while keeping the program effective
                                                numOfChecks++;
                                                if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                                    gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                                    ship2.setOrientationV(true);
                                                    for (int q = 0; q < gameBoard1.getRows()-ship2.getSize()+1; q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols(); w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                //changing orientation
                                                    ship2.setOrientationV(false);
                                                    for (int q = 0; q < gameBoard1.getRows(); q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols()-ship2.getSize()+1; w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                    gameBoard1.resetBoard(1);
                                                }
                                            }
                                        }
                                        gameBoard1.resetBoard(3);
                                   }
                                }
                            }

                        //horizontal for ship 3
                            ship3.setOrientationV(false);
                            for (int e = 0; e < gameBoard1.getRows(); e++) {
                                int r=0;
                                for (r = 0; r < gameBoard1.getCols()-ship3.getSize()+1; r++) {
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(e,r,ship3.getSize(),ship3.getOrientationV())) {
                                        gameBoard1.changeShipValues(e,r,ship3.getSize(),3,ship3.getOrientationV());
                                        ship1.setOrientationV(true);
                                        for (int i = 0; i < gameBoard1.getRows()-ship1.getSize()+1; i++) {
                                            int j=0;
                                            for (j = 0; j < gameBoard1.getCols(); j++) {
                                                numOfChecks++;
                                                if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                                    gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                                    ship2.setOrientationV(true);
                                                    for (int q = 0; q < gameBoard1.getRows()-ship2.getSize()+1; q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols(); w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                //gameBoard1.printBoard();
                                                                //std::cout<<counter<<std::endl;
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                //changing orientation
                                                    ship2.setOrientationV(false);
                                                    for (int q = 0; q < gameBoard1.getRows(); q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols()-ship2.getSize()+1; w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                    gameBoard1.resetBoard(1);
                                                }
                                            }
                                        }
                                        ship1.setOrientationV(false);
                                        for (int i = 0; i < gameBoard1.getRows(); i++) {
                                            int j=0;
                                            for (j = 0; j < gameBoard1.getCols()-ship1.getSize()+1; j++) {
                                                numOfChecks++;
                                                if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                                    gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                                    ship2.setOrientationV(true);
                                                    for (int q = 0; q < gameBoard1.getRows()-ship2.getSize()+1; q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols(); w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                //changing orientation
                                                    ship2.setOrientationV(false);
                                                    for (int q = 0; q < gameBoard1.getRows(); q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols()-ship2.getSize()+1; w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                //gameBoard1.printBoard();
                                                                //std::cout<<counter<<std::endl;
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                    gameBoard1.resetBoard(1);
                                                }

                                            }
                                        }
                                        //copy everything below here
                                        gameBoard1.resetBoard(3);
                                    }
                                }
                            }
                            gameBoard1.resetBoard(4);
                        }
                    }
                }

/*
                //horizontal for ship4
                ship4.setOrientationV(false);
                for (int z = 0; z < gameBoard1.getRows(); z++) {
                    int x=0;
                    for (x = 0; x < gameBoard1.getCols()-ship4.getSize()+1; x++) {
                        numOfChecks++;
                        if (gameBoard1.checkShipSpot(z,x,ship4.getSize(),ship4.getOrientationV())) {
                            gameBoard1.changeShipValues(z,x,ship4.getSize(),4,ship4.getOrientationV());
                         //vertical for ship 3
                            ship3.setOrientationV(true);
                            for (int e = 0; e < gameBoard1.getRows()-ship3.getSize()+1; e++) {
                                int r=0;
                                for (r = 0; r < gameBoard1.getCols(); r++) {
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(e,r,ship3.getSize(),ship3.getOrientationV())) {
                                        gameBoard1.changeShipValues(e,r,ship3.getSize(),3,ship3.getOrientationV());
                            //the bit above this should be good for copying
                                        ship1.setOrientationV(true);
                                        for (int i = 0; i < gameBoard1.getRows()-ship1.getSize()+1; i++) {
                                            int j=0;
                                            for (j = 0; j < gameBoard1.getCols(); j++) {
                                                numOfChecks++;
                                                if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                                    gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                                    ship2.setOrientationV(true);
                                                    for (int q = 0; q < gameBoard1.getRows()-ship2.getSize()+1; q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols(); w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());

                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                //changing orientation
                                                    ship2.setOrientationV(false);
                                                    for (int q = 0; q < gameBoard1.getRows(); q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols()-ship2.getSize()+1; w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                    gameBoard1.resetBoard(1);
                                                }
                                            }
                                        }
                                        ship1.setOrientationV(false);
                                        for (int i = 0; i < gameBoard1.getRows(); i++) {
                                            int j=0;
                                            for (j = 0; j < gameBoard1.getCols()-ship1.getSize()+1; j++) {
                                                numOfChecks++;
                                                if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                                    gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                                    ship2.setOrientationV(true);
                                                    for (int q = 0; q < gameBoard1.getRows()-ship2.getSize()+1; q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols(); w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                //changing orientation
                                                    ship2.setOrientationV(false);
                                                    for (int q = 0; q < gameBoard1.getRows(); q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols()-ship2.getSize()+1; w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                    gameBoard1.resetBoard(1);
                                                }
                                            }
                                        }
                                        gameBoard1.resetBoard(3);
                                   }
                                }
                            }
                        //horizontal for ship 3
                            ship3.setOrientationV(false);
                            for (int e = 0; e < gameBoard1.getRows(); e++) {
                                int r=0;
                                for (r = 0; r < gameBoard1.getCols()-ship3.getSize()+1; r++) {
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(e,r,ship3.getSize(),ship3.getOrientationV())) {
                                        gameBoard1.changeShipValues(e,r,ship3.getSize(),3,ship3.getOrientationV());
                                        ship1.setOrientationV(true);
                                        for (int i = 0; i < gameBoard1.getRows()-ship1.getSize()+1; i++) {
                                            int j=0;
                                            for (j = 0; j < gameBoard1.getCols(); j++) {
                                                numOfChecks++;
                                                if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                                    gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                                    ship2.setOrientationV(true);
                                                    for (int q = 0; q < gameBoard1.getRows()-ship2.getSize()+1; q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols(); w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                //changing orientation
                                                    ship2.setOrientationV(false);
                                                    for (int q = 0; q < gameBoard1.getRows(); q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols()-ship2.getSize()+1; w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                    gameBoard1.resetBoard(1);
                                                }
                                            }
                                        }
                                        ship1.setOrientationV(false);
                                        for (int i = 0; i < gameBoard1.getRows(); i++) {
                                            int j=0;
                                            for (j = 0; j < gameBoard1.getCols()-ship1.getSize()+1; j++) {
                                                numOfChecks++;
                                                if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                                    gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                                    ship2.setOrientationV(true);
                                                    for (int q = 0; q < gameBoard1.getRows()-ship2.getSize()+1; q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols(); w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                //changing orientation
                                                    ship2.setOrientationV(false);
                                                    for (int q = 0; q < gameBoard1.getRows(); q++) {
                                                        int w=0;
                                                        for (w = 0; w < gameBoard1.getCols()-ship2.getSize()+1; w++) {
                                                            numOfChecks++;
                                                            if (gameBoard1.checkShipSpot(q,w,ship2.getSize(),ship2.getOrientationV())) {
                                                                counter++;
                                                                gameBoard1.changeShipValues(q,w,ship2.getSize(),2,ship2.getOrientationV());
                                                                //gameBoard1.printBoard();
                                                                //std::cout<<counter<<std::endl;
                                                                gameBoard1.resetBoard(2);
                                                            }
                                                        }
                                                    }
                                                    gameBoard1.resetBoard(1);
                                                }

                                            }
                                        }
                                        //copy everything below here
                                        gameBoard1.resetBoard(3);
                                    }
                                }
                            }
                            //copy everything below here
                            gameBoard1.resetBoard(4);
                        }
                    }
                }
*/
    counter = counter*2; //the splitting it in half worked. the numOfChecks is reduced b/c i fixed an error adding time complexity
    //the assumption was that there is a 90 degree rotation of every position possible for vertical 4 ship that makes the board horizontal
    std::cout <<"num of ways to put ship in "<< counter<<std::endl;
    std::cout <<"num of iterations tested in total "<< numOfChecks<<std::endl; //gotta get this number down overall

    return 0;
}