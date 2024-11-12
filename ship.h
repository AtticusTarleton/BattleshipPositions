//
// Created by Atticus Tarleton on 11/12/24.
//

#ifndef SHIP_H
#define SHIP_H
#include <string>

//this will create ships of different sizes
class ship {
private:
    std::string type, keyPoint;
    /* keyPoint is the key point where everything is determined off of
     *
     */
    boolean orientationV; //the idea is if horizontal its false, if vertical its true
    int size = 0; //the size of the ship
public:
    ship(int size, bool orientation) {
        this->size = size;
        orientationV = orientation;
    }
};



#endif //SHIP_H
