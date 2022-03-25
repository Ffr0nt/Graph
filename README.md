# Graph
Template Graph class to represent a directed graph 
stores information inside itself about:
1) The unique keys that can be used to get to the vertices (the name of the vertex);
2) The data that is stored in the vertex;
3) Directed edges that connect vertices (with weight).

Class organisation:
1) Graph is a map of Nodes name and Node objects themselves;
2) Node has map of connected Nodes with weights of connection;
