#include <iostream>
#include "../include/Figure.hpp"

void swap(DistancePair *a, DistancePair *b){
  DistancePair temp;
  temp = *a;
  *a = *b;
  *b = temp;
};

int partition(DistancePair arr[], int low, int high){
  DistancePair pivot = arr[high];    // pivot
  int i = (low - 1);  // Index of smaller element

  for (int j = low; j <= high- 1; j++)
    {
      if (arr[j].distance <= pivot.distance)
        {
          i++;
          swap(&arr[i], &arr[j]);
        }
    }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
};

void quicksortFigure(DistancePair arr[], int low, int high){
  if(low < high) {
    int partitionIndex = partition(arr, low, high);
    quicksortFigure(arr, low, partitionIndex - 1);
    quicksortFigure(arr, partitionIndex + 1, high);
  }
};
