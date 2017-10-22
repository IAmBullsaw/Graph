#include <iostream>
#include "graph.h"
#include <fstream>
#include <sstream>
#include <functional>
using namespace std;

Graph::Graph()
  :size{0},nodes{}
{}

Graph::~Graph() {
  for (Node* n: nodes) {
    delete n;
    n = nullptr;
  }
}

void Graph::add_node(Node*  n) {
  bool add{true};
  for (Node* node: nodes) {
    if (*node == *n) {
      add = false;
      break;
    }
  }
  if (add) {
    nodes.push_back(n);
    ++size;
  }
}

unsigned Graph::get_size() const {
  return size;
}

void Graph::print() const {
  for (Node* const node: nodes) {
    cout << *node << endl;
  }
}

void Graph::for_each_node(std::function<void(Node*)> fun) {
  for (Node* node: nodes){
    fun(node);
  }
}

vector<Node*> Graph::get_nodes() const {
  return nodes;
}

Node* Graph::get_node_by_name(string name) {
  for (Node* node: nodes) {
    if (node->get_name() == name) {
      return node;
    }
  }
  throw out_of_range("No node with name '" + name + "'.");
}

void Graph::load_from_file(string const& filename) {
  fstream f{filename,fstream::in};
  string line;
  stringstream ss;
  while (getline(f,line)) {
    string name;
    ss.str(line);
    ss >> name;
    if (name == "#") {continue;} // comment in file
    else if (name == "NODES") {
      load_nodes(f,name);
    }
    else if (name == "CONNECTIONS") {
      connect_nodes(f,ss,name,line);
    }
    ss.clear();
  }
  f.close();
}

void Graph::load_nodes(fstream & f, string name){
  while (getline(f, name)) {
    if (name == "STOP") {
      break;
    } else if (name == "#") {
      continue;
    } else {
      add_node(new Node(name));
    }
  }
}

void Graph::connect_nodes(fstream & f, stringstream & ss, string name, string line){
  while (getline(f, line)) {
    ss.clear();
    ss.str(line);
    name.clear();
    ss >> name;
    bool mutual{false};
    int cost{0};

    if (name == "STOP") { break;}
    else if (name == "#") {continue;}
    else if (name == "m") {
      ss >> name; // Update to actual name
      mutual = true;
    }
    Node* n = get_node_by_name(name);
    while (ss >> name >> cost) {
      if (mutual) {
        Node* c = get_node_by_name(name);
        n->mutual_connect(c, cost);
      } else {
        n->connect(get_node_by_name(name), cost);
      }
    }
  }
}

int Graph::get_cost(std::string const& n1, std::string const& n2) {
  Node* n = get_node_by_name(n1);
  Node* o = get_node_by_name(n2);
  return n->get_cost(o);
}
