/*
 * Created by Peng Qixiang on 2018/5/27.
 */

/*
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序。
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分
 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 *
 */

# include <iostream>
# include <vector>
# include <stack>

using namespace std;

void reOrderArray(vector<int> &array) {
    stack<int> odd;
    stack<int> pair;
    for(int i = 0; i < array.size(); i++){
        if(array[i] % 2 == 1){
            odd.push(array[i]);
        }
        else{
            pair.push(array[i]);
        }
    }
    int i = array.size() - 1;
    while(!pair.empty()){
        array[i] = pair.top();
        pair.pop();
        i--;
    }
    while(!odd.empty()){
        array[i] = odd.top();
        odd.pop();
        i--;
    }
}

int main(){
    vector<int> a = vector<int>(4,0);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << endl;
    }
    reOrderArray(a);
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << endl;
    }
    return 0;
}





