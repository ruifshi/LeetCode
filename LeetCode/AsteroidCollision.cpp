#include "stdafx.h"
#include "AsteroidCollision.h"

vector<int> Solution::asteroidCollision(vector<int>& asteroids) {
  vector<int> s; // use vector to simulate stack
  // keep positive astroids on the stack (back of vector) until they are destroyed
  for (int i : asteroids) {
    if (i > 0) s.push_back(i);
    else {
      while (!s.empty() && s.back() > 0 && s.back() < abs(i)) s.pop_back(); // negavtive astroid bigger
      if (s.empty() || s.back() < 0) s.push_back(i);  //all positive astroids destroyed
      else if (s.back() == -i) s.pop_back();  // astroids same value destroys themselves
    }
  }
  return s;
}