/*
 * Created by Peng Qixiang on 2018/8/1.
 */

/*
 * 二叉树中和为某一值的路径
 * 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
 *
 */

# include <iostream>
# include <vector>
# include <stack>

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
    // 如何保证 在返回值的list中，数组长度大的数组靠前 ？？？？？
    void DFS(TreeNode* root, int expectNumber, vector<vector<int>>& finalRes, vector<int>& oneRes){
        oneRes.push_back(root->val);
        if(!root->left && !root->right) {
            if (root->val == expectNumber) {
                finalRes.push_back(oneRes);
            }
        }
        if(root->left){
            DFS(root->left, expectNumber-root->val, finalRes, oneRes);
        }
        if(root->right){
            DFS(root->right, expectNumber-root->val, finalRes, oneRes);
        }
        oneRes.pop_back();
    }

    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> finalRes;
        vector<int> oneRes;
        if(root){
            DFS(root, expectNumber, finalRes, oneRes);
        }
        return finalRes;

    }
};

int main(){
    Solution s = Solution();

    return 0;
}