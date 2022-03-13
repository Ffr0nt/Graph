//
// Created by Фёдор Захаров on 13.03.2022.
//

#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

template<typename Key,
        typename Value,
        typename Weight
>
class Node {
public:
    using key_type = Key;
    using mapped_type = Value;
    using weight_type = Weight;
    using iterator = typename std::map<key_type, Weight> ::iterator;
    using const_iterator = typename std::map<key_type, Weight>::const_iterator;
//    -----------------------|constructors|--------------------------------------
    Node() = default;
    Node(const Node& obj):data(obj.data),m_con_nodes(obj.m_con_nodes) {};

//    ------------------------|iterators|--------------------------------------

    iterator begin(){return m_con_nodes.begin();}
    const_iterator begin() const {return m_con_nodes.cbegin();}
    iterator end(){return m_con_nodes.end();}
    const_iterator end() const{return m_con_nodes.cend();}

    const_iterator cbegin() const {return m_con_nodes.cbegin();}
    const_iterator cend() const {return m_con_nodes.cend();}


    //    ------------------------|methods|--------------------------------------
    size_t size() const{return m_con_nodes.size();}

    bool empty() const {return size() == 0;}

    void clear() {m_con_nodes.clear();}

    Weight* value() const {return *data;}

    void swap(Node& obj){};

private:
    Weight data;
    std::map<key_type, mapped_type> m_con_nodes;
};



#endif //GRAPH_NODE_H
