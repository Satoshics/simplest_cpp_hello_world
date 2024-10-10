#pragma once
#include <iostream>
#include <atomic>
#include <mutex>
#include <functional>
#include <future>
#define ret return
void print_smb(int val, std::once_flag& calc_flag);
void* operator new[](size_t sz);
void operator delete(void* ptr);
void try_printer(uint16_t val);
bool runtime_template_fucntion_call(uint16_t value);

template <short num>
void print_letter(std::function<void(int8_t)>& printer)
{
	printer(num);
}

template <short num>
inline void print1_2()
{
}

template <>
inline void print1_2<42>()
{
	std::cout << static_cast<unsigned char>(42 ^ 69);
}