#include "ListRand.h"
#include <unordered_map>
#include <cassert>

// @comment: operator<<
std::ostream &operator<< (std::ostream &out, ListRand &list) {
    if (list.m_head == nullptr || list.m_tail == nullptr) return out;
    ListNode *begin = list.m_head;
    ListNode *end = list.m_tail->m_next;
    for (auto *ptr = begin; ptr != end; ptr = ptr->m_next)
    {
        out << ptr->m_data << '\t' << ptr << ' ' << ptr->m_rand << '\n';
    }
    return out;
}

// @comment: operator=
ListRand& ListRand::operator= (const ListRand &list) {
	if (this == &list) return *this;

    clear();
    deep_copy(list);

    return *this;
}

// @comment: Добавление узла в начало списка
ListNode *ListRand::push_front(const std::string &data)
{
    auto *ptr = new (std::nothrow) ListNode(data);
    if (ptr == nullptr) return nullptr;

    ptr->m_next = m_head;

    if (m_head != nullptr) m_head->m_prev = ptr;
    if (m_tail == nullptr) m_tail = ptr;

    m_head = ptr;
    ++m_count;

    return ptr;
}

// @comment: Добавление узла в конец списка
ListNode *ListRand::push_back(const std::string &data)
{
    auto *ptr = new (std::nothrow) ListNode(data);
    if (ptr == nullptr) return nullptr;

    ptr->m_prev = m_tail;

    if (m_head == nullptr) m_head = ptr;
    if (m_tail != nullptr) m_tail->m_next = ptr;

    m_tail = ptr;
    ++m_count;

    return ptr;
}

// @comment: Удаление узла из начала списка
void ListRand::pop_front()
{
    if (m_head == nullptr) return;

    ListNode *ptr = m_head->m_next;
    (ptr != nullptr)
        ? ptr->m_prev = nullptr
        : m_tail = nullptr;

    clear_rand_ref(m_head);
    delete m_head;
    m_head = ptr;
    --m_count;
}

// @comment: Удаление узла из конца списка
void ListRand::pop_back()
{
    if (m_tail == nullptr) return;

    ListNode *ptr = m_tail->m_prev;
    (ptr != nullptr)
        ? ptr->m_next = nullptr
        : m_head = nullptr;

    clear_rand_ref(m_tail);
    delete m_tail;
    m_tail = ptr;
    --m_count;
}

// @comment: Вернуть узел по индексу
ListNode* ListRand::get_node(const int &index) const {
    if (index > m_count) return nullptr;

    ListNode *ptr = m_head;
    for (int n{}; n < index; ++n)
    {
        if (ptr == nullptr) return ptr;
        ptr = ptr->m_next;
    }
    return ptr;
}

// @comment: Вернуть индекс по узлу (с указанием головы)
int ListRand::get_index(ListNode *head, ListNode *find) const{
    for (int i{}; head != nullptr; head = head->m_next, ++i)
        if (head == find) return i;

    return -1;
}

// @comment: Вставить узел по индексу
ListNode* ListRand::insert(const int &index, const std::string &data) {
    ListNode *right = get_node(index);
    if (right == nullptr) return push_back(data);

    ListNode *left = right->m_prev;
    if (left == nullptr) return push_front(data);

    auto *ptr = new (std::nothrow) ListNode(data);
    if (ptr == nullptr) return nullptr;

    ptr->m_next = right;
    ptr->m_prev = left;
    right->m_prev = ptr;
    left->m_next = ptr;

    ++m_count;
    return ptr;
}

// @comment: Глубокое копирование
void ListRand::deep_copy(const ListRand &list) {
    std::unordered_map<int, ListNode *> map;

    ListNode *ptr = list.m_head;
    while (m_count != list.m_count)
    {
        if (ptr->m_rand != nullptr)
            map.insert(std::make_pair(m_count, ptr->m_rand));

        push_back(ptr->m_data);
        ptr = ptr->m_next;
    }
    
    for (auto &el : map) //
        get_node(el.first)->m_rand = get_node(
            get_index(list.m_head, el.second));
}

// @comment: Удалить узел по индексу
void ListRand::clear(const int &index) {
    ListNode *ptr = get_node(index);
    if (ptr == nullptr) return;
    if (m_tail == ptr) { pop_back(); return; }
    if (m_head == ptr) { pop_front(); return; }

    ListNode *left = ptr->m_prev;
    ListNode *right = ptr->m_next;

    left->m_next = right;
    right->m_prev = left;

    clear_rand_ref(ptr);
    delete ptr;
    --m_count;
}

// @comment: Очистка списка
void ListRand::clear() {
    while (m_tail != nullptr)
    {
        pop_back();
    }
}

// @comment: Установить дополнительную связь узлу
void ListRand::set_rand_ref(const int &index_from, const int &index_to) {
    ListNode *to = get_node(index_to);
    if (to != nullptr) get_node(index_from)->m_rand = get_node(index_to);
}

// @comment: Очистить дополнительную связь узла
void ListRand::clear_rand_ref(ListNode* node) {
    for (ListNode *ptr(m_head); ptr != nullptr; ptr = ptr->m_next)
    {
        if (ptr->m_rand == node) 
            ptr->m_rand = nullptr;
    }
}

// _______________________________________________
//  Serialize
// _______________________________________________
void ListRand::serialize(std::ostream& out) const {
    std::unordered_map<ListNode *, int> map;

    ListNode *ptr = m_head;
    for (int pos{}; ptr != nullptr; ++pos, ptr = ptr->m_next)
        map.insert(std::make_pair(ptr, pos));

    ptr = m_head;
    out << m_count;
    while (ptr != nullptr) 
    {
        out << cnst::separator << ptr->m_data << cnst::separator;
        (ptr->m_rand == nullptr)
            ? out << cnst::null_rand
            : out << map[ptr->m_rand];
        ptr = ptr->m_next;
    }

    assert(!(out.fail() || out.bad()));
}

// _______________________________________________
//  Deserialize
// _______________________________________________
void ListRand::deserialize(std::istream &in) {
    std::unordered_map<ListNode *, int> map;
    std::vector<ListNode *> list_rand;
    std::string data;
    ListNode *ptr;

    {
        int count;
        in >> count;
        list_rand.reserve(std::move(count));
    }

    while (!in.eof())
    {
        in >> data;
        ptr = push_back(data);
        list_rand.push_back(std::move(ptr));

        int pos;
        in >> pos;
        if (pos != cnst::null_rand)
            map.insert(std::make_pair(ptr, std::move(pos)));
    }
    
    assert(!(in.fail() || in.bad()));
    assert(list_rand.size() == m_count);

    for (auto &el : map)
        el.first->m_rand = list_rand[el.second];
}