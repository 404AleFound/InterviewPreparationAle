#include "part11_monotonic_stack.h"
#include <cassert>

#define TEST(name) void name()
#define ASSERT_TRUE(expr) assert(expr)
#define ASSERT_FALSE(expr) assert(expr)
#define ASSERT_EQ(expr1, expr2) assert(expr1 == expr2)
#define RUN_TEST(test) \
    do { \
        std::cout << "running test examples: " << #test << "..."; \
        test(); \
        std::cout << "pass!" << std::endl; \
    } while(0)

TEST(DailyTemperatures739) {
    LeetCode::Solution739 sol;
    std::vector<int> test1{73,74,75,71,69,72,76,73};
    std::vector<int> test2{30,40,50,60};
    std::vector<int> test3{30,60,90};

    std::vector<int> ans1{1,1,4,2,1,1,0,0};
    std::vector<int> ans2{1,1,1,0};
    std::vector<int> ans3{1,1,0};

    std::vector<int> pre1 = sol.dailyTemperatures(test1);
    std::vector<int> pre2 = sol.dailyTemperatures(test2);
    std::vector<int> pre3 = sol.dailyTemperatures(test3);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
    ASSERT_EQ(pre3, ans3);
}

TEST(nextGreaterElement496) {
    LeetCode::Solution496 sol;
    std::vector<int> test1_1{4,1,2};
    std::vector<int> test1_2{1,3,4,2};

    std::vector<int> test2_1{2,4};
    std::vector<int> test2_2{1,2,3,4};

    std::vector<int> ans1{-1,3,-1};
    std::vector<int> ans2{3,-1};

    std::vector<int> pre1 = sol.nextGreaterElement(test1_1, test1_2);
    std::vector<int> pre2 = sol.nextGreaterElement(test2_1, test2_2);

    ASSERT_EQ(ans1, pre1);
    ASSERT_EQ(ans2, pre2);
}

TEST(nextGreaterElements503) {
    LeetCode::Solution503 sol;
    std::vector<int> test1{1,2,1};
    std::vector<int> test2{1,2,3,4,3};

    std::vector<int> ans1{2,-1,2};
    std::vector<int> ans2{2,3,4,-1,4};

    std::vector<int> pre1 = sol.nextGreaterElements(test1);
    std::vector<int> pre2 = sol.nextGreaterElements(test2);

    ASSERT_EQ(ans1, pre1);
    ASSERT_EQ(ans2, pre2);
}

TEST(trap42) {
    LeetCode::Solution42 sol;
    std::vector<int> test1{0,1,0,2,1,0,1,3,2,1,2,1};
    std::vector<int> test2{4,2,0,3,2,5};

    int ans1 = 6;
    int ans2 = 9;

    int pre1 = sol.trap(test1);
    int pre2 = sol.trap(test2);

    ASSERT_EQ(ans1, pre1);
    ASSERT_EQ(ans2, pre2);
}

TEST(largestRectangleArea84) {
    LeetCode::Solution84 sol;
    std::vector<int> test1{2,1,5,6,2,3};
    std::vector<int> test2{2,4};

    int ans1 = 10;
    int ans2 = 4;

    int pre1 = sol.largestRectangleArea(test1);
    int pre2 = sol.largestRectangleArea(test2);

    ASSERT_EQ(ans1, pre1);
    ASSERT_EQ(ans2, pre2);
}

int main() {
    std::cout << std::endl << "start testing!" << std::endl;
    RUN_TEST(nextGreaterElement496);
    RUN_TEST(nextGreaterElement496);
    RUN_TEST(nextGreaterElements503);
    RUN_TEST(trap42);
    RUN_TEST(largestRectangleArea84);
    std::cout << std::endl << "all tests passing!" << std::endl;
    return 0;
}