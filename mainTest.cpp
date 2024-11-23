//
// Created by Atticus Tarleton on 11/12/24.
//
#include <iostream>
//#include <vector>
#include "board.h"
#include "ship.h"

int main() {
//this is testing larger and larger sizes


    //this now has 3 ships
    //best way to add more ships i have found is add them to the outside
        //copy the whole for loop. paste it right below, labeling 1 as vertical 1 as horizontal
        //then copy and modify the requisite parts from the top and bottom,
        //i notated which ones are important to not forget to copy

    //also, don't print from the 10 by 10 again, it takes so much time
        //not printing really removes the time it takes to run this
    //i am also removing the print part of this program

    //rows keep track of vertical, columns of horizontal
    int row=10,col=10;
    board gameBoard1 = board(row, col);
    ship ship1 = ship(2, true);
    ship ship2 = ship(3, true);
    ship ship3 = ship(3, true);
    ship ship4 = ship(4, true);
    //std::cout <<"num of cols "<< gameBoard1.getCols()<<std::endl;
    //std::cout <<"num of rows "<< gameBoard1.getRows()<<std::endl;
    //gameBoard1.printBoard();
    //std::cout<<""<<std::endl;
    int counter = 0;
    int numOfChecks = 0;

//vertical for ship4
    ship4.setOrientationV(true);
    for (int z = 0; z < gameBoard1.getRows()-ship4.getSize()+1; z++) {
        int x=0;
        for (x = 0; x < gameBoard1.getCols(); x++) {
            numOfChecks++; //this is for seeing how many times my loop tries to do a thing
            if (gameBoard1.checkShipSpot(z,x,ship4.getSize(),ship4.getOrientationV())) {
                //counter++;
                gameBoard1.changeShipValues(z,x,ship4.getSize(),4,ship4.getOrientationV());
                //vertical for ship 3 stop here for copying
                ship3.setOrientationV(true);
                for (int e = 0; e < gameBoard1.getRows()-ship3.getSize()+1; e++) {
                    int r=0;
                    for (r = 0; r < gameBoard1.getCols(); r++) {
                        numOfChecks++; //this is for seeing how many times my loop tries to do a thing
                        if (gameBoard1.checkShipSpot(e,r,ship3.getSize(),ship3.getOrientationV())) {
                            //counter++;
                            gameBoard1.changeShipValues(e,r,ship3.getSize(),3,ship3.getOrientationV());
                //the bit above this should be good for copying
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
                                                    //gameBoard1.printBoard();
                                                    //std::cout<<counter<<std::endl;
                                                    gameBoard1.resetBoard(2);
                                                }
                                            }
                                        }
                                        gameBoard1.resetBoard(1);
                                    }
                                    //changing orientation
                                    ship2.setOrientationV(false);
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                        //counter++;
                                        gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                        //the second embedded loop.  it works :)
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
                                                    //gameBoard1.printBoard();
                                                    //std::cout<<counter<<std::endl;
                                                    gameBoard1.resetBoard(2);
                                                }
                                            }
                                        }
                                        gameBoard1.resetBoard(1);
                                    }
                                    //changing orientation
                                    ship2.setOrientationV(false);
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                        //counter++;
                                        gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                        //the second embedded loop.  it works :)
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
                            gameBoard1.resetBoard(3);
                       }
                    }
                }
                gameBoard1.resetBoard(4);
            }
        }
    }




            //horizontal for ship 3
                ship3.setOrientationV(false);
                for (int e = 0; e < gameBoard1.getRows(); e++) {
                    int r=0;
                    for (r = 0; r < gameBoard1.getCols()-ship3.getSize()+1; r++) {
                        numOfChecks++; //this is for seeing how many times my loop tries to do a thing
                        if (gameBoard1.checkShipSpot(e,r,ship3.getSize(),ship3.getOrientationV())) {
                            //counter++;
                            gameBoard1.changeShipValues(e,r,ship3.getSize(),3,ship3.getOrientationV());
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
                                                    //gameBoard1.printBoard();
                                                    //std::cout<<counter<<std::endl;
                                                    gameBoard1.resetBoard(2);
                                                }
                                            }
                                        }
                                        gameBoard1.resetBoard(1);
                                    }
                                    //changing orientation
                                    ship2.setOrientationV(false);
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                        //counter++;
                                        gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                        //the second embedded loop.  it works :)
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
                                                    //gameBoard1.printBoard();
                                                    //std::cout<<counter<<std::endl;
                                                    gameBoard1.resetBoard(2);
                                                }
                                            }
                                        }
                                        gameBoard1.resetBoard(1);
                                    }
                                    //changing orientation
                                    ship2.setOrientationV(false);
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                        //counter++;
                                        gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                        //the second embedded loop.  it works :)
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

    //horizontal for ship4
    ship4.setOrientationV(false);
    for (int z = 0; z < gameBoard1.getRows(); z++) {
        int x=0;
        for (x = 0; x < gameBoard1.getCols()-ship4.getSize()+1; x++) {
            numOfChecks++; //this is for seeing how many times my loop tries to do a thing
            if (gameBoard1.checkShipSpot(z,x,ship4.getSize(),ship4.getOrientationV())) {
                //counter++;
                gameBoard1.changeShipValues(z,x,ship4.getSize(),4,ship4.getOrientationV());
             //vertical for ship 3
                ship3.setOrientationV(true);
                for (int e = 0; e < gameBoard1.getRows()-ship3.getSize()+1; e++) {
                    int r=0;
                    for (r = 0; r < gameBoard1.getCols(); r++) {
                        numOfChecks++; //this is for seeing how many times my loop tries to do a thing
                        if (gameBoard1.checkShipSpot(e,r,ship3.getSize(),ship3.getOrientationV())) {
                            //counter++;
                            gameBoard1.changeShipValues(e,r,ship3.getSize(),3,ship3.getOrientationV());
                //the bit above this should be good for copying
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
                                                    //gameBoard1.printBoard();
                                                    //std::cout<<counter<<std::endl;
                                                    gameBoard1.resetBoard(2);
                                                }
                                            }
                                        }
                                        gameBoard1.resetBoard(1);
                                    }
                                    //changing orientation
                                    ship2.setOrientationV(false);
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                        //counter++;
                                        gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                        //the second embedded loop.  it works :)
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
                                                    //gameBoard1.printBoard();
                                                    //std::cout<<counter<<std::endl;
                                                    gameBoard1.resetBoard(2);
                                                }
                                            }
                                        }
                                        gameBoard1.resetBoard(1);
                                    }
                                    //changing orientation
                                    ship2.setOrientationV(false);
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                        //counter++;
                                        gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                        //the second embedded loop.  it works :)
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
                            gameBoard1.resetBoard(3);
                       }
                    }
                }




            //horizontal for ship 3
                ship3.setOrientationV(false);
                for (int e = 0; e < gameBoard1.getRows(); e++) {
                    int r=0;
                    for (r = 0; r < gameBoard1.getCols()-ship3.getSize()+1; r++) {
                        numOfChecks++; //this is for seeing how many times my loop tries to do a thing
                        if (gameBoard1.checkShipSpot(e,r,ship3.getSize(),ship3.getOrientationV())) {
                            //counter++;
                            gameBoard1.changeShipValues(e,r,ship3.getSize(),3,ship3.getOrientationV());
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
                                                    //gameBoard1.printBoard();
                                                    //std::cout<<counter<<std::endl;
                                                    gameBoard1.resetBoard(2);
                                                }
                                            }
                                        }
                                        gameBoard1.resetBoard(1);
                                    }
                                    //changing orientation
                                    ship2.setOrientationV(false);
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                        //counter++;
                                        gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                        //the second embedded loop.  it works :)
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
                                                    //gameBoard1.printBoard();
                                                    //std::cout<<counter<<std::endl;
                                                    gameBoard1.resetBoard(2);
                                                }
                                            }
                                        }
                                        gameBoard1.resetBoard(1);
                                    }
                                    //changing orientation
                                    ship2.setOrientationV(false);
                                    numOfChecks++;
                                    if (gameBoard1.checkShipSpot(i,j,ship1.getSize(),ship1.getOrientationV())) {
                                        //counter++;
                                        gameBoard1.changeShipValues(i,j,ship1.getSize(),1,ship1.getOrientationV());
                                        //the second embedded loop.  it works :)
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


    std::cout <<"num of ways to put ship in "<< counter<<std::endl;
    std::cout <<"num of iterations tested in total "<< numOfChecks<<std::endl; //gotta get this number down overall
    // gameBoard1.printBoard();



    return 0;
}