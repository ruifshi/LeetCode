#include "stdafx.h"
#include "FindKClosestElements.h"

vector<int> Solution::findClosestElements(vector<int>& arr, int k, int x) {
	//find closest element index
	int l = 0, r = arr.size() - 1;
	while (l <= r) {	// <= in case of duplicates
		int mid = l + (r - l) / 2;
		if (arr[mid] == x) {
			l = mid;
			break;
		}
		else if (arr[mid] > x) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	// expand around closest
	r = l + 1;

	while (k > 0) {
		if (r >= arr.size() || (l >= 0 && x - arr[l] <= arr[r] - x)) {
			l--;
		}
		else {
			r++;
		}

		k--;
	}

	vector<int> ans;
	for (int i = l; i < r; i++) ans.push_back(arr[i]);

	return ans;

}

/* O(nlogn)
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		sort(arr.begin(), arr.end(), [x](int a, int b) {
				int xa = abs(x - a), xb = abs(x - b);
				return xa < xb || xa == xb && a < b;
		});
		arr.resize(k);
		sort(arr.begin(), arr.end());
		return arr;
}
*/

/* O(klogk)
vector<int> findClosestElements(vector<int>& arr, int k, int x) {

	priority_queue<pair<int, int>>pq;
	for (int i = 0; i < arr.size(); i++) {
		pq.push(make_pair(abs(arr[i] - x), arr[i]));
		if (pq.size() > k) pq.pop();
	}

	vector<int>res;
	while (!pq.empty()) {
		int t = pq.top().second;
		res.push_back(t);
		pq.pop();
	}

	sort(res.begin(), res.end());
	return res;
}
*/