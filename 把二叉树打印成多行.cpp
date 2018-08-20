/*
 * Created by Peng Qixiang on 2018/8/14.
 */

/*
 * 把二叉树打印成多行
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行
 *
 */

# include <iostream>
# include <vector>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot == NULL) return res;
        queue<TreeNode*> tmp;
        tmp.push(pRoot);
        int length;
        while(!tmp.empty()){
            int length = tmp.size();
            vector<int> layer;
            while(length > 0){
                TreeNode* node = tmp.front();
                layer.push_back(node->val);
                // from left to right
                if(node->left) tmp.push(node->left);
                if(node->right) tmp.push(node->right);
                tmp.pop();
                length--;
            }
            res.push_back(layer);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    return 0;
}





