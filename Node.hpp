//
// Created by Фёдор Захаров on 13.03.2022.
//


#pragma once

#include "Node.h"

template<typename Key, typename Value, typename Weight>
typename Node<Key, Value, Weight>::iterator Node<Key, Value, Weight>::begin() {
    return m_con_nodes.begin();
}

template<typename Key, typename Value, typename Weight>
typename Node<Key, Value, Weight>::const_iterator Node<Key, Value, Weight>::begin() const {
    return m_con_nodes.cbegin();
}

template<typename Key, typename Value, typename Weight>
typename Node<Key, Value, Weight>::iterator Node<Key, Value, Weight>::end() {
    return m_con_nodes.end();
}

template<typename Key, typename Value, typename Weight>
typename Node<Key, Value, Weight>::const_iterator Node<Key, Value, Weight>::end() const {
    return m_con_nodes.cend();
}

template<typename Key, typename Value, typename Weight>
const typename Node<Key, Value, Weight>::weight_type& Node<Key, Value, Weight>::operator[](const key_type &key) const {
    return &m_con_nodes[key];
}

template<typename Key, typename Value, typename Weight>
typename Node<Key, Value, Weight>::weight_type& Node<Key, Value, Weight>::operator[](const key_type &key) {
    return &m_con_nodes[key];
}

template<typename Key, typename Value, typename Weight>
std::pair<typename Node<Key, Value, Weight>::iterator, bool>
        Node<Key, Value, Weight>::insert_edge(const key_type &input_key, const  weight_type& weight) {
    return m_con_nodes.insert({input_key,weight});
}

template<typename Key, typename Value, typename Weight>
std::pair<typename Node<Key, Value, Weight>::iterator, bool>Node<Key, Value, Weight>
        ::insert_or_assign_edge(const key_type& input_key,const  weight_type& weight) {
    return m_con_nodes.insert_or_assign(input_key,weight);
}

template<typename Key, typename Value, typename Weight>
void Node<Key, Value, Weight>::clear_edges_to_for_node(const key_type& search_key) noexcept {
    try{ m_con_nodes.at(search_key);}
    catch (...){ return ;}
    m_con_nodes.erase(search_key);
}

template<typename Key, typename Value, typename Weight>
bool Node<Key, Value, Weight>::erase_edge(const key_type &search_key) {
    try{ m_con_nodes.at(search_key);}
    catch (...){ return 0;}
    m_con_nodes.erase(search_key);
    return 1;
}
