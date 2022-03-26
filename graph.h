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
    using node_it =  typename Node<Key, Value, Weight>::iterator ;
////    -----------------------|constructors|--------------------------------------
    Graph() = default;
    Graph(const Graph& obj): m_nodes(obj.m_nodes){};
    Graph (Graph&& obj)noexcept : m_nodes(std::move(obj.m_nodes)){};
    Graph(const std::initializer_list<std::pair<key_type,value_type>> & init_list):
    m_nodes(init_list.begin(), init_list.end()){};

////    ---------------------------| = |--------------------------------------
    Graph& operator = (const Graph& gr) {
        m_nodes = gr.m_nodes;
        return *this;
    }
    Graph& operator = (Graph&& gr) noexcept {
        m_nodes = std::move(gr.m_nodes);
        return *this;
    }

////    ------------------------|iterators|--------------------------------------

    iterator begin() noexcept;
    const_iterator begin() const noexcept;

    iterator end() noexcept;
    const_iterator end() const noexcept;

    const_iterator cbegin() const noexcept {return m_nodes.cbegin();}
    const_iterator cend() const noexcept {return m_nodes.cend();}

////    ------------------------|addressing|------------------------------------

    value_type & operator[] (const key_type& key);

    const weight_type& operator[] (const key_type& key) const;

    Node<key_type,value_type,weight_type>& at(const key_type& key);

////    --------------------------|insert|--------------------------------------
    std::pair<iterator, bool> insert_node(const key_type& input_key,const value_type& val);

    std::pair<iterator, bool> insert_or_assign_node(const key_type& input_key,const value_type& val);

    std::pair<node_it, bool> insert_edge(std::pair<key_type,key_type> key_pair, weight_type weight);

    std::pair<node_it, bool> insert_or_assign_edge(std::pair<key_type,key_type> key_pair, weight_type weight);

////    ---------------------------|erase|--------------------------------------
    void clear_edges();

    bool erase_edges_go_from(const key_type& search_key);

    bool erase_edges_go_to(const key_type& search_key);

    bool erase_node(const key_type& search_key);

////    ------------------------|methods|--------------------------------------

    size_t size() const noexcept {return m_nodes.size();}

    bool empty() const noexcept {return size() == 0;}

    void clear() noexcept {m_nodes.clear();}

    void swap(Graph& obj){m_nodes.swap(obj.m_nodes);};

    size_t degree_in (const key_type & key);

    size_t degree_out (const key_type & key);

    bool loop(const key_type & key);

private:
    std::map< key_type, Node<key_type,value_type,weight_type> > m_nodes;

};
#include "graph.hpp"

template<typename Key, typename Value, typename Weight>
void swap(Graph<Key, Value, Weight> & left, Graph<Key, Value, Weight> & right){left.swap(right);}

#endif //GRAPH_GRAPH_H
