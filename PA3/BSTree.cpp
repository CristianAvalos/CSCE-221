#ifndef BSTREE_CPP
#define BSTREE_CPP
#include <stdexcept>
#include <fstream>
#include <string>
#include "BSTree.h"
using namespace std;

struct EmptyTree : public std::runtime_error {
  explicit EmptyTree(char const* msg=nullptr): runtime_error(msg) {}
};

// input / output operators
ostream& operator<<(ostream& out, BSTree& tree)
{
  tree.print_level_by_level(out);
  return out;
}

ostream& operator<<(ostream& out, Node node)
{
  return out << "( " << node.value << ", "
	     << node.search_time << " )";
}

istream& operator>>(istream& in, BSTree& tree)
{
  /*
    take input from the in stream, and build your tree
    input will look like
    4 
    2 
    6 
    1 
    3 
    5 
    7
  */
  int next;
  while(in >> next) 
    tree.insert(next);
  return in;
}

///////////// Implementation To Do ////////////////////

// copy constructor
BSTree::BSTree(const BSTree& other)
{
  /*
    complete this copy constructor
    make sure when copying nodes to copy
    the value and left and right children
  */
  if (other.root == nullptr) {
    this->root = nullptr;
  }
  else if (other.root->left == nullptr && other.root->right == nullptr) {
    this->root = new Node(other.root->value);
    this->size = other.size;
  }
  else {
    this->root = new Node(other.root->value);
    this->size = other.size;
    copy_helper(this->root, other.root);
  }
}

// move constructor
BSTree::BSTree(BSTree&& other)
{
  this->root = other.root;
  this->size = other.size;
  other.root = nullptr;
  other.size = 0;
}

//copy assignment
BSTree& BSTree::operator=(const BSTree& other)
{
  /*
    complete this assignment operator
    make sure when copying nodes to copy
    the value
    and left and right children
    not important for this part but will be used later
  */
  if (this != &other) {
    clear(this->root);
    this->root = nullptr;
    this->size = 0;
  }
  if(other.root == nullptr) {
    this->root = nullptr;
  }
  else if (other.root->left == nullptr && other.root->right == nullptr) {
    this->root = new Node(other.root->value);
    this->size = other.size;
  }
  else{
    this->root = new Node(other.root->value);
    this->size = other.size;
    copy_helper(this->root, other.root);
  }
  return *this;
}

// move assignment
BSTree& BSTree::operator=(BSTree&& other) /////////////////
{
  if (this != &other) {
    clear(this->root);
    this->root = nullptr;
    this->size = 0;
    if (other.root == nullptr && other.size == 0) {
      throw EmptyTree("Empty Tree");
      this->clear(this->root);
      this->root = nullptr;
      this->size = 0;
    }
    this->root = other.root;
    this->size = other.size;
    other.root = nullptr;
    other.size = 0;
  }
  return *this;
}

// destructor
BSTree::~BSTree()
{
  // use a helper function
  clear(root);
  this->root = nullptr;
  this->size = 0;
}

// clear helper
void BSTree::clear(Node* root) {
  if (root) {
    if (root->left) {
      clear(root->left);
    }
    if (root->right) {
      clear(root->right);
    }
    delete root;
  }
}

// recursive
void BSTree::copy_helper(Node* copy_to, const Node* copy_from) const
{
  if(copy_from == nullptr)
    return;

  if(copy_from->left != nullptr) {
    copy_to->left = new Node(*copy_from->left);
    copy_helper(copy_to->left, copy_from->left);
  } else {
    copy_to->left = nullptr;
  }

  if(copy_from->right != nullptr) {
    copy_to->right = new Node(*copy_from->right);
    copy_helper(copy_to->right, copy_from->right);
  } else {
    copy_to->right = nullptr;
  }
}


Node* BSTree::insert(int obj)
{
  /*
    insert a node into the tree
    first find where the node should go
    then modify pointers to connect your new node 
  */
  Node* curr = nullptr;
  if (root == nullptr) {
    Node* newNode = new Node(obj);
    this->root = newNode;
    this->root->search_time = 1;
    this->size++;
  }
  else {
    int time = 2;
    curr = insertHelper(this->root, obj, time);
  }
  return curr;
}

