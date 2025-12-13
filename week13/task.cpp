#include "task.h"
#include <iostream>

std::vector<int> Triangular::s_elems;

Triangular::Triangular(int length, int beg_pos)
    : m_length(length > 0 ? length : 1), m_beg_pos(beg_pos > 0 ? beg_pos : 1), m_next(m_beg_pos - 1)
{
    int size = m_beg_pos + m_length - 1;
    for (int ix = s_elems.size(); ix < size; ++ix)
    {
        s_elems.push_back( (ix + 1) * (ix + 2) / 2);
    }
}

Triangular::Triangular(const Triangular& rhs)
    :   m_length(rhs.m_length), m_beg_pos(rhs.m_beg_pos), m_next(rhs.m_beg_pos - 1)
{
    int size = m_beg_pos + m_length - 1;
        for (int ix = s_elems.size(); ix < size; ++ix)
    {
        s_elems.push_back( (ix + 1) * (ix + 2) / 2);
    }
}

int Triangular::elem(int pos) const {
    return s_elems[pos - 1];
}

bool Triangular::next(int &val) const {
    if(m_next < m_beg_pos + m_length - 1)
    {
        val = s_elems[m_next++];
        return true;
    }
    return false;
}

int Triangular::sum(const Triangular& trian){
    int beg_pos = trian.beg_pos();
    int length = trian.length();
    int sum = 0;
    for (int ix = 0; ix < length; ++ix){
        sum += trian.elem(beg_pos + ix);
    }
    return sum;
}

void task_main(){

    Triangular tri1(4);
    std::cout << "sum of elements: " << Triangular::sum(tri1) << std::endl;
    Triangular tri2(4,3);
    std::cout << "sum of elements: " << Triangular::sum(tri2) << std::endl;
    Triangular tri3(4,8);
    std::cout << "sum of elements: " << Triangular::sum(tri3) << std::endl;

}