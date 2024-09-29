#ifndef POISSONSOFT_TEST_POLYGON_H
#define POISSONSOFT_TEST_POLYGON_H

#include <vector>
#include <iostream>
#include "../Segment/Segment.h"

/**
 * @class Polygon
 * @brief Class representing a polygon in a 2D plane.
 */
class Polygon {
private:
    std::vector<Point> points;
    std::vector<Segment> segments;

public:
    /**
     * @brief Get the edges of the polygon.
     * @return A constant reference to the vector of segments.
     */
    [[nodiscard]] const std::vector<Segment> &get_edges() const;

    /**
     * @brief Get the vertices (points) of the polygon.
     * @return A constant reference to the vector of points.
     */
    [[nodiscard]] const std::vector<Point> &get_points() const;

    /**
     * @brief Constructor to create a polygon from a set of points.
     *
     * Constructs a polygon using the given vector of points as vertices. The edges are
     * automatically generated based on the order of the points.
     *
     * @param points Vector of points representing the vertices of the polygon.
     */
    explicit Polygon(const std::vector<Point> &points);

    /**
     * @brief Default destructor.
     */
    ~Polygon() = default;

    /**
     * @brief Default constructor.
     *
     * Creates an empty polygon.
     */
    Polygon() = default;

    /**
     * @brief Output stream operator.
     * @param os Output stream.
     * @param poly Polygon to be output.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Polygon &poly);

    /**
     * @brief Find the centroid of the polygon.
     * @return The centroid of the polygon as a Point.
     */
    [[nodiscard]] Point find_centroid() const;

    /**
     * @brief Check if a point is a vertex of the polygon.
     * @param point The point to check.
     * @return true if the point is a vertex, otherwise false.
     */
    [[nodiscard]] bool is_vertex(const Point &point) const;
};

#endif //POISSONSOFT_TEST_POLYGON_H