#include "SymmetryAxisesFinder.h"

std::vector<Segment> SymmetryAxisesFinder::find_symmetry_axises(const Polygon &poly) {
    if (poly.get_points().size() % 2 == 0)
        return symmetry_axises_even(poly);
    return symmetry_axises_odd(poly);
}

std::vector<Segment> SymmetryAxisesFinder::symmetry_axises_even(const Polygon &poly) {
    std::vector<Segment> axises = vertex_to_vertex(poly);
    auto mtm = edge_mid_to_edge_mid(poly);
    axises.insert(axises.end(), mtm.begin(), mtm.end());
    return axises;
}

std::vector<Segment> SymmetryAxisesFinder::symmetry_axises_odd(const Polygon &poly) {
    std::vector<Segment> axises = edge_mid_to_edge_mid(poly);
    auto vtm = vertex_to_edge_mid(poly);
    axises.insert(axises.end(), vtm.begin(), vtm.end());
    return axises;
}

std::vector<Segment> SymmetryAxisesFinder::vertex_to_vertex(const Polygon &poly) {
    std::vector<Segment> axises;
    auto points = poly.get_points();
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 2; j < points.size(); ++j) {
            if (check_axis(poly, points[i], points[j])) {
                axises.emplace_back(points[i], points[j]);
            }
        }
    }
    return axises;
}

std::vector<Segment> SymmetryAxisesFinder::vertex_to_edge_mid(const Polygon &poly) {
    std::vector<Segment> axises;
    const auto &points = poly.get_points();
    const auto &edges = poly.get_edges();
    for (const auto &point: points) {
        for (const auto &edge: edges) {
            if (check_axis(poly, point, edge.get_mid_point())) {
                axises.emplace_back(point, edge.get_mid_point());
            }
        }
    }
    return axises;
}

std::vector<Segment> SymmetryAxisesFinder::edge_mid_to_edge_mid(const Polygon &poly) {
    const auto &points = poly.get_points();
    const auto &edges = poly.get_edges();
    std::vector<Segment> axises;
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 2; j < points.size(); ++j) {
            if (check_axis(poly, edges[i].get_mid_point(), edges[j].get_mid_point())) {
                axises.emplace_back(edges[i].get_mid_point(), edges[j].get_mid_point());
            }
        }
    }
    return axises;
}


bool SymmetryAxisesFinder::check_axis(const Polygon &poly, const Point &a, const Point &b) {
    return std::ranges::all_of(poly.get_points(), [&](const auto &vertex) {
        return poly.is_vertex(reflect(vertex, a, b));
    });
}

Point SymmetryAxisesFinder::reflect(const Point &pt, const Point &p1, const Point &p2) {
    const long double a = p2.get_y() - p1.get_y();
    const long double b = p1.get_x() - p2.get_x();
    const long double c = p2.get_x() * p1.get_y() - p1.get_x() * p2.get_y();
    const long double denom = a * a + b * b;
    const long double x = pt.get_x() - (2 * a * (a * pt.get_x() + b * pt.get_y() + c)) / denom;
    const long double y = pt.get_y() - (2 * b * (a * pt.get_x() + b * pt.get_y() + c)) / denom;
    return {x, y};
}
