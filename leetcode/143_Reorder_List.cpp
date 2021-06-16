#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next== NULL){
            return;
        } else if(head->next->next == NULL){
            return;
        }
        ListNode* curr = head;
        while (true){
            ListNode* node_next = curr->next;
            ListNode* node_end_pre = curr;
            ListNode* node_end = curr->next;
            while (node_end->next != NULL){
                node_end_pre = node_end;
                node_end = node_end->next;
            }
            // 将node_next插到curr后
            curr->next = node_end;
            node_end->next = node_next;
            node_end_pre->next = NULL;
            curr = node_next;

            if(curr->next== NULL){
                break;
            } else if(curr->next->next == NULL){
                break;
            }
        }
    }
};

int main(){
    ListNode* test = new ListNode(1);
    test->next = new ListNode(2);
    // test->next->next = new ListNode(3);
    // test->next->next->next = new ListNode(4);
    // test->next->next->next->next = new ListNode(5);

    Solution s;
    s.reorderList(test);

    while (test){
        cout<<test->val<<" ";
        test = test->next;
    }
    return 0;
}