// testing the templated class DLList
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include "TemplatedDLList.h"
using namespace std;

int main ()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList<string> dll;
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_last(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_first(ss.str());
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Copy to a new list" << endl;
  DLList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  cout << "Assign to another new list" << endl;
  DLList<string> dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;
  
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;
  cout << endl;

  ///////////////////////////////////////////////
  // more testing...
  ///////////////////////////////////////////////
  // testing is empty
  ///////////////////////////////////////////////
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing empty function." << endl;
  cout << "///////////////////////////////////////////////" << endl;
  cout << "list1: " << dll << endl;
  cout << "list1: " << dll.is_empty() << endl;
  cout << "list3: " << dll3 << endl;
  cout << "list3: " << dll3.is_empty() << endl << endl;

  ///////////////////////////////////////////////
  // testing insert first
  ///////////////////////////////////////////////
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing insert first/last functions." << endl;
  cout << "///////////////////////////////////////////////" << endl;
  cout << "list2: " << dll2 << endl;
  cout << "testing inserting first." << endl;
  stringstream ss;
  ss << 5;
  dll2.insert_first(ss.str());
  cout << "list2: " << dll2 << endl;
  cout << "testing inserting last" << endl;
  stringstream ss2;
  ss2 << 105;
  dll2.insert_last(ss2.str());
  cout << "list2: " << dll2 << endl << endl;

  cout << "Testing insert first/last functions on empty dll." << endl;
  DLList<string> testFL;
  cout << "empty list: " << testFL << endl;
  cout << "inserting fist." << endl;
  stringstream ss3;
  ss3 << 1;
  testFL.insert_first(ss3.str());
  cout << "empty list: " << testFL << endl;
  cout << "inserting last" << endl;
  stringstream ss4;
  ss4 << 2;
  testFL.insert_last(ss4.str());
  cout << "empty list: " << testFL << endl << endl;

  ///////////////////////////////////////////////
  // testing first and last
  ///////////////////////////////////////////////
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing first and last funtion." << endl;
  cout << "///////////////////////////////////////////////" << endl;
  // empty dll
  cout << "Testing first and last on empty dll." << endl;
  cout << "list1: " << dll << endl;
  cout << "list1 first:" << endl;
  try {
    cout << "list1 first: " << dll.first() << endl;
  } 
  catch (exception &test) {
      cout << test.what() << endl;
  }
  cout << "list1 last:" << endl;
  try {
    cout << "list1 last: " << dll.last() << endl << endl;
  } 
  catch (exception &test) {
      cout << test.what() << endl << endl;
  }

  // filled dll
  cout << "Testing on a dll with values." << endl;
  cout << "list2: " << dll2 << endl;
  try {
    cout << "list2 first: " << dll2.first() << endl;
  }
  catch (exception &test) {
      cout << test.what() << endl;
  }
  try {
    cout << "list2 last: " << dll2.last() << endl << endl;
  }
  catch (exception &test) {
      cout << test.what() << endl;
  }

  /////////////////////////////////////////////
  // testing remove first and last
  ///////////////////////////////////////////////
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing remove first/last." << endl;
  cout << "///////////////////////////////////////////////" << endl;
  // dll with values
  cout << "list2: " << dll2 << endl;
  try {
    cout << "removing first." << endl;
    dll2.remove_first();
    cout << "list2: " << dll2 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }
  try {
    cout << "removing last." << endl;
    dll2.remove_last();
    cout << "list2: " << dll2 << endl << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  // dll without values
  cout << "Testing removing first/last from an empty dll." << endl;
  cout << "list1: " << dll << endl;
  try {
    cout << "removing first." << endl;
    dll.remove_first();
    cout << "list1: " << dll << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }
  try {
    cout << "removing last." << endl;
    dll.remove_last();
    cout << "list1: " << dll << endl << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  /////////////////////////////////////////////////
  // testing for insert_after, insert_before
  ///////////////////////////////////////////////
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing insert_after/before function." << endl;
  cout << "///////////////////////////////////////////////" << endl;
  // insert after
  DLList<string> dll4;
  for (int i = 1; i < 9; i++) {
    if (i % 2 == 0) {
      stringstream ss;
      ss << i;
      dll4.insert_last(ss.str());
    }
  }
  cout << "list4: " << dll4 << endl;
  cout << "insert_after first node" << endl;
  DLListNode<string> *test = dll4.first_node();
  try {
    stringstream ss;
    ss << 3;
    dll4.insert_after(*test, ss.str());
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "insert_after in middle" << endl;
  test = test->next->next;
  try {
    stringstream ss;
    ss << 5;
    dll4.insert_after(*test, ss.str());
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "insert_after last node" << endl;
  test = test->next->next->next;
  try {
    stringstream ss;
    ss << 9;
    dll4.insert_after(*test, ss.str());
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }
  cout << "Attempting to insert out of bounds." << endl;
  test = test->next->next;
  try {
    stringstream ss;
    ss << 11;
    dll4.insert_after(*test, ss.str());
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "Attempting to insert after in an empty dll." << endl;
  cout << "list1: " << dll << endl;
  try {
    stringstream ss;
    ss << 5;
    dll.insert_after(*test, ss.str());
    cout << "list1: " << dll << endl << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  // insert before
  cout << "list4: " << dll4 << endl;
  cout << "insert_before first node" << endl;
  test = dll4.first_node();
  try {
    stringstream ss;
    ss << 1;
    dll4.insert_before(*test, ss.str());
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  cout << "insert in the middle of the node" << endl;
  test = test->next->next->next;
  try {
    stringstream ss;
    ss << -5;
    dll4.insert_before(*test, ss.str());
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  cout << "insert_before last node" << endl;
  test = test->next->next->next;
  try {
    stringstream ss;
    ss << 7;
    dll4.insert_before(*test, ss.str());
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "attempting to insert out of bounds" << endl;
  test = dll4.first_node();
  test = test->prev;
  try {
    stringstream ss;
    ss << 100;
    dll4.insert_before(*test, ss.str());
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "Attempting to insert before in an empty dll." << endl;
  cout << "list1: " << dll << endl;
  try {
    stringstream ss;
    ss << 5;
    dll.insert_before(*test, ss.str());
    cout << "list1: " << dll << endl << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }
  
  //////////////////////////////////////////////////
  // add tests for remove_after, remove_before
  ///////////////////////////////////////////////
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing remove_after/before." << endl;
  cout << "///////////////////////////////////////////////" << endl;
  // remove before
  cout << "list4: " << dll4 << endl;
  test = dll4.first_node();
  cout << "attempting to remove before first node" << endl;
  try {
    dll4.remove_before(*test);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "removing before the second node" << endl;
  test = dll4.first_node();
  test = test->next;
  try {
    dll4.remove_before(*test);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  cout << "removing from the middle of the DLL" << endl;
  test = test->next->next->next;
  try {
    dll4.remove_before(*test);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  cout << "removing before the last node" << endl;
  test = dll4.first_node();
  test = test->next->next->next->next->next->next->next;
  try {
    dll4.remove_before(*test);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "Attempting to remove before in an empty dll." << endl;
  cout << "list1: " << dll << endl;
  try {
    dll.remove_before(*test);
    cout << "list1: " << dll << endl << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  // remove after 
  cout << "testing remove after" << endl;
  cout << "list4: " << dll4 << endl;
  cout << "removing after the first node" << endl;
  test = dll4.first_node();
  try {
    dll4.remove_after(*test);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  cout << "removing from after from one in the middle" << endl;
  test = test->next->next;
  try {
    dll4.remove_after(*test);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  cout << "removing from after the second to last node" << endl;
  test = test->next;
  try {
    dll4.remove_after(*test);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  cout << "attempting to remove a node out of bounds" << endl;
  try {
    dll4.remove_after(*test);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "attempting to remove after in an empty dll." << endl;
  cout << "list1: " << dll << endl;
  try {
    dll.remove_after(*test);
    cout << "list1: " << dll << endl << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  //////////////////////////////////////////////
  // move constructor/ assingment
  ///////////////////////////////////////////////
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing move constructor and assignment:" << endl;
  cout << "///////////////////////////////////////////////" << endl;
  // move constructor
  cout << "testing move constructor." << endl;
  cout << "creating a new empty DLL and moving dll3 into it." << endl;
  cout << "ddl3: " << dll3 << endl;
  cout << "constructing..." << endl;
  DLList<string> moveTest(move(dll3));
  cout << "testDLL: " << moveTest << endl;
  cout << "dll3: " << dll3 << endl << endl;

  // move assignment
  cout << "testing move assignment." << endl;
  cout << "testDLL: " << moveTest << endl;
  cout << "dll3: " << dll3 << endl;
  dll3 = move(moveTest);
  cout << "moving..." << endl;
  cout << "testDLL: " << moveTest << endl;
  cout << "dll3: " << dll3 << endl << endl;
  return 0;
}
