/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 不用加减乘除做加法
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 *
 */

# include <iostream>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2){
        while(num2 != 0){ //没有进位了停止循环
            int sum = num1 ^ num2; //按位异或单纯求和
            int carry_bit = (num1 & num2) << 1; //按位与左移求进位
            num1 = sum;
            num2 = carry_bit;
        }
        return num1;
    }

};

int main(){
    Solution s;
    cout << s.Add(4, 10) << endl;
    return 0;
}