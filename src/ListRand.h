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
    ListNode *operator[] (const int &index) const { return get_node(index); }
    friend std::ostream &operator<< (std::ostream &out, ListRand &list);

    ListNode *push_front(const std::string &data);
    ListNode *push_back(const std::string &data);
    void pop_front();
    void pop_back();
    ListNode *get_node(const int &index) const;
    int get_index(ListNode *head, ListNode *find) const;
    ListNode *insert(const int &index, const std::string &data);
    void deep_copy(const ListRand &list);
    void clear(const int &index);
    void clear();
    void set_rand_ref(const int &index_from, const int &index_to);
    void clear_rand_ref(ListNode *node);

    void serialize(std::ostream &out) const;
    void deserialize(std::istream &in);



    ListNode *operator[] (const int &&index) const { return get_node(index); }
    ListNode *get_node(const int &&index) const { return get_node(index); };
    void clear(const int &&index) { clear(index); };
    void set_rand_ref(const int &&index_from, const int &&index_to) { set_rand_ref(index_from, index_to); };
    ListNode *insert(const int &&index, const std::string &&data) { return insert(index, data); };
    ListNode *push_front(const std::string &&data) { return push_front(data); }
    ListNode *push_back(const std::string &&data) { return push_back(data); }
};

#endif // !LISTRAND_H
