/*
 * Created by Peng Qixiang on 2018/7/19.
 */

/*
 * 树的子结构
 * 输入两棵二叉树A，B，判断B是不是A的子结构。
 * 我们约定空树不是任意一个树的子结构
 *
 */

# include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

// 若是root节点值相同，判断各自左右子树是不是分别值相同的的树，或者1的左右子树是否含有2
// 注意两种情况的不同

//判断第一种情况
bool SameRoot(TreeNode* pRoot1, TreeNode* pRoot2){
    // pRoot2为null，为true
    if(!pRoot2){
        return true;
    }
    // pRoot2不为null，pRoot1为null，为false
    if(!pRoot1){
        return false;
    }

    if(pRoot1->val == pRoot2->val){
        return SameRoot(pRoot1->left, pRoot2->left) && SameRoot(pRoot1->right, pRoot2->right);
    }
    else{
        return false;
    }
}
// 判断第二种情况
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    // 有一个为null，返回false
    if(!pRoot1 || !pRoot2){
        return false;
    }
    return SameRoot(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

int main(){

    return 0;
}





