#include "headers/classes.hpp"
#include "functions/functions.hpp"

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
    std::function<void(int8_t)> w_print = [](int8_t value) { std::cout << static_cast<char>(~value); };
    print_letter<-120>(w_print);
    short iter{};
    while (!std::async(std::launch::async, runtime_template_fucntion_call, iter++).get())
    {
    }
    try_printer(1337);
    int* ptr = new int[1];
    delete[] ptr;
    asm_printer bbj(41);
}