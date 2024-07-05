// corpo.hpp

#ifndef OBJECT_HPP
#define OBJECT_HPP

class Corpo {
public:
    int getHealth() const { return health; }
    int getSpeed() const { return speed; }
    int getSize() const { return size; }
    int getPoints() const { return points; }
    int getX() const { return x; }
    int getY() const { return y; }

    void setHealth(int newHealth) { health = newHealth; }
    void setSpeed(int newSpeed) { speed = newSpeed; }
    void setSize(int newSize) { size = newSize; }
    void setPoints(int newPoints) { points = newPoints; }
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }



private:
    int health;
    int points;
    int speed;
    int size;
    int x;
    int y;

};

#endif