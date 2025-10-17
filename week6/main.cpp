// #include <iostream>

// #define LOG(x) std::cout << x << std::endl

// // void Increment(int value){
// //     value++;
// // }

// // void Increment(int* value){
// //     (*value)++;
// // }

// void Increment(int& value){
//     value++;
// }

// int main(){

//     int a = 5;
//     Increment(a);
//     // int& ref = a;
//     // ref = 2;

//     int a = 5;
//     int b = 8;
//     int& ref = a;
//     // ref = b; ERROR!
//     // 在rust中更好去理解，ref 是 unmutable 的。 ：）

//     LOG(a);

//     return 0;
// }


// #include <iostream>

// #define LOG(x) std::cout << x << std::endl

// class Player
// {
// public:
//     int x,y;
//     int speed;

//     void Move(int xa, int ya){
//         x += xa * speed;
//         y += ya * speed;
//     }
// };



// int main(){

//     Player Tom;
//     Tom.x = 5;
//     Tom.y = 5;
//     Tom.speed = 5;
    
//     Tom.Move(1, -1);

//     return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

void display(const vector<int> *vec)
{
    if (! vec){
        return;
        cout << "display(): the vector pointer is 0\n";
    }
    for (int ix = 0; ix < vec->size(); ++ix)
        cout << (*vec)[ix] << ' ';
    cout << endl;
}

void swap(int& val1, int& val2){
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

int main(){

    int ia[] = {8, 34, 3, 13, 1, 21, 5, 2};

    vector<int> vec(ia, ia + (sizeof(ia) / sizeof(int)));
    
    cout << "vector before sort : ";
    display(&vec);

    for (size_t ix = 0; ix < vec.size(); ix++)
    {
        for (size_t jx = 0; jx < vec.size(); jx++)
        {
            if (vec[ix] > vec[jx])
            {
                cout << "about to call swap!"
                    << " ix: " << ix << " jx: " << jx << '\t'
                    << " swapping: " << vec[ix]
                    << " with " << vec[jx] << endl; 
                swap(vec[ix], vec[jx]);
            }
        }
    }
    
    cout << "vector after sort : ";
    display(&vec);

    return 0;
}
