#include "stdafx.h"
#include "RemoveSubFoldersFromTheFilesystem.h"

#include <algorithm>

vector<string> Solution::removeSubfolders(vector<string>& folder) {

  // sorting makes sure the top level folders are in front
  // then you just compare next folder with prev and eliminate
  // subfolders
  sort(folder.begin(), folder.end());

  vector<string> ans;
  for (const auto &f : folder) {
    // if first element, then add
    // search for top level folder from the back
    if (ans.size() == 0 ||
      (f.rfind(ans.back() + "/", 0) == string::npos)) {
      ans.push_back(f);
    }
  }

  return ans;
}

/*
vector<string> removeSubfolders(vector<string>& folder) {
    vector<string> ans;
    int idxKey=0, idxTarget=1;
    if (folder.size()==1) return folder;

    sort(folder.begin(),folder.end());
    ans.push_back(folder[idxKey]);

    while(idxTarget < folder.size())
    {
        if (folder[idxKey] ==
            folder[idxTarget].substr(0,folder[idxKey].size())
           && folder[idxTarget][folder[idxKey].size()] == '/')
        {
            idxTarget++;
            continue;
        }
        ans.push_back(folder[idxTarget]);
        idxKey = idxTarget;
        idxTarget++;
    }
    return ans;
}
*/