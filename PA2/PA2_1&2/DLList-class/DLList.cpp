// implementation of the DLList class
#include <stdexcept>
#include "DLList.h"

// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error {
  explicit EmptyDLList(char const* msg=nullptr): runtime_error(msg) {}
};

struct OutofRangeDLList : public std::runtime_error {
  explicit OutofRangeDLList(char const* msg=nullptr): runtime_error(msg) {}
};

// copy constructor
DLList::DLList(const DLList& dll)
{
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  if (!dll.is_empty()) {
    DLListNode* curr = dll.header.next;
    int obj;
    while (curr != &dll.trailer) { //?
      this->insert_last(curr->obj);
      curr = curr->next;
    }
  }
}

// move constructor
DLList::DLList(DLList&& dll)
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
DLList& DLList::operator=(const DLList& dll)
{
  if (this != &dll) {
    DLListNode* prev_node = &header;
    DLListNode* node = header.next;
    while (node != &trailer) {
      prev_node = node;
      node = node->next;
      delete prev_node;
    }
  }
  header.next = &trailer;
  trailer.prev = &header;
  if (!dll.is_empty()) {
    DLListNode* curr = dll.header.next;
    int obj;
    while (curr != &dll.trailer) {
      this->insert_last(curr->obj);
      curr = curr->next;
    }
  }
  return *this;
}

// move assignment operator
DLList& DLList::operator=(DLList&& dll)
{
  if (this != &dll) {
    DLListNode* prev_node;
    DLListNode* node = header.next;
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
DLList::~DLList()
{
  DLListNode* prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// insert a new object as the first one
void DLList::insert_first(int obj)
{ 
  DLListNode *newNode = new DLListNode(obj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}

// insert a new object as the last one
void DLList::insert_last(int obj)
{
  DLListNode *newNode = new DLListNode(obj, trailer.prev, &trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first node from the list
int DLList::remove_first()
{ 
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List");
  DLListNode *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  int obj = node->obj;
  delete node;
  return obj;
}

// remove the last node from the list
int DLList::remove_last()
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List");
  DLListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}

// return the first object (do not remove)
int DLList::first() const
{ 
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List");
  return header.next->obj;
}

// return the last object (do not remove)
int DLList::last() const
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List");
  return trailer.prev->obj;
}

// insert a new node after the node p
void DLList::insert_after(DLListNode &p, int obj)
{
  if (is_empty()) {
    throw EmptyDLList("Empty Doubly Linked List.");
  }
  else if (p.prev->next == &trailer) {
    throw OutofRangeDLList("Out of bounds.");
  }
  else {
    DLListNode* node = new DLListNode(obj, &p, p.next);
    p.next = node;
    node->next->prev = node;
  }
}

// insert a new node before the node p
void DLList::insert_before(DLListNode &p, int obj)
{
  if (is_empty()) {
    throw EmptyDLList("Empty Doubly Linked List.");
  }
  else if (p.next->prev == &header) {
    throw OutofRangeDLList("Out of bounds.");
  }
  DLListNode* node = new DLListNode(obj, p.prev, &p);
  p.prev = node;
  node->prev->next = node;
}

// remove the node after the node p
int DLList::remove_after(DLListNode &p)
{
  if (is_empty()) {
    throw EmptyDLList("Empty Doubly Linked List");
  }
  else if (p.next == &trailer) {
    throw OutofRangeDLList("Out of bounds.");
  }
  else {
    p.next = p.next->next;
    int obj = p.next->prev->obj;
    delete p.next->prev;
    p.next->prev = &p;
    return obj;
  }
}

// remove the node before the node p
int DLList::remove_before(DLListNode &p)
{
  if (is_empty()) {
    throw EmptyDLList("Empty Doubly Linked List");
  }
  else if (p.prev == &header) {
    throw OutofRangeDLList("Out of bounds.");
  }
  else {
    p.prev = p.prev->prev;
    int obj = p.prev->next->obj;
    delete p.prev->next;
    p.prev->next = &p;
    return obj;
  }
}

// output operator
ostream& operator<<(ostream& out, const DLList& dll)
{  
  DLListNode* temp = dll.first_node();
  int obj;
  while (temp != dll.after_last_node()) {
    out << temp->obj << " ";
    temp = temp->next;
  }
  return out;
}
