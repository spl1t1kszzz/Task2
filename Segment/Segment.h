#ifndef POISSONSOFT_TEST_SEGMENT_H
#define POISSONSOFT_TEST_SEGMENT_H

#include <ostream>
#include "../Point/Point.h"

/**
 * @class Segment
 * @brief Class representing a line segment in a 2D plane.
 */
class Segment {
private:
    Point a;
    Point b;
public:
    /**
     * @brief Default constructor.
     *
     * Creates an empty segment.
     */
    Segment() = default;

    /**
     * @brief Destructor.
     */
    ~Segment() = default;

    /**
     * @brief Constructor to create a segment with two given points.
     *
     * @param a Starting point of the segment.
     * @param b Ending point of the segment.
     */
    Segment(const Point &a, const Point &b);

    /**
     * @brief Output stream operator.
     *
     * Outputs the segment to the given output stream, showing the coordinates of both points.
     *
     * @param os Output stream.
     * @param segment Segment to be output.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Segment &segment);

    /**
     * @brief Get the starting point of the segment.
     *
     * @return Reference to the starting point a.
     */
    [[nodiscard]] const Point &get_a() const;

    /**
     * @brief Get the ending point of the segment.
     *
     * @return Reference to the ending point b.
     */
    [[nodiscard]] const Point &get_b() const;

    /**
     * @brief Calculate the midpoint of the segment.
     *
     * @return The midpoint of the segment as a Point.
     */
    [[nodiscard]] Point get_mid_point() const;
};

#endif //POISSONSOFT_TEST_SEGMENT_H
