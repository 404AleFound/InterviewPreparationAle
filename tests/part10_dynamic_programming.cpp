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
    LeetCode::Solution01bp sol;

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

TEST(fullBackpack){
    LeetCode::Solutionfullbp sol;
    int test_bagweight = 5;
    std::vector<int> test_values{2,4,4,5};
    std::vector<int> test_weights{1,2,3,4};
    int ans1 = 10;
    int pre1 = sol.fullBackpack(test_bagweight, test_values, test_weights);

    ASSERT_EQ(pre1, ans1);
}

TEST(change){
    LeetCode::Solution518 sol;
    int test1_amount = 5;
    std::vector<int> test1_coins{1, 2, 5};
    int ans1 = 4;

    int test2_amount = 3;
    std::vector<int> test2_coins{2};
    int ans2 = 0;

    int test3_amount = 10;
    std::vector<int> test3_coins{10};
    int ans3 = 1;

    int pre1 = sol.change(test1_amount, test1_coins);
    int pre2 = sol.change(test2_amount, test2_coins);
    int pre3 = sol.change(test3_amount, test3_coins);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
    ASSERT_EQ(pre3, ans3);
}

TEST(combinationSum4){
    LeetCode::Solution377 sol;
    std::vector<int> test1_nums{1,2,3};
    int test1_target = 4;
    int ans1 = 7;

    std::vector<int> test2_nums{9};
    int test2_target = 3;
    int ans2 = 0;

    int pre1 = sol.combinationSum4(test1_nums, test1_target);
    int pre2 = sol.combinationSum4(test2_nums, test2_target);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
}

TEST(coinChange){
    LeetCode::Solution322 sol;
    std::vector<int> test1_coins{1, 2, 5};
    int test1_amount = 11;
    int ans1 = 3;

    std::vector<int> test2_coins{2};
    int test2_amount = 3;
    int ans2 = -1;

    std::vector<int> test3_coins{1};
    int test3_amount = 0;
    int ans3 = 0;

    int pre1 = sol.coinChange(test1_coins, test1_amount);
    int pre2 = sol.coinChange(test2_coins, test2_amount);
    int pre3 = sol.coinChange(test3_coins, test3_amount);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
    ASSERT_EQ(pre3, ans3);

}

TEST(numSquares){
    LeetCode::Solution279 sol;

    int test1 = 12;
    int ans1 = 3;
    int test2 = 13;
    int ans2 = 2;

    int pre1 = sol.numSquares(test1);
    int pre2 = sol.numSquares(test2);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
}

TEST(climbStair){
    LeetCode::SolutionStair sol;
    int test1_1 = 2;
    int test1_2 = 3;
    int ans1 = 3;
    int pre1 = sol.climbStair(test1_1, test1_2);
    ASSERT_EQ(ans1, pre1);
}

TEST(wordbreak){
    LeetCode::Solution139 sol;
    std::string s1{"leetcode"};
    std::vector<std::string> wordDict1{"leet", "code"};
    std::string s2{"applepenapple"};
    std::vector<std::string> wordDict2{"apple", "pen"};
    std::string s3{"catsandog"};
    std::vector<std::string> wordDict3{"cats", "dog", "sand", "and", "cat"};

    bool ans1 = true;
    bool ans2 = true;
    bool ans3 = false;

    bool pre1 = sol.wordBreak(s1, wordDict1);
    bool pre2 = sol.wordBreak(s2, wordDict2);
    bool pre3 = sol.wordBreak(s3, wordDict3);

    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
    ASSERT_EQ(pre3, ans3);
}

TEST(multiBackpack){
    LeetCode::SolutionMulbp sol;
    int test_bagweight = 10;
    std::vector<int> test_weights{1,3,4};
    std::vector<int> test_values{15,20,30};
    std::vector<int> test_nums{2,3,2};
    int ans = 90;

    int pre = sol.multiBackpack(test_bagweight, test_values, test_weights, test_nums);
    ASSERT_EQ(pre, ans);
}

TEST(rob){
    LeetCode::Solution198 sol;
    std::vector<int> test1{1,2,3,1};
    std::vector<int> test2{2,7,9,3,1};
    int ans1 = 4;
    int ans2 = 12;
    int pre1 = sol.rob(test1);
    int pre2 = sol.rob(test2);
    ASSERT_EQ(pre1, ans1);
    ASSERT_EQ(pre2, ans2);
}

TEST(rob_){
    LeetCode::Solution213 sol;
    std::vector<int> test1{2,3,2};
    std::vector<int> test2{1,2,3,1};
    int ans1 = 3;
    int ans2 = 4;
    int pre1 = sol.rob(test1);
    int pre2 = sol.rob(test2);
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
    RUN_TEST(fullBackpack);
    RUN_TEST(change);
    RUN_TEST(combinationSum4);
    RUN_TEST(coinChange);
    RUN_TEST(numSquares);
    RUN_TEST(climbStair);
    RUN_TEST(wordbreak);
    // RUN_TEST(multiBackpack);
    // RUN_TEST(findMaxForm);
    RUN_TEST(rob);
    RUN_TEST(rob_);
    std::cout << std::endl << "all tests passing!" << std::endl;
    return 0;
}