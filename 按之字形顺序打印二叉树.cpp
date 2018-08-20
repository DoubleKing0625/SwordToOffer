/*
 * Created by Peng Qixiang on 2018/8/20.
 */

/*
 * 按之字形顺序打印二叉树
 * 请实现一个函数按照之字形打印二叉树
 * 即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
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
        deque<TreeNode*> tmp;
        tmp.push_back(pRoot);
        int length;
        bool odd = true;
        while(!tmp.empty()){
            int length = tmp.size();
            vector<int> layer;
            while(length > 0){
                if(odd) {
                    TreeNode *node = tmp.front();
                    tmp.pop_front();
                    layer.push_back(node->val);
                    if(node->left) tmp.push_back(node->left);
                    if(node->right) tmp.push_back(node->right);
                }
                else{
                    TreeNode *node = tmp.back();
                    tmp.pop_back();
                    layer.push_back(node->val);
                    if(node->right) tmp.push_front(node->right);
                    if(node->left) tmp.push_front(node->left);
                }
                length--;
            }
            odd = !odd;
            res.push_back(layer);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    TreeNode* a1 = new TreeNode(8);
    TreeNode* a2 = new TreeNode(6);
    TreeNode* a3 = new TreeNode(10);
    TreeNode* a4 = new TreeNode(5);
    TreeNode* a5 = new TreeNode(7);
    TreeNode* a6 = new TreeNode(9);
    TreeNode* a7 = new TreeNode(11);

    a1->left = a2;
    a1->right = a3;
    a2->left = a4;
    a2->right = a5;
    a3->left = a6;
    a3->left = a7;

    vector<vector<int>> res = s.Print(a1);
    return 0;
}





