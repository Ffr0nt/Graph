//
// Created by Фёдор Захаров on 12.03.2022.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "map"
#include "Node.cpp"
#include <iostream>
template<typename Key,
    typename Value,
    typename Weight
        >
class Graph {
public:
    using key_type = Key;
    using mapped_type = Value;
    using weight_type = Weight;
    using iterator = typename  std::map< key_type, Node<key_type,mapped_type,weight_type> >::iterator;
    using const_iterator = typename std::map< key_type, Node<key_type,mapped_type,weight_type>>::const_iterator;
//    -----------------------|constructors|--------------------------------------
    Graph() = default;

    Graph(const Graph& obj): m_nodes(obj.m_nodes){};
//    ------------------------|iterators|--------------------------------------

    iterator begin(){return m_nodes.begin();}
    const_iterator begin() const{return m_nodes.cbegin();}
    iterator end(){return m_nodes.end();}
    const_iterator end() const{return m_nodes.cend();}

    const_iterator cbegin() const {return m_nodes.cbegin();}
    const_iterator cend() const {return m_nodes.cend();}

//    ------------------------|methods|--------------------------------------

    size_t size() const{return m_nodes.size();}

    bool empty() const {return size() == 0;}

    void clear() {m_nodes.clear();}

    void swap(Graph& obj){};

//    -----------------------|additional|--------------------------------------
    void print() {
        if (this->empty()) {
            std::cout << "> This graph is empty!" << std::endl;
            return;
        }
        std::cout << "> Size of graph: " << this->size() << std::endl;
        for (const auto& [key, node] : *this) {
            std::cout << '[' << key << "] stores: " << node.value()
                      << " and matches with:" << std::endl;
            for (const auto& [key, weight] : node)
                std::cout << "\t[" << key << "]\t with weight: "
                          << weight << std::endl;
        }
    }

private:
    std::map< key_type, Node<key_type,mapped_type,weight_type> > m_nodes;

};


#endif //GRAPH_GRAPH_H
