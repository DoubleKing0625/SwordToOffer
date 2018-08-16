/*
 * Created by Peng Qixiang on 2018/8/14.
 */

/*
 * 左旋转字符串
 * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
 *
 */

# include <iostream>
# include <string>
# include <queue>

using namespace std;

class Solution {

public:
    string LeftRotateString(string str, int n) {
        if(str.empty()) return str;
        queue<char> tmp;
        for(int i = 0; i < str.size(); i++){
            tmp.push(str[i]);
        }
        for(int i = 0; i < n; i++){
            char cur = tmp.front();
            tmp.pop();
            tmp.push(cur);
        }
        for(int i = 0; i < str.size(); i++){
            str[i] = tmp.front();
            tmp.pop();
        }
        return str;
    }
    //还可以三次翻转
};

int main(){
    Solution s = Solution();
    string test = "abcdef";
    cout << s.LeftRotateString(test, 2) << endl;
    return 0;
}





