#pragma once

#include <vector>
#include <iostream>

class Triangular{
private:
    int m_length;
    int m_beg_pos;
    mutable int m_next;
    static std::vector<int> s_elems;
    static const int s_max_elems = 1024;
public:
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
};


void task_main();
