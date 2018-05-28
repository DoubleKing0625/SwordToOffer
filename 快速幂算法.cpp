/*
 * Created by Peng Qixiang on 2018/5/27.
 */

/*
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 *
 */

# include <iostream>

using namespace std;
// a^(156) = a^(10011100) = [a^(2^7*1)]*[a^(2^6*0)]*...*[a^(2^0*0)]
double Power(double base, int exponent) {
    int e; // 指数
    double res = 1.0;
    if(exponent > 0){ // 指数 > 0
        e = exponent;
    }
    else if(exponent < 0){ // 指数 < 0, base 不能为0， res = 1 / (base ^ (-exponent))
        if(base == 0){
            cout << "分母不能为0" << endl;
            return 0;
        }
        else{
            e = -exponent;
        }
    }
    else{
        return 1;
    }
    while( e != 0){
        if(e & 1){
            res *= base;
        }
        base *= base;
        e  >>= 1;
    }
    return exponent >= 0 ? res : (1 / res);
}

int main(){
    cout << Power(2, -3) << endl;
    return 0;
}





