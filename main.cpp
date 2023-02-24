/*
* Created by Logunov on 22/02/23
* Техническое задание №1
*/

#include "ListRand.h"
#include <fstream>

int main()
{
    ListRand list;

    // Test ListRand
    list.push_back("22b");
    list.push_back("333b");
    list.push_back("4444b");
    list.push_back("55555b");
    list.push_front("55555f");
    list.push_front("4444f");
    list.push_front("333f");
    list.push_front("22f");

    list.set_rand_ref(0, 0);
    list.set_rand_ref(1, 4);
    list.set_rand_ref(2, 4);
    list.set_rand_ref(3, 7);

    list.clear(5);
    list.pop_back();
    list.pop_front();

    std::cout <<
        list[0]->m_data << '\n' <<
        list[1]->m_data << '\n' <<
        "\tList:" << '\n' << list <<
        "________________________" << '\n' << std::endl;


    // serialize
    std::ofstream outf(cnst::patch);
    list.serialize(outf);
    outf.close();

    // ~ListRand()
    list.clear();
    std::cout << 
        "List cleaned" << '\n' <<
        "________________________" << '\n' << std::endl;

    // deserialize
    std::ifstream inf(cnst::patch);
    list.deserialize(inf);
    inf.close();

    std::cout << "\tList:" << '\n' << list;
}