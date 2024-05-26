#ifndef SNAKE_H
#define SNAKE_H

#include <deque>


enum Direction { Up=1, Down=-1, Left=2, Right=-2 };

struct Segment {
    int x, y;
    Segment(int x, int y) : x(x), y(y) {}
};

class Snake {
public:
    Snake();
    void move();
    void grow();
    void setDirection(Direction dir);
    Direction getDirection() const;
    const std::deque<Segment>& getSegments() const;
    bool checkCollision() const;

private:
    std::deque<Segment> segments;
    Direction direction;
};

#endif