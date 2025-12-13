#pragma once


#include <vector>

class Triangular{
private:
    int m_length;
    int m_beg_pos;
    mutable int m_next;
    static std::vector<int> s_elems;
public:
    Triangular(int length = 1, int beg_pos = 1);
    Triangular(const Triangular& rhs);
    int length() const { return m_length; }
    int beg_pos() const { return m_beg_pos; }
    int elem(int pos) const;
    bool next(int& val) const;
    void next_reset() {m_next = m_beg_pos - 1; }
    static int sum(const Triangular& trian);
};


void task_main();
