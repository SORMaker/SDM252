#include <iostream>

void Log(const char* message);
int Multiply(int a, int b);

int main(){
    std::cout << Multiply(5,2) << std::endl;

    std::cin.get();
    return 0;
}