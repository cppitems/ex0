#pragma once

// EX0 implementation header
class Vector {
private:
  int _size = 0;
  int *_data;

public:
  using value_type = int; // modern "typedef"
  Vector(int size, value_type value);
  ~Vector();
  int size();
};