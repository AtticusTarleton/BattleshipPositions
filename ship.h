//
// Created by Atticus Tarleton on 11/12/24.
//

#ifndef SHIP_H
#define SHIP_H
#include <string>

//this will create ships of different sizes
class ship {
private:
    /* keyPoint is the key point where everything is determined off of
     * could also arrange in a 2 int format.  THINK I WILL DO THIS
     */
    bool orientationV; //the idea is if horizontal its false, if vertical its true
    int size = 0, keyPointR=0, keyPointC=0; //the size of the ship
public:
    ship(const int size, bool orientation) {
        this->size = size;
        orientationV = orientation;
    }

    //getters
    int getKeyPointR() const{
        return keyPointR;
    }
    int getKeyPointC() const{
        return keyPointC;
    }
    bool getOrientationV() const {
        return orientationV;
    }
    int getSize() const {
        return size;
    }

    //setters
    void setKeyPointR(int keyPointR) {
        this->keyPointR = keyPointR; //will be used for changing locations
    }
    void setKeyPointC(int keyPointC) {
        this->keyPointC = keyPointC; //will be used for changing locations
    }
    void setOrientationV(bool orientationV) {
        this->orientationV = orientationV;
    }
    void setSize(int size) {
        this->size = size;
    }

};



#endif //SHIP_H
