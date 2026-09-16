#pragma once

#include <cstddef>
#include <iostream>


char* str_alloc(const char* src); // копия строки в новой динамической памят
std::size_t str_len(const char* s); // длина до '\0'
void str_copy(char* dst, const char* src); // копирование в существующий буфер
void str_delete(char*& s); // delete[] и обнулить
void str_print(const char* s);
void str_to_upper(char* s);
size_t str_count_char(const char* s, char ch);