/*
 * Created by Peng Qixiang on 2018/9/15.
 */

/*
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符
 * 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
 * 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 * 如果当前字符流没有存在出现一次的字符，返回#字符。
 */

# include <iostream>
# include <vector>

using namespace std;

class Solution {

public:
    // 一个字符8位，所以最多256个字符

    int save[256] = {0};
    string s;

    //Insert one char from stringstream
    void Insert(char ch)
    {
        save[ch]++;
        s+=ch;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i = 0; i < s.size(); i++){
            if(save[s[i]] == 1)
                return s[i];
        }
        return '#';
    }


};

int main(){
    Solution s;
    vector<int> res(256, 10);
    return 0;
}





