/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 删除链表中重复的结点
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 *
 */

# include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
        if(pHead == NULL) return pHead;
        ListNode* tmp = new ListNode(0);
        tmp->next = pHead;
        ListNode* preNode = tmp;
        ListNode* curNode = pHead;
        ListNode* nextNode = pHead;
        while(nextNode){
            bool duplicated = false;
            while(nextNode->next && nextNode->next->val == curNode->val) {
                nextNode = nextNode->next;
                duplicated = true;
            }
            if(duplicated) preNode->next = nextNode->next;
            else preNode = nextNode;

            nextNode = nextNode->next;
            curNode = nextNode;

        }
        return tmp->next;
    }
};

int main(){
    Solution s;
    return 0;
}