/* *
 * MIT License
 *
 * Copyright (c) 2016 Daniel Santos
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */
#ifndef DSTRUCTS_DYNAMIC_ARRAY_H
#define DSTRUCTS_DYNAMIC_ARRAY_H


#include <cstdio>

namespace DStructs {

template <class T>
class DynamicArray {
 public:
  DynamicArray();
  ~DynamicArray();
  void push_back(const T& data);
  T& at(std::size_t idx) const;
  std::size_t size() const;
  std::size_t capacity() const;
  T& operator[](std::size_t idx);

 private:
  T* buffer_;
  std::size_t capacity_;
  std::size_t size_;
  void increase_capacity(const std::size_t new_capacity);

};  // DYNAMIC ARRAY

} // NAMESPACE DSTRUCTS

#include "dynamic_array.cc"
#endif //DSTRUCTS_DYNAMIC_ARRAY_H