/*
 * Created by Peng Qixiang on 2018/7/19.
 */

/*
 * 合并两个排序的链表
 * 输入两个单调递增的链表，输出两个链表合成后的链表。
 * 当然我们需要合成后的链表满足单调不减规则。
 *
 */

# include <iostream>
# include <stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if(!pHead1 || !pHead2){
        return pHead1 ? pHead1 : pHead2;
    }
    ListNode fake(0);
    ListNode* preHead = &fake;
    while(pHead1 && pHead2){
        if(pHead1->val < pHead2->val){
            preHead->next = pHead1;
            pHead1 = pHead1->next;
        }
        else{
            preHead->next = pHead2;
            pHead2 = pHead2->next;
        }
        preHead = preHead->next;
    }
    preHead->next = pHead1 ? pHead1 : pHead2;
    return fake.next;
}

// recurrence version
ListNode* Merge1(ListNode* pHead1, ListNode* pHead2){
    if(!pHead1 || !pHead2){
        return pHead1 ? pHead1 : pHead2;
    }
    if(pHead1->val < pHead2->val){
        pHead1->next = Merge1(pHead1->next, pHead2);
        return pHead1;
    }
    else{
        pHead2->next = Merge1(pHead1, pHead2->next);
        return pHead2;
    }
}

int main(){

    ListNode *node1 = new ListNode(1);
    ListNode *node12 = new ListNode(3);
    ListNode *node13 = new ListNode(5);

    ListNode *node2 = new ListNode(2);
    ListNode *node22 = new ListNode(4);
    ListNode *node23 = new ListNode(6);

    node1->next = node12;
    node12->next = node13;

    node2->next = node22;
    node22->next = node23;

    ListNode *node_merge = Merge1(node1, node2);
    while(node_merge != NULL){
        cout << node_merge->val << endl;
        node_merge = node_merge->next;
    }

    return 0;
}





