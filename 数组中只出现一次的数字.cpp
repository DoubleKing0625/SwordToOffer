/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 数组中只出现一次的数字
 * 一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。
 * 请写程序找出这两个只出现一次的数字。
 *
 */

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) return;
        int tmp = data[0];
        for(int i = 1; i < data.size(); i++){
            tmp ^= data[i];
        }
        if(tmp == 0) return;
        int index = 0;
        while((tmp&1) == 0){ // 按位与比判断等优先级低！！！！！！！
            index++;
            tmp = tmp>>1;
        }
        *num1 = *num2 = 0;
        for(int i = 0; i < data.size(); i++){
            if(isBit(data[i], index))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }

    bool isBit(int num, int index){
        num = num >> index;
        return (num&1);
    }
};

int main(){
    return 0;
}