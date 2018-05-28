/*
 * Created by Peng Qixiang on 2018/5/27.
 */

/*
 * 输入一个整数，输出该数二进制表示中1的个数.
 * 其中负数用补码表示。
 */

# include <iostream>

using namespace std;
// 错误，负数左移最高位填1， 固会陷入死循环
int NumberOf1_v1(int n) {
    int count = 0;
    while (n != 0) {
        count += (n & 1);
        n = n >> 1;
    }
    return count;
}

// 解法1， n = n & (n-1), 将最右边一个1置0
int NumberOf1(int n){
    int count = 0;
    while( n != 0){
        count ++;
        n = n & (n-1);
    }
    return count;
}

int main(){
    cout << NumberOf1(61) << endl;
    return 0;
}





