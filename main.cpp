#include <iostream>
#include "graph.cpp"

struct Point { double x, y, z; };
std::ostream& operator << (std::ostream& out, Point p) {
    std::cout << '(' << p.x << ',' << p.y << ',' << p.z << ')';
    return out;
}


int main() {
    Graph<std::string, Point, double> graph;
    graph.print();
    std::cout << graph.size()<< std::endl;
    std::cout << graph.empty();



    return 0;
}
