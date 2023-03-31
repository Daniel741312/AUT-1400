#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <string>
#include <vector>
#include "unique_ptr.h"
#include "shared_ptr.h"
using namespace std;

TEST(HW4Test, TEST1) {
    UniquePtr<int> ptr1{new int{10}};
    EXPECT_EQ(*ptr1.get(), 10);

    UniquePtr<std::string> ptr2{new std::string{"hello world!"}};
    EXPECT_EQ(*ptr2.get(), "hello world!");
}

TEST(HW4Test, TEST2) {
    UniquePtr<int> ptr1{make_unique<int>(10)};
    EXPECT_EQ(*ptr1.get(), 10);

    UniquePtr<std::string> ptr2{make_unique<std::string>("hello world!")};
    EXPECT_EQ(*ptr2.get(), "hello world!");
}

TEST(HW4Test, TEST3) {
    UniquePtr<int> ptr1;
    EXPECT_EQ(ptr1.get(), nullptr);

    UniquePtr<std::string> ptr2{};
    EXPECT_EQ(ptr2.get(), nullptr);
}

TEST(HW4Test, TEST4) {
    UniquePtr<int> ptr1{new int{10}};
    EXPECT_EQ(*ptr1, 10);

    UniquePtr<std::string> ptr2{new std::string{"hello world!"}};
    EXPECT_EQ(*ptr2, "hello world!");

    UniquePtr<std::vector<int>> ptr3{new std::vector<int>{1, 2, 3, 4, 5}};
    EXPECT_EQ((*ptr3)[1], 2);
}

TEST(HW4Test, TEST5) {
    UniquePtr<std::string> ptr1{new std::string{"hello world!"}};
    EXPECT_EQ(ptr1->length(), 12);

    UniquePtr<std::vector<int>> ptr3{new std::vector<int>{1, 2, 3, 4, 5}};
    EXPECT_FALSE(ptr3->empty());
}

TEST(HW4Test, TEST6) {
    UniquePtr<std::string> ptr{new std::string{"hello world!"}};
    EXPECT_EQ(ptr->length(), 12);
    ptr.reset();
    EXPECT_EQ(ptr.get(), nullptr);
}

TEST(HW4Test, TEST7) {
    UniquePtr<std::string> ptr{new std::string{"hello world!"}};
    EXPECT_EQ(ptr->length(), 12);
    ptr.reset(new std::string{"nice job!"});
    EXPECT_EQ(*ptr, "nice job!");
}

TEST(HW4Test, TEST8) {
    UniquePtr<double> ptr{new double{1.567}};
    EXPECT_DOUBLE_EQ(*ptr, 1.567);
    if(ptr)
        ptr.reset();
    EXPECT_FALSE(ptr);
}

TEST(HW4Test, TEST9) {
    UniquePtr<double> ptr{new double{1.567}};
    EXPECT_DOUBLE_EQ(*ptr, 1.567);
    double *tmp;
    if(ptr)
        tmp = ptr.release();
    EXPECT_DOUBLE_EQ(*tmp, 1.567);
    EXPECT_FALSE(ptr);
    delete tmp;
}

TEST(HW4Test, TEST10) {
    SharedPtr<int> ptr1{new int{10}};
    EXPECT_EQ(*ptr1.get(), 10);

    SharedPtr<std::string> ptr2{new std::string{"hello world!"}};
    EXPECT_EQ(*ptr2.get(), "hello world!");
}

TEST(HW4Test, TEST11) {
    SharedPtr<int> ptr1{make_shared<int>(10)};
    EXPECT_EQ(*ptr1.get(), 10);

    SharedPtr<std::string> ptr2{make_shared<std::string>("hello world!")};
    EXPECT_EQ(*ptr2.get(), "hello world!");
}

TEST(HW4Test, TEST12) {
    SharedPtr<int> ptr1;
    EXPECT_EQ(ptr1.get(), nullptr);

    SharedPtr<std::string> ptr2{};
    EXPECT_EQ(ptr2.get(), nullptr);
}

