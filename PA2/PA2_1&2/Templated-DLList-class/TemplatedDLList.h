// header file for the templated DLList
#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H
#include <stdexcept>
#include <iostream>
using namespace std;

// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error {
  explicit EmptyDLList(char const* msg=nullptr): runtime_error(msg) {}
};

struct OutofRangeDLList : public std::runtime_error {
  explicit OutofRangeDLList(char const* msg=nullptr): runtime_error(msg) {}
};

template <typename T> class DLList; // class declaration

// doubly linked list node
template <typename T> 
struct DLListNode {
  T obj;
  DLListNode<T> *prev, *next;
  // constructor
  DLListNode(T e={}, DLListNode<T> *p = nullptr, DLListNode<T> *n = nullptr)
    : obj(e), prev(p), next(n) {}
};

// doubly linked list class
template <typename T> 
class DLList {
private:
  DLListNode<T> header, trailer;
public:
  DLList() : header(T()), trailer(T()) // default constructor
  { header.next = &trailer; trailer.prev = &header; }
  DLList(const DLList& dll); // copy constructor
  DLList(DLList&& dll); // move constructor
  ~DLList(); // destructor
  DLList<T>& operator=(const DLList<T>& dll); // copy assignment operator
  DLList<T>& operator=(DLList<T>&& dll); // move assignment operator
  // return the pointer to the first node
  DLListNode<T> *first_node() const { return header.next; } 
  // return the pointer to the trailer
  const DLListNode<T> *after_last_node() const { return &trailer; }
  // return if the list is empty
  bool is_empty() const { return header.next == &trailer; }
  T first() const; // return the first object
  T last() const; // return the last object
  void insert_first(T obj); // insert to the first node
  T remove_first(); // remove the first node
  void insert_last(T obj); // insert to the last node
  T remove_last(); // remove the last node
  void insert_after(DLListNode<T> &p, T obj); //
  void insert_before(DLListNode<T> &p, T obj); //
  T remove_after(DLListNode<T> &p);
  T remove_before(DLListNode<T> &p);
};

// output operator
template <typename T>
ostream& operator<<(ostream& out, const DLList<T>& dll);

// copy constructor
template <typename T>
DLList<T>::DLList(const DLList& dll)
{
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  if (!dll.is_empty()) {
    DLListNode<T>* curr = dll.header.next;
    T obj;
    while (curr != &dll.trailer) { //?
      this->insert_last(curr->obj);
      curr = curr->next;
    }
  }
}

// move constructor
template <typename T>
DLList<T>::DLList(DLList&& dll)
{
  if (dll.is_empty()) {
    throw EmptyDLList("Empty Doubly Linked List");
    header.next = &trailer;
    trailer.prev = &header;
  }
  else {
    header.next = dll.header.next;
    header.next->prev = &header;
    trailer.prev = dll.trailer.prev;
    trailer.prev->next = &trailer;
    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
  }
}

// copy assignment operator
template <typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& dll)
{
  if (this != &dll) {
    DLListNode<T>* prev_node = &header;
    DLListNode<T>* node = header.next;
    while (node != &trailer) {
      prev_node = node;
      node = node->next;
      delete prev_node;
    }
  }
  header.next = &trailer;
  trailer.prev = &header;
  if (!dll.is_empty()) {
    DLListNode<T>* curr = dll.header.next;
    T obj;
    while (curr != &dll.trailer) {
      this->insert_last(curr->obj);
      curr = curr->next;
    }
  }
  return *this;
}

// move assignment operator
template <typename T>
DLList<T>& DLList<T>::operator=(DLList<T>&& dll)
{
  if (this != &dll) {
    DLListNode<T>* prev_node;
    DLListNode<T>* node = header.next;
    while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
    }
    if (dll.is_empty()) {
      throw EmptyDLList("Empty Doubly Linked List");
      header.next = &trailer;
      trailer.prev = &header;
    }
    else {
      header.next = dll.header.next;
      header.next->prev = &header;
      trailer.prev = dll.trailer.prev;
      trailer.prev->next = &trailer;
      dll.header.next = &dll.trailer;
      dll.trailer.prev = &dll.header;
    }
  }
  return *this;
}

// destructor
template <typename T>
DLList<T>::~DLList()
{
  DLListNode<T>* prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// insert a new object as the first one
template <typename T>
void DLList<T>::insert_first(T obj)
{ 
  DLListNode<T> *newNode = new DLListNode<T>(obj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}

// insert a new object as the last one
template <typename T>
void DLList<T>::insert_last(T obj)
{
  DLListNode<T> *newNode = new DLListNode<T>(obj, trailer.prev, &trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first node from the list
template <typename T>
T DLList<T>::remove_first()
{ 
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List");
  DLListNode<T> *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  T obj = node->obj;
  delete node;
  return obj;
}

// remove the last node from the list
template <typename T>
T DLList<T>::remove_last()
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List");
  DLListNode<T> *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  T obj = node->obj;
  delete node;
  return obj;
}

// return the first object (do not remove)
template <typename T>
T DLList<T>::first() const
{ 
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List");
  return header.next->obj;
}

// return the last object (do not remove)
template <typename T>
T DLList<T>::last() const
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List");
  return trailer.prev->obj;
}

// insert a new node after the node p
template <typename T>
void DLList<T>::insert_after(DLListNode<T> &p, T obj)
{
  if (is_empty()) {
    throw EmptyDLList("Empty Doubly Linked List.");
  }
  else if (p.prev->next == &trailer) {
    throw OutofRangeDLList("Out of bounds.");
  }
  else {
    DLListNode<T>* node = new DLListNode<T>(obj, &p, p.next);
    p.next = node;
    node->next->prev = node;
  }
}

// insert a new node before the node p
template <typename T>
void DLList<T>::insert_before(DLListNode<T> &p, T obj)
{
  if (is_empty()) {
    throw EmptyDLList("Empty Doubly Linked List.");
  }
  else if (p.next->prev == &header) {
    throw OutofRangeDLList("Out of bounds.");
  }
  DLListNode<T>* node = new DLListNode<T>(obj, p.prev, &p);
  p.prev = node;
  node->prev->next = node;
}

// remove the node after the node p
template <typename T>
T DLList<T>::remove_after(DLListNode<T> &p)
{
  if (is_empty()) {
    throw EmptyDLList("Empty Doubly Linked List");
  }
  else if (p.next == &trailer) {
    throw OutofRangeDLList("Out of bounds.");
  }
  else {
    p.next = p.next->next;
    T obj = p.next->prev->obj;
    delete p.next->prev;
    p.next->prev = &p;
    return obj;
  }
}

// remove the node before the node p
template <typename T>
T DLList<T>::remove_before(DLListNode<T> &p)
{
  if (is_empty()) {
    throw EmptyDLList("Empty Doubly Linked List");
  }
  else if (p.prev == &header) {
    throw OutofRangeDLList("Out of bounds.");
  }
  else {
    p.prev = p.prev->prev;
    T obj = p.prev->next->obj;
    delete p.prev->next;
    p.prev->next = &p;
    return obj;
  }
}

// output operator
template <typename T>
ostream& operator<<(ostream& out, const DLList<T>& dll)
{  
  DLListNode<T>* temp = dll.first_node();
  T obj;
  while (temp != dll.after_last_node()) {
    out << temp->obj << " ";
    temp = temp->next;
  }
  return out;
}

#endif
