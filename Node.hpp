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
const typename Node<Key, Value, Weight>::value_type& Node<Key, Value, Weight>::operator[](const key_type &key) const {
    return m_con_nodes[key];
}

template<typename Key, typename Value, typename Weight>
typename Node<Key, Value, Weight>::value_type& Node<Key, Value, Weight>::operator[](const key_type &key) {
    return m_con_nodes[key];
}
