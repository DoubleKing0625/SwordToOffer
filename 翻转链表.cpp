/*
 * Created by Peng Qixiang on 2018/7/5.
 */

/*
 * 反转链表
 * 输入一个链表，反转链表后，输出新链表的表头。
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

ListNode* ReverseList(ListNode* pHead) {
    ListNode* pre = pHead;
    if(pre == NULL){
        return NULL;
    }
    ListNode* current = pre->next;
    if(current == NULL){
        return pre;
    }
    ListNode* post = current->next;
    if(post == NULL){
        current->next = pre;
        pre->next = NULL;
        return current;
    }
    pre->next = NULL; // reverse the first node
    while(post != NULL){
        current->next = pre;
        pre = current;
        current = post;
        post = post->next;
        // current->next = pre;
    }
    current->next=pre;
    return current;
}

// 提前加一个pre, 完善循环操作
ListNode* ReverseList1(ListNode* pHead){
    ListNode* pre = NULL;
    ListNode* current = pHead;
    while(current){
        ListNode* post = current->next;
        current->next = pre;
        pre = current;
        current = post;
    }
    return pre;
}


int main(){

    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    ListNode *node_reverse = ReverseList(node1);
    while(node_reverse != NULL){
        cout << node_reverse->val << endl;
        node_reverse = node_reverse->next;
    }

    return 0;
}





