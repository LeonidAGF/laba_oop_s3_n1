#include <gtest/gtest.h>
#include "str_ops.h"


TEST(counttest, Count) {
    EXPECT_EQ(str_count_char("kiiiii", 'i'), 5);
}

TEST(counttest, MissingCount) {
    EXPECT_EQ(str_count_char("kiiiii", 'x'), 0);
}

TEST(alloctest, EmptyAlloc) {
    char* s = str_alloc("");
    EXPECT_EQ(s[0], '\0');
    str_delete(s);
}

TEST(alloctest, NullptrAlloc) {
    char* s = str_alloc(nullptr);
    EXPECT_EQ(s, nullptr);
}

TEST(lentest, Length) {
    EXPECT_EQ(str_len("hello"), 5);
}

TEST(lentest, EmptyLength) {
    EXPECT_EQ(str_len(""), 0);
}

TEST(uppertest, Upper) {
    char s[] = "hell";
    str_to_upper(s);
    EXPECT_EQ(s[0], 'H');
    EXPECT_EQ(s[1], 'E');
    EXPECT_EQ(s[2], 'L');
    EXPECT_EQ(s[3], 'L');
    EXPECT_EQ(s[4], '\0');
}

TEST(deletetest, Delete) {
    char* s = str_alloc("byby");
    str_delete(s);
    EXPECT_EQ(s, nullptr);
}

TEST(copytest, Copy) {
    char dst[20];
    str_copy(dst, "hi");
    EXPECT_EQ(dst[0], 'h');
    EXPECT_EQ(dst[1], 'i');
    EXPECT_EQ(dst[2], '\0');
}

TEST(alloctest, Alloc) {
    char* s = str_alloc("hello");
    EXPECT_EQ(s[0], 'h');
    EXPECT_EQ(s[1], 'e');
    EXPECT_EQ(s[2], 'l');
    EXPECT_EQ(s[3], 'l');
    EXPECT_EQ(s[4], 'o');
    EXPECT_EQ(s[5], '\0');
    
    str_delete(s);
}
