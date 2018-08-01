/*
 * Created by Peng Qixiang on 2018/8/1.
 */

/*
 * 二叉搜索树的后序遍历序列
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 *
 */

# include <iostream>
# include <vector>

using namespace std;



class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence){
        if(sequence.empty()){
            return false;
        }
        int index = 0, root = sequence.back();
        vector<int> left, right;
        // find the bound between left and right subtree
        while(index < sequence.size() - 1){
            if(sequence[index] < root){
                index++;
                left.push_back(sequence[index]);
                continue;
            }
            else {
                break;
            }
        }
        for(int i = index; i < sequence.size() - 1; i++){
            if(sequence[i] < root){
                return false;
            }
            else{
                right.push_back(sequence[i]);
            }
        }
        return (left.empty()? true : VerifySquenceOfBST(left)) && (right.empty()? true : VerifySquenceOfBST(right));
    }
    //上述版本占用额外空间太多，其实只需保存两个index即可
    bool judge(vector<int>& sequence, int start, int end){
        if(start >= end){
            return true;
        }
        //find the bound between left and right subtree
        int index = start;
        while(index < end ){
            if(sequence[index] > sequence[end]){
                break;
            }
            index++;
        }
        for(int i = index; i < end; i++){
            if(sequence[i] < sequence[end]){
                return false;
            }
        }
        return judge(sequence, start, index - 1) && judge(sequence, index, end - 1);
    }

    bool VerifySquenceOfBST1(vector<int> sequence){
        if(sequence.empty()){
            return false;
        }
        return judge(sequence, 0, sequence.size()-1);
    }
};

int main(){
    Solution s = Solution();
    return 0;
}