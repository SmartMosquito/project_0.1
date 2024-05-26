#ifndef FOOD_H
#define FOOD_H


class Food {
public:
    Food();
    void respawn();
    int getX() const;
    int getY() const;

private:
    int x, y;
};

#endif