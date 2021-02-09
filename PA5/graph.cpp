#include "graph.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// to be implemented
void Graph::buildGraph(ifstream &input) {
    string line, val;
    bool vertex;
    int source, index = 0;
    while(getline(input, line)) {
        stringstream nums(line);
        vertex = true;
        while(nums >> val) {
            source = stoi(val);
            if (source != -1) {
                if(vertex) {
                    node_list.push_back(Vertex(source));
                    vertex = false;
                }
                else {
                    adj_list.push_back(new list<int>);
                    adj_list[index]->push_back(source);
                }
            }
        }
        index++;
    }
    input.close();
}

void Graph::displayGraph() {
    for(int i = 0; i < node_list.size(); i++) {
        list<int>::iterator it;
        cout << node_list[i].label << " : " ;
        for(it = adj_list.at(i)->begin(); it != adj_list.at(i)->end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
} 