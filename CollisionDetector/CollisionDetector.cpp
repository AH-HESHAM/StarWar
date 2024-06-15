#include "Object.h"
#include "CollisionDetector.h"
#include "../Drawer/Drawer.h"
#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include <vector>
using namespace std;
Projectile DeleteProjectileAndReturn(int index){
    for(int i = 0; i < Utility::projectiles.size() ; i++){
        if(i == index){
            Utility::projectiles[i].deleteProjectile();
            return Utility::projectiles[i];
        }
    }
    return Projectile(glm::vec3(5000.0, 0.0f, 5000.0), glm::vec3(sin(0 * Utility::PI / 180.0f), 0.0f, -cos(0 * Utility::PI / 180.0f)), 10.0, 0.0);
}
bool DecreaseEnemyHealth(int EnemyIndex, float damage){
    for(int i = 0; i < Drawer::getInstance().getEnemies().size() ; i++){
        if(EnemyIndex == i){
            Drawer::getInstance().getEnemies()[i].decreaseHealth(damage);
            if(Drawer::getInstance().getEnemies()[i].isAlive()){
               return false;
            }
            else{
                return true;
            }
        }
    }
    return false;
}

int CollisionDetector::checkSpheresIntersection(float x1, float y1 ,float z1, float r1,
                             float x2, float y2, float z2, float r2)
{
    return (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2)) <= (r1 + r2)*(r1 + r2));
}

void CollisionDetector::HandleCollision(Object first,  Object second ) {
      string type1 = min(first.getType(), second.getType()), type2 = max(first.getType(), second.getType());
      if(type1 != first.getType()){
          swap(first, second);
      }
    if(type1 == "spacecraft" && type2 == "sun"){
        Drawer::getInstance().userSpacecraft.decreaseHealth(User::getMaxHealth());
    }
    else if (type1 == "moon" && type2 == "spacecraft"){
        Drawer::getInstance().userSpacecraft.decreaseHealth(User::getMaxHealth());
    }
    else if (type1 == "planet" && type2 == "spacecraft" ) {
        Drawer::getInstance().userSpacecraft.decreaseHealth(User::getMaxHealth());
    }
    else if(type1 == "enemy" && type2 == "spacecraft"){
        Drawer::getInstance().userSpacecraft.decreaseHealth(User::getMaxHealth());
    }
    else if (type1 == "projectile" && type2 == "spacecraft"){
        Projectile projectile = DeleteProjectileAndReturn(first.getIndex());
        Drawer::getInstance().userSpacecraft.decreaseHealth(projectile.getDamage());
    }
    else if( type1 == "planet" && type2 == "projectile"){
        Projectile projectile = DeleteProjectileAndReturn(second.getIndex());
    }
    else if(type1 == "moon" && type2 == "projectile"){
        Projectile projectile = DeleteProjectileAndReturn(second.getIndex());
    }
    else if(type1 == "projectile" && type2 == "sun"){
        Projectile projectile = DeleteProjectileAndReturn(first.getIndex());
    }
    else if(type1 == "enemy" && type2 == "projectile"){
        Projectile projectile = DeleteProjectileAndReturn(second.getIndex());
        if(DecreaseEnemyHealth(first.getIndex(), projectile.getDamage())){
            Drawer::getInstance().userSpacecraft.increaseScore(1.0);
        }
    }
    else if(type1 == "enemy" && type2 == "sun"){
        DecreaseEnemyHealth(first.getIndex(), 120.1);
    }
    else if(type1 == "enemy" && type2 == "moon"){
        DecreaseEnemyHealth(first.getIndex(), 120.1);
    }
    else if(type1 == "enemy" && type2 == "planet"){
        DecreaseEnemyHealth(first.getIndex(), 120.1);
    }
    else if(type1 == "item" && type2 == "spacecraft") {
        cout << "spacecraft collided with items" << endl;
    }
}

void CollisionDetector::DetectCollision(const std::vector<Object>& objects) {
    for (int i = 0; i < (int)objects.size(); i++) {
        for(int j = i + 1; j < (int)objects.size(); j++) {
            if (checkSpheresIntersection(objects[i].getX(), objects[i].getY(), objects[i].getZ(), objects[i].getRadius(),
                                         objects[j].getX(), objects[j].getY(), objects[j].getZ(), objects[j].getRadius())) {
                HandleCollision(objects[i], objects[j]);
            }
        }
    }
}