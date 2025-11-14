#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <functional>

std::string GetName(){
    return "Cherno";
}

class Device{};

class DeviceManager
{
    private:
        std::unordered_map<std::string, std::vector<Device*>> m_Devices;
    public:
        const std::unordered_map<std::string, std::vector<Device*>>& GetDevice() const
        {
            return m_Devices;
        }
};

void Lecture56(){

    auto name = GetName();

    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

    for (auto i = strings.begin(); i != strings.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    
    DeviceManager dm;
    // const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevice();
    const auto& devices = dm.GetDevice();

    return;

}

void Helloworld(int a){
    std::cout << "Hello World Value: " << a << std::endl;
}

void PrintValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}

// void ForEach(const std::vector<int>& values, void(*func)(int)){
//     for (int value: values)
//         func(value);
// }

void Lecture58(){

    typedef void(*HelloworldPtr)(int);

    HelloworldPtr fun = Helloworld;

    void(*cherno)(int) = Helloworld;

    auto function = Helloworld;

    function(10);

    // std::vector<int> values = {1, 5, 4, 2, 3};
    // ForEach(values, [](int value){std::cout << "Value: " << value << std::endl;});

    return;
}

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func){
    for (int value: values)
        func(value);
}

void Lecture59()
{
    std::vector<int> values = {1, 5, 4, 7, 2, 3};
    auto it = std::find_if(values.begin(), values.end(), [](int value){ return value > 3; });
    std::cout << *it << std::endl;
    int a  = 5;

    auto lambda = [=](int value){std::cout << "Value: " << a << std::endl;};
    ForEach(values, lambda);
}
void LectureMain()
{
    Lecture56();
    Lecture58();
    Lecture59();
    return;
}

template <typename IteratorType, typename elemType>
IteratorType my_find(IteratorType first, IteratorType last, const elemType &value)
{
    for (; first != last; ++first)
        if (*first == value)
            return first;
    return last;
}

void TaskMain()
{

    int ia[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    double da[6] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    std::string sa[4] = {"pooh", "piglet", "eeyore", "tigger"};
    const int *pi = my_find(ia, ia + sizeof(ia)/sizeof(int), ia[3]);
    const double *pd = my_find(da, da + sizeof(da)/sizeof(double), da[3]);
    auto ps = my_find(sa, sa + sizeof(sa)/sizeof(std::string), sa[3]);
    std::cout << *(pi) << "," << *(pd) << "," << *(ps) << std::endl;

    std::vector<std::string> svec(sa, sa + 4);
    auto pv = my_find(svec.begin(), svec.end(), "tigger");

    std::cout << *(pv) << std::endl;
}

int main(int argc, char *argv[])
{

    std::cout << argc << "," << argv[argc - 1] << std::endl;

    if (argc != 2)
    {
        std::cout << "Parameter Number Error" << std::endl;
        return 1;
    }

    std::string param = argv[1];

    if (param == "lmain")
    {
        LectureMain();
    }
    else if (param == "tmain")
    {
        TaskMain();
    }
    else
    {
        std::cout << "Parameter Name Error" << std::endl;
    }

    return 0;
}