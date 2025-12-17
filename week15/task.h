#pragma once

#include <vector>
#include <iostream>
#include "Triangular_iterator.h"
#include <stdexcept>

class iterator_overflow : public std::logic_error {
public:
    iterator_overflow(const std::string& msg = "Triangular Iterator Overflow") 
        : std::logic_error(msg) { }
};

class Triangular{
private:
    int m_length;
    int m_beg_pos;
    mutable int m_next;
    static std::vector<int> s_elems;
    static const int s_max_elems = 1024;
public:
    typedef Triangular_iterator iterator;
    iterator begin() const {return iterator(m_beg_pos);}
    iterator end() const {return iterator(m_beg_pos + m_length);}
    Triangular(int length = 1, int beg_pos = 1);
    Triangular(const Triangular& rhs);
    int length() const { return m_length; }
    int beg_pos() const { return m_beg_pos; }
    int elem(int pos) const;
    bool next(int& val) const;
    void next_reset() {m_next = m_beg_pos - 1; }
    static int sum(const Triangular& trian);

    static bool is_elem(int value);
    static void gen_elements(int length);
    static void gen_elems_to_value(int value);
    static void display(int len, int beg_pos, std::ostream& os = std::cout); 

    friend class Triangular_iterator;
};


void task_main();
