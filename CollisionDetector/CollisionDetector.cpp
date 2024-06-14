#include "Object.h"
#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include <vector>
using namespace std;

int checkSpheresIntersection(float x1, float y1 ,float z1, float r1,
                             float x2, float y2, float z2, float r2)
{
    return (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2)) <= (r1 + r2)*(r1 + r2));
}

void HandleCollision(const string& type1, const string& type2) {
    if ((type1 == "spacecraft" && type2 == "moon") || (type1 == "moon" && type2 == "spacecraft")) {
        cout << "Spacecraft collided with Moon" << endl;
    }
    else if ((type1 == "planet" && type2 == "spacecraft") || (type1 == "spacecraft" && type2 == "planet")) {
        cout << "planet collided with spacecraft" << endl;
    }
    else if ((type1 == "projectile" && type2 == "spacecraft") || (type1 == "spacecraft" && type2 == "projectile")) {
        cout << "Spacecraft collided with Projectile" << endl;
    }
    else if((type1 == "spacecraft" && type2 == "items") || (type1 == "items" && type2 == "spacecraft")) {
        cout << "spacecraft collided with items" << endl;
    }
}

void DetectCollision(vector<Object> objects) {
    for (int i = 0; i < (int)objects.size(); i++) {
        for(int j = i + 1; j < (int)objects.size(); j++) {
            if (checkSpheresIntersection(objects[i].getX(), objects[i].getY(), objects[i].getZ(), objects[i].getRadius(),
                                         objects[j].getX(), objects[j].getY(), objects[j].getZ(), objects[j].getRadius())) {
                cout<<"collision detected between: "<<objects[i].getType()<<" "<<objects[j].getType()<<endl;
                HandleCollision(objects[i].getType(), objects[j].getType());
            }
        }
    }
}