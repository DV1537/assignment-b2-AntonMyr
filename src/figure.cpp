#include <iostream>
#include <cstring>
#include "../include/Figure.hpp"
#include "../include/Polygon.hpp"

Figure::Figure(int shapeAmount, Polygon *orgShapeArr){
  capacity = shapeAmount + 5;
  capacityUsed = shapeAmount;
  shapeArr = new Polygon[capacity];

  for(int i = 0; i < capacityUsed; i++) {
    shapeArr[i] = orgShapeArr[i];
  }
}

float Figure::getMin(coordType type) {
  float minTemp = shapeArr[0].getMin(type);
  float currentMin;
  for(int i = 0; i < capacityUsed; i++) {
    currentMin = shapeArr[i].getMin(type);
    if(currentMin < minTemp)
      minTemp = currentMin;
  }
  return minTemp;
}

float Figure::getMax(coordType type) {
  float maxTemp = shapeArr[0].getMax(type);
  float currentMax;
  for(int i = 0; i < capacityUsed; i++) {
    currentMax = shapeArr[i].getMax(type);
    if(currentMax > maxTemp) {
      maxTemp = currentMax;
    }
  }
  return maxTemp;
}

void Figure::addShape(Polygon *s){
  if(capacityUsed + 1 > capacity) {
    capacity += 5;
    Polygon *temp = new Polygon[capacity];
    for(int i = 0; i < capacityUsed; i++) {
      temp[i] = shapeArr[i];
    }
    delete [] shapeArr;
    shapeArr = temp;
    delete [] temp;
  }

  capacityUsed += 1;

  shapeArr[capacityUsed-1] = *s;
};

void Figure::getBoundingBox(Coordinate *topLeft, Coordinate *botRight) {
  *topLeft = { getMin(X), getMax(Y) };
  *botRight = { getMax(X), getMin(Y)};
}

Figure::~Figure() {
  delete [] shapeArr;
}
