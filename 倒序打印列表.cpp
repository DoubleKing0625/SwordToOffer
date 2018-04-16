/*
 * Created by Peng Qixiang on 2018/4/1.
 */

/*
 *
 * 输入一个链表，从尾到头打印链表每个节点的值。
 *
 */


# include <iostream>
# include <stack>
# include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

// 用栈
vector<int> printListFromTailToHead(ListNode* head) {
    stack<int> tmp;
    ListNode* node = head;
    while(node != NULL){
        tmp.push(node->val);
        node = node->next;
    }
    vector<int> res;
    while(!tmp.empty()){
        res.push_back(tmp.top());
        tmp.pop();
    }
    return res;
}


int main(){

    ListNode *node1;
    node1->val = 1;
    ListNode *node2;
    node2->val = 2;
    node1->next =  node2;
    node2->next = NULL;

    vector<int> res = printListFromTailToHead(node1);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}





