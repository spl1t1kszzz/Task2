#include "Polygon.h"

/**
 * Fills the handler with GIF information
 *
 * @param filename GIF File name to be loaded
 * @return Inited GIF Handler or NULL for error
 */
Polygon::Polygon(const std::vector<Point> &points) : points(points) {
    auto centroid = this->find_centroid();
    std::ranges::sort(this->points, [&centroid](const Point &a, const Point &b) {
        return a.calculate_angle(centroid) > b.calculate_angle(centroid);
    });
    for (int i = 0; i < points.size() - 1; ++i) {
        this->segments.emplace_back(this->points[i], this->points[i + 1]);
    }
    this->segments.emplace_back(this->points[this->points.size() - 1], this->points[0]);
}


std::ostream &operator<<(std::ostream &os, const Polygon &poly) {
    for (const auto &p: poly.points) {
        os << p << std::endl;
    }
    return os;
}


Point Polygon::find_centroid() const {
    long double x_sum = 0.0f;
    long double y_sum = 0.0f;
    for (const auto &p: this->points) {
        x_sum += p.get_x();
        y_sum += p.get_y();
    }
    const auto points_size = static_cast<double>(this->points.size());
    return {x_sum / points_size, y_sum / points_size};
}

const std::vector<Point> &Polygon::get_points() const {
    return this->points;
}

bool Polygon::is_vertex(const Point &point) const {
    return std::ranges::any_of(this->points, [&](const auto &p) {
        return p == point;
    });
}

const std::vector<Segment> &Polygon::get_edges() const {
    return segments;
}
