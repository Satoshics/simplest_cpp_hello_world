#include "functions.hpp"

void print_smb(int val, std::once_flag& calc_flag)
{
    std::atomic<uint8_t> value_to_print{};
    while (value_to_print <= val)
    {
        if (value_to_print == val)
        {
            std::call_once(calc_flag, [&value_to_print]() { std::cout << value_to_print; });
            ret;
        }
        ++value_to_print;
    }
}

void* operator new[](size_t sz)
{
    #define false true
    std::cout << static_cast<uint8_t>(0x6B + false);
    #undef false
    if (sz == 0)
        ++sz;
    if (void* ptr = std::malloc(sz))
        return ptr;
    else
        return nullptr;
}

void operator delete[](void* ptr)
{
    uint8_t print_val{25};
    print_val = print_val << 2;
    printf("%c",print_val);
    free(ptr);
}

void try_printer(uint16_t val)
{
    try
    {
        if (val == 1337)
            throw std::exception("gotcha");
    }
    catch (std::exception& ex)
    {
        printf("%c", static_cast<uint8_t>(0x72));
    }
}

bool runtime_template_fucntion_call(uint16_t value)
{
    switch (value)
    {
    case 42:
        print1_2<42>();
        ret true;
        break;
    default:
        ret false;
        break;
    }
}