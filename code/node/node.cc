#include "node.h"
#include <string>
#include <map>
using namespace std;
unsigned Node::_id=0;

Node::Node()
  :id{++_id}, name{"N/A"}, connections{}
{}

Node::Node(string const& name)
  :id{++_id}, name{name}, connections{}
{}

Node::~Node() {
  for (pair<Node*,int> p:connections) {
    p.first = nullptr;
  }
}

void Node::connect(Node* const n, int const& cost) {
  connections.emplace(n,cost);
}

void Node::mutual_connect(Node* n, int const& cost) {
  connect(n,cost);
  n->connect(this,cost);
}

unsigned Node::get_id() const {return id;}
std::string Node::get_name() const {return name;}

bool Node::operator==(Node const& n) const {
  return (id == n.get_id() && name == n.get_name());
}

bool Node::operator!=(Node const& n) const {
  return !(*this==n);
}

bool Node::operator<(Node const& n) const {
  return id < n.get_id();
}

bool Node::operator>(Node const& n) const {
  return id > n.get_id();
}

int Node::get_cost(Node* const n) const {
    return connections.at(n);
}

unsigned Node::connections_size() const {
  return connections.size();
}

void Node::update_cost(Node* const n, int const& cost) {
  connections.at(n) = cost;
}

void Node::mutual_update_cost(Node* n, int const& cost) {
  update_cost(n,cost);
  n->update_cost(this,cost);
}

bool Node::connected() const {
  return connections_size() > 0;
}

bool Node::connects_to(Node* const n) const {
  bool answer = false;
  if (!connections.empty()) {
    auto found = connections.find(n);
    if (found != connections.end() ){
      answer = true;
    }
  }
  return answer;
}

std::map<Node*,int> Node::get_connections() const {
  return connections;
}

ostream& operator<<(ostream & os, Node const& n) {
  os << "<Node n." << n.id << ", '" << n.name << "' c. ";
  if (n.connected())
    for (pair<Node*,int> const& o: n.get_connections()) {
      os << o.first->get_name() << ":" << o.second << ", ";
    }
  else os << "none";
  os << ">";

  return os;
}
