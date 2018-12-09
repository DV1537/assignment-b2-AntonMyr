#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

class Coordinate {
 private:
  float xVal;
  float yVal;
  friend std::ostream& operator<< (std::ostream& stream, Coordinate &Coord);

 public:
  Coordinate(float x, float y);
  Coordinate();
  float getX();
  float getY();
  float distance(Coordinate d);
};

#endif
