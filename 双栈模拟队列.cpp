/*
 * Created by Peng Qixiang on 2018/4/3.
 */

/*
 * 用两个栈实现队列
 * 完成队列的Push和Pop操作。
 *
 */


# include <iostream>
# include <stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
    int pop(){
        int res;
        if(stack2.empty()){
            while(!stack1.empty()){
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};



int main(){

    return 0;
}





