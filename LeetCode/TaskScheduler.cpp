#include "stdafx.h"
#include "TaskScheduler.h"

#include <algorithm>

int SolutionleastInterval(vector<char>& tasks, int n) {
	int taskmap[26] = { 0 };

	for (auto x : tasks) {
		taskmap[x - 'A']++;
	}

	sort(taskmap, taskmap+26); //O(1)

	int max = taskmap[25] - 1; // -1 since last task doesn't need any idle
	int idle_slots = max * n; // worse case situation where we always execute same tasks

  /*
  The purpose is that we don't substract more idle spots than we are supposed to.
  the max_value will contain the number of times the most frequent task needs to be done 
  (since you order the array and then you take the last position) minus 1. We substract one  
  because for the last task executed, you don't need to wait n intervals of time.
  Now, every other element of the char array is supposed to be less than or equal to the max_value, 
  but because we substracted 1 to it, now we don't know it for sure. So, let's say that after sorting the array, 
  the last two positions hold the same value. The max_value will be then less than the element in char_map[24]. 
  So if we substract this value to the idle spots, we will be substracting one idle spot that we didn't take in count in the first place.
  */
	for (int i = 24; i >= 0; i--) {
		idle_slots -= min(taskmap[i], max);	// fill idle slots with the other tasks
	 }

	// all idle filled or not
	return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
}