// created by Maxim Busel @sajeruk
#ifndef QUEUE_WITH_EXTREMAL_H
#define QUEUE_WITH_EXTREMAL_H

#include "StackWithExtremal.h"
#include <algorithm>

template <typename T, typename Comparator = std::less<T>>
class QueueWithExtremal
{
public:

  void enqueue(const T& element);
  const T& extremum() const;
  const T& front() const;
  void dequeue();
  bool empty() const;

private:

  void transfer_();
  StackWithExtremal<T, Comparator> head_, tail_;
};

#include "QueueWithExtremal.cpp"
#endif
