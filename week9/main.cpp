#include <iostream>
#include <string>
#include <array>
#include <vector>

class Entity
{
public:
    static const int exampleSize = 5;
    // static constexpr int exampleSize_expr = 10;
    int *e_example = new int[exampleSize];
    std::array<int, 5> e_another;

    Entity();
    ~Entity();
};

Entity::Entity()
{
    for (size_t i = 0; i < 5; i++)
    {
        e_example[i] = 2;
    }

    for (size_t i = 0; i < e_another.size(); i++)
    {
        e_another[i] = 2;
    }
}

Entity::~Entity()
{
    delete[] e_example;
}

void Lecture31()
{
    int example[5];
    example[0] = 2;
    example[4] = 4;

    // int a = example[0];
    // example[5] = 10;

    for (int i = 0; i < 5; i++)
    {
        example[i] = 2;
    }

    std::cout << example[2] << std::endl;
    int *ptr = example;
    *(ptr + 2) = 6;

    *(int *)((char *)ptr + 8) = 6;

    std::cout << example[2] << std::endl;

    std::cout << example[0] << std::endl;
    std::cout << example << std::endl;

    int *another = new int[5];

    for (int i = 0; i < 5; i++)
    {
        another[i] = 2;
    }

    delete[] another;

    Entity e;
}

template <typename T>
void Print(T value)
{
    cout << value << endl;
}

template <typename T, int N>
class Array
{
private:
    T m_Array[N];

public:
    int GetSize() const { return N; }
};

void Lecture53()
{

    Print<int>(10);
    Print(5.5f);
    Print("Hello");

    Array<int, 5> array;
    std::cout << array.GetSize() << std::endl;
    return;
}

void LectureMain()
{

    Lecture31();
    Lecture53();

    return;
}

template <typename elemType>
const elemType *find(const elemType *first, const elemType *last, const elemType &value)
{
    if (!first || !last)
        return 0;
    for (; first != last; ++first)
        if (*first == value)
            return first;
    return 0;
}

template <typename elemType>
inline const elemType *my_begin(const std::vector<elemType> &vec)
{
    return vec.empty() ? 0 : &vec[0];
}

template <typename elemType>
inline const elemType *my_end(const std::vector<elemType> &vec)
{
    return vec.empty() ? 0 : &vec[0] + vec.size();
}

void TaskMain()
{

    int ia[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    double da[6] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    std::string sa[4] = {"pooh", "piglet", "eeyore", "tigger"};
    const int *pi = find(ia, ia + 8, ia[3]);
    const double *pd = find(da, da + 6, da[3]);
    const std::string *ps = find(sa, sa + 4, sa[3]);
    std::cout << *(pi) << "," << *(pd) << "," << *(ps) << std::endl;

    std::vector<std::string> svec(sa, sa + 4);
    const std::string *pv = find(svec.data(), svec.data() + svec.size(), "tigger");

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

    if (param == "LectureMain")
    {
        LectureMain();
    }
    else if (param == "TaskMain")
    {
        TaskMain();
    }
    else
    {
        std::cout << "Parameter Name Error" << std::endl;
    }

    return 0;
}