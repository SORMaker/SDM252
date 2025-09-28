#include <iostream>
#include "log.h"
using namespace std;
/*
int Multiply(int a, int b){
    return a * b;
}

void MultiplyAndLog(int a, int b){
    int result = Multiply(a, b);
    cout << result << endl;
}
*/


int main(){
/*  
    int variable = 8; // 4bytes: -2^31 -- 2^31 -1
    cout << variable << endl;
    
    variable = 20;
    cout << variable << endl;

    unsigned int var = 200; // 4bytes: 0 -- 2^32 -1
    cout << var << endl;

    char a = 'a';
    char b = 98;
    cout << a << endl;
    cout << b << endl;

    float varf = 5.5; // 4bytes
    double vard = 5.6; // 8bytes
    cout << varf << endl;
    cout << vard << endl;

    bool varb = true; // 1byte
    cout << varb << endl;

    cout << sizeof(bool) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;
    cout << sizeof(long double) << endl;
*/

/*    
    int result = Multiply(2,3);
    cout << result << endl;

    MultiplyAndLog(3, 4);
*/

    InitLog();
    Log("Hello");
return 0;
}
