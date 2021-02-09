// testing the templated class DLList
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include "MinQueue.h"
using namespace std;

int main ()
{
  // Constructing a list
  cout << "Create a new list." << endl;
  MinQueue<string> mq;
  cout << "list: ";
  mq.printItems();
  cout << endl;
  cout << "list size: " << mq.size() << endl << endl;

  // Testing Enqueue
  cout << "Testing Enqueue function by adding 10 nodes value 10, 20, 30, ... , 100." << endl;
  for (int i = 10; i <= 100; i += 10) {
    stringstream ss;
    ss << i;
    mq.enqueue(ss.str());
  }
  cout << "list: ";
  mq.printItems();
  cout << endl;
  cout << "list size: " << mq.size() << endl << endl;

  // Constructing another list
  cout << "creating another new list (empty)." << endl;
  MinQueue<string> mq2;
  cout << "list2: ";
  mq2.printItems();
  cout << endl;
  cout << "list size: " << mq2.size() << endl << endl;

  // Testing Dequeue
  cout << "Testing Dequeue function." << endl;
  cout << "Testing with list1." << endl;
  try {
    cout << "Dequeue 3 nodes." << endl;
    cout << "Dequeue first item " << mq.dequeue() << endl;
    cout << "Dequeue second item " << mq.dequeue() << endl;
    cout << "Dequeue third item " << mq.dequeue() << endl;
    cout << "list: ";
    mq.printItems();
    cout << endl;
    cout << "list size: " << mq.size() << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }
  try {
    cout << "Testing with list2." << endl;
    cout << "Dequeue" << mq2.dequeue() << endl << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  // Testing empty function
  cout << "Testing is empty function." << endl;
  cout << "Testing with list1." << endl;
  try {
    cout << "list size: " << mq.size() << endl;
    cout << "Is empty?: " << mq.is_empty();
    cout << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }
  cout << "Testing with list2." << endl;
  try {
    cout << "list2 size: " << mq2.size() << endl;
    cout << "Is empty?: " << mq2.is_empty();
    cout << endl << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  // Testing min function
  cout << "Testing min function." << endl;
  // the following test case does not work correctly. The output should be 40 when in reality it output 100
  cout << "Testing with list1." << endl;
  try {
    cout << "list size: " << mq.size() << endl;
    mq.printItems();
    cout << endl;
    cout << "Min: " << mq.min();
    cout << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }
  cout << "Testing with list2." << endl;
  try {
    cout << "list2 size: " << mq2.size() << endl;
    mq2.printItems();
    cout << endl;
    cout << "Min: " << mq2.min();
    cout << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }
  // the following test case works correctly. It outputs one and the min
  cout << "Testing with list1 again with more values." << endl;
  try {
    stringstream ss;
    ss << 15;
    mq.enqueue(ss.str());
    stringstream ss2;
    ss2 << 5;
    mq.enqueue(ss2.str());
    stringstream ss3;
    ss3 << 1;
    mq.enqueue(ss3.str());
    stringstream ss4;
    ss4 << 55;
    mq.enqueue(ss4.str());
    cout << "list size: " << mq.size() << endl;
    mq.printItems();
    cout << endl;
    cout << "Min: " << mq.min();
    cout << endl;
  }
  catch (exception &test) {
    cout << test.what() << endl;
  }

  return 0;
}
