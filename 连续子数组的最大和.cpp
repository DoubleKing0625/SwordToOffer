/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 连续子数组的最大和
 * {6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和。
 * 子向量的长度至少是1。
 *
 */

# include <iostream>
# include <vector>
# include <cmath>

using namespace std;

class Solution {
public:
    // 动态规划
    // F(i) = max(F(i-1)+array[i], arrary[i]) 以第i个元素结尾的子序列的和
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;

        int res = array[0];
        int sum = array[0];

        for(int i = 1; i < array.size(); i++){
            sum = max(sum + array[i], array[i]);
            res = max(res, sum);
        }

        return res;
    }


};

int main(){
    Solution s = Solution();
    vector<int> test;
    test.push_back(6);
    test.push_back(-3);
    test.push_back(-2);
    test.push_back(7);
    test.push_back(-15);
    test.push_back(1);
    test.push_back(2);
    test.push_back(2);
    cout << s.FindGreatestSumOfSubArray(test) << endl;
    return 0;
}