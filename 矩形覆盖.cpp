/*
 * Created by Peng Qixiang on 2018/4/25.
 */

/*
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形.
 * 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * same as fibonacci
 * when n > 2,
 * case 1: put 2*1 firstly, f(n-1)
 * case 2: put 1*2 firstly, f(n-2)
 * so f(n) = f(n-1) + f(n-2)
 */

# include <iostream>

using namespace std;

int rectCover(int number) {
    if(number < 0){
        return -1;
    }
    if(number <= 2){
        return number;
    }
    int f = 1, g = 2;
    int n = number -2;
    while(n--){
        g += f;
        f = g - f;
    }
    return g;
}

int main(){
    cout << rectCover(5) << endl;
    return 0;
}





