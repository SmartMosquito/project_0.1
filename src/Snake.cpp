#include "Snake.h"
#include "Constants.h"
#include <cstdlib>

Snake::Snake() {
    segments.push_back(Segment(400, 300));
    direction = Right;
}

void Snake::move() {
    Segment head = segments.front();

    switch (direction) {
        case Up: head.y -= Constants::SIZE; break;
        case Down: head.y += Constants::SIZE; break;
        case Left: head.x -= Constants::SIZE; break;
        case Right: head.x += Constants::SIZE; break;
    }

    segments.push_front(head);
    segments.pop_back();
}

void Snake::grow() {
    segments.push_back(segments.back());
}

void Snake::setDirection(Direction dir) {
    if (dir!=-direction)
    {
        direction = dir;
    }
}

Direction Snake::getDirection() const {
    return direction;
}

const std::deque<Segment>& Snake::getSegments() const {
    return segments;
}

bool Snake::checkCollision() const {
    const Segment& head = segments.front();
    if (head.x < 0 || head.x >= Constants::WIDTH || head.y < 0 || head.y >= Constants::HEIGHT) {
        return true;
    }

    for (size_t i = 1; i < segments.size(); ++i) {
        if (head.x == segments[i].x && head.y == segments[i].y) {
            return true;
        }
    }

    return false;
}