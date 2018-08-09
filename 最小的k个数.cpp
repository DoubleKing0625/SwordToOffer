/*
 * Created by Peng Qixiang on 2018/8/8.
 */

/*
 * 最小的k个数
 * 输入n个整数，找出其中最小的K个数。
 * 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
 *
 */

# include <iostream>
# include <vector>
# include <queue>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        // 异常处理！！！！！！！！！！！！！！！！！！！！
        if(input.size() < k || input.empty() || k <= 0) return vector<int>();
        // 用最大堆
        vector<int> res(k);
        priority_queue<int> heap;
        for(int i = 0; i < k; i++){
            heap.push(input[i]);
        }
        for(int i = k; i < input.size(); i++){
            if(input[i] < heap.top()){
                heap.pop();
                heap.push(input[i]);
            }
        }
        for(int i = k-1; i >= 0; i--){
            res[i] = heap.top();
            heap.pop();
        }
        return res;
    }


};

int main(){
    Solution s = Solution();
    vector<int> test;
    test.push_back(4);
    test.push_back(5);
    test.push_back(1);
    test.push_back(6);
    test.push_back(2);
    test.push_back(7);
    test.push_back(3);
    test.push_back(8);
    vector<int> res = s.GetLeastNumbers_Solution(test, 4);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}