/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 二叉树的深度
 * 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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
    // 递归版本
    int TreeDepth(TreeNode* pRoot){
        if(pRoot == NULL) return 0;
        int hLeft = TreeDepth(pRoot->left);
        int hRight = TreeDepth(pRoot->right);
        return hLeft > hRight ? hLeft + 1: hRight + 1;
    }
    // 广度遍历，记录层数
    int TreeDepth1(TreeNode* pRoot){
        if(pRoot == NULL) return 0;
        queue<TreeNode*> save;
        int height = 0;
        TreeNode* tmp = pRoot;
        save.push(tmp);
        while(!save.empty()){
            height++;
            int cnt = 0;
            int curLayerNodes = save.size();
            while(cnt < curLayerNodes){
                cnt++;
                TreeNode* tmp = save.front();
                save.pop();
                if(tmp->right) save.push(tmp->right);
                if(tmp->left) save.push(tmp->left);
            }
        }
        return height;
    }
};

int main(){
    return 0;
}