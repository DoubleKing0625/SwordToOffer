/*
 * Created by Peng Qixiang on 2018/4/3.
 */

/*
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 *
 */


# include <iostream>
# include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // 构造函数:后面内容用于给类成员赋值
};

// 前序:根左右， 中序:左根右， 后序: 左右根
// 给定前序中序或者后序中序才能决定唯一的一棵树
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.size() == 0){
        return NULL;
    }

    TreeNode* root = new TreeNode(pre[0]);
    int index; //记录root在中序的位置
    for(index = 0; index < vin.size(); index++){ //例子中index=3
        if(vin[index] == root->val){
            break;
        }
    }
    //有子树，算出左右子树前序中序数组，迭代
    vector<int> left_pre, right_pre, left_vin, right_vin;
    for (int i = 0; i < index; i++) {
        left_pre.push_back(pre[i + 1]);
        left_vin.push_back(vin[i]);
    }
    for (int i = index + 1; i < pre.size(); i++) {
        right_pre.push_back(pre[i]);
        right_vin.push_back(vin[i]);
    }

    root->left = reConstructBinaryTree(left_pre, left_vin);
    root->right = reConstructBinaryTree(right_pre, right_vin);

    return root;
}



int main(){

    int p[] = {1,2,4,7,3,5,6,8};
    int v[] = {4,7,2,1,5,3,8,6};
    vector<int> pre(p, p + sizeof(p) / sizeof(int));
    vector<int> vin(v, v + sizeof(v) / sizeof(int));
    cout << pre.size() << endl << vin.size() << endl;
    TreeNode* root = reConstructBinaryTree(pre, vin);
    cout << root->left->left->val << endl;

    return 0;
}





