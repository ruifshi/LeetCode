#include "stdafx.h"
#include "DesignHitCounter.h"

// can also use list

/** Initialize your data structure here. */
HitCounter::HitCounter() {

}

/** Record a hit.
    @param timestamp - The current timestamp (in seconds granularity). */
void HitCounter::hit(int timestamp) {
  q.push_back(timestamp);
}

/** Return the number of hits in the past 5 minutes.
    @param timestamp - The current timestamp (in seconds granularity). */
int HitCounter::getHits(int timestamp) {
  while (!q.empty() && q.front() <= timestamp - 300) q.pop_front();
  return q.size();
}