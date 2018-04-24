/*
 * Created by Peng Qixiang on 2018/4/23.
 */

/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法。
 *
 */


# include <iostream>
# include <vector>

using namespace std;

int jumpFloor(int number) {
    if(number < 0){
        return -1;
    }
    if(number <= 2){
        return number;
    }
    int n1 = 1;
    int n2 = 2;
    int n = number - 2;//begin from n = 3
    while(n--){
        n2 += n1;
        n1 = n2 - n1;
    }
    return n2;
}

int main(){
    cout << jumpFloor(5) << endl;
    return 0;
}





