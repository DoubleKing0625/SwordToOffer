/*
 * Created by Peng Qixiang on 2018/9/15.
 */

/*
 * 将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)。
 * 要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
 *
 */

# include <iostream>

using namespace std;

class Solution {

public:
    /* 边界条件：
     * 上下溢出
     * 空字符串
     * 正负号检查, 或者只有正负号
     * 非正常字符，不在0-9
     * 1e20 ??? 牛客没有考虑
     */
    int StrToInt(string str) {
        long num = 0;
        int minus = 1;
        long size = str.size();

        //空字符串检查
        if(str.empty())
            return 0;
        //正负号检查
        int index = 0;
        if(str[0] == '-' || str[0] == '+'){
            if(size == 1) //只有正负号
                return 0;
            if(str[0] == '-')
                minus = -1;
            index = 1;
        }
        for(;index < size; index++){
            // 正常字符检查
            if(str[index] >= '0' && str[index] <= '9'){
                num = num * 10 + str[index] - '0';
                //上下溢出检查
                if(minus == 1 && num * minus > numeric_limits<int>::max())
                    return 0;
                if(minus == -1 && num * minus < numeric_limits<int>::min())
                    return 0;
            }
            else
                return 0;
        }
        return (int)(num * minus);
    }
};

int main(){
    Solution s;
    string test = "+100";
    cout << s.StrToInt(test) << endl;
    return 0;
}





