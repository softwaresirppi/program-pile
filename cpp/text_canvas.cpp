#include <iostream>
#include <string.h>

#include "../potions/point.hpp"

#include "../potions/text_canvas.hpp"
#include "../potions/choco.hpp"

// EVERYTHING HERE ONLY SUPPORTS STRAIGHT LINES. Curved aint supprted for now


// class Line
TextCanvas::Line::Line(Point _from, Point _to) : from(_from), to(_to) {}
TextCanvas::Line::Line(Point _from, Point direction, int length) {
    from = _from;
    to = from.offset(direction, length);
}
void TextCanvas::Line::printLine() {
    from.printPoint();
    std::cout << " -> ";
    to.printPoint();
}
Point TextCanvas::Line::getPoint() {
    Point diff = to - from;
    return diff.unify();
}
int TextCanvas::Line::getLength() {
    Point diff = to - from;
    return diff.aggregate() + 1;
}

// class Canvas
// width and height starts with 1
TextCanvas::Canvas::Canvas(frozen int _width, frozen int _height) : width(_width), height(_height) {
    canvas = new char[width * height];
}
void TextCanvas::Canvas::printDebugCanvas() {
    std::cout << ' ';
    for (size_t x = 0; x < width; x++) {
        std::cout << x;
    }
    std::cout << br;
    for (size_t i = 0; i < height; i++) {
        std::cout << i;
        for (size_t j = 0; j < width; j++) {
            std::cout << getCharRef(Point(i, j));
        }
        std::cout << br;
    }
}

void TextCanvas::Canvas::printCanvas() {
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            std::cout << getCharRef(Point(i, j));
        }
        std::cout << br;
    }
}

// row and column starts with 0
inline char &TextCanvas::Canvas::getCharRef(Point point) {
    return canvas[(point.row) * (width)+point.column];
    /*
    +012
    0012
    1345
    2678
    */
}

inline void TextCanvas::Canvas::putChar(Point point, char x) {
    getCharRef(point) = x;
}

// Diagonals aint supported. The line is INCLUSIVE of [from] and [to] of the line
inline void TextCanvas::Canvas::putLine(Line line, char x) {
    Point direction = line.getPoint();
    int length = line.getLength();
    for (int i = 0; i < length; i++) {
        putChar(line.from.offset(direction, i), x);
    }
}
void TextCanvas::Canvas::putString(Point point, Point direction, char *x) {
    int len = strlen(x);
    for (unsigned int i = 0; i < len; i++) {
        getCharRef(point.offset(direction, i)) = x[i];
    }
}
void TextCanvas::Canvas::putString(Point point, Point direction, const char *x) {
    putString(point, direction, (char *)x);
}
void TextCanvas::Canvas::fill(char x) {
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            putChar(Point(i, j), x);
        }

    }
}
void TextCanvas::Canvas::clear() {
    fill(' ');
}

#include "../potions/unchoco.hpp"
