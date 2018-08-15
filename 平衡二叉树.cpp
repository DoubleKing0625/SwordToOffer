/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 平衡二叉树
 * 定义：空树或左右子树高度高度差不超过1，且左右子树都是平衡二叉树
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 *
 */

# include <iostream>
# include <queue>
# include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot){
        int height = 0;
        return isBalanced(pRoot, height);
    }

    bool isBalanced(TreeNode *root, int &height)
    {
        if(!root) return true;
        int left=0,right=0;
        if(!isBalanced(root->left,left)) return false;
        if(!isBalanced(root->right,right)) return false;
        if(abs(left-right) > 1) return false;
        height = max(left,right) + 1;
        return true;
    }
};

int main(){
    return 0;
}