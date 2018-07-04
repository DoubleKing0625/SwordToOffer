/*
 * Created by Peng Qixiang on 2018/6/25.
 */

/*
 * 链表中倒数第k个结点
 * 输入一个链表，输出该链表中倒数第k个结点。
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

// Each solution has O(n + n - k + 1)

/* use stack */
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(!pListHead || k == 0){
        return NULL;
    }
    stack<ListNode*> data;
    ListNode* point = pListHead;
    int num = 0;
    while(point != NULL){
        data.push(point);
        point = point->next;
        num++;
    }
    if(num < k){
        return NULL;
    }
    for(int i = 0; i < k; i++){
        point = data.top();
        data.pop();
    }
    return point;
}



/* two points, first one points at k_th node, second one points at 1_th node.
 * Then two points run at same time. When first one points at final node, second one points at last k_th node.
 */
ListNode* FindKthToTail11(ListNode* pListHead, unsigned int k) {
    if(!pListHead || k == 0){
        return NULL;
    }
    ListNode* pre = pListHead;
    ListNode* last = pListHead;
    for(int i = 1; i < k; i++){
        if(pre->next){
            pre = pre->next;
        }
        else {
            return NULL;
        }
    }
    while(pre->next){
        pre = pre->next;
        last = last->next;
    }
    return last;
}

int main(){

    return 0;
}





