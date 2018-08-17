/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 扑克牌顺子
 * 判断数组是不是0-13的一个顺子
 *
 */

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int> numbers){
        if(numbers.empty()) return false;
        sort(numbers.begin(), numbers.end());
        int border = 0;
        while(numbers[border] == 0){
            border++;
        }
        int min = numbers[border], max = numbers[numbers.size()-1];
        for(int i = border+1; i < numbers.size(); i++){
            if(numbers[i] == numbers[i-1]) return false;
        }
        if(max - min < 5) return true;
        else return false;
    }
};

int main(){
    Solution s;
    vector<int> test(5,0);
    test[0] = 1;
    test[1] = 1;
    cout << s.IsContinuous(test) << endl;
    return 0;
}