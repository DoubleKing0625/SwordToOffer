/*
 * Created by Peng Qixiang on 2018/8/20.
 */

/*
 * 序列化二叉树
 * 请实现两个函数，分别用来序列化和反序列化二叉树
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
    char* Serialize(TreeNode *root) {
        if(root == NULL) return NULL;
    }

    void serialize(TreeNode *root, string& str){

    }

    TreeNode* Deserialize(char *str) {

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

    char* resChar = s.Serialize(a1);
    TreeNode* resTree = s.Deserialize(resChar);

    return 0;
}





