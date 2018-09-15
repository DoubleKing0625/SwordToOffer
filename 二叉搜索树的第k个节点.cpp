/*
 * Created by Peng Qixiang on 2018/8/20.
 */

/*
 * 给定一棵二叉搜索树，请找出其中的第k小的结点。
 * 例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
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

class Solution {

public:
    // 中序遍历即排好序的序列
    int index = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if(pRoot != NULL) {
            TreeNode *node = KthNode(pRoot->left, k);
            if(node != NULL)
                return node;
            if (++index == k)
                return pRoot;
            node = KthNode(pRoot->right, k);
            if(node != NULL)
                return node;
        }
        return NULL; // 最重要始终返回NULL
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

    TreeNode* res = s.KthNode(a1, 3);
    cout << res->val << endl;

    return 0;
}





