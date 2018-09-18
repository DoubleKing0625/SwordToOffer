/*
 * Created by Peng Qixiang on 2018/9/17.
 */

/*
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口
 * 他们的最大值分别为{4,4,6,6,6,5}；
 * 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 * {[2,3,4],2,6,2,5,1}，
 * {2,[3,4,2],6,2,5,1}，
 * {2,3,[4,2,6],2,5,1}，
 * {2,3,4,[2,6,2],5,1}，
 * {2,3,4,2,[6,2,5],1}，
 * {2,3,4,2,6,[2,5,1]}
 *
 */

# include <iostream>
# include <vector>
# include <queue>

using namespace std;


class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned  size) {
        vector<int> res;
        if(num.empty() || size == 0)
            return res;

        deque<int> save; // 存储num数组的index

        for(unsigned i = 0; i < num.size(); i++){
            while(!save.empty() && num[save.back()] < num[i]){
                save.pop_back();
            }
            while(!save.empty() && i - save.front() >= size){ // i - size >= save.front() 因为unsigned，结果不一样
                save.pop_front();
            }
            save.push_back(i);
            if(i + 1 >= size)
                res.push_back(num[save.front()]);
        }
        return res;
    }



};

int main(){
    Solution s;
    vector<int> test;
    test.push_back(1);
    test.push_back(3);
    test.push_back(-1);
    test.push_back(-3);
    test.push_back(5);
    test.push_back(3);
    test.push_back(6);
    test.push_back(7);

    vector<int> res = s.maxInWindows(test, 3);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}