#include "stdafx.h"
#include "LoggerRateLimiter.h"

//unordered_map<string, int> times;

/** Initialize your data structure here. */
Logger::Logger() {

}

/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
    If this method returns false, the message will not be printed.
    The timestamp is in seconds granularity. */
bool Logger::shouldPrintMessage(int timestamp, string message) {
  if (timestamp < times[message]) return false;
  times[message] = timestamp + 10;

  return true;
}