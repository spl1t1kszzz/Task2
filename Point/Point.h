#ifndef POISSONSOFT_TEST_POINT_H
#define POISSONSOFT_TEST_POINT_H

#include <iostream>

/**
 * @class Point
 * @brief Class representing a point in a 2D plane.
 */
class Point {
private:
    long double x;
    long double y;

public:
    /**
     * @brief Constructor to create a point with given coordinates.
     *
     * @param _x X-coordinate value.
     * @param _y Y-coordinate value.
     */
    Point(long double _x, long double _y);

    /**
     * @brief Default constructor.
     *
     * Creates a point with zero coordinates.
     */
    Point() = default;

    /**
     * @brief Destructor.
     */
    ~Point() = default;

    /**
     * @brief Assignment operator.
     *
     * Copies the coordinates from another point.
     *
     * @param other Object of type Point to copy from.
     * @return Reference to the current object.
     */
    Point &operator=(const Point &other);

    /**
     * @brief Equality operator.
     *
     * Compares two points by their coordinates.
     *
     * @param left First point.
     * @param right Second point.
     * @return true if the points have the same coordinates, otherwise false.
     */
    friend bool operator==(const Point &left, const Point &right);

    /**
     * @brief Get the X-coordinate value.
     *
     * @return X-coordinate of the point.
     */
    [[nodiscard]] long double get_x() const;

    /**
     * @brief Get the Y-coordinate value.
     *
     * @return Y-coordinate of the point.
     */
    [[nodiscard]] long double get_y() const;

    /**
     * @brief Output stream operator.
     *
     * Outputs the coordinates of the point to the standard output stream.
     *
     * @param os Output stream.
     * @param p Point to be output.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Point &p);

    /**
     * @brief Calculate the angle relative to another point.
     *
     * Calculates the angle between two points with respect to the X-axis.
     *
     * @param other The other point.
     * @return Angle in radians.
     */
    [[nodiscard]] long double calculate_angle(const Point &other) const;
};

#endif //POISSONSOFT_TEST_POINT_H
