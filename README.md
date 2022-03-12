# Graph
Template Graph class to represent a directed graph 
stores information inside itself:
1) About the unique keys that can be used to get to the vertices (the name of the vertex);
2) About the data that is stored in the vertex;
3) About directed edges that connect vertices (with weight).

Class organisation:
1) Graph is a map of Nodes name and Node objects themselves;
2) Node has map of connected Nodes with weights of connection;
