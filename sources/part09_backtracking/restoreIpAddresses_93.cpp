#include "part09_backtracking.h"

/**
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
 * 你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 * 
 * Input: s = "25525511135"
 * Output: ["255.255.11.135","255.255.111.35"]
 * 
 * Input: s = "0000"
 * Output: ["0.0.0.0"]
 * 
 * Input: s = "101023"
 * Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 */


bool LeetCode::Solution93::isIP(const std::string& s, int left, int right) {
    if (right < left || left < 0 || right > s.size() - 1) return false;
    if (left < right && s[left] == '0') return false;
    int num = 0;
    for (int i = left; i <= right; i++) {
        num = num * 10 + s[i] - '0';
        if (num < 0 || num > 255) return false;
    }
    return true;
}
void LeetCode::Solution93::backtracking(const std::string& s, int index, int countPoint) {
    if (countPoint == 3) {
        if (isIP(s, index, s.size() - 1)) {
            std::string temp = s.substr(index, s.size() - index);
            path = path + temp;
            res.push_back(path);
        }
        return;
    }
    for (int i = index; i < s.size(); i++) {
        if (isIP(s, index, i)) {
            std::string temp = s.substr(index, i - index + 1);
            std::string origin = path;
            path = path + temp + ".";
            countPoint ++;
            backtracking(s, i + 1, countPoint);
            countPoint--;
            path = origin;
        } else {
            break;
        }
    }
}

 std::vector<std::string> LeetCode::Solution93::restoreIpAddresses(std::string s) {
     backtracking(s, 0, 0);
     return res;
 }
