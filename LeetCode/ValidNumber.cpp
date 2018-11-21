#include "stdafx.h"
#include "ValidNumber.h"

bool Solution::isNumber(string s) {
    int len = s.size();
    if(len == 0) return false; // empty string, not a number

    // Remember the common format is: 
    //         [spaces][sign1][digits1][.][digits2][e][sign2][digits3][spaces]
    // has_e: if we have "e"
    // has_sign2: if we have the second sign.
    // has_dot: if we have the ".".
    // has_dig1,2,3: if we have the digits1, digits2, and digits3.
    bool has_e = false, has_sign2 = false, has_dot = false;
    bool has_dig1 = false, has_dig2 = false, has_dig3 = false;

    int i = 0;
    // Skip all the leading spaces.
    while(i < len && s[i] == ' ') i ++;
    // Check if we have a sign.
    if(i < len && (s[i] == '+' || s[i] == '-')) { i ++;}
    // go through digits1 part.
    while(i < len && isdigit(s[i])) {i ++; has_dig1 = true;}
    // Check '.'
    if(i < len && s[i] == '.') {i ++; has_dot = true;}
    // Go through digits2 part.
    while(i < len && isdigit(s[i])) {i ++; has_dig2 = true;}
    // Check "e"
    if(i < len && s[i] == 'e') {i ++; has_e = true; }
    // Check the 2nd sign.
    if(i < len && (s[i] == '+' || s[i] == '-')) { i ++; has_sign2 = true;}
    // Go through digits part.
    while(i < len && isdigit(s[i])) {i ++; has_dig3 = true;}
    // Skip the tailing spaces.
    while(i < len && s[i] == ' ') i ++;

    // We mush have at least one of digits1 or digits2.  
    // " 1." or ".1" are valid. "."  or "-.e10" is not valid.
    if(!has_dig2 && !has_dig1) return false;

    // if we have "e", we must have digits3 part. 
    //For example, "1e3" valid. "1e" not valid.
    if(has_e && !has_dig3) return false;

    // If we have sign2, we must have "e".
    // For example, "1e-3" is valid, "1e-" is not valid.
    if(!has_e && has_sign2) return false;

    // If we have scanned all letters, this is a valid number.
    return i == s.size();
}