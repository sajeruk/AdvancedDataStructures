// created by Maxim Busel @sajeruk
#include "QueueWithExtremal.h"

template <typename T, typename Comparator>
void QueueWithExtremal<T, Comparator>::enqueue(const T& element) {
  tail_.push(element);
}

template <typename T, typename Comparator>
const T& QueueWithExtremal<T, Comparator>::extremum() const {

  if (head_.empty()) {
    return tail_.extremum();
  } else if (tail_.empty()) {
    return head_.extremum();
  } else if (empty()) {
    throw std::logic_error("No extremum in empty queue");
  } else {
    return std::min(head_.extremum(), tail_.extremum(), Comparator());
  }
}

template <typename T, typename Comparator>
const T& QueueWithExtremal<T, Comparator>::front() {
  if (head_.empty()) {
      if (tail_.empty())
        throw std::logic_error("No front"
        "element in empty queue");
      transfer_();
  }
  return head_.top();
}

template <typename T, typename Comparator>
void QueueWithExtremal<T, Comparator>::dequeue() {
  if (head_.empty()) {
    if (tail_.empty())
      throw std::logic_error("Cannot dequeue empty queue");
    transfer_();      
  }
  head_.pop();
}

template <typename T, typename Comparator>
void QueueWithExtremal<T, Comparator>::transfer_() {
  head_.push(tail_.top());
  tail_.pop();

  while (!tail_.empty()) {
    head_.push(tail_.top());
    tail_.pop();        
  }    
}

template <typename T, typename Comparator>
bool QueueWithExtremal<T, Comparator>::empty() const {
  return head_.empty() && tail_.empty();
}