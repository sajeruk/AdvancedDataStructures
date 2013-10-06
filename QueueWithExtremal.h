#ifndef QUEUE_WITH_EXTREMAL_H
#define QUEUE_WITH_EXTREMAL_H

#include "StackWithExtremal.h"

template <typename T, typename Comparator = std::less<T>>
class QueueWithExtremal
{
public:

  void enqueue(const T& element);
  const T& extremum() const;
  const T& front(); // should be const, but it doesnt't compile
  void dequeue();
  bool empty() const;

private:

  void transfer_();
  StackWithExtremal<T, Comparator> head_, tail_;
};

#include "QueueWithExtremal.cpp"
#endif