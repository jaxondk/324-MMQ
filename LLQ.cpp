//
// Created by Jaxon Keeler on 10/19/17.
//

#include "LLQ.h"

LLQ::LLQ()
{
  head = nullptr;
  tail = nullptr;
}

LLQ::~LLQ()
{
  Node* current = head;
  while(current)
  {
    Node* next = current->next;
    delete current;
    current = next;
  }
}

void LLQ::enqueue(int item)
{
  if(head == nullptr)
  {
    head = new Node(item);
    tail = head;
  }
  else
  {
    tail = tail->next = new Node(item);
  }
}

int LLQ::dequeue()
{
  int item = head->data;
  Node* current = head;
  head = head->next;
  delete current;

  return item;
}