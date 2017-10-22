CC=g++ -std="c++17"

all: bfs dfs
	echo "Jobs done."
bfs:
	$(CC)	breadth_first_search.cc ../node/node.cc ../graph/graph.cc -o breadth_first_search
dfs:
	$(CC)	depth_first_search.cc ../node/node.cc ../graph/graph.cc -o depth_first_search
zap:
	rm -fv *.o depth_first_search breadth_first_search
