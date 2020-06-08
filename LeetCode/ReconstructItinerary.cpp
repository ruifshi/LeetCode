#include "stdafx.h"
#include "ReconstructItinerary.h"

/*
First keep going forward until you get stuck. That's a good main path already. 
Remaining tickets form cycles which are found on the way back and get merged into that main path. 
By writing down the path backwards when retreating from recursion, merging the cycles into the main
path is easy - the end part of the path has already been written, the start part of the path hasn't
been written yet, so just write down the cycle now and then keep backwards-writing the path.

unordered_map<string, multiset<string>> targets;
vector<string> route;
*/
void Solution::visit(string airport) {
  while (targets[airport].size()) {
    string next = *targets[airport].begin();
    targets[airport].erase(targets[airport].begin());
    visit(next);
  }
  route.push_back(airport);
}

vector<string> Solution::findItinerary(vector<pair<string, string>> &tickets) {
  for (auto ticket : tickets)
    targets[ticket.first].insert(ticket.second);
  visit("JFK");
  return vector<string>(route.rbegin(), route.rend());
}