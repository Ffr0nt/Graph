//
// Created by Фёдор Захаров on 13.03.2022.
//

#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H
#include "map"

template<typename Key,
        typename Value,
        typename Weight
>
class Node {
public:
    using key_type = Key;
    using value_type = Value;
    using weight_type = Weight;
    using iterator = typename std::map<key_type, value_type> ::iterator;
    using const_iterator = typename std::map<key_type,value_type>::const_iterator;
//    -----------------------|constructors|--------------------------------------
    Node() = default;
    Node(const Node& obj):data(obj.data),m_con_nodes(obj.m_con_nodes) {};

//    ------------------------|iterators|--------------------------------------

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    const_iterator cbegin() const {return m_con_nodes.cbegin();}
    const_iterator cend() const {return m_con_nodes.cend();}

//    ------------------------|addressing|------------------------------------

    value_type& operator[] (const key_type& key);
    const value_type& operator[] (const key_type& key) const;

    //    ------------------------|methods|--------------------------------------
    size_t size() const{return m_con_nodes.size();}

    bool empty() const {return size() == 0;}

    void clear() {m_con_nodes.clear();}

    weight_type* value() {return &data;}
    const weight_type* value() const {return & data;}

    void swap(Node& obj){m_con_nodes.swap(obj.m_con_nodes);};

    bool is_connected(const key_type &searching_key){return m_con_nodes.count(searching_key);}

private:
    weight_type data;
    std::map<key_type, value_type> m_con_nodes;
};

#include"Node.hpp"

#endif //GRAPH_NODE_H
