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
    return m_nodes.end();
}

template<typename Key, typename Value, typename Weight>
typename Graph<Key, Value, Weight>::const_iterator Graph<Key, Value, Weight>::end() const {
    return m_nodes.cend();
}

template<typename Key, typename Value, typename Weight>
size_t Graph<Key, Value, Weight>::degree_in(const key_type &searching_key) {

    if (m_nodes.count(searching_key) == 0) {
        throw std::runtime_error(
                "\nNo key named: \"" + std::string(searching_key) + "\" in graph. While degree_in command.");
    }
    size_t answer = 0;
    for (auto&[key, node]: *this) {
        if (node.is_connected(searching_key)) {
            ++answer;
        }
    }
    return answer;


}

template<typename Key, typename Value, typename Weight>
size_t Graph<Key, Value, Weight>::degree_out(const key_type &searching_key) {
    if (m_nodes.count(searching_key) == 0) {
        throw std::runtime_error(
                "\nNo key named: \"" + std::string(searching_key) + "\" in graph. While degree_out command.");
    }
    return m_nodes[searching_key].size();

}

template<typename Key, typename Value, typename Weight>
bool Graph<Key, Value, Weight>::loop(const key_type &searching_key)
{
    if (m_nodes.count(searching_key) == 0) {
        throw std::runtime_error("\nNo key named: \"" + std::string(searching_key) + "\" in graph. While loop command.");
    }
    return m_nodes[searching_key].is_connected(searching_key);
}

template<typename Key, typename Value, typename Weight>
Node<Key, Value, Weight> &Graph<Key, Value, Weight>::at(const key_type &searching_key) {
    if (m_nodes.count(searching_key) == 0) {
        throw std::runtime_error("\nNo key named: \"" + std::string(searching_key) + "\" in graph. While at command.");
    }
    return m_nodes.at(searching_key);
}

template<typename Key, typename Value, typename Weight>
Value& Graph<Key, Value, Weight>::operator[](const key_type &searching_key) {
    return m_nodes[searching_key].value();
}

template<typename Key, typename Value, typename Weight>
std::pair<typename Graph<Key, Value, Weight>::iterator, bool> \
 Graph<Key, Value, Weight>::insert_node(const key_type &input_key, const value_type &input_val) {

    return m_nodes.insert(std::make_pair(input_key, Node<Key, Value, Weight>(input_val)));
}

template<typename Key, typename Value, typename Weight>
std::pair<typename Graph<Key, Value, Weight>::iterator, bool>
Graph<Key, Value, Weight>::insert_or_assign_node(const key_type &input_key, const value_type &input_val) {

    return m_nodes.insert_or_assign(input_key, input_val);
}

template<typename Key, typename Value, typename Weight>
std::pair<typename Node<Key, Value, Weight>::iterator, bool>
Graph<Key, Value, Weight>::insert_edge(std::pair<key_type, key_type> key_pair, weight_type weight) {
    m_nodes.at(key_pair.second);
    return m_nodes.at(key_pair.first).insert_edge(key_pair.second, weight);
}

template<typename Key, typename Value, typename Weight>
std::pair<typename Node<Key, Value, Weight>::iterator, bool>
Graph<Key, Value, Weight>::insert_or_assign_edge(std::pair<key_type, key_type> key_pair, weight_type weight) {
    m_nodes.at(key_pair.second);
    return m_nodes.at(key_pair.first).insert_or_assign_edge(key_pair.second, weight);
}

template<typename Key, typename Value, typename Weight>
void Graph<Key, Value, Weight>::clear_edges() noexcept {
    for (auto&[key, node]: *this){
        node.clear_edges_for_node();
    }
}

template<typename Key, typename Value, typename Weight>
bool  Graph<Key, Value, Weight>::erase_edges_go_from(const key_type& search_key){
    try{ m_nodes.at(search_key);}
    catch (...){ return 0;}

    m_nodes[search_key].clear_edges_for_node();
    return 1;

}

template<typename Key, typename Value, typename Weight>
bool Graph<Key, Value, Weight>::erase_edges_go_to(const key_type &search_key) {
    try{ m_nodes.at(search_key);}
    catch (...){ return 0;}

    for (auto&[key, node]: *this){
        node.clear_edges_to_for_node(search_key);
    }
    return 1;
}

template<typename Key, typename Value, typename Weight>
bool Graph<Key, Value, Weight>::erase_node(const key_type &search_key) {
    try{ m_nodes.at(search_key);}
    catch (...){ return 0;}

    m_nodes.erase(search_key);

    for (auto&[key, node]: *this){
        node.clear_edges_to_for_node(search_key);
    }
    return 1;
}


