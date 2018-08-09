/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 把数组排成最小的数
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 * 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 *
 */

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    // sort的比较函数参数要求是一个普通函数指针，而不是成员函数指针，因此定义在类内的话要加static
    static bool compare(int a, int b){
        string ab = to_string(a) + to_string(b);
        string ba = to_string(b) + to_string(a);
        return ab < ba;
    }

    string PrintMinNumber(vector<int> numbers) {
        string res;
        if(numbers.empty()) return res;
        sort(numbers.begin(), numbers.end(), compare);
        for(int i = 0; i < numbers.size(); i++){
            res += to_string(numbers[i]);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int> test;
    test.push_back(3);
    test.push_back(32);
    test.push_back(321);
    cout << s.PrintMinNumber(test) << endl;
    return 0;
}