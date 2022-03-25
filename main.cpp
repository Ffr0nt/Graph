#include <iostream>
#include "graph.h"

struct Point { double x, y, z; };
std::ostream& operator << (std::ostream& out, Point p) {
    std::cout << '(' << p.x << ',' << p.y << ',' << p.z << ')';
    return out;
}

template<typename Graph>
void print(const Graph& graph) {
    if (graph.empty()) {
        std::cout << "> This graph is empty!" << std::endl;
        return;
    }
    std::cout << "> Size of graph: " << graph.size() << std::endl;
    for (const auto& [key, node] : graph) {
        std::cout << '[' << key << "] stores: " << node.value()
                  << " and matches with:" << std::endl;
        for (const auto& [key, weight] : node)
            std::cout << "\t[" << key << "]\t with weight: "
                      << weight << std::endl;
    }
}

void test_1(){
    Graph<std::string, Point, double> gr_1;
    std::cout<< "default constructor:"<<std::endl;
    gr_1["unique_feature"] = Point{1,2,3};
    print(gr_1);
    Graph<std::string, Point, double> gr_2 = gr_1;
    std::cout<< "copy constructor:"<<std::endl;
    print(gr_2);
    Graph<std::string, Point, double> gr_3 = Graph<std::string, Point, double>();
    std::cout<< "move constructor:"<<std::endl;
    print(gr_3);

//    insert smth in gr_1
    gr_1["zero"];
    auto [it1, flag1] = gr_1.insert_node("first", {1, 1, 1});
    std::cout<< "gr_2 = gr_1,  gr_2:"<<std::endl;
    gr_2 = gr_1;
    print(gr_2);

    std::cout<< "gr_2 = Graph<std::string, Point, double>() :"<<std::endl;
    gr_2 = Graph<std::string, Point, double>();
    print(gr_2);

} // constructors ; =
void test_2(){
    Graph<std::string, Point, double> gr;
    gr["one"] = Point{1.1, 1.1,1.1};
    gr["two"] = Point{2.2,2.2,2.2};
    gr["three"] = Point{3.3,3.3,3.3};
    gr.insert_edge({"three","two"}, 3.2);
    gr.insert_edge({"two","three"}, 2.3);
    gr.insert_edge({"three","one"}, 3.1);

    print(gr);

    std::cout<< "gr.empty(); " << gr.empty()<< std::endl << "gr.size(); "<< gr.size()<< std::endl;
    std::cout << "gr['one']; " <<  gr["one"]<< std::endl;
    std::cout << "ggr.clear(); " << std::endl;
    gr.clear();
    print(gr);

    Node<std::string, Point, double> node;
    node.insert_edge("other", 555.5);
    std::cout<< "node.empty(); " << node.empty()<< std::endl << "node.size(); "<< node.size()<< std::endl;
    std::cout << "node.clear(); " << std::endl;
    node.clear();
    std::cout<< "node.empty(); " << node.empty();
} // methods describing characteristics of graph and nodes
void test_3(){
    Graph<std::string, Point, double> gr;
    gr["one"] = Point{1.1, 1.1,1.1};
    gr["two"] = Point{2.2,2.2,2.2};
    gr["three"] = Point{3.3,3.3,3.3};
    gr.insert_edge({"three","two"}, 3.2);
    gr.insert_edge({"two","three"}, 2.3);
    gr.insert_edge({"three","one"}, 3.1);
    print(gr);
    std::cout << std::endl;

    for (auto& [key, node] : gr) {
        std::cout << "Is here no edges? - " << std::boolalpha << node.empty() << "\t";
        std::cout << "How many edges are going from here?" << node.size();
        node.value() = Point{ 1,2,3 }; // могу поменять вес
        std::cout<< "\tweights:";
        for (auto& [key, weight] : node) {
            std::cout<< " " << weight;
        }
        std::cout << std::endl;
    }

    std::cout<< "--------------|same graph but const|--------------"<< std::endl;
    const Graph<std::string, Point, double> graph (gr);
    for (auto& [key, node] : graph) {
        std::cout << "Is here no edges? - " << std::boolalpha << node.empty() << "\t";
        std::cout << "How many edges are going from here?" << node.size();
        std::cout<< "\tweights:";
        for (auto& [key, weight] : node) {
            std::cout<< " " << weight;
        }
        std::cout << std::endl;
    }

} // iterators
void test_4(){
    Graph<std::string, Point, double> gr;
    gr["one"] = Point{1.1, 1.1,1.1};
    gr["two"] = Point{2.2,2.2,2.2};
    gr["three"] = Point{3.3,3.3,3.3};
    gr.insert_edge({"three","two"}, 3.2);
    gr.insert_edge({"two","three"}, 2.3);
    gr.insert_edge({"three","one"}, 3.1);
    print(gr);
    std::cout << std::endl;

    std::cout << "gr.degree_in(\"one\"); " << gr.degree_in("one")<<std::endl;
    std::cout << "gr.degree_out(\"one\"); " << gr.degree_out("one")<<std::endl<<std::endl;

    std::cout << "gr.degree_in(\"two\"); " << gr.degree_in("two")<<std::endl;
    std::cout << "gr.degree_out(\"two\"); " << gr.degree_out("two")<<std::endl<<std::endl;

    std::cout << "gr.degree_in(\"three\"); " << gr.degree_in("three")<<std::endl;
    std::cout << "gr.degree_out(\"three\"); " << gr.degree_out("three")<<std::endl;

    gr.insert_edge({"three","three"}, 3.3);
    std::cout << "gr.loop(\"three\"); (after adding one) " << gr.loop("three")<<std::endl<<std::endl;
    std::cout << "gr.loop(\"one\") " << gr.loop("one")<<std::endl;

    std::cout << "gr.at(\"one\").value() " << gr.at("one").value() <<std::endl << std::endl;
    try{
        gr.at("four");
    }
    catch (std::runtime_error er){
        std::cout << "gr.at(\"four\");"<< er.what();
    }
} // methods describing edges
void test_5(){
    Graph<std::string, Point, double> gr;
    gr["one"] = Point{1.1, 1.1,1.1};
    gr["two"] = Point{2.2,2.2,2.2};
    gr["three"] = Point{3.3,3.3,3.3};
    gr.insert_edge({"three","two"}, 3.2);
    gr.insert_edge({"two","three"}, 2.3);
    gr.insert_edge({"three","one"}, 3.1);
    print(gr);
    std::cout << std::endl;

    std::cout << "gr.insert_node(\"four\",Point{1.1, 1.1,1.1} ).second"<< std::endl;
    std::cout << gr.insert_node("four",Point{1.1, 1.1,1.1} ).second << std::endl;
    std::cout << gr.insert_node("four",Point{1.1, 1.1,1.1} ).second << std::endl;

    std::cout << "gr.insert_edge({\"one\", \"two\"}, 22.22).second"<< std::endl;
    std::cout << gr.insert_edge({"one", "two"}, 22.22).second<< std::endl;
    std::cout << gr.insert_edge({"one", "two"}, 22.22).second<< std::endl;
    print(gr);

    std::cout << "gr.erase_edges_go_from((\"two\")"<< std::endl;
    std::cout << gr.erase_edges_go_from("two")<< std::endl;
    std::cout << "gr.erase_edges_go_from((\"six\")"<< std::endl;
    std::cout << gr.erase_edges_go_from("six")<< std::endl;
    print(gr);
    std::cout << "gr.erase_edges_go_to((\"two\")"<< std::endl;
    std::cout << gr.erase_edges_go_to("two")<< std::endl;
    std::cout << "gr.erase_edges_go_to((\"six\")"<< std::endl;
    std::cout << gr.erase_edges_go_to("six")<< std::endl;
    print(gr);
    std::cout << " gr.clear();"<< std::endl;
    gr.clear();
    print(gr);

} // node / edge insert / clear
void test_6(){
    Graph<std::string, Point, double> gr;

    try{
        gr.degree_in("random");
    }
    catch( std::runtime_error er ){std::cout<<er.what()<<std::endl;}
    try{
        gr.degree_out("random");
    }
    catch( std::runtime_error er ){std::cout<<er.what()<<std::endl;}
    try{
        gr.loop("random");
    }
    catch( std::runtime_error er ){std::cout<<er.what()<<std::endl;}
    try{
        gr.at("random");
    }
    catch( std::runtime_error er ){std::cout<<er.what()<<std::endl;}
} // degree_in degree_out loop at special errors

