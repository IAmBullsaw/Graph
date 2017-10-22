# Graph
This is a simple C++ implementation to easily build trees or graphs from connected nodes.

## node/
This node has zero or more connections to other nodes.
It can only have one connection/arc to any one node, however possible to have different costs:
```
Cost:   1        3
Arcs: a -> b   a <- b
```

Example of use
```
 Node n{"name"};
 Node o{"Cool node"};
 n.connect(&o,2); // One way connection of cost 2
 o.connects_to(&n); // Will therefore return false
```

## graph/
This graph implementation can load up a graph from file using this simple DSL:
```
# This is a comment.
# It must be on the form "# "
# Otherwise it'll fail.
NODES
these
are
all
names
of
nodes
STOP
# Here be connections/arcs between nodes.
# a line that is preceded with an "m"
# means that these nodes are going to
# be mutually connected, so a->b, a<-b
# and will have the same cost.
these are 1 all 2 names 1
m names of 2 nodes 2
STOP
# Now that's a complete file
```

## search_algorithms/
This is a folder that contains different search algorithms implemented using these nodes. Cool.

## graphs/
A folder containing graphs in the format loadable by the Graph.
