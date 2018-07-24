/*
 * Created by Peng Qixiang on 2018/7/21.
 */

/*
 * 树的镜像
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
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

// recursion version
void Mirror(TreeNode *pRoot) {
    if(pRoot){
        TreeNode* tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
}
// normal version
void Mirror1(TreeNode *pRoot){
// 首先判断tmp为空
    if(!pRoot){
        return;
    }
    stack<TreeNode*> save;
    save.push(pRoot);
    while(!save.empty()){ // empty return true
        TreeNode* tmp = save.top();
        save.pop();
//
//        if(tmp){
//            TreeNode *tmp1 = tmp->left;
//            tmp->left = tmp->right;
//            tmp->right = tmp1;
//            save.push(tmp->left);
//            save.push(tmp->right);
//        }
        if(tmp->left || tmp->right) {
            TreeNode *tmp1 = tmp->left;
            tmp->left = tmp->right;
            tmp->right = tmp1;
        }
        if(tmp->left){
            save.push(tmp->left);
        }
        if(tmp->right){
            save.push(tmp->right);
        }
    }
}

// normal version2
void Mirror2(TreeNode *pRoot){

    stack<TreeNode*> save;
    save.push(pRoot);
    while(!save.empty()){ // empty return true
        TreeNode* tmp = save.top();
        save.pop();
        if(tmp){
            TreeNode *tmp1 = tmp->left;
            tmp->left = tmp->right;
            tmp->right = tmp1;
            save.push(tmp->left);
            save.push(tmp->right);
        }
    }
}

int main(){

    return 0;
}





