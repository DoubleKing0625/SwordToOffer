/*
 * Created by Peng Qixiang on 2018/4/23.
 */

/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * F(n) = F(n-1) + F(n-2) + F(n-3) + ... + F(1) + 1 = 2 * F(n-1)
 */
# include <iostream>
# include <cmath>

using namespace std;

int jumpFloorII(int number){
    return pow(2, number - 1);
}

int main(){
    cout << jumpFloorII(5) << endl;
    return 0;
}





