#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <functional>
#include <string>
#include <sstream>
#include <fstream>
#include "../node/node.h"
class Graph {
 public:
  Graph();
  ~Graph();
  void add_node(Node* const n);
  void print() const;
  unsigned get_size() const;
  void for_each_node(std::function<void(Node*)> fun);
  std::vector<Node*> get_nodes() const;
  Node* get_node_by_name(std::string name);
  void load_from_file(std::string const& filename);
  int get_cost(std::string const& n1, std::string const& n2);

 private:
  unsigned size;
  std::vector<Node*> nodes;
  void load_nodes(std::fstream & f, std::string name);
  void connect_nodes(std::fstream & f, std::stringstream & ss, std::string name, std::string line);
};
#endif /* GRAPH_H */
