/*
 * Created by Peng Qixiang on 2018/8/7.
 */

/*
 * 数组中出现次数超过一半的数字
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 *
 */

# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers){
        if(numbers.empty()) return 0;
        int length = numbers.size();
        unordered_map<int, int> res;
        int finalRes = 0;
        for(int i = 0; i < length; i++){
            if(res.count(numbers[i])){
                res[numbers[i]]++;
                if(res[numbers[i]] > (length / 2)){
                    finalRes = numbers[i];
                }
            }
            else{
                pair<int, int> tmp (numbers[i], 1);
                res.insert(tmp);
                // 必须加， 因为会有 【1】
                if(res[numbers[i]] > (length / 2)){
                    finalRes = numbers[i];
                }
            }
        }
        return finalRes;
    }
};

int main(){
//    Solution s = Solution();
//    vector<int> test;
//    test.push_back(1);
//    test.push_back(2);
//    test.push_back(3);
//    test.push_back(2);
//    test.push_back(2);
//    test.push_back(2);
//    test.push_back(5);
//    test.push_back(4);
//    test.push_back(2);
//    cout << s.MoreThanHalfNum_Solution(test) << endl;
    cout << 1/2 << endl;
    return 0;
}