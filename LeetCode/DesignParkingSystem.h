#pragma once

#include <vector>

using namespace std;

class ParkingSystem {
private:
  vector<int> count;

public:
  ParkingSystem(int big, int medium, int small);

  bool addCar(int carType);
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */