#include "stdafx.h"
#include "GasStation.h"

/*
It's impossible to perform the road trip if sum(gas) < sum(cost). In this situation the answer is -1.

It's impossible to start at a station i if gas[i] - cost[i] < 0, because then there is not enough gas in 
the tank to travel to i + 1 station.

Let's introduce curr_tank variable to track the current amount of gas in the tank. 
If at some station curr_tank is less than 0, that means that one couldn't reach this station.

Next step is to mark this station as a new starting point, and reset curr_tank to zero 
since one starts with no gas in the tank.
*/
int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int n = gas.size();

  int total_tank = 0;
  int curr_tank = 0;
  int starting_station = 0;
  for (int i = 0; i < n; ++i) {
    total_tank += gas[i] - cost[i];
    curr_tank += gas[i] - cost[i];
    // If one couldn't get here,
    if (curr_tank < 0) {
      // Pick up the next station as the starting one.
      starting_station = i + 1;
      // Start with an empty tank.
      curr_tank = 0;
    }
  }
  return total_tank >= 0 ? starting_station : -1;
}