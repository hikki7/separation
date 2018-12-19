
//
//  Vehicle.cpp
//  separation
//
//  Created by 引田祐樹 on 2018/12/19.
//

#include "Vehicle.hpp"

Vehicle::Vehicle(){
    maxSpeed=3;
    location=ofVec2f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    velocity=ofVec2f(ofRandom(-ofGetWidth(),ofGetWidth()),ofRandom(-ofGetHeight(),ofGetHeight()));
    velocity.normalize();
    velocity*=maxSpeed;
    acceleration=ofVec2f(0,0);
    r=12;
    maxForce=0.2;
}

void Vehicle::addForce(ofVec2f _force){
    acceleration+=_force;
}

void Vehicle::update(){
    velocity+=acceleration;
    if(velocity.length()>maxSpeed){
        velocity.normalize();
        velocity*=maxSpeed;
    }
    location+=velocity;
    acceleration*=0;
}

void Vehicle::display(){
    ofSetColor(255);
    ofDrawCircle(location.x,location.y,r);
}

void Vehicle::border(){
    if(location.x>ofGetWidth()+r){
        location.x=-r;
    }else if(location.x<-r){
        location.x=ofGetWidth()+r;
    }
    
    if(location.y>ofGetHeight()+r){
        location.y=-r;
    }else if(location.y<-r){
        location.y=ofGetHeight()+r;
    }
}

void Vehicle::separate(vector<unique_ptr<Vehicle>>& vehicles){
    
    float desiredseparation=2*r;
    ofVec2f sum=ofVec2f();
    int count;
    
    for (auto& other: vehicles) {
        ofVec2f div=this->location-other->location;
        float d=div.length();
        if(d>0 && d<desiredseparation){
            div.normalize();
            div/=d;
            sum+=div;
            count++;
        }
    }
    
    if(count>0){
        sum.normalize();
        sum*=maxSpeed;
        ofVec2f steer=sum-this->velocity;
        if(steer.length()>maxForce){
            steer.normalize();
            steer*=maxForce;
        }
        addForce(steer);
    }
}
