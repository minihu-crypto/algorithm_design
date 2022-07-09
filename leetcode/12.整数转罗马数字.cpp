/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <map>
#include <string>
using namespace std;
class Solution {
   public:
    string intToRoman(int num) {
        const pair<int, string> valueSymbol[]{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};
        string res = "";
        for (const auto &[value, symbol] : valueSymbol) {
            while (num >= value) {
                res += symbol;
                num -= value;
            }
        }
        return res;
    }
    string intToRoman_v1(int num) {
        map<int, char> intToChar{{1, 'I'},   {5, 'V'},   {10, 'X'},  {50, 'L'},
                                 {100, 'C'}, {500, 'D'}, {1000, 'M'}};
        string res = "";
        // 1.思路: 先进行分解，先以10为单位，后以5为单位
        //处理千
        while (num >= 1000) {
            res.push_back(intToChar[1000]);
            num -= 1000;
        }
        //处理百
        // 400-499 900-999单独处理
        if (num >= 900) {
            res.push_back(intToChar[100]);
            res.push_back(intToChar[1000]);
            num %= 100;
        } else if (num >= 500) {
            res.push_back(intToChar[500]);
            num %= 500;
        } else if (num >= 400) {
            res.push_back(intToChar[100]);
            res.push_back(intToChar[500]);
            num %= 100;
        }
        while (num >= 100) {
            res.push_back(intToChar[100]);
            num -= 100;
        }
        //处理十
        if (num >= 90) {
            res.push_back(intToChar[10]);
            res.push_back(intToChar[100]);
            num %= 10;
        } else if (num >= 50) {
            res.push_back(intToChar[50]);
            num %= 50;
        } else if (num >= 40) {
            res.push_back(intToChar[10]);
            res.push_back(intToChar[50]);
            num %= 10;
        }
        while (num >= 10) {
            res.push_back(intToChar[10]);
            num -= 10;
        }
        //处理1
        if (num == 9) {
            res.push_back(intToChar[1]);
            res.push_back(intToChar[10]);
        } else if (num >= 5) {
            res.push_back(intToChar[5]);
            while (num >= 6) {
                res.push_back(intToChar[1]);
                num -= 1;
            }
        } else if (num == 4) {
            res.push_back(intToChar[1]);
            res.push_back(intToChar[5]);
        } else {
            while (num >= 1) {
                res.push_back(intToChar[1]);
                num -= 1;
            }
        }
        return res;
    }
};
// @lc code=end
