#ifndef SYMMETRYAXISESFINDER_H
#define SYMMETRYAXISESFINDER_H

#include <vector>
#include "../Polygon/Polygon.h"

/**
 * @class SymmetryAxisesFinder
 * @brief Class for finding symmetry axes of a polygon.
 */
class SymmetryAxisesFinder {
public:
    /**
     * @brief Find all symmetry axes of the polygon.
     * @param poly The polygon to analyze for symmetry.
     * @return A vector of segments representing the symmetry axes of the polygon.
     */
    static std::vector<Segment> find_symmetry_axises(const Polygon &poly);

private:
    /**
     * @brief Find symmetry axes for polygons with an even number of vertices.
     * @param poly The polygon to analyze.
     * @return A vector of segments representing the symmetry axes.
     */
    static std::vector<Segment> symmetry_axises_even(const Polygon &poly);

    /**
     * @brief Find symmetry axes for polygons with an odd number of vertices.
     * @param poly The polygon to analyze.
     * @return A vector of segments representing the symmetry axes.
     */
    static std::vector<Segment> symmetry_axises_odd(const Polygon &poly);

    /**
     * @brief Find symmetry axes from vertex to vertex.
     * @param poly The polygon to analyze.
     * @return A vector of segments representing the vertex-to-vertex symmetry axes.
     */
    static std::vector<Segment> vertex_to_vertex(const Polygon &poly);

    /**
     * @brief Find symmetry axes from vertex to edge midpoint.
     * @param poly The polygon to analyze.
     * @return A vector of segments representing the vertex-to-edge-midpoint symmetry axes.
     */
    static std::vector<Segment> vertex_to_edge_mid(const Polygon &poly);

    /**
     * @brief Find symmetry axes from edge midpoint to edge midpoint.
     * @param poly The polygon to analyze.
     * @return A vector of segments representing the edge-midpoint-to-edge-midpoint symmetry axes.
     */
    static std::vector<Segment> edge_mid_to_edge_mid(const Polygon &poly);

    /**
     * @brief Check if a given axis is a valid symmetry axis.
     * @param poly The polygon to check.
     * @param a First point defining the axis.
     * @param b Second point defining the axis.
     * @return true if the axis is a valid symmetry axis, false otherwise.
     */
    static bool check_axis(const Polygon &poly, const Point &a, const Point &b);

    /**
     * @brief Reflect a point across a line.
     * @param pt The point to reflect.
     * @param p1 First point of the line to reflect across.
     * @param p2 Second point of the line to reflect across.
     * @return The reflected point.
     */
    static Point reflect(const Point &pt, const Point &p1, const Point &p2);
};

#endif //SYMMETRYAXISESFINDER_H
