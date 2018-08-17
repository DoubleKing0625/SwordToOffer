/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 构建乘积数组
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
 * 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
 * 不能使用除法.
 *
 */

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // 从左到右算 B[i]=A[0]*A[1]*...*A[i-1]
    // 从右到左算B[i]*=A[i+1]*...*A[n-1]
    // 注意头尾情况
    vector<int> multiply(const vector<int>& A){
        if(A.empty()) return A;
        int length = A.size();
        vector<int> res(length);
        int mul = 1;
        res[0] = 1;
        for(int i = 1; i < length; i++){
            mul *= A[i-1];
            res[i] = mul;
        }
        mul = 1;
        for(int i = length - 2; i >= 0; i--){
            mul *= A[i+1];
            res[i] *= mul;
        }
        return res;
    }
};

int main(){
    Solution s;
    int test[] = {2,3,1,0,2,5,3};
    int i = 0;
    s.duplicate(test, 7, &i);
    cout << i << endl;
    return 0;
}