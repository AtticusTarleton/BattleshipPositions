//
// Created by Atticus Tarleton on 11/12/24.
//

#ifndef SHIP_H
#define SHIP_H
#include <string>

//this will create ships of different sizes
class ship {
private:
    std::string keyPoint;
    /* keyPoint is the key point where everything is determined off of
     * could also arrange in a 2 int format
     */
    bool orientationV; //the idea is if horizontal its false, if vertical its true
    int size = 0; //the size of the ship
public:
    ship(const int size, bool orientation) {
        this->size = size;
        orientationV = orientation;
    }

    //getters
    std::string getKeyPoint() const{
        return keyPoint;
    }
    bool getOrientationV() const {
        return orientationV;
    }
    int getSize() const {
        return size;
    }

    //setters
    void setKeyPoint(std::string &keyPoint) {
        this->keyPoint = keyPoint; //will be used for changing locations
    }
    void setOrientationV(bool orientationV) {
        this->orientationV = orientationV;
    }
    void setSize(int size) {
        this->size = size;
    }

};



#endif //SHIP_H
