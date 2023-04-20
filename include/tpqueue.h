// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
  struct Item {
    T value;
    Item* next;
  } *head;
  Item* add(T value) {
    Item* tmp = new Item;
    tmp->value = value;
    tmp->next = nullptr;
    return tmp;
  }

 public:
  TPQueue() : head(nullptr) {}
  void push(const T& val) {
    Item* temp = new Item;
    temp->value = val;
    if (head == nullptr) {
      head = add(val);
        } else if (head->value.prior >= val.prior) {
      Item* node = head;
      while (node->next != nullptr && node->next->value.prior > val.prior) {
        node = node->next;
      }
      Item* temp = add(val);
      temp->next = node->next;
      node->next = temp;
    } else {
      Item* temp = add(val);
      temp->next = head;
      head = temp;
    }
  }
  T pop() {
    if (head == nullptr) {
      throw std::string("Empty");
    } else {
      Item* tmp = head->next;
      T val = head->value;
      delete head;
      head = tmp;
      return val;
    }
  }
  ~TPQueue() {
    while (head) {
      Item* temp = head->next;
      delete head;
      head = temp;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
