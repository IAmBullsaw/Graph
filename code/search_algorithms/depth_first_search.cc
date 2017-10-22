#include "../node/node.h"
#include "../graph/graph.h"
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

string get_filename(char* const argv[]) {
  string filename{argv[1]};
  return filename;
}

int main(int argc, char* argv[]) {
  Graph g{};
  string start_node_name{};
  string goal_node_name{};
  if (argc > 3) {
    g.load_from_file(get_filename(argv));
    start_node_name = argv[2];
    goal_node_name = argv[3];
  }
  else {
    string name{argv[0]};
    cerr << "-> Usage:\n" + name + " path-to-graph.txt start-node-name goal-node-name" << endl;
    return 1;
  }

  // Breadth first search YO
  Node* start{g.get_node_by_name(start_node_name)};
  Node* goal{g.get_node_by_name(goal_node_name)};
  bool found{false};
  stack<Node*> stack;
  set<Node*> visited;
  visited.insert(start);
  stack.push(start);

  while(!stack.empty()) {
    Node* current = stack.top();
    stack.pop();
    cout << "-> visiting " << *current << endl;
    if (current != goal) {
      vector<pair<Node*,int>> list;
      for (pair<Node*,int> arc :current->get_connections()) {
        auto p{visited.insert(arc.first)};
        if (p.second) {
          list.push_back(arc);
        }
      }
      sort(list.begin(),list.end(),[](pair<Node*,int> a,pair<Node*,int> b){
          return a.second < b.second;
        });
      for (auto it = list.rbegin();it != list.rend(); ++it) {
        stack.push(it->first);
      }
    } else {
      found = true;
      cout << "-> Found node: " << *current << "!" <<endl;
      break;
    }
  }
  if (!found)
    cout << "-> Couldn't find goal node " << *goal <<" :(" << endl;

  return 0;
}
