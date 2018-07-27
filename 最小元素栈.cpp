/*
 * Created by Peng Qixiang on 2018/7/27.
 */

/*
 * 定义栈的数据结构，
 * 请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））
 *
 */

# include <iostream>
# include <stack>

using namespace std;
// stack pop一个最小值， m应该也变，所以借用一个辅助栈
class Solution {
public:
    stack<int> res, min_stack;
    int m; //记录当前最小值
    void push(int value) {
        // update m
        if(res.empty()){
            m = value;
        }
        else{
            m = m <= value? m : value;
        }
        res.push(value);
        min_stack.push(m);
    }
    void pop() {
        res.pop();
        min_stack.pop();
    }
    int top() {
        return res.top();
    }
    int min() {
        return min_stack.top();
    }
};

int main(){

    return 0;
}