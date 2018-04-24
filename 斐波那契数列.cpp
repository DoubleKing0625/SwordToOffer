/*
 * Created by Peng Qixiang on 2018/4/23.
 */

/*
 * 大家都知道斐波那契数列，
 * 现在要求输入一个整数n，请你输出斐波那契数列的第n项。
 * n <= 39
 *
 */


# include <iostream>
# include <vector>

using namespace std;

int FibonacciRecursion(int n) { //效率太低
    if(n < 0){
        return -1;
    }
    else if(n <= 1){
        return n;
    }
    else{
        return FibonacciRecursion(n-1) + FibonacciRecursion(n-2);
    }
}

int Fibonacci(int n){
    int f = 0;
    int g = 1;
    while(n--){
        g += f;
        f = g - f;
    }
    return f;
}

int main(){
    cout << Fibonacci(5) << endl;
    return 0;
}





