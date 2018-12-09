#ifndef POLYGON_H
#define POLYGON_H

#include <string>
#include "Shape.hpp"

enum coordType {X, Y};
class Polygon : public Shape {
private:
  bool convex;
  bool regular = true;
  bool convexHasBeenRun = false;
  bool positionHasBeenRun = false;
  float xMax = 0;
  float yMax = 0;
  float xMin = 0;
  float yMin = 0;
  friend std::ostream& operator<< (std::ostream& stream, const Polygon &Plgn);
  void getMaxValues();

public:
  Polygon();
  Polygon(Coordinate *coords, int coordsSize);
  Polygon(const Polygon &source);
  Polygon& operator=(const Polygon& source);
  Polygon operator+(const Polygon &p2);

  float getMax(coordType type);
  float getMin(coordType type);
  std::string getType();
  float area();
  float circumference();
  Coordinate position();
  bool isConvex();
  float distance(Shape *s);
  ~Polygon();

};

#endif
