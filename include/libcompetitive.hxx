#pragma once

#include <cstdio>
#include <vector>

inline int parseint(void) {
  int c, n;

  n = getchar_unlocked() - '0';
  while ((c = getchar_unlocked()) >= '0') n = 10 * n + c - '0';

  return n;
}

template <typename T, typename A>
inline bool is_rotated(std::vector<T, A> const& v) {
  int rises = 0;
  int falls = 0;
  for (size_t i = 0, s = v.size(); i < s; i++) {
    if (v[i] < v[(i + 1) % s]) {
      rises++;
    }
    if (v[i] > v[(i + 1) % s]) {
      falls++;
    }
    if (rises > 1 && falls > 1) {
      return false;
    }
  }
  return true;
}
