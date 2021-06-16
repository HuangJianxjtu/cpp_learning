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
    ListNode* sortList(ListNode* head) {
        if((head == NULL) || (head->next == NULL)){
            return head;
        }
        ListNode* res = new ListNode(0, head);
        ListNode* pre = res;
        ListNode* curr = res->next;
        while ((curr != NULL) && (curr->next != NULL)){
            ListNode* min = curr;
            ListNode* min_pre = pre;
            ListNode* p = curr;
            while (p != NULL){
                if(p->val < min->val){
                    min = p;
                }
                p = p->next;
            }
            ListNode* tmp_curr_next = curr->next;
            if(curr != min){// 交换curr和min
                if(curr->next == min){
                    ListNode* tmp_min_next = min->next;
                    pre->next = min;
                    min->next = curr;
                    curr->next = tmp_min_next;

                    pre = min;
                } else{
                    while (min_pre->next != min){
                        min_pre = min_pre->next;
                    }
                    ListNode* tmp_min_next = min->next;
                    pre->next = min;
                    min->next = tmp_curr_next;
                    min_pre->next = curr;
                    curr->next = tmp_min_next;

                    pre = min;
                    curr = tmp_curr_next;
                }

            } else{
                pre = curr;
                curr = tmp_curr_next;
            }

        }
        return res->next;
    }
};


int main(){
    //[4,19,14,5,-3,1,8,5,11,15]
    ListNode* test = new ListNode(4);
    test->next = new ListNode(19);
    test->next->next = new ListNode(14);
    test->next->next->next = new ListNode(5);
    test->next->next->next->next = new ListNode(-3);
    test->next->next->next->next->next = new ListNode(1);
    test->next->next->next->next->next->next = new ListNode(8);
    test->next->next->next->next->next->next->next = new ListNode(5);
    test->next->next->next->next->next->next->next->next = new ListNode(11);
    test->next->next->next->next->next->next->next->next->next = new ListNode(15);

    Solution s;

    ListNode* res = s.sortList(test);

    while (res){
        cout<<res->val<<" ";
        res = res->next;
    }
    return 0;
}
