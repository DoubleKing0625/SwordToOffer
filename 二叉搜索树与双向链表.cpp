/*
 * Created by Peng Qixiang on 2018/8/1.
 */

/*
 * 二叉搜索树与双向链表
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
 *
 */

# include <iostream>
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
    // recursion version
    TreeNode* Convert(TreeNode* pRootOfTree){
        if(!pRootOfTree){
            return NULL;
        }
        // 先处理右子树
        TreeNode* rightRoot = Convert(pRootOfTree->right);
        if(rightRoot) {
            pRootOfTree->right = rightRoot;
            rightRoot->left = pRootOfTree;
        }

        if(!pRootOfTree->left){
            return pRootOfTree;
        }
        // 递归左子树，返回左子树转换后的链表根节点
        TreeNode* leftRoot = Convert(pRootOfTree->left);
        // find the end point
        TreeNode* tmp = leftRoot;
        while(tmp->right){
            tmp = tmp->right;
        }
        tmp->right = pRootOfTree;
        pRootOfTree -> left = tmp;
        return leftRoot;
    }
    // normal version 中序遍历
    TreeNode* Convert1(TreeNode* pRootOfTree){
        if(!pRootOfTree){
            return NULL;
        }
        TreeNode* current = pRootOfTree;
        TreeNode* pre;
        bool first = true;
        stack<TreeNode*> save;
        while(current || !save.empty()){
            while(current){
                save.push(current);
                current = current->left;
            }
            current = save.top();
            save.pop();
            if(first){
                pRootOfTree = current;
                pre = current;
                first = false;
            }
            else{
                pre->right = current;
                current->left = pre;
                pre = current;
            }
            current = current->right;
        }
        return pRootOfTree;
    }

};

int main(){
    Solution s = Solution();

    return 0;
}