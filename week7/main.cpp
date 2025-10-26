// #include <iostream>
// #include <string>

// void PrintString(const std::string& string){
//     // string += "h";

//     std::cout << string << std::endl;
// }

// int main(){
//     // char* name = "Cherno";
//     // char name2[] = {'C', 'h', 'e', 'r', 'n', 'o'};
//     // std::cout << name << std::endl;
//     // std::cout << name2 << std::endl;

//     // std::string name = "Cherno";
//     // name += " hello!";

//     std::string name = std::string("Cherno") + " hello!";
    
//     bool contains = name.find("no") != std::string::npos;
//     if(contains) std::cout << name.size() << std::endl;
    
//     PrintString(name);

//     return 0;
// }


// #include <iostream>
// #include <string>

// struct Vector3
// {
//     float x,y,z;

//     Vector3()
//         : x(10), y(11), z(12){}
// };


// int main(){
//     {
//         //stack
//         int value = 5; 
//         int array[5];
//         array[0] = 1;
//         array[1] = 2;
//         array[2] = 3;
//         array[3] = 4;
//         array[4] = 5;
//         Vector3 vector;
//     }

//     //heap
//     int* hvalue = new int; 
//     *hvalue = 5;
//     int* harray = new int[5];
//     harray[0] = 1;
//     harray[1] = 2;
//     harray[2] = 3;
//     harray[3] = 4;
//     harray[4] = 5;
//     Vector3* hvector = new Vector3();

//     delete hvalue;
//     delete[] harray;
//     delete hvector;

//     return 0;
// }


#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

const vector<int> *fibon_seq(int size)
{
    // Lazy Computation
    /*

        因为static的存在，elems这个vector不会重复生成，仅在最初创建一次。
        比如一开始生成的是5，这样我会创建一个长度为5的elems。
        之后，我查询5以内的位置，根据ix = elems.size()，我不会再次生成，而是直接查询输出。
        如果我查询5之后的位置，根据ix = elems.size() = 5，他会从5开始计算后面的。
        这就叫lazy computation或者动态规划，我可以根据需求随时更新，并且不会增加我的运行开销，并且启动速度快。
        
        而还有一种策略叫pre computation，就是我们预先生成一个大的数组，存储所有可能的位置，比如这里是1-1024.
        这会在一开始就进行大量的计算，并且肯能会产生大量的无用内存开销，比如可能1024这个位置我们永远也不可能输入，
        这样就增加了我们的时间成本和内存成本。

        所以在lazy computation中，static是关键。

    */
    static vector<int> elems;
    if (! is_size_ok(size))
        return 0;
    for (int ix = elems.size(); ix < size; ++ix)
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else elems.push_back(elems[ix-1]+elems[ix-2]);
    return &elems;
}

inline bool fibon_elem(int pos, int &elem)
{
    const vector<int> *pseq = fibon_seq(pos);
    if (! pseq)
    {
        elem = 0; 
        return false; 
    }
    elem = (*pseq)[pos-1];
    return true;
}

int main(){

    int pos;
    int elem;
    cin >> pos;
    if (fibon_elem(pos, elem))
    {
        cout << elem << endl;
    }
    else{
        cout << "error" << endl;
    }
    
    return 0;
}