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

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* res = new ListNode(0, head);
        ListNode* curr = res->next;
        ListNode* curr_pre = res;
        ListNode* end = head;
        while (end->next != NULL){
            end = end->next;
        }
        while (curr != end) {
            ListNode *tmp_curr_next = curr->next;
            ListNode *tmp_end_next = end->next;
            end->next = curr;  //交换
            curr->next = tmp_end_next;
            curr_pre->next = tmp_curr_next;

            curr = tmp_curr_next;// curr向下移动
        }
        return res->next;
    }
};

int main(){
    ListNode* test = new ListNode(1);
    test->next = new ListNode(2);
    test->next->next = new ListNode(3);
    test->next->next->next = new ListNode(4);
    test->next->next->next->next = new ListNode(5);

    ListNode* test1 = new ListNode(5);
    test1->next = new ListNode(4);

    Solution s;
    ListNode* result = s.reverseList(test1);
    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}