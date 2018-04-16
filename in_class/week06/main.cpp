#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

typedef vector<vector<int> > AdjacencyList;


void displayAdjList(vector<vector<int> > graph){
 for (int i = 0; i < graph.size(); i++){
     cout << "Node " << i << endl;
     for (auto edge : graph.at(i)){

     }
 }
}

int main(){
    AdjacencyList graph = {{0,1,2}, {1,0,4}, {2,0,4}, {3,2,4,5}, {4,1,2,3}, {5,3,6}, {6,5}};
    displayAdjList(graph);
  return 0;
}
