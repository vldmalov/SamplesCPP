#include <gtest/gtest.h>
#include <cstring>

#include "CustomString.h"

TEST(CustomStringCreation, DefaultConstructor) {
    CustomString str;

    EXPECT_EQ(str.GetSize(), 0);

    ASSERT_NE(str.GetData(), nullptr);
    EXPECT_STREQ(str.GetData(), "");
}

TEST(CustomStringCreation, CStringConstructor) {
    char cStr[] = "The testing C-sting";
    CustomString str(cStr);

    EXPECT_EQ(str.GetSize(), strlen(cStr));
    EXPECT_NE(str.GetData(), cStr);
    EXPECT_STREQ(str.GetData(), cStr);
}

TEST(CustomStringCreation, CStringConstructorInvalidArgument) {
    const char* cStr = nullptr;
    CustomString str(cStr);

    EXPECT_EQ(str.GetSize(), 0);
    EXPECT_STREQ(str.GetData(), "");
}

TEST(CustomStringCreation, CopyConstructor) {
    // A
    CustomString str1("The test string");

    // Act
    CustomString str2 = str1;

    // Assert
    EXPECT_EQ(str1.GetSize(), str2.GetSize());
    EXPECT_EQ(str1.GetSize(), strlen("The test string"));

    EXPECT_NE(str1.GetData(), str2.GetData());
    EXPECT_STREQ(str1.GetData(), "The test string");
}

TEST(CustomStringCreation, MoveConstructor) {
    CustomString srcStr("The test string");
    const size_t srcStrSize = srcStr.GetSize();
    const char* srcStrData = srcStr.GetData();

    CustomString strDst = std::move(srcStr);

    EXPECT_EQ(strDst.GetSize(), srcStrSize);
    EXPECT_EQ(strDst.GetData(), srcStrData);

    EXPECT_NE(srcStr.GetData(), srcStrData);
}

TEST(CustomStringBasicOperations, Assignment) {
    CustomString str1("The first custom string");
    CustomString str2("Another custom string");

    str1 = str2;

    EXPECT_EQ(str1.GetSize(), str2.GetSize());
    EXPECT_EQ(str1.GetSize(), strlen("Another custom string"));

    EXPECT_NE(str1.GetData(), str2.GetData());
    EXPECT_STREQ(str1.GetData(), str2.GetData());
    EXPECT_STREQ(str1.GetData(), "Another custom string");
}

TEST(CustomStringBasicOperations, MoveAssignment) {
    CustomString str1("The first custom string");
    const char* str1Data = str1.GetData();
    const size_t str1Size = str1.GetSize();

    CustomString str2("Another custom string");
    str2 = std::move(str1);

    EXPECT_EQ(str2.GetSize(), str1Size);
    EXPECT_EQ(str2.GetSize(), strlen("The first custom string"));

    EXPECT_NE(str1.GetData(), str1Data);
    EXPECT_NE(str1.GetData(), str2.GetData());
    EXPECT_STREQ(str2.GetData(), "The first custom string");
}

TEST(CustomStringBasicOperations, Append) {
    CustomString str1("One");
    CustomString str2("More ");
    CustomString str3("Little Thing");

    CustomString resultStr = str1 + " " + str2;
    resultStr += str3;

    EXPECT_EQ(resultStr.GetSize(), strlen("One More Little Thing"));
    EXPECT_STREQ(resultStr.GetData(), "One More Little Thing");

    EXPECT_EQ(str1.GetSize(), strlen("One"));
    EXPECT_STREQ(str1.GetData(), "One");

    EXPECT_EQ(str2.GetSize(), strlen("More "));
    EXPECT_STREQ(str2.GetData(), "More ");

    EXPECT_EQ(str3.GetSize(), strlen("Little Thing"));
    EXPECT_STREQ(str3.GetData(), "Little Thing");
}

TEST(CustomStringBasicOperations, OperatorGetItemByIndexConst) {
    const CustomString str = "Word";
    EXPECT_EQ(str[0], 'W');
    EXPECT_NE(str[0], 'w');
    EXPECT_EQ(str[1], 'o');
    EXPECT_EQ(str[2], 'r');
    EXPECT_EQ(str[3], 'd');
}

TEST(CustomStringBasicOperations, OperatorGetItemByIndex) {
    CustomString str = "Word";
    char& ch = str[0];
    ch = 'a';
    str[1] = 'B';

    EXPECT_STREQ(str.GetData(), "aBrd");
}

TEST(CustomStringBasicOperations, IsEmpty) {
    EXPECT_TRUE(CustomString("").IsEmpty());
    EXPECT_FALSE(CustomString(" ").IsEmpty());
}

TEST(CustomStringBasicOperations, GetSize) {
    EXPECT_EQ(CustomString("").GetSize(), 0);
    EXPECT_EQ(CustomString(" ").GetSize(), 1);
    EXPECT_EQ(CustomString("    ").GetSize(), 4);
    EXPECT_EQ(CustomString("Word").GetSize(), 4);
    EXPECT_EQ(CustomString("Word ").GetSize(), 5);
    EXPECT_EQ(CustomString(" Word").GetSize(), 5);
    EXPECT_EQ(CustomString(" Word ").GetSize(), 6);
    EXPECT_EQ(CustomString("AbcDef Gh 1234567 890").GetSize(), 21);
    EXPECT_EQ(CustomString("!#%&/(=?").GetSize(), 8);
}

TEST(CustomStringCompare, Equal) {
    EXPECT_EQ(CustomString(""), CustomString(""));
    EXPECT_EQ(CustomString("    "), CustomString("    "));
    EXPECT_EQ(CustomString("A"), CustomString("A"));
    EXPECT_EQ(CustomString("Word"), CustomString("Word"));
    EXPECT_EQ(CustomString("AbcDef Gh 1234567 890"), CustomString("AbcDef Gh 1234567 890"));
    EXPECT_EQ(CustomString("!#%&/(=?"), CustomString("!#%&/(=?"));
}

TEST(CustomStringCompare, NotEqual) {
    EXPECT_NE(CustomString(""), CustomString(" "));
    EXPECT_NE(CustomString("A"), CustomString("a"));
    EXPECT_NE(CustomString("WORD"), CustomString("word"));
}