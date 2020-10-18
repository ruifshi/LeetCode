#include "stdafx.h"
#include "DesignParkingSystem.h"

//  vector<int> count;

ParkingSystem::ParkingSystem(int big, int medium, int small) {
  count = { big, medium, small };
}

bool ParkingSystem::addCar(int carType) {
  return count[carType - 1]-- > 0;
}