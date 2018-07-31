/*
 * Created by Peng Qixiang on 2018/7/27.
 */

/*
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。
 * 例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
 * (注意：这两个序列的长度是相等的）
 *
 */

# include <iostream>
# include <vector>
# include <stack>

using namespace std;

class Solution {
public:

    // 遍历pushV，建立辅助栈。每个pushV，遍历popV. 最后判断辅助栈空与否
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if(!pushV.size()){
            return false;
        }
        int length = pushV.size();
        int index_pop = 0;
        stack<int> test;
        for(int i = 0; i < length; i++){
            test.push(pushV[i]);
            while(index_pop < length && popV[index_pop] == test.top()){
                test.pop();
                index_pop++;
            }
        }
        return test.empty();
    }
};

int main(){
    int a[5] = {1,2,3,4,5};
    int b[5] = {4,5,3,2,1};
    vector<int> pushV(a, a+5);
    vector<int> popV(b, b+5);
    Solution s = Solution();
    cout << s.IsPopOrder(pushV, popV) << endl;
    return 0;
}