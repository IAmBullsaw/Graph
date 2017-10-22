#ifndef NODE_H
#define NODE_H
#include <map>
#include <string>
#include <ostream>
class Node {
 public:
  static unsigned _id;
  Node();
  ~Node();
  Node(std::string const& name);

  void connect(Node* const n, int const& cost);
  void mutual_connect(Node* n, int const& cost);

  // Getters/Setters
  unsigned get_id() const;
  std::string get_name() const;
  int get_cost(Node* const n) const;
  std::map<Node*,int> get_connections() const;
  unsigned connections_size() const;

  bool connects_to(Node* const n) const;
  bool connected() const;

  void update_cost(Node* const n, int const& cost);
  void mutual_update_cost(Node* n, int const& cost);

  // Operators
  bool operator==(Node const& n) const;
  bool operator!=(Node const& n) const;
  bool operator<(Node const& n) const;
  bool operator>(Node const& n) const;

  friend std::ostream& operator<<(std::ostream & os, Node const& n);
 private:
  unsigned id;
  std::string name;
  std::map<Node*,int> connections;
};
#endif /* NODE_H */