Node* BSTree::insertHelper(Node* curr, int obj, int time) {
  if (curr->value >= obj) {
    if(curr->left == nullptr ){
        curr->left = new Node(obj);
        curr->left->search_time = time;
        this->size++;
        return curr->left;
    }
    else {
      time++;
      insertHelper(curr->left, obj, time);
    }
  }
  else {
    if(curr->right == nullptr) {
      curr->right = new Node(obj);
      curr->right->search_time = time;
      this->size++;
      return curr->right;
    }
    else {
      time++;
      insertHelper(curr->right, obj, time);
    }
  }
}

Node* BSTree::search(int obj)
{
  /*
    recursivly search down the tree to find the node that contains obj
    if you dont find anything return null
  */
  return searchHelper(root, obj);
}

Node* BSTree::searchHelper(Node* root, int obj) {
  if (root == nullptr) {
    throw EmptyTree("Item not found.");
  } 
  if (root->value == obj) {
    return root;
  }
  if (root->value > obj) {
    return searchHelper(root->left, obj);
  }
  return searchHelper(root->right, obj);
}

void BSTree::update_search_times()
{
  /*
    do a BFS or DFS of your tree and update the searchtimes of all nodes
  */
  if(this->root != nullptr) {
    searchTimeHelp(this->root, 1);
  }
  else{
    throw EmptyTree("Empty Tree.");
  }
}

void BSTree::searchTimeHelp(Node* node, int val) {
  node->search_time = val;
  if(node->left != nullptr) {
    searchTimeHelp(node->left, val + 1);
  }
  if(node->right != nullptr) {
    searchTimeHelp(node->right, val + 1);
  }
}

ostream& BSTree::inorder(ostream& out)
{
  /*
    print your nodes in infix order
    if our tree looks like 

    4
    2 6
    1 3 5 7

    we should get

    1 2 3 4 5 6 7 
  */
  if (this->size < 16) {
    inorderHelper(this->root, out);
  }
  else {
    ofstream myfile;
    myfile.open ("treeResult.txt");
    inorderHelper(this->root, myfile);
    myfile.close();
  }
  return out;
}

// inorderHelper
void BSTree::inorderHelper(Node* root, ostream& out) {
  if (root != nullptr) {
    if (root->left) {
      inorderHelper(root->left, out);
    }
    pretty_print_node(out, root);
    if (root->right) {
      inorderHelper(root->right, out);
    }
  }
}

// implemented
void BSTree::pretty_print_node(ostream& out,Node* node)
{
  out << node->value << "["<<node->search_time<<"] ";
}

// implemented
ostream& BSTree::print_level_by_level(ostream& out)
{
  /*
    print the tree using a BFS 
    output should look like this if we dont have a full tree

    4
    2 6
    1 X 5 7
    X X X X X X X 9

    it will be helpfull to do this part iterativly, 
    so do the BFS with the std stack data structure.

    it may also be helpfull to put the entire tree into a vector 
    (probably google this if you dont know how to do it)
  */

  if(root == nullptr)
    return out;

  bool hasNodes = true;
  vector<Node*> current_level;
  vector<Node*> next_level;
  current_level.push_back(root);
  while(hasNodes) {
    hasNodes = false;
    for(auto node : current_level) {
      if(node != nullptr) {
	pretty_print_node(out, node);
	if(node->left != nullptr)
	  hasNodes = true;
	if(node->right != nullptr)
	  hasNodes = true;
	
	next_level.push_back(node->left);
	next_level.push_back(node->right);
      } else {
	out << "X ";
	next_level.push_back(nullptr);
	next_level.push_back(nullptr);
      }
    }
    out << endl;
    current_level.clear();
    current_level = next_level;
    next_level.clear();
  }
  return out;
}

// implemented
int BSTree::get_total_search_time(Node* node)
{
  if(node == nullptr)
    return 0;

  return get_total_search_time(node->left) +
    get_total_search_time(node->right) + node->search_time;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if(total_search_time == 0)
    return -1;
	
  return ((float)total_search_time)/size;
}

#endif