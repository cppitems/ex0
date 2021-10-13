#include <vector.hpp> // search in default include paths 
// #include "../include/vector.hpp" // would search relative to current file

// EX0 implementation source

Vector::Vector(int size, Vector::value_type value)
    : _size(size), _data(new int[size]) {}
Vector::~Vector() { delete[] _data; }
int Vector::size() { return _size; }
