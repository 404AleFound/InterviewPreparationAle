#include "part10_dynamic_programming.h"
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

TEST(fib509) {
    LeetCode::Solution509 sol;
    int test1 = 2;
    int test2 = 3;
    int test3 = 4;

    int ans1 = 1;
    int ans2 = 2;
    int ans3 = 3;

    int pre1 = sol.fib(test1);
    int pre2 = sol.fib(test2);
    int pre3 = sol.fib(test3);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
    ASSERT_EQ(pre3, ans3);
}

TEST(climbStairs70) {
    LeetCode::Solution70 sol;
    int test1 = 2;
    int test2 = 3;

    int ans1 = 2;
    int ans2 = 3;

    int pre1 = sol.climbStairs(test1);
    int pre2 = sol.climbStairs(test2);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
}

TEST(minCostClimbingStairs746) {
    LeetCode::Solution746 sol;
    std::vector<int> test1{10,15,20};
    std::vector<int> test2{1,100,1,1,1,100,1,1,100,1};

    int ans1 = 15;
    int ans2 = 6;

    int pre1 = sol.minCostClimbingStairs(test1);
    int pre2 = sol.minCostClimbingStairs(test2);

    ASSERT_EQ(ans1, pre1);
    ASSERT_EQ(ans2, pre2);
}

TEST(uniquePaths62) {
    LeetCode::Solution62 sol;
    int test1_1 = 3, test1_2 = 7;
    int test2_1 = 3, test2_2 = 2;

    int ans1 = 28;
    int ans2 = 3;

    int pre1 = sol.uniquePaths(test1_1, test1_2);
    int pre2 = sol.uniquePaths(test2_1, test2_2);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
}

TEST(uniquePathsWithObstacles63) {
    LeetCode::Solution63 sol;
    std::vector<std::vector<int>> test1{{0,0,0},{0,1,0},{0,0,0}};
    std::vector<std::vector<int>> test2{{0,1},{0,0}};

    int ans1 = 2;
    int ans2 = 1;

    int pre1 = sol.uniquePathsWithObstacles(test1);
    int pre2 = sol.uniquePathsWithObstacles(test2);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
}

TEST(integerBreak343) {
    LeetCode::Solution343 sol;
    int test1 = 2;
    int test2 = 10;

    int ans1 = 1;
    int ans2 = 36;

    int pre1 = sol.integerBreak(test1);
    int pre2 = sol.integerBreak(test2);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
}

TEST(numTrees96) {
    LeetCode::Solution96 sol;
    int test1 = 3;
    int test2 = 1;

    int ans1 = 5;
    int ans2 = 1;

    int pre1 = sol.numTrees(test1);
    int pre2 = sol.numTrees(test2);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
}

TEST(zerOneBackpack) {
    LeetCode::Solution01pb sol;

    int test1_bagweight = 1;
    std::vector<int> test1_weights{2,2,3,1,5,2};
    std::vector<int> test1_values{2,3,1,5,4,3};

    int ans1 = 5;

    int pre1 = sol.zerOneBackpack(test1_bagweight, test1_weights, test1_values);

    ASSERT_EQ(pre1, ans1);
}

TEST(canPartition) {
    LeetCode::Solution416 sol;

    std::vector<int> test1{1,5,11,5};
    std::vector<int> test2{1,2,3,5};

    bool res1 = true;
    bool res2 = false;

    bool pre1 = sol.canPartition(test1);
    bool pre2 = sol.canPartition(test2);

    ASSERT_EQ(pre1, res1);
    ASSERT_EQ(pre2, res2);
}

TEST(lastStoneWeightII) {
    LeetCode::Solution1049 sol;
    std::vector<int> test1{2,7,4,1,8,1};
    std::vector<int> test2{31,26,33,21,40};

    int res1 = 1;
    int res2 = 5;

    int pre1 = sol.lastStoneWeightII(test1);
    int pre2 = sol.lastStoneWeightII(test2);

    ASSERT_EQ(pre1, res1);
    ASSERT_EQ(pre2, res2);
}

TEST(findTargetSumWays) {
    LeetCode::Solution494 sol;
    std::vector<int> test1_1{1,1,1,1,1};
    int test1_2 = 3;
    std::vector<int> test2_1{1};
    int test2_2 = 1;

    int ans1 = 5;
    int ans2 = 1;

    int pre1 = sol.findTargetSumWays(test1_1, test1_2);
    int pre2 = sol.findTargetSumWays(test2_1, test2_2);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
}

TEST(findMaxForm){
    LeetCode::Solution474 sol;
    std::vector<std::string> test1{"10", "0001", "111001", "1", "0"};
    int test1_1 = 5, test1_2 = 3;
    std::vector<std::string> test2{"10", "0", "1"};
    int test2_1 = 1, test2_2 = 1;

    int ans1 = 4;
    int ans2 = 2;

    int pre1 = sol.findMaxForm(test1, test1_1, test1_2);
    int pre2 = sol.findMaxForm(test2, test2_1, test2_2);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
}

int main() {
    std::cout << std::endl << "start testing!" << std::endl;
    RUN_TEST(fib509);
    RUN_TEST(climbStairs70);
    RUN_TEST(minCostClimbingStairs746);
    RUN_TEST(uniquePaths62);
    RUN_TEST(uniquePathsWithObstacles63);
    RUN_TEST(integerBreak343);
    RUN_TEST(numTrees96);
    RUN_TEST(zerOneBackpack);
    RUN_TEST(canPartition);
    RUN_TEST(lastStoneWeightII);
    RUN_TEST(findTargetSumWays);
    // RUN_TEST(findMaxForm);
    std::cout << std::endl << "all tests passing!" << std::endl;
    return 0;
}