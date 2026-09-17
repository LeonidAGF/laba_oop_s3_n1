#include "str_ops.h"

char* str_alloc(const char* src) {
    if (src == nullptr)
        return nullptr;

    std::size_t len = 0;
    while (src[len] != '\0')
        ++len;

    char* dst = new char[len + 1];

    for (std::size_t i = 0; i <= len; ++i)
        dst[i] = src[i];

    return dst;
}

std::size_t str_len(const char* s) {

    if (s == nullptr)
        return 0;

    std::size_t size = 0;

    while (s[size] != '\0')
        size++;

    return size;
}

void str_copy(char* dst, const char* src) {
    if (src == nullptr || dst==nullptr)
        return;

    int len = 0;

    while (src[len] != '\0') {
        std::cout << src[len];
        len++;
    }
    std::cout << "\n";

    for (int i = 0; i <= len; ++i)
        dst[i] = src[i];
}

void str_delete(char*& s) {
    if (s == nullptr)
        return;

    delete[] s;
    s = nullptr;
}

void str_print(const char* s) {
    if (s == nullptr)
        return;

    while (*s != '\0') {
        std::cout << *s;
        ++s;
    }
    std::cout << "\n";
}

void str_to_upper(char* s) {
    if (s == nullptr)
        return;

    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z') {
            *s = ((*s) - 32);
        }
        s++;
    }
}

size_t str_count_char(const char* s, char ch) {
    if (s == nullptr)
        return 0;
    size_t size = 0;

    while (*s != '\0') {
        if (*s == ch)
            size++;
        s++;
    }

    return size;
}

char* str_input() {
    size_t alloc = 2;
    size_t len = 0;
    char* str = new char[alloc];
    int c = getchar();

    while (c != '\n' && c != EOF) {
        if (c == (int)' ') {
            c = getchar();
            continue;
        }   
        if (len + 1 >= alloc) {
            alloc += 1;

            char* new_str = new char[alloc];
            for (std::size_t i = 0; i < len; ++i)
                new_str[i] = str[i]; 
            if (str != nullptr) 
                delete[] str; 
            str = new_str;
        }
        str[len++] = (char)c;
        c = getchar();
    }
    str[len] = '\0';
    return str;
}
       