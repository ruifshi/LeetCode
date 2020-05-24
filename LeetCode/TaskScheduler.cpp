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

	for (int i = 24; i >= 0; i--) {
		idle_slots -= min(taskmap[i], max);	// fill idle slots with the other tasks
	 }

	// all idle filled or not
	return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
}