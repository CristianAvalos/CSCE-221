// test of the DLList class
#include <iostream>
#include <cstdlib>
#include "DLList.h"
using namespace std;

int main ()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList dll;
  cout << "list: " << dll << endl << endl;
  
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_last(i);
  }
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_first(i);
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Copy to a new list" << endl;
  DLList dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  cout << "Assign to another new list" << endl;
  DLList dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;
  
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl << endl;

  ///////////////////////////////////////////////
  // more testing...
  ///////////////////////////////////////////////
  // testing is empty
  ///////////////////////////////////////////////
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing empty function:" << endl;
  cout << "///////////////////////////////////////////////" << endl;
  cout << "list1: " << dll << endl;
  cout << "list1: " << dll.is_empty() << endl;
  cout << "list3: " << dll3 << endl;
  cout << "list3: " << dll3.is_empty() << endl << endl;

  ///////////////////////////////////////////////
  // testing insert first and last with values
  ///////////////////////////////////////////////
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing insert first/last functions:" << endl;
  cout << "///////////////////////////////////////////////" << endl;
  cout << "list2: " << dll2 << endl;
  cout << "inserting first." << endl;
  dll2.insert_first(5);
  cout << "list2: " << dll2 << endl;
  cout << "inserting last" << endl;
  dll2.insert_last(105);
  cout << "list2: " << dll2 << endl;
  cout << endl;

  // testing insert first and last without values 
  cout << "Testing insert first/last functions on empty dll." << endl;
  DLList testFL;
  cout << "empty list: " << testFL << endl;
  cout << "inserting fist." << endl;
  testFL.insert_first(1);
  cout << "empty list: " << testFL << endl;
  cout << "inserting last" << endl;
  testFL.insert_last(2);
  cout << "empty list: " << testFL << endl << endl;

  ///////////////////////////////////////////////
  // testing first and last with no values in dll
  ///////////////////////////////////////////////
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing first and last funtion:" << endl;
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
    cout << "list1 last: " << dll.last() << endl;
  } 
  catch (exception &test) {
      cout << test.what() << endl;
  }
  cout << endl;

  // testing first and last with values in dll
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

  ///////////////////////////////////////////////
  // testing remove first and last
  ///////////////////////////////////////////////
  // testing remove first and last with values in dll
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing remove first/last:" << endl;
  cout << "///////////////////////////////////////////////" << endl;
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
    cout << test.what() << endl << endl;
  }

  // testing remove first and last with no values in dll
  cout << "Testing removing first/last from an empty dll." << endl;
  cout << "list1: " << dll << endl;
  cout << "remove first" << endl;
  try {
    dll.remove_first();
    cout << "list1: " << dll << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }
  cout << "remove last" << endl;
  try {
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
  cout << "Testing insert_after/before function:" << endl;
  cout << "///////////////////////////////////////////////" << endl;
  // insert after
  cout << "testing insert after" << endl;
  DLList dll4;
  for (int i = 1; i < 9; i++) {
    if (i % 2 == 0) {
      dll4.insert_last(i);
    }
  }
  cout << "list4: " << dll4 << endl;
  cout << "insert_after first node" << endl;
  DLListNode *test = dll4.first_node();
  try {
    dll4.insert_after(*test, 3);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "insert_after in middle" << endl;
  test = test->next->next;
  try {
    dll4.insert_after(*test, 5);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "insert_after last node" << endl;
  test = test->next->next->next;
  try {
    dll4.insert_after(*test, 9);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "Attempting to insert out of bounds." << endl;
  test = test->next->next;
  try {
    dll4.insert_after(*test, 11);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "Attempting to insert after in an empty dll." << endl;
  cout << "list1: " << dll << endl;
  try {
    dll.insert_after(*test, 5);
    cout << "list1: " << dll << endl << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }
  
  // insert before 
  cout << "testing insert before" << endl;
  cout << "list4: " << dll4 << endl;
  cout << "insert_before first node" << endl;
  test = dll4.first_node();
  try {
    dll4.insert_before(*test, 1);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  cout << "insert in the middle of the node" << endl;
  test = test->next->next->next;
  try {
    dll4.insert_before(*test, -5);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  cout << "insert_before last node" << endl;
  test = test->next->next->next;
  try {
    dll4.insert_before(*test, 7);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  cout << "attempting to insert out of bounds" << endl;
  test = dll4.first_node();
  test = test->prev;
  try {
    dll4.insert_before(*test, 100);
    cout << "list4: " << dll4 << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  cout << "Attempting to insert before in an empty dll." << endl;
  cout << "list1: " << dll << endl;
  try {
    dll.insert_before(*test, 5);
    cout << "list1: " << dll << endl << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }
  
  //////////////////////////////////////////////
  // add tests for remove_after, remove_before
  ///////////////////////////////////////////////
  cout << "///////////////////////////////////////////////" << endl;
  cout << "Testing remove_after/before:" << endl;
  cout << "///////////////////////////////////////////////" << endl;
  // remove before
  cout << "testing remove before" << endl;
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
  DLList moveTest(move(dll3));
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
