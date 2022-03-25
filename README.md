# Graph
Template Graph class to represent a directed graph 
stores information about:
1) The unique keys that can be used to get to the nodes (the name of the node);
2) The data that is stored in the node;
3) Directed edges that connect nodes (with weight).

Class organisation:
1) Graph is a map of Nodes name and Node objects themselves;
2) Node has map of connected Nodes with weights of connection and values of that particular node;

Mostly methods are based on std::map methods (constructors, addressing, insert and erase).
However there is functional that realize graph unique features (degree in/out, loop counting)

 
