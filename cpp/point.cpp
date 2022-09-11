#include <iostream>
#include <array>

#include "../potions/point.hpp"
#include "../potions/choco.hpp"


int unifyInt(int x) {
    if (x > 0) {
        return 1;
    } else if (x == 0) {
        return 0;
    } else {
        return -1;
    }
}

Point::Point(int _row, int _column) : row(_row), column(_column) {}
Point::Point() {}
void Point::printPoint() {
    std::cout << '(' << row << ", " << column << ')';
}
Point Point::operator + (Point other) {
    return Point(row + other.row, column + other.column);
}
Point Point::operator - (Point other) {
    return Point(row - other.row, column - other.column);
}
Point Point::operator * (Point other) {
    return Point(row * other.row, column * other.column);
}
Point Point::operator * (int other) {
    return Point(row * other, column * other);
}
Point Point::offset(Point direction, int units) {
    return *this + direction * units;
}
Point Point::invert() {
    return (*this) * Point(-1, -1);
}
Point Point::unify() {
    return Point(unifyInt(this->row), unifyInt(this->column));
}
int Point::aggregate() {
    return row + column;
}
#include "../potions/unchoco.hpp"
