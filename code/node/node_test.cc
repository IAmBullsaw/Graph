#include <exception>
#include <iostream>
#include "node.h"

#define assert(x,y) do { if(x != y) cerr << "Expected '" << x << "' got '" << y << "'" << endl;} while(false)

using namespace std;

int main() {
  // Creation
  Node n{"Hello World"};
  assert(n.get_name(),"Hello World");
  assert(n.get_id(),1);

  // Connections
  Node n1{"Yello World"};
  assert(false,n.connects_to(n1));
  assert(false,n.connected());
  assert(false,n1.connects_to(n));

  n.connect(n1,1);
  assert(true,n.connects_to(n1));
  assert(true,n.connected());
  assert(false,n1.connects_to(n));

  // Mutual connect
  Node a{"Let's"};
  Node b{"Connect"};
  a.mutual_connect(b,1);
  assert(true,a.connects_to(b));
  assert(true,b.connects_to(a));

  // Update mutual cost
  a.mutual_update_cost(b,10);
  assert(10, a.get_cost(b));
  assert(10, b.get_cost(a));

  // Cost finding
  bool throws{false};
  try {
    n.get_cost(Node("new node"));
  } catch (out_of_range e) {
    throws = true;
  }
  assert(true,throws);
  assert(1, n.get_cost(n1));

  // Adding same node as connection
  n.connect(n1, 2);
  assert(true, n.connects_to(n1));
  assert(1, n.connections_size());
  assert(1, n.get_cost(n1));

  // Updating node cost
  n.update_cost(n1,2);
  assert(2, n.get_cost(n1));

  cout << "All tests passed" << endl;
  return 0;
}
