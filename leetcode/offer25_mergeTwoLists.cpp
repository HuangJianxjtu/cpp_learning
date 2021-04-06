#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

 //双指针法+伪头节点
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *curr = res;
        while (l1 && l2){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            } else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1){
            curr->next = l1;
        }
        if(l2){
            curr->next = l2;
        }
        return res->next;
    }

    ListNode* mergeTwoLists_recursion(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        if(l1->val < l2->val){
            l1->next = mergeTwoLists_recursion(l1->next, l2);
            return l1;
        } else{
            l2->next = mergeTwoLists_recursion(l1, l2->next);
            return l2;
        }
    }
};

int main(){
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next =new ListNode(4);
    Solution s;
    ListNode *res;
    res = s.mergeTwoLists_recursion(l1, l2);
    while (res){
        cout<<res->val<<" ";
        res = res->next;
    }
    return 0;
}