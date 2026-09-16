#include "str_ops.h"

char* str_alloc(const char* src) {
    if (src == nullptr)
        return nullptr;

    std::size_t len = 0;
    while (src[len] != '\0')
        ++len;

    char* dst = new char[len + 1];
    if (dst == nullptr)
        return nullptr;

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

    int* len = new int(0);
    if (len == nullptr) {
        return;
    }

    while (src[*len] != '\0') {
        std::cout << src[*len];
        len++;
    }
    std::cout << "\n";

    for (int i = 0; i <= *len; ++i)
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
        std::cout << *s << std::endl;
        ++s;
    }
}

void str_to_upper(char* s) {
    if (s == nullptr)
        return;

    while (*s != '\0') {
        if (*s > 'a' && *s < 'z') {
            *s = ((*s) - 32);
        }
    }
}

size_t str_count_char(const char* s, char ch) {
    if (s == nullptr)
        return 0;
    size_t size = 0;

    while (*s != '\0') {
        if (*s == ch)
            size++;
    }

    return size;
}