#include "Segment.h"

Segment::Segment(const Point &a, const Point &b) : a(a), b(b) {}

const Point &Segment::get_a() const {
    return a;
}

const Point &Segment::get_b() const {
    return b;
}

std::ostream &operator<<(std::ostream &os, const Segment &segment) {
    os << segment.a << " - " << segment.b;
    return os;
}

Point Segment::get_mid_point() const {
    return {(this->a.get_x() + this->b.get_x()) / 2.0, (this->a.get_y() + this->b.get_y()) / 2.0};
}

