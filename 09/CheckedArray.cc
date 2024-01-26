#include "CheckedArray.hh"
#include <cassert>

CheckedArray::CheckedArray(int n, float val) : Array(n, val)
{}

float& CheckedArray::operator[] (int i)
{
    assert (i >= min_index() && i <= max_index());
    return Array::operator[](i);
}