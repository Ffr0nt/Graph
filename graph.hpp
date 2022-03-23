//
// Created by Фёдор Захаров on 12.03.2022.
//

#pragma once
#include "map"
#include "graph.h"

template<typename Key, typename Value, typename Weight>
typename Graph<Key, Value, Weight>::iterator Graph<Key, Value, Weight>::begin() {
    return m_nodes.begin();
}

template<typename Key, typename Value, typename Weight>
typename Graph<Key, Value, Weight>::const_iterator Graph<Key, Value, Weight>::begin() const {
    return m_nodes.cbegin();
}

template<typename Key, typename Value, typename Weight>
typename Graph<Key, Value, Weight>::iterator Graph<Key, Value, Weight>::end() {
    return  m_nodes.end();
}

template<typename Key, typename Value, typename Weight>
typename Graph<Key, Value, Weight>::const_iterator Graph<Key, Value, Weight>::end() const {
    return m_nodes.cend();
}

template<typename Key, typename Value, typename Weight>
size_t Graph<Key, Value, Weight>::degree_in(const key_type &searching_key) {

    if (m_nodes.count(searching_key) == 0) {
        throw std::runtime_error("\nNo key named: "+ std::string(searching_key) +" in graph. While degree_in command.");
    }
    size_t answer = 0;
    for (auto& [key, node] : *this){
        if (node.is_connected(searching_key)){
            ++answer;
        }
    }
    return answer;


}

template<typename Key, typename Value, typename Weight>
size_t Graph<Key, Value, Weight>::degree_out(const key_type &searching_key) {
    if (m_nodes.count(searching_key) == 0) {
        throw std::runtime_error("\nNo key named: "+ std::string(searching_key) +" in graph. While degree_out command.");
    }
    return m_nodes[searching_key].size();

}

template<typename Key, typename Value, typename Weight>
bool Graph<Key, Value, Weight>::loop(const key_type &searching_key) {
    if (m_nodes.count(searching_key) == 0) {
        throw std::runtime_error("\nNo key named: "+ std::string(searching_key) +" in graph. While loop command.");
    }
    return m_nodes[searching_key].is_connected(searching_key);
}

template<typename Key, typename Value, typename Weight>
typename Graph<Key, Value, Weight>::value_type &Graph<Key, Value, Weight>::at(const key_type &searching_key) {
    if (m_nodes.count(searching_key) == 0) {
        throw std::runtime_error("\nNo key named: "+ std::string(searching_key) +" in graph. While at command.");
    }
    return this->operator[](searching_key);
}

template<typename Key, typename Value, typename Weight>
typename Graph<Key, Value, Weight>::value_type& Graph<Key, Value, Weight>::operator[](const key_type &searching_key) {
    Node<Key, Value, Weight>  node = m_nodes[searching_key];
    return node[searching_key] ;
}

template<typename Key, typename Value, typename Weight>
std::pair< typename Graph<Key, Value, Weight>::iterator, bool> \
    Graph<Key, Value, Weight>::insert_node (const key_type &input_key,const value_type& input_val) {

    if (m_nodes.count(input_key) == 1) {
        throw std::runtime_error("\nKey named: "+ std::string(input_key) \
        +" already exist in graph. While insert_node command.");
    }

    return m_nodes.insert();
}
