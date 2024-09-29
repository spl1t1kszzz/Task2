#include "Point.h"

Point::Point(const long double _x, const long double _y) : x(_x), y(_y) {
}

Point &Point::operator=(const Point &other) {
    if (other == *this) {
        return *this;
    }
    this->x = other.x;
    this->y = other.y;
    return *this;
}

bool operator==(const Point &left, const Point &right) {
    return std::abs(left.x - right.x) < 1e-5 and std::abs(left.y - right.y) < 1e-5;
}


std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << p.x << ' ' << p.y;
    return os;
}

long double Point::get_x() const {
    return x;
}

long double Point::get_y() const {
    return y;
}

long double Point::calculate_angle(const Point &other) const {
    return std::atan2(this->y - other.y, this->x - other.x);
}
