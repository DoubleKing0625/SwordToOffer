/*
 * Created by Peng Qixiang on 2018/8/14.
 */

/*
 * 翻转单词顺序列
 * studen a am i -> i am a student
 *
 */

# include <iostream>
# include <string>
# include <queue>

using namespace std;

class Solution {

public:
    void reverse(string& str, int start, int end){
        while(start < end){
            char tmp = str[start];
            str[start] = str[end];
            str[end] = tmp;
            start++;
            end--;
        }
    }
    string ReverseSentence(string str) {
        if(str.empty()) return str;
        reverse(str, 0, str.size()-1);
        int start = 0, end = 0;
        while(start < str.size()){
            if(str[start]== ' '){
                start++;
                end++;
            }
            else if(str[end]==' '){//遍历到终止字符为空格，就进行翻转
                reverse(str, start, --end);
                start=++end;
            }
            else if(end==str.size()-1){//若遍历结束，就进行翻转
                reverse(str, start, end);
                start=++end;
            }
            else{//没有遍历到空格或者遍历结束，则单独对end自减
                end++;
            }
        }
        return str;
    }
};

int main(){
    Solution s = Solution();
    string test = "student a am i";
    cout << test << endl;
    cout << s.ReverseSentence(test) << endl;
    return 0;
}





