#ifndef LISTNODE_H
#define LISTNODE_H

#include <string>

// @comment: Ёлемент списка
class ListNode
{
public:
    ListNode *m_prev;
    ListNode *m_next;
    ListNode *m_rand;
    std::string m_data;

    ListNode(std::string data)
        : m_data(data),
          m_prev(nullptr),
          m_next(nullptr),
          m_rand(nullptr)
    {
    }
};

#endif // !LISTNODE_H
