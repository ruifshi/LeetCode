#include "stdafx.h"
#include "EmployeeImportance.h"

#include <unordered_map>

void DFS(unordered_map<int, Employee*>& m, int id, int& sum) {
  sum += m[id]->importance;
  for (auto x : m[id]->subordinates) DFS(m, x, sum);
}

int Solution::getImportance(vector<Employee*> employees, int id) {
  unordered_map<int, Employee*>m; // map employee id to employee
  for (auto x : employees) m[x->id] = x;
  int sum = 0;
  DFS(m, id, sum);
  return sum;
}