#include "stdafx.h"
#include "ValidateIPAddress.h"

#include <vector>
#include <sstream>

vector<string> split(string s, char c) {
  vector<string> parts;
  string part;
  stringstream in(s);
  while (getline(in, part, c)) {
    parts.push_back(part);
  }
  return parts;
}

bool validIPv4(string IP) {
  if (count(IP.begin(), IP.end(), '.') != 3) {
    return false;
  }
  vector<string> parts = split(IP, '.');
  if (parts.size() != 4) {
    return false;
  }
  for (string part : parts) {
    if (part.empty() || part.size() > 3 || part.size() > 1 && part[0] == '0') {
      return false;
    }
    for (char c : part) {
      if (!isdigit(c)) {
        return false;
      }
    }
    if (stoi(part) > 255) {
      return false;
    }
  }
  return true;
}

bool validIPv6(string IP) {
  if (count(IP.begin(), IP.end(), ':') != 7) {
    return false;
  }
  vector<string> parts = split(IP, ':');
  if (parts.size() != 8) {
    return false;
  }
  for (string part : parts) {
    if (part.empty() || part.size() > 4) {
      return false;
    }
    for (char c : part) {
      if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F')) {
        return false;
      }
    }
  }
  return true;
}

string Solution::validIPAddress(string IP) {
  return validIPv4(IP) ? "IPv4" : (validIPv6(IP) ? "IPv6" : "Neither");
}