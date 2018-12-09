#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "../include/Figure.hpp"
#include "../include/Coordinate.hpp"
#include "../include/Polygon.hpp"
#include "../include/Functions.hpp"

int main(int argc, char* argv[]) {
  std::ifstream readFile;
  std::string c;
  int badChars;

  int size;
  int coordSize;
  int line = 0;

  float* floatsFromString;

  Coordinate *coordArr;

  Polygon *shapes;

  if(argc == 1) {
    std::cout << "Need input file" << std::endl;
  }

  readFile.open(argv[1]);
  if(readFile.bad()) {
    std::cout << "Could not open file" << std::endl;
    exit(EXIT_FAILURE);
  }

  while(std::getline(readFile, c)) {
    badChars = numberOfBadChars(c);
    line++;
    if(badChars) {
      std::cout << "Cannot read file, bad character at line " << line << ", position: " << badChars << std::endl;
      exit(EXIT_FAILURE);
    }
    if(c.length() < 1) {
      std::cout << "Cannot read file, line " << line << " is empty" << badChars << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  readFile.clear();
  readFile.seekg(0, std::ios::beg);

  int currentLine = 0;
  shapes = new Polygon[line];
  while(std::getline(readFile, c)){

    size = getFloatCount(c);

    if(size % 2 == 0) {

      coordSize = size/2;
      floatsFromString = new float[size];
      coordArr = new Coordinate[coordSize];
      extractFloatsFromString(c, floatsFromString, size);
      int i = 0;

      while(i < coordSize) {
        for(int j = 0; j < size; j+=2) {
          coordArr[i] = {floatsFromString[j], floatsFromString[j+1]};
          i++;
        }
      }

      shapes[currentLine] = {coordArr, coordSize};
      delete [] coordArr;
      delete [] floatsFromString;
      currentLine++;
    }
  }

  Figure everyShape(currentLine, shapes);

  //getBoundingBox uses these coordinates to return
  Coordinate topLeft;
  Coordinate botRight;

  everyShape.getBoundingBox(&topLeft, &botRight);

  std::cout << "Bounding box top left coordinate: " << topLeft;
  std::cout << "Bounding box bottom right coordinate: " << botRight;

  delete [] shapes;

  readFile.close();
}
