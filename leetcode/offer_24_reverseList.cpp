#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *curr = head;

        while (curr){
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
    void printList(ListNode* head){
        while (head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
};

int main(){
    ListNode *head = nullptr;
    head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    ListNode *res = nullptr;
    Solution s;
    s.printList(head);
    res = s.reverseList(head);
    s.printList(res);
    return 0;
}