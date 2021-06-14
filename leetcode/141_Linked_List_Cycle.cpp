#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    bool hasCycle(ListNode* head){
        ListNode* curr = head;
        vector<ListNode*> node_set;
        node_set.push_back(head);
        int pos = -1;
        while (curr){
            ListNode* tmp_next = curr->next;
            for(int i=0;i<node_set.size();i++){
                if(node_set[i] == tmp_next){
                    pos = i;
                    break;
                }
            }
            if(pos > -1){
                break;
            } else{
                node_set.push_back(curr);
                curr = curr->next;
            }
        }
        if(pos == -1){
            return false;
        } else {
            return true;
        }
    }
};