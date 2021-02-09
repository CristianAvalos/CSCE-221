// topological sort
#include "graph.h"
#include <iostream>
#include <stdexcept>
using namespace std;

struct GraphCycle : public std::runtime_error {
  explicit GraphCycle(char const* msg=nullptr): runtime_error(msg) {}
};

void Graph::compute_indegree() {
  for (int i = 0; i < node_list.size(); i++) {
    int count = 0;
    for (int j = 0; j < node_list.size(); j++) {
      list<int>::iterator it;
      for(it = adj_list.at(j)->begin(); it != adj_list.at(j)->end(); it++) {
        if (node_list[i].label == *it) {
          count++;
        }
      }
    }
    node_list[i].indegree = count;
    count = 0;
  }
}

void Graph::topological_sort() {
  queue<Vertex> que;
  for(int i = 0; i < node_list.size(); i++) {
    if (node_list[i].indegree == 0) {
      que.push(node_list[i]);
    }
  }
  int count = 0;
  while(!que.empty()) {
    Vertex val = que.front();
    que.pop();
    val.top_num = ++count;
    topSort.push_back(val);
    list<int>::iterator it;
    for(it = adj_list.at(val.label - 1)->begin(); it != adj_list.at(val.label - 1)->end(); it++) {
      if (--node_list[*it - 1].indegree == 0) {
        que.push(node_list[*it - 1]);
      }
    }
  }
  if (count != node_list.size()) {
    throw GraphCycle("There is a cycle in the graph. Top sort cannot work.");
  }
}

void Graph::print_top_sort() {
  cout << "Top Sort: ";
  for(int i = 0; i < topSort.size(); i++) {
    cout << topSort[i].label << " ";
  }
  cout << endl;
}
