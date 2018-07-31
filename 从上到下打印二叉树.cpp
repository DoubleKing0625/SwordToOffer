/*
 * Created by Peng Qixiang on 2018/7/31.
 */

/*
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 *
 */

# include <iostream>
# include <queue>

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
    //广度遍历
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> traverse;
        vector<int> res;
        traverse.push(root);
        while(!traverse.empty()) {
            TreeNode* tmp = traverse.front();
            traverse.pop();
            // 初始值错误处理
            if(!tmp){
                continue;
            }
            res.push_back(tmp->val);
            if(tmp->left){
                traverse.push(tmp->left);
            }
            if(tmp->right){
                traverse.push(tmp->right);
            }
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    return 0;
}