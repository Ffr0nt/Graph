//
// Created by Фёдор Захаров on 13.03.2022.
//
#include "map"
#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H


template<typename Key,
        typename Value,
        typename Weight
>
class Node {
public:
    using key_type = Key;
    using value_type = Value;
    using weight_type = Weight;
    using iterator = typename std::map<key_type, weight_type> ::iterator;
    using const_iterator = typename std::map<key_type,weight_type>::const_iterator;

    friend std::map<key_type, weight_type> get_con_nodes(key_type key);

    ////    -----------------------|constructors|--------------------------------------
    Node() = default;
    Node(const Node& obj):data(obj.data),m_con_nodes(obj.m_con_nodes) {};
    Node (Node&& obj) noexcept : m_con_nodes(std::move(obj.m_con_nodes)), data(std::move(obj.data)){};
    Node(const value_type& val):data(val){};
    Node(const std::initializer_list<std::pair<key_type, weight_type>> & init_list):
            m_con_nodes(init_list.begin(), init_list.end()){};

////    ------------------------------| = |--------------------------------------
    Node& operator = (const Node& obj) {
        m_con_nodes = obj.m_con_nodes;
        data = obj.data;
        return *this;
    }

    Node& operator = (Node&& obj) noexcept {
        m_con_nodes = std::move(obj.m_con_nodes);
        data = std::move(obj.data);
        return *this;
    }

////    ------------------------|iterators|--------------------------------------

    iterator begin();
    const_iterator begin() const;

    iterator end();
    const_iterator end() const;

    const_iterator cbegin() const {return m_con_nodes.cbegin();}
    const_iterator cend() const {return m_con_nodes.cend();}

////    ------------------------|addressing|------------------------------------

    weight_type& operator[] (const key_type& key);

    const weight_type& operator[] (const key_type& key) const;

////    --------------------------|methods|--------------------------------------
    size_t size() const noexcept{return m_con_nodes.size();}

    bool empty()  const noexcept{return m_con_nodes.empty();}

    void clear() noexcept {m_con_nodes.clear();}

    value_type& value() noexcept{return data;}

    const value_type& value() const noexcept {return data;}

    void swap(Node& obj){m_con_nodes.swap(obj.m_con_nodes);};

    bool is_connected(const key_type &searching_key){return m_con_nodes.count(searching_key);}

    ////     -------------------------|insert|--------------------------------------

    std::pair<iterator, bool>insert_edge(const key_type& input_key,const  weight_type& weight);

    std::pair<iterator, bool> insert_or_assign_edge(const key_type& input_key,const weight_type& weight);

////    ---------------------------|erase|--------------------------------------

    void clear_edges_to_for_node(const key_type& search_key);

    bool erase_edge(const key_type& search_key);

    std::map<key_type, weight_type> get_m_con_nodes(){return m_con_nodes;}

private:
    ////     --------------------------|data|--------------------------------------
    value_type data;
    std::map<key_type, weight_type> m_con_nodes;

};

#endif //GRAPH_NODE_H

#include"Node.hpp"