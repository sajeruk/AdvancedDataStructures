// created by Maxim Busel @sajeruk
#ifndef STACK_WITH_MAX_H
#define STACK_WITH_MAX_H
#include <algorithm>
#include <stack>

template <typename T, typename Comparator = std::less<T>>
class StackWithExtremal
{
public:

  void push(const T& element);
  const T& extremum() const;
  bool empty() const;
  const T& top() const;
  void pop();

private:
  std::stack<T> stack_, stackMin_;
};
#include "StackWithExtremal.cpp"
#endif
