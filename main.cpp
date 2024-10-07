#include "headers/classes.hpp"

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
    std::cout << "world";
    if (sz == 0)
        ++sz;
    if (void* ptr = std::malloc(sz))
        return ptr;
    else
        return nullptr;
}

int main()
{
    base b{ std::string{"ak;hladf"},3 };
    b.print();
    derived<101> d;
    d.print();
    diff_base_printer dd(std::move(std::bitset<8>{"00110110"}));
    dd.print_from_hex(std::move(std::string("6C")));
    o_print obj{111};
    {
        std::vector<std::jthread> arr_printer;
        int thread_amount = std::thread::hardware_concurrency();
        arr_printer.reserve(thread_amount);
        std::once_flag guarantor{};
        for (int i = 0; i < thread_amount; ++i)
        {
            arr_printer.emplace_back(print_smb, 32, std::ref(guarantor));
        }
    }
    int* ptr = new int[1];
    asm_printer bbj(41);
}