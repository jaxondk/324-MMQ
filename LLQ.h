//
// Created by Jaxon Keeler on 10/19/17.
//

#ifndef MEMMAPPEDQ_LLQ_H
#define MEMMAPPEDQ_LLQ_H

#include "IQueue.h"

class LLQ : public IQueue
{
  struct Node
  {
    Node(int d) {data = d; next = nullptr;}
    int data;
    Node* next;
  };

public:
  LLQ();
  ~LLQ();
  void enqueue(int item) override; //just annotates the f(x) as overriding a parent's virtual f(x)
  int dequeue() override;


private:
  Node *head;
  Node *tail;

  bool isEmpty() override { return head == nullptr; }

};

#endif //MEMMAPPEDQ_LLQ_H
