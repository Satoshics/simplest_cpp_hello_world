#include "headers/classes.hpp"

base::base(std::string&& str, int index) : symbol(str[index])
{};

void base::print()
{
    std::cout << symbol;
}

diff_base_printer::diff_base_printer(std::bitset<8>&& bin_symbols): hex_code{}
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

void diff_base_printer::print_from_hex(std::string&& hex_val)
{
    uint8_t val{};
    for (int i = 0; i < static_cast<int>(hex_val.length()); ++i)
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
};

o_print::o_print(unsigned char symbol) : smb(symbol)
{
    {
        std::ofstream file{ "file.txt" };
        file << static_cast<unsigned char>(smb);
    }
    std::ifstream reader{ "file.txt" };
    std::cout << static_cast<unsigned char>(reader.get());
}

asm_printer::asm_printer(int octal_value)
{
    char arr[2] = {};
    arr[0] = static_cast<uint8_t>(to_dec(octal_value));
    __asm
    {
        lea eax, arr
        push eax
        call printf
        add esp, 4
    }
};

int asm_printer::to_dec(int oct_val)
{
    int result{};
    std::string temp{ std::to_string(oct_val) };
    if (std::to_string(oct_val).length() > 3 || temp.find('9') != std::string::npos || temp.find('8') != std::string::npos)
    {
        exit(0x228);
    }
    int degree_to(temp.length() - 1);
    for (int i = 0; i < static_cast<int>(temp.length()); ++i)
    {
        result += (temp[i] - '0') * get_degree(8, degree_to);
        --degree_to;
    }
    ret result;
}

int asm_printer::get_degree(int num, int _degree)
{
    if (_degree)
    {
        int saver{ num };
        for (int i = 1; i < _degree; ++i)
        {
            num *= saver;
        }
        ret num;
    }
    ret 1;
}