//
//  Vehicle.hpp
//  separation
//
//  Created by 引田祐樹 on 2018/12/19.
//

#pragma once
#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include "ofMain.h"

class Vehicle{
  
public:
    
    Vehicle();
    void addForce(ofVec2f _force);
    void update();
    void display();
    void border();
    void separate(vector<unique_ptr<Vehicle>>& vehicles);
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float r;
    float maxSpeed;
    float maxForce;
    
};

#endif /* Vehicle_hpp */
