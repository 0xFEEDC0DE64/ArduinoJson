// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2020
// MIT License

#pragma once

#include <ArduinoJson/Namespace.hpp>
#include <ArduinoJson/Strings/IsString.hpp>
#include <ArduinoJson/Strings/StoragePolicy.hpp>

#include <string>

namespace ARDUINOJSON_NAMESPACE {

template <typename TString>
class StdStringAdapter {
 public:
  StdStringAdapter(const TString& str) : _str(&str) {}

  void copyTo(char* p, size_t n) const {
    memcpy(p, _str->c_str(), n);
  }

  bool isNull() const {
    return false;
  }

  int compare(const char* other) const {
    if (!other)
      return 1;
    return _str->compare(other);
  }

  bool equals(const char* expected) const {
    if (!expected)
      return false;
    return *_str == expected;
  }

  size_t size() const {
    return _str->size();
  }

  const char* begin() const {
    return _str->c_str();
  }

  typedef storage_policies::store_by_copy storage_policy;

 private:
  const TString* _str;
};

template <typename TStringView>
class StdStringViewAdapter {
 public:
  StdStringViewAdapter(TStringView strView) : _strView(strView) {}

  void copyTo(char* p, size_t n) const {
    memcpy(p, _strView.data(), n);
  }

  bool isNull() const {
    return false;
  }

  int compare(const char* other) const {
    if (!other)
      return 1;
    return _strView.compare(other);
  }

  bool equals(const char* expected) const {
    if (!expected)
      return false;
    return _strView == expected;
  }

  size_t size() const {
    return _strView.size();
  }

  const char* begin() const {
    return _strView.data();
  }

  typedef storage_policies::store_by_copy storage_policy;

 private:
  TStringView _strView;
};

template <typename TCharTraits, typename TAllocator>
struct IsString<std::basic_string<char, TCharTraits, TAllocator> > : true_type {
};

template <typename TCharTraits>
struct IsString<std::basic_string_view<char, TCharTraits> > : true_type {
};

template <typename TCharTraits, typename TAllocator>
inline StdStringAdapter<std::basic_string<char, TCharTraits, TAllocator> >
adaptString(const std::basic_string<char, TCharTraits, TAllocator>& str) {
  return StdStringAdapter<std::basic_string<char, TCharTraits, TAllocator> >(
      str);
}

template <typename TCharTraits>
inline StdStringViewAdapter<std::basic_string_view<char, TCharTraits> >
adaptString(const std::basic_string_view<char, TCharTraits>& str) {
  return StdStringViewAdapter<std::basic_string_view<char, TCharTraits> >(str);
}

}  // namespace ARDUINOJSON_NAMESPACE
