#include "stdafx.h"
#include "FindDuplicateFileInSystem.h"

#include <unordered_map>

vector<vector<string>> Solution::findDuplicate(vector<string>& paths) {
  if (paths.size() == 0) return {};

  vector<vector<string>> out;
  unordered_map<string, vector<string>> table;

  for (int i = 0; i < paths.size(); i++) {
    paths[i] += ' '; // needed for while loop to find last file

    string dir = paths[i].substr(0, paths[i].find(' '));  // root path
    string files = paths[i].substr(paths[i].find(' ') + 1); // beginning of files

    while (files.find(' ') != string::npos) {
      string file = files.substr(0, files.find(' '));  // start of file
      string fileName = file.substr(0, file.find('('));  // file name
      string content = file.substr(file.find('(') + 1); // content
      content.pop_back(); // delete ')'

      table[content].push_back(dir + '/' + fileName); // map content to path
      files = files.substr(files.find(' ') + 1);
    }
  }

  // only need to group if there are more than one
  for (auto &x : table) {
    if (x.second.size() > 1) {
      out.push_back(x.second);
    }
  }

  return out;
}