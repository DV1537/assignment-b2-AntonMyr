#ifndef FIGURE_H
#define FIGURE_H

#include "Coordinate.hpp"
#include "Polygon.hpp"

class Figure {
 private:
  Polygon *shapeArr;
  int capacity;
  int capacityUsed;

  float getMax(coordType type);
  float getMin(coordType type);

 public:
  Figure(int capacity, Polygon *orgShapeArr);
  ~Figure();
  void addShape(Polygon *s);
  void getBoundingBox(Coordinate *topLeft, Coordinate *botRight);
  int getClosest(Coordinate location, int n, Polygon *closestArr);
};

struct DistancePair {
  int index;
  float distance;
};

void quicksortFigure(DistancePair arr[], int low, int high);

#endif
