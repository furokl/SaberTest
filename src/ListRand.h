#ifndef LISTRAND_H
#define LISTRAND_H

#include "ListNode.h"
#include "Constants.h"
#include <iostream>

// @comment: Список
class ListRand
{
public:
    ListNode *m_head;
    ListNode *m_tail;
    int m_count;

    ListRand()
        : m_head(nullptr),
          m_tail(nullptr),
          m_count{}
    {
    }
    ~ListRand()
    {
        clear();
    }
    ListRand(const ListRand &list)
        : m_head(nullptr),
          m_tail(nullptr),
          m_count{}
    {
        deep_copy(list);
    }
    ListRand &operator= (const ListRand &list);
    ListNode *operator[] (int index) { return get_node(index); }

    friend std::ostream &operator<< (std::ostream &out, ListRand &list);
    ListNode *push_front(std::string data);
    ListNode *push_back(std::string data);
    void pop_front();
    void pop_back();
    ListNode *get_node(int index) const;
    ListNode *insert(int index, std::string data);
    void deep_copy(const ListRand &list);
    void clear(int index);
    void clear();
    void set_rand_ref(int index_from, int index_to);
    void clear_rand_ref(ListNode *node);

    void serialize(std::ostream &out) const;
    void deserialize(std::istream &in);
};

#endif // !LISTRAND_H