void test_0(){
    Graph<std::string, Point, double> gr;
    print(gr);
    std::cout << gr.size()<< std::endl;
    std::cout << gr.empty();

    gr["A"];
    auto a = gr.at("A");
    std::cout<< std::endl <<  a.value() << std::endl << std::endl ;
    print(gr);


    Graph<std::string, Point, double> graph;
    graph["zero"];
    auto [it1, flag1] = graph.insert_node("first", {1, 1, 1});
    std::cout << std::boolalpha << flag1 << std::endl; // => true
    graph["second"];
    auto [it2, flag2] = graph.insert_or_assign_node("second", {2, 2, 2});
    std::cout << std::boolalpha << flag2 << " flag2 " << std::endl; // => false
    graph["third"] = Point{ 3, 3, 3 };
    auto [it3, flag3] = graph.insert_node("third", {1, 1, 1});
    std::cout << std::boolalpha << flag3 << std::endl; // => false
    graph["fourth"];
    graph.at("fourth") = Point{ 4, 4, 4 };
    try { graph.at("fifth"); }
    catch (std::exception& ex) { std::cout << ex.what() << std::endl; }
    auto [it4, flag4] = graph.insert_edge({ "first", "second" }, 44.44);
    std::cout << std::boolalpha << flag4 << std::endl; // => true
    auto [it5, flag5] = graph.insert_edge({ "first", "second" }, 55.55);
    std::cout << std::boolalpha << flag5 << std::endl; // => false
    auto [it6, flag6] = graph.insert_or_assign_edge({ "first", "second" }, 66.66);
    std::cout << std::boolalpha << flag6 << std::endl; // => false
    auto [it7, flag7] = graph.insert_or_assign_edge({ "second", "first" }, 77.77);
    std::cout << std::boolalpha << flag7 << std::endl; // => true
    print(graph);
    auto graph_other = graph;
    auto graph_new = std::move(graph);
    graph = std::move(graph_new);
    graph_new = graph;
    graph.swap(graph_new);
    swap(graph, graph_new);
    print(graph);
    for (auto& [key, node] : graph) {
        std::cout << "Is here no edges?" << std::boolalpha << node.empty() << std::endl;
        std::cout << "How many edges are going from here?" << node.size() << std::endl;
        node.value() = Point{ 1,2,3 };
        for (auto& [key, weight] : node) {

            weight = 11.11;
        }
        bool flag = node.erase_edge("first");

    }
    print(graph);
    bool flag8 = graph.erase_node("new name");
    std::cout << std::boolalpha << flag8 << std::endl;
    bool flag9 = graph.erase_node("first");
    std::cout << std::boolalpha << flag9 << std::endl;
    print(graph);
    graph.insert_edge({ "second", "zero" }, 4.4);
    graph.insert_edge({ "third", "second" }, 6.6);
    print(graph);
    bool flag10 = graph.erase_edges_go_from("new name");
    std::cout << std::boolalpha << flag10 << std::endl;
    bool flag11 = graph.erase_edges_go_from("second");
    std::cout << std::boolalpha << flag11 << std::endl;
    print(graph);
    graph.erase_edges_go_to("second");
    print(graph);
    graph.insert_edge({ "second", "zero" }, 4.4);
    graph.insert_edge({ "third", "second" }, 6.6);
    graph.insert_edge({ "third", "third" }, 6.6);
    graph.insert_edge({ "third", "zero" }, 6.6);
    print(graph);
    std::cout << graph.degree_in("second") << std::endl;
    std::cout << graph.degree_in("third") << std::endl;
    std::cout << graph.degree_out("second") << std::endl;
    std::cout << graph.degree_out("third") << std::endl;
    std::cout << std::boolalpha << graph.loop("second") << std::endl;
    std::cout << std::boolalpha << graph.loop("third") << std::endl;
    bool flag12 = graph.erase_node("new name");
    std::cout << std::boolalpha << flag12 << std::endl;
    bool flag13 = graph.erase_node("second");
    std::cout << std::boolalpha << flag13 << std::endl;
    print(graph);
    graph.clear_edges();
    print(graph);
    graph.clear();
    print(graph);


} // baseline test

int main() {
    int NUM = 0; //enter number of test you want to have

    switch (NUM) {
        case 1:
            test_1();
            break;
        case 2:
            test_2();
            break;
        case 3:
            test_3();
            break;
        case 4:
            test_4();
            break;
        case 5:
            test_5();
            break;
        case 6:
            test_6();
            break;
        default:
            std::cout<<"Original tests"<< std::endl << std::endl;
            test_0();
    }

    return 0;
}
