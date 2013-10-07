// created by Maxim Busel @sajeruk
#include "StackWithExtremal.h"

template <typename T, typename Comparator>
void StackWithExtremal<T, Comparator>::push(const T& element) {
  const T& extremalElement = (stackMin_.empty()) ?
    element : std::min(element, stackMin_.top(), Comparator());
  stackMin_.push(extremalElement);
  stack_.push(element);
}

template <typename T, typename Comparator>
const T& StackWithExtremal<T, Comparator>::extremum() const {
  return stackMin_.top();
}

template <typename T, typename Comparator>
bool StackWithExtremal<T, Comparator>::empty() const {
  return stack_.empty();
}

template <typename T, typename Comparator>
const T& StackWithExtremal<T, Comparator>::top() const {
  if (stack_.empty())
    throw std::logic_error("Cannot top empty stack");
  return stack_.top();
}

template <typename T, typename Comparator>
void StackWithExtremal<T, Comparator>::pop() {
  if (stack_.empty())
    throw std::logic_error("Cannot pop from empty stack");
  stack_.pop();
  stackMin_.pop();
}

