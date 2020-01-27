#include <iostream>
#include "gtest/gtest.h"
#include "Node.hpp"

TEST(EvenDistance, AddChild)
{
    Node n1(1);
    Node n2(2);

    n1.addChild(n2);

    ASSERT_TRUE(*(n1.getChildren()[0]) == n2);
}

int main(int argc, char* argv[])
{  
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}