/*
* Created by Logunov on 22/02/23
* Техническое задание №1
*/

#include "ListRand.h"
#include <fstream>

int main()
{
    ListRand list;

    // methods
    list.push_front("111");
    list.push_front("222");
    list.push_front("333");
    list.push_front("444");
    list.pop_front();
    std::cout << list << '\n';
    list.clear();

    list.push_back("111");
    list.push_back("222");
    list.push_back("333");
    list.push_back("444");
    list.pop_back();
    std::cout << list << '\n';

    list.set_rand_ref(0, 2);
    list.set_rand_ref(1, 1);
    list.set_rand_ref(2, 0);
    std::cout << list << '\n';

    list.insert(0, "000_");
    list.insert(3, "333_");
    list.insert(5, "555_");
    std::cout << list << '\n';

    list.clear(5);
    list.clear(5);
    list.clear(5);
    list.clear(5);
    list.clear(5);
    list.clear(3);
    list.clear(0);
    list.push_back("444");
    std::cout << list << '\n';

    // operator[]
    std::cout <<
        list[0]->m_data << '\n' <<
        list[1]->m_data << '\n' << std::endl;

    std::cout <<
        "// FILE " << '\n';

    std::cout <<
        "\tList:" << '\n' << list <<
        "Count: " << list.m_count << '\n' <<
        "________________________" << '\n' << std::endl;

    // serialize
    std::ofstream outf(cnst::patch);
    list.serialize(outf);
    outf.close();

    // clear
    list.clear();

    std::cout << 
        "List cleaned" << '\n' <<
        "Count: " << list.m_count << '\n' <<
        "________________________" << '\n' << std::endl;

    ListRand list2;

    // deserialize
    std::ifstream inf(cnst::patch);
    list2.deserialize(inf);
    inf.close();

    std::cout << "\tList2:" << '\n' << list2 << 
        "Count: " << list2.m_count << '\n' <<
        "________________________" << '\n' << std::endl;

    std::ifstream inf2(cnst::patch);
    list.deserialize(inf2);
    inf2.close();

    std::cout << "\tList:" << '\n' << list << 
        "Count: " << list.m_count << '\n' <<
        "________________________" << '\n' << std::endl;

    // operator=
    list2.push_back("GHOST");
    list2 = list;

    std::cout << "\v\vOperator=" << '\n' <<
        "\tList1:" << '\n' << list <<
        "Count: " << list.m_count << '\n' << std::endl <<
        "\tList2:" << '\n' << list2 << 
        "Count: " << list2.m_count << '\n' <<
        "________________________" << '\n' << std::endl;

    // copy constructor()
    ListRand list3 = list;
    std::cout << "\v\vCopy Constructor()" << '\n' <<
        "\tList1:" << '\n' << list <<
        "Count: " << list.m_count << '\n' << std::endl <<
        "\tList3:" << '\n' << list3 << 
        "Count: " << list3.m_count << '\n' <<
        "________________________" << '\n' << std::endl;
}