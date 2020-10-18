#include "stdafx.h"
#include "SnapshotArray.h"

//map<int, map<int, int>> snaps;  //maps index of element in array to versions of that element (snapId, val)
//int snapId = 0;

//O(N)
SnapshotArray::SnapshotArray(int length) {
  for (int i = 0; i < length; i++) {
    map<int, int> mp; mp[0] = 0;
    snaps[i] = mp;
  }
}

//O(1)
void SnapshotArray::set(int index, int val) {
  snaps[index][snapId] = val;
}

//O(1)
int SnapshotArray::snap() {
  return snapId++;
}

//O(log number of snapId)
int SnapshotArray::get(int index, int snap_id) {
  auto it = snaps[index].upper_bound(snap_id); it--;  //first element greater than snap_id
  return it->second;
}