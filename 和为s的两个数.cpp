/*
 * Created by Peng Qixiang on 2018/8/14.
 */

/*
 * 和为S的两个数字
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S。
 * 如果有多对数字的和等于S，输出两个数的乘积最小的。
 *
 */

# include <iostream>
# include <vector>

using namespace std;

class Solution {

public:
    //双指针
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(array.empty()) return res;
        int low = 0, high = array.size()-1;
        while(low < high){
            int cur = array[low] + array[high];
            if(cur == sum){
                res.push_back(array[low]);
                res.push_back(array[high]);
                break;
            }
            else if(cur < sum) low++;
            else high--;
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    return 0;
}





