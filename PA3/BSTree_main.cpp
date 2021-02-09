#include <iostream>
#include <fstream>
#include "BSTree.h"

BSTree read_file(string file_name)
{
  /*
    open the file and use the input operator (operator>>)
    to construct a new tree
  */
    
  BSTree new_tree;
  ifstream infile(file_name); 
  // use >> to read in to new_tree
  infile >> new_tree;
  return new_tree;
}

int main()
{
  // Testing purposes
  cout << "-------------------------------------------" << endl;
  cout << "The following are the testing purposes." << endl;
  cout << "-------------------------------------------" << endl;
  cout << "I will be creating two trees. The insert function will be tested." << endl;
  BSTree treeOne;
  treeOne.insert(100);
  treeOne.insert(68);
  treeOne.insert(46);
  treeOne.insert(13);
  treeOne.insert(74);
  treeOne.insert(86);
  treeOne.insert(175);
  treeOne.insert(124);
  treeOne.insert(148);
  treeOne.insert(187);
  treeOne.insert(200);
  treeOne.insert(199);
  treeOne.insert(1);
  cout << "First tree:" << endl;
  treeOne.print_level_by_level(cout) << endl << endl;

  BSTree treeTwo;
  treeTwo.insert(67);
  treeTwo.insert(15);
  treeTwo.insert(87);
  treeTwo.insert(2);
  treeTwo.insert(98);
  treeTwo.insert(76);
  treeTwo.insert(23);
  treeTwo.insert(65);
  treeTwo.insert(4);
  cout << "Second tree:" << endl;
  treeTwo.print_level_by_level(cout) << endl << endl;

  // test copy constructor
  cout << "-------------------------------------------" << endl;
  cout << "Testing copy constructor." << endl;
  cout << "-------------------------------------------" << endl;
  BSTree copyOne(treeOne);
  cout << copyOne << endl << endl;

  // test copy assignment
  cout << "-------------------------------------------" << endl;
  cout << "Testing copy assignment." << endl;
  cout << "-------------------------------------------" << endl;
  copyOne = treeTwo;
  cout << copyOne << endl << endl;

  // testing move constructor
  cout << "-------------------------------------------" << endl;
  cout << "Testing move constructor." << endl;
  cout << "-------------------------------------------" << endl;
  BSTree treeThree(move(treeOne));
  cout << treeThree << endl << endl;
  
  // testing move assignment
  cout << "-------------------------------------------" << endl;
  cout << "Teesting move assingment." << endl;
  cout << "-------------------------------------------" << endl;
  BSTree moveTree;
  moveTree = move(treeTwo);
  cout << moveTree << endl << endl; 

  // testing search
  cout << "-------------------------------------------" << endl;
  cout << "Testing search function." << endl;
  cout << "-------------------------------------------" << endl;
  cout << "With value that works." << endl;
  try {
    Node* value = moveTree.search(98);
    if (value != nullptr) {
      cout << *value << " found!" << endl << endl;
    }
  } 
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }
  cout << "Now with value that does not work." << endl;
  try {
    Node* value = moveTree.search(9823512);
    if (value != nullptr) {
      cout << *value << " found!" << endl << endl;
    }
  } 
  catch (exception &test) {
    cout << test.what() << endl << endl;
  }

  // testing updated search
  cout << "-------------------------------------------" << endl;
  cout << "Testing updated search." << endl;
  cout << "-------------------------------------------" << endl;
  cout << moveTree << endl;
  moveTree.update_search_times();
  cout << moveTree << endl << endl;

  // testing in-order
  cout << "-------------------------------------------" << endl;
  cout << "Testing in-order." << endl;
  cout << "-------------------------------------------" << endl;
  moveTree.inorder(cout) << endl << endl;
  treeThree.inorder(cout) << endl << endl;
  // done with personal testing

  cout << "-------------------------------------------" << endl;
  cout << "Provided testing." << endl;
  cout << "-------------------------------------------" << endl;
  // the following file was created to gather data points
  // ofstream myfile;
  // myfile.open ("datapoints.csv");
  for(int i = 1; i <= 12; i++) {
    string dir= "data-files/"+std::to_string(i);
    BSTree l = read_file(dir+"l");
    cout << "average search time linear " << i << " " << l.get_average_search_time() << endl;
    BSTree p = read_file(dir+"p");
    cout << "average search time perfect "<< i << " " << p.get_average_search_time() << endl;
    BSTree r = read_file(dir+"r");
    cout << "average search time random "<< i << " " << r.get_average_search_time() << endl;
    cout << "Size: " << r.get_size() << endl;
    if(i <= 4) {
      cout << "prefect tree " << i << endl << p;
      cout << "linear tree " << i << endl << l;
      cout << "random tree " << i << endl << r;
    }
    // testing output for the the 12 input files
    if (i == 12) {
      p.inorder(cout);
      r.inorder(cout);
    }
    // for data points
    //myfile << r.get_size() << "," << l.get_average_search_time() << "," << p.get_average_search_time() << "," << r.get_average_search_time() << endl;
  }
  //myfile.close();
  return 0;
}