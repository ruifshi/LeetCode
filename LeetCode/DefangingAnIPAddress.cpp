#include "stdafx.h"
#include "DefangingAnIPAddress.h"

string Solution::defangIPaddr(string address) {
  for (size_t i = 0; i < address.size(); i++)
  {
    if (address[i] == '.')
    {
      address.replace(i, 1, std::string("[.]"));
      i += 2;
    }
  }

  return address;
}