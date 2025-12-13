#include "task.h"
#include <algorithm>

std::vector<int> Triangular::s_elems;

Triangular::Triangular(int length, int beg_pos)
    : m_length(length > 0 ? length : 1), 
      m_beg_pos(beg_pos > 0 ? beg_pos : 1), 
      m_next(m_beg_pos - 1)
{
    int elem_cnt = m_beg_pos + m_length - 1;
    if(s_elems.size() < elem_cnt){
        gen_elements(elem_cnt);
    }

}

Triangular::Triangular(const Triangular& rhs)
    :   m_length(rhs.m_length), m_beg_pos(rhs.m_beg_pos), m_next(rhs.m_beg_pos - 1)
{

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

int Triangular::sum(const Triangular& tri){
    int beg_pos = tri.beg_pos();
    int length = tri.length();
    int sum = 0;
    for (int ix = 0; ix < length; ++ix){
        sum += tri.elem(beg_pos + ix);
    }
    return sum;
}

bool Triangular::is_elem(int value){
    if (!s_elems.size() || s_elems.back() < value)
        gen_elems_to_value(value); // grow s_elems to surpass the value
    
    std::vector<int>::iterator found_it;
    std::vector<int>::iterator end_it = s_elems.end();
    found_it = std::find(s_elems.begin(), end_it, value);
    return found_it != end_it;
}

void Triangular::gen_elements(int length){
    if (length < 0 || length > s_max_elems)
        std::cerr << "Triangular Sequence: oops, an invalid length " << std::endl;
    if (s_elems.size() < length)
    {
        int ix = (s_elems.size() ? s_elems.size() + 1 : 1);
        for ( ; ix <= length; ++ix)
            s_elems.push_back( ix * (ix+1) / 2);
    }
}

void Triangular::gen_elems_to_value(int value){
    int ix = s_elems.size();

    if (!ix) { 
        s_elems.push_back(1); 
        ix = 1; 
    }

    while (s_elems[ix - 1] < value && ix < s_max_elems){ 
        ++ix; 
        s_elems.push_back( ix * (ix+1) / 2); 
    }

    if (ix == s_max_elems)
        std::cerr << "Triangular Sequence: oops, value too large " << std::endl;
}

void Triangular::display(int len, int beg_pos, std::ostream& os){
    if (len < 0 || beg_pos < 0 || beg_pos + len - 1 > s_max_elems)
        std::cerr << "Triangular Sequence: oops, invalid inputs " << std::endl;
    for (int ix = beg_pos - 1; ix < beg_pos + len - 1; ix++)
        os << ' ' << s_elems[ix];
} 

void task_main(){

    Triangular tri1(4);
    Triangular::display(4,1);
    std::cout << " sum of elements: " << Triangular::sum(tri1) << std::endl;
    Triangular tri2(4,3);
    Triangular::display(4, 3);
    std::cout << " sum of elements: " << Triangular::sum(tri2) << std::endl;
    Triangular tri3(4,8);
    Triangular::display(4, 8);
    std::cout << " sum of elements: " << Triangular::sum(tri3) << std::endl;


}