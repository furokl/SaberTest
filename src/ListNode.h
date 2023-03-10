#ifndef LISTNODE_H
#define LISTNODE_H

#include <string>
#include <iostream>
// @comment: Узел списка
class ListNode
{
public:
    ListNode *m_prev;
    ListNode *m_next;
    ListNode *m_rand;
    std::string m_data;

    ListNode(const std::string &data)
        : m_data(data),
          m_prev(nullptr),
          m_next(nullptr),
          m_rand(nullptr)
    {
    }
    ListNode(const std::string &&data) 
        : ListNode(data)
    {
    }
    ~ListNode() 
    {
    }

    ListNode(const ListNode &) = delete;
    ListNode &operator= (const ListNode &) = delete;

    ListNode(ListNode &&) = delete;
    ListNode &operator= (ListNode &&) = delete;
};

#endif // !LISTNODE_H
