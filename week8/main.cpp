// #include <iostream>

// class Log
// {
//     public:
//         enum Level{
//             LevelError = 0, LevelWarning, LevelInfo
//         };
//     private:
//         Level m_LogLevel = LevelInfo;
//     public:
//         Log(Level level){
//             std::cout << "Created Log! " << std::endl;
//             m_LogLevel = level;
//         }

//         ~Log(){
//             std::cout << "Destoryed Log! " << std::endl;
//         }

//         void SetLevel(Level level){
//             m_LogLevel = level;
//         }

//         void Error(const char* message){
//             if (m_LogLevel >= LevelError){
//                 std::cout << "[ERROR]: " << message << std::endl;
//             }
//         }

//         void Warn(const char* message){
//             if (m_LogLevel >= LevelWarning){
//                 std::cout << "[WARNING]: " << message << std::endl;
//             }
//         }

//         void Info(const char* message){
//             if (m_LogLevel >= LevelInfo){
//                 std::cout << "[INFO]: " << message << std::endl;
//             }
//         }
// };

// int main(){
//     Log log(Log::LevelWarning);
//     log.Info("Hello");
//     log.Warn("Hello");
//     log.Error("Hello");
//     log.SetLevel(Log::LevelError);
//     log.Info("Hello");
//     log.Warn("Hello");
//     log.Error("Hello");
//     return 0;
// }


#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename elemType>
void display_message(const string &msg, const vector<elemType> &vec)
{
    cout << msg;
    for (int ix = 0; ix < vec.size(); ++ix)
    {
        elemType t = vec[ix];
        cout << t << ' ';
    }
}

void display_message(const string &msg){
    cout << msg << endl;
}

bool is_size_ok(int size)
{
    const int max_size = 1024;
    if (size <= 0 || size > max_size)
    {
        cerr << "Oops: requested size is not supported : "
            << size << " -- can't fulfill request.\n";
        return false;
    }
    return true;
}

const vector<int>* fibon_seq(int size)
{
    static vector<int> elems;
    if (! is_size_ok(size))
        return 0;
    for (int ix = elems.size(); ix < size; ++ix)
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else elems.push_back(elems[ix-1]+elems[ix-2]);
    return &elems;
}

const vector<int>* lucas_seq(int size)
{
    static vector<int> elems;
    if (! is_size_ok(size))
        return 0;
    
    for (int ix = elems.size(); ix < size; ++ix)
    {
        if (ix == 0)
            elems.push_back(2); // L(0) = 2
        else if (ix == 1)
            elems.push_back(1); // L(1) = 1
        else 
            // L(n) = L(n-1) + L(n-2)
            elems.push_back(elems[ix - 1] + elems[ix - 2]);
    }
    return &elems;
}

const vector<int>* pell_seq(int size)
{
    static vector<int> elems;
    if (! is_size_ok(size))
        return 0;
    
    for (int ix = elems.size(); ix < size; ++ix)
    {
        if (ix == 0)
            elems.push_back(0); // P(0) = 0
        else if (ix == 1)
            elems.push_back(1); // P(1) = 1
        else 
            // P(n) = 2 * P(n-1) + P(n-2)
            elems.push_back(2 * elems[ix - 1] + elems[ix - 2]);
    }
    return &elems;
}

const vector<int>* triangular_seq(int size)
{
    static vector<int> elems;
    if (! is_size_ok(size))
        return 0;
    
    for (int ix = elems.size(); ix < size; ++ix)
    {
        if (ix == 0)
            elems.push_back(1); // T(0) = 1
        else 
            // T(n) = T(n-1) + (n+1)
            elems.push_back(elems[ix - 1] + (ix + 1));
    }
    return &elems;
}

const vector<int>* square_seq(int size)
{
    static vector<int> elems;
    if (! is_size_ok(size))
        return 0;
    
    for (int ix = elems.size(); ix < size; ++ix)
    {
        // S(n) = (n+1)^2
        elems.push_back((ix + 1) * (ix + 1));
    }
    return &elems;
}

const vector<int>* pentagonal_seq(int size)
{
    static vector<int> elems;
    if (! is_size_ok(size))
        return 0;
    
    for (int ix = elems.size(); ix < size; ++ix)
    {
        if (ix == 0)
            elems.push_back(1); // P(0) = 1
        else 
            // P(n) = P(n-1) + (3 * (n+1) - 2)
            elems.push_back(elems[ix - 1] + (3 * (ix + 1) - 2));
    }
    return &elems;
}

bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int)){
    
    const vector<int>* pseq = seq_ptr(pos);

    if (!pseq)
    {
        elem = 0;
        display_message("Internal Error: seq_ptr is set to null!");
        return false;
    }

    elem = (*pseq)[pos - 1];
    return true;
}

int main(){

    const vector<int>* (*seq_array[])(int) = {
        fibon_seq, lucas_seq, pell_seq,
        triangular_seq, square_seq, pentagonal_seq
    };

    int pos;
    int elem;
    int seq;
    cout << "Position: ";
    cin >>  pos;

    cout << "Sequence: ";
    cin >> seq;

    if (seq_elem(pos, elem, seq_array[seq]))
    {
        cout << elem << endl;
    }
    else{
        cout << "error" << endl;
    }
    
    return 0;
}