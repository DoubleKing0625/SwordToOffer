/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 从1到n整数中1出现的次数
 * 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次
 * 求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）
 *
 */

# include <iostream>
# include <vector>
# include <cmath>

using namespace std;

class Solution {
public:
    // 暴力
    int NumberOf1Between1AndN_Solution(int n){
        int count = 0;
        for(int i = 0; i <= n; i++){
            int tmp = i;
            while(tmp){
                if(tmp % 10 == 1) count++;
                tmp /= 10;
            }
        }
        return count;
    }
    // 总结规律
    // 分为个位和其他位 以534 为例
    // 个位： round = 53, weight = 4, base = 1
    //       (1) weight == 0: count = round * base
    //       (2) weight > 0: count = round * base + 1
    // 其他位(以十位为例) round = 5, weight = 3, former = 4, base = 10(千位则为100)
    //       (1) weight == 0: count = round * base
    //       (2) weight == 1: count = round * base + former + 1
    //       (3) weight > 1: count = round % base + base
    int NumberOf1Between1AndN_Solution1(int n){
        if(n<1)
            return 0;
        int count = 0;
        int base = 1;
        int round = n;
        while(round>0){
            int weight = round%10;
            round/=10;
            count += round*base;
            if(weight==1)
                count+=(n%base)+1; // n%base == former
            else if(weight>1)
                count+=base;
            base*=10;
        }
        return count;
    }
};

int main(){
    Solution s = Solution();
    cout << s.NumberOf1Between1AndN_Solution(13) << endl;
    cout << s.NumberOf1Between1AndN_Solution1(13) << endl;

    return 0;
}