TEST(HW4Test, TEST13) {
    SharedPtr<int> ptr1{make_shared<int>(10)};
    SharedPtr<int> ptr2{ptr1};
    EXPECT_EQ(*ptr1, 10);
    EXPECT_EQ(*ptr2, 10);
    EXPECT_EQ(ptr1.get(), ptr2.get());
    EXPECT_EQ(ptr1.use_count(), 2);
    EXPECT_EQ(ptr2.use_count(), 2);    
}

TEST(HW4Test, TEST14) {
    SharedPtr<std::string> ptr1{make_shared<std::string>("hello world!")};
    SharedPtr<std::string> ptr2{ptr1};
    SharedPtr<std::string> ptr3{ptr1};
    EXPECT_EQ(*ptr1, "hello world!");
    EXPECT_EQ(*ptr1, "hello world!");
    EXPECT_EQ(*ptr2, "hello world!");
    EXPECT_EQ(ptr1.get(), ptr2.get());
    EXPECT_EQ(ptr2.get(), ptr3.get());
    EXPECT_EQ(ptr1.use_count(), 3);
    EXPECT_EQ(ptr2.use_count(), 3);    
    EXPECT_EQ(ptr3.use_count(), 3);    
}

TEST(HW4Test, TEST15) {
    SharedPtr<std::string> ptr1{make_shared<std::string>("hello world!")};
    {
        {
            SharedPtr<std::string> ptr2{ptr1};
            EXPECT_EQ(ptr1.use_count(), 2);
            EXPECT_EQ(ptr2.use_count(), 2);    
        }
        EXPECT_EQ(ptr1.use_count(), 1);
        SharedPtr<std::string> ptr3{ptr1};
        EXPECT_EQ(ptr1.use_count(), 2);
        EXPECT_EQ(ptr3.use_count(), 2);
    }
    EXPECT_EQ(ptr1.use_count(), 1);
    ptr1.~SharedPtr();
    EXPECT_EQ(ptr1.use_count(), 0);
    EXPECT_EQ(ptr1.get(), nullptr);
}

TEST(HW4Test, TEST16) {
    SharedPtr<int> ptr1{new int{10}};
    EXPECT_EQ(*ptr1, 10);

    SharedPtr<std::string> ptr2{new std::string{"hello world!"}};
    EXPECT_EQ(*ptr2, "hello world!");

    SharedPtr<std::vector<int>> ptr3{new std::vector<int>{1, 2, 3, 4, 5}};
    EXPECT_EQ((*ptr3)[1], 2);
}

TEST(HW4Test, TEST17) {
    SharedPtr<std::string> ptr1{new std::string{"hello world!"}};
    EXPECT_EQ(ptr1->length(), 12);

    SharedPtr<std::vector<int>> ptr3{new std::vector<int>{1, 2, 3, 4, 5}};
    EXPECT_FALSE(ptr3->empty());
}

TEST(HW4Test, TEST18) {
    SharedPtr<std::string> ptr{new std::string{"hello world!"}};
    EXPECT_EQ(ptr->length(), 12);
    ptr.reset();
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr.use_count(), 0);
}

TEST(HW4Test, TEST19) {
    SharedPtr<std::string> ptr{new std::string{"hello world!"}};
    EXPECT_EQ(ptr->length(), 12);
    ptr.reset(new std::string{"nice job!"});
    EXPECT_EQ(*ptr, "nice job!");
    EXPECT_EQ(ptr.use_count(), 1);
}

TEST(HW4Test, TEST20) {
    SharedPtr<double> ptr{new double{1.567}};
    EXPECT_DOUBLE_EQ(*ptr, 1.567);
    if(ptr)
        ptr.reset();
    EXPECT_FALSE(ptr);
}

TEST(HW4Test, TEST21) {
    SharedPtr<double> ptr1{new double{1.567}};
    SharedPtr<double> ptr2{new double{5.1234}};
    ptr1 = ptr1;
    ptr2 = ptr1;
    EXPECT_DOUBLE_EQ(*ptr2, 1.567);
    EXPECT_EQ(ptr1.use_count(), 2);
    EXPECT_EQ(ptr2.use_count(), 2);
}
/*
*/