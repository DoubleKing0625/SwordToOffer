/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 求1+2+3+...+n
 * 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 *
 */

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
        // 逻辑与短路特性判断异常
        n && (n+=Sum_Solution(n-1));
        return n;
    }
};

int main(){
    Solution s;
    cout << s.Sum_Solution(100) << endl;
    return 0;
}