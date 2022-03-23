//
// Created by Фёдор Захаров on 12.03.2022.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "map"
#include "Node.h"
#include <iostream>
template<typename Key,
    typename Value,
    typename Weight
        >
class Graph {
public:
    using key_type = Key;
    using value_type = Value;
    using weight_type = Weight;
    using iterator = typename  std::map< key_type, Node<key_type,value_type,weight_type> >::iterator;
    using const_iterator = typename std::map< key_type, Node<key_type,value_type,weight_type>>::const_iterator;
//    -----------------------|constructors|--------------------------------------
    Graph() = default;

    Graph(const Graph& obj): m_nodes(obj.m_nodes){};
//    ------------------------|iterators|--------------------------------------

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    const_iterator cbegin() const {return m_nodes.cbegin();}
    const_iterator cend() const {return m_nodes.cend();}

//    ------------------------|addressing|------------------------------------
    value_type& operator[] (const key_type& key);

    value_type& at(const key_type& key);

//    ------------------------|insert|--------------------------------------
    std::pair<iterator, bool> insert_node(const key_type& input_key,const value_type& val);


//    ------------------------|methods|--------------------------------------

    size_t size() const{return m_nodes.size();}

    bool empty() const {return size() == 0;}

    void clear() {m_nodes.clear();}

    void swap(Graph& obj){m_nodes.swap(obj.m_nodes);};

    size_t degree_in(const key_type & key);

    size_t degree_out (const key_type & key);

    bool loop(const key_type & key);

private:
    std::map< key_type, Node<key_type,value_type,weight_type> > m_nodes;
};
#include "graph.hpp"

template<typename Key, typename Value, typename Weight>
void swap(Graph<Key, Value, Weight> & left, Graph<Key, Value, Weight> & right){left.swap(right);return;}

#endif //GRAPH_GRAPH_H
