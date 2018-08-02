/*
 * Created by Peng Qixiang on 2018/8/1.
 */

/*
 * 复杂链表的复制
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
 * 注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空
 *
 */

# include <iostream>
# include <vector>
# include <stack>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(!pHead){
            return NULL;
        }
        RandomListNode* currNode = pHead;
        // copy list， A->B->C ===>  A->A'->B->B'->C->C'
        while(currNode){
            RandomListNode* cloneNode = new RandomListNode(currNode->label);
            cloneNode->next = currNode->next;
            currNode->next = cloneNode;
            currNode = cloneNode->next;
        }
        // copy random relation
        currNode = pHead;
        while(currNode){
            RandomListNode* cloneNode = currNode->next;
            if(currNode->random){
                cloneNode->random = currNode->random->next;
            }
            currNode = cloneNode->next;
        }
        // split list
        RandomListNode* cloneHead = pHead->next;
        currNode = pHead;
        // 不用while(currNode)判断，因为要保证tmp->next存在
        while(currNode->next){
            RandomListNode* tmp = currNode->next;
            currNode->next = tmp->next;
            currNode = tmp;
        }
        return cloneHead;
    }
};

int main(){
    Solution s = Solution();

    return 0;
}