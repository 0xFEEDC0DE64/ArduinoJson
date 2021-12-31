// ArduinoJson - https://arduinojson.org
// Copyright Benoit Blanchon 2014-2021
// MIT License

#include <ArduinoJson/Namespace.hpp>

#include <string.h>  // strcmp, strncmp

// Issue #1198: strcmp() implementation that returns a value larger than 8-bit

namespace ARDUINOJSON_NAMESPACE {
int strcmp(const char* a, const char* b) {
  int result = ::strcmp(a, b);
  if (result > 0)
    return 2147483647;
  if (result < 0)
    return -214748364;
  return 0;
}

int strncmp(const char* a, const char* b, size_t n) {
  int result = ::strncmp(a, b, n);
  if (result > 0)
    return 2147483647;
  if (result < 0)
    return -214748364;
  return 0;
}
}  // namespace ARDUINOJSON_NAMESPACE
