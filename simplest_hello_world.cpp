#include <iostream>
#include <bitset>
#include <memory>
#include <stdio.h>
#include <string>
#include <utility>
class base
{
public:
    base(std::string&& str, int index) : symbol(str[index])
    {};
    virtual void print()
    {
        std::cout << symbol;
    }
private:
    char symbol;
};
template<int index>
class derived : base
{
public:
    derived() : base{ "0", NULL }
    {
        if (index > 255)
        {
            exit(0x16);
        }
    };
    void print() override
    {
        char c{ index };
        printf("%c", c);
    }
};
class diff_base_printer
{
public:
    diff_base_printer(std::bitset<8> bin_symbols)
    {
        unsigned char result{};
        int value{};
        int bit_iter{};
        for (int i = 0; i < 8; ++i)
        {
            switch (bin_symbols[i])
            {
            default:
                bit_iter++;
                break;
            case 1:
                switch (bit_iter++)
                {
                case 0:
                    value += 8;
                    break;
                case 1:
                    value += 4;
                    break;
                case 2:
                    value += 2;
                    break;
                default:
                    value += 1;
                    break;
                }
                break;
            }
            if (i == 3 || i == 7)
            {
                hex_code[i > 4 ? 1 : 0] = value;
                value = 0;
                bit_iter = 0;
            }
        }
        result = hex_code[0] * 16 + hex_code[1];
        std::cout << result;
    }
    void print_from_hex(std::string&& hex_val)
    {
        uint8_t val{};
        for (int i = 0; i < hex_val.length(); ++i)
        {
            if (!std::isdigit(hex_val[i]))
            {
                if (hex_val.length() - 1 == i)
                {
                    switch (hex_val[i])
                    {
                    case 'F':
                        val += 15;
                        break;
                    case 'E':
                        val += 14;
                        break;
                    case 'D':
                        val += 13;
                        break;
                    case 'C':
                        val += 12;
                        break;
                    case 'B':
                        val += 11;
                        break;
                    case 'A':
                        val += 10;
                        break;
                    }
                }
            }
            else
            {
                if (hex_val.length() - 1 == i)
                {
                    val += hex_val[i];
                }
                val += hex_val[i] * 16;
            }

        }
        std::cout << val;
    }
private:
    char hex_code[2];
};

void* operator new[](std::size_t sz)
{
    std::cout << "o world";
    if (sz == 0)
        ++sz;
    if (void* ptr = std::malloc(sz))
        return ptr;

}
int main()
{
    base b{ std::string{ "ak;hladf" },3 };
    b.print();
    derived<101> d;
    d.print();
    diff_base_printer dd(std::move(std::bitset<8>{"00110110"}));
    dd.print_from_hex(std::move(std::string("6C")));
    int* ptr = new int[2];
    return 0;
}