#include <gtest/gtest.h>

#include "../SymmetryAxisesFinder/SymmetryAxisesFinder.h"


TEST(Task2, exmaple1) {
    Point a{0, 0};
    Point b{1, 0};
    Point c{1, 1};
    Point d{0, 1};
    Polygon poly{{a, b, c, d}};
    ASSERT_EQ(SymmetryAxisesFinder::find_symmetry_axises(poly).size(), 4);
}

TEST(Task2, exmaple2) {
    Point a{0, 0};
    Point b{2, 1};
    Point c{0, 3};
    Point d{-2, 1};
    Polygon poly{{a, b, c, d}};
    auto axises = SymmetryAxisesFinder::find_symmetry_axises(poly);
    ASSERT_EQ(axises.size(), 1);
    ASSERT_EQ(axises[0].get_a(), Point(0, 3));
    ASSERT_EQ(axises[0].get_b(), Point(0, 0));
}

TEST(Task2, exmaple3) {
    Point a{0.1, 1.0};
    Point b{-1.0, 0.0};
    Point c{0.0, -1.0};
    Point d{1.0, -0.5};
    Point e{2.0, 1.0};
    Polygon poly{{a, b, c, d, e}};
    ASSERT_TRUE(SymmetryAxisesFinder::find_symmetry_axises(poly).empty());
}

TEST(Task2, rhombus) {
    Point a{0, 0};
    Point b{4, 2};
    Point c{-4, 2};
    Point d{0, 4};
    Polygon poly{{a, b, c, d}};
    auto axises = SymmetryAxisesFinder::find_symmetry_axises(poly);
    ASSERT_EQ(axises.size(), 2);
    ASSERT_EQ(axises[0].get_a(), Point(-4, 2));
    ASSERT_EQ(axises[0].get_b(), Point(4, 2));
    ASSERT_EQ(axises[1].get_a(), Point(0, 4));
    ASSERT_EQ(axises[1].get_b(), Point(0, 0));
}

TEST(Task2, triangle) {
    Point a{0, 0};
    Point b{3, 0};
    Point c{3, 3};
    Polygon poly{{a, b, c}};
    auto axises = SymmetryAxisesFinder::find_symmetry_axises(poly);
    ASSERT_EQ(axises.size(), 1);
    ASSERT_EQ(axises[0].get_a(), Point(3, 0));
    ASSERT_EQ(axises[0].get_b(), Point(1.5, 1.5));
}
