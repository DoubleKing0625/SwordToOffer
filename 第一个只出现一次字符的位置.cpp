/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 第一个只出现一次的字符
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置。
 * 如果没有则返回 -1（需要区分大小写）。
 *
 */

# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
        int min = str.size() - 1;
        unordered_map<char, vector<int>> res;
        for(int i = 0; i < str.size(); i++){
            char tmp = str[i];
            if(res.count(tmp)){
                res[tmp][0] = 2;
            }
            else{
                vector<int> position;
                position.push_back(1); // first time
                position.push_back(i); // position
                res.insert(make_pair(tmp, position));
            }
        }
        // traverse map
        for(unordered_map<char, vector<int>>::iterator it = res.begin(); it!=res.end(); ++it){
            if(it->second[0] == 1 && it->second[1] < min){
                min = it->second[1];
            }
        }

        return min;
    }

    // 空间精简版
    int FirstNotRepeatingChar1(string str) {
        map<char, int> mp;
        for(int i = 0; i < str.size(); ++i)
            mp[str[i]]++;
        for(int i = 0; i < str.size(); ++i){
            if(mp[str[i]]==1)
                return i;
        }
        return -1;
    }
};

int main(){
    Solution s = Solution();
    string test("aaaabcc");
    cout << s.FirstNotRepeatingChar(test) << endl;
    return 0;
}