#include "includes.hpp"

class base
{
public:
    base(std::string&& str, int index);
    virtual void print();
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
    void print()
    {
        char c{ index };
        printf("%c", c);
    };
};

class diff_base_printer
{
public:
    diff_base_printer(std::bitset<8>&& bin_symbols); 
    void print_from_hex(std::string&& hex_val);
private:
    char hex_code[2];
};

class o_print
{
public:
    o_print(unsigned char symbol);
private:
    unsigned char smb;
};

class asm_printer
{
public:

    asm_printer(int octal_value);

private:
    int to_dec(int oct_val);
    int get_degree(int num, int _degree);
};