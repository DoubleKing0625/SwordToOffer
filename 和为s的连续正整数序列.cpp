/*
 * Created by Peng Qixiang on 2018/8/14.
 */

/*
 * 和为S的连续正数序列
 * 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 * 序列至少包含两个数
 *
 */

# include <iostream>
# include <vector>

using namespace std;

class Solution {

public:
    //双指针
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if(sum < 3) return res;
        int low = 1, high = 2;
        while(low < high && high <= sum / 2 + 1){
            int cur = (low + high) * (high - low + 1) / 2;
            if(cur == sum){
                vector<int> tmp;
                for(int i = low; i <= high; i++){
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                low++;//low，high不能同时加
            }
            else if(cur < sum) high++;
            else low++;
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> test = s.FindContinuousSequence(5);
    for(int i = 0 ; i < test.size(); ++i){
        for(int j = 0; j < test[i].size(); ++j){
            cout << test[i][j] << endl;
        }
    }
    return 0;
}





