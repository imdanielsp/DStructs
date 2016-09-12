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

#include <exception>

#include "node.h"

namespace DStructs {

/**
 *  \brief This is the implementation of the Node class
 * */
template <class T>
Node<T>::Node() {
  this->next_ = nullptr;  //< Init empty next
  this->data_ = nullptr;    //< Allocate memory for T
}

template <class T>
Node<T>::Node(T& data) {
  this->data_ = &data;
  this->next_ = nullptr;
}

template<class T>
Node<T>::Node(T& data, Node<T> *next) {
  this->data_ = &data;
  this->next_ = next;
}

template <class T>
Node<T>::~Node() {
  if (this->data_ != nullptr) delete this->data_;
  if (this->next_ != nullptr) delete this->next_;
}

template <class T>
T& Node<T>::get_data() {
  if (!data_) throw std::out_of_range("Null found");
  return *data_;
}

template <class T>
void Node<T>::set_data(T& data) {
  this->data_ = &data;
}

template <class T>
void Node<T>::set_next(Node<T> *next) {
  if (!next) throw std::invalid_argument("The Node is null");
  this->next_ = next;
}

template <class T>
Node<T>* Node<T>::next() {
  if (!next_) throw std::out_of_range("Null found");
  return next_;
}

template <class T>
bool Node<T>::is_next() {
  return this->next_ != nullptr;
}

/**
 *  \brief This is the implementation of BiNode class
 * */

template <class T>
BiNode<T>::BiNode() : Node<T>() {
  this->previous_ = nullptr;
}

template <class T>
BiNode<T>::BiNode(T &data) : Node<T>(data) {
  this->previous_ = nullptr;
}

template <class T>
BiNode<T>::BiNode(T &data, Node<T> *previous, Node<T> *next) : Node<T>(data, next) {
  this->previous_ = previous;
}

template <class T>
BiNode<T>::~BiNode() {
  if (this->previous_ != nullptr) delete this->previous_;
}

template <class T>
void BiNode<T>::set_previous(Node<T> *previous) {
  if (!previous) throw std::invalid_argument("The Node is null");
  this->previous_ = previous;
}

template <class T>
Node<T>* BiNode<T>::previous() {
  if (!previous_) throw std::out_of_range("Null found");
  return this->previous_;
}

template <class T>
bool BiNode<T>::is_previous() {
  return this->previous_ != nullptr;
}
}  // NAMESPACE DStructs