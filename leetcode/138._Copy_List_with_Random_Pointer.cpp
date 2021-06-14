#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution{
public:
    Node* copyRandomList(Node* head){
        Node* res = new Node(0);
        Node* curr_orig = head;
        Node* curr_new = res;
        while(curr_orig){
            curr_new->next = new Node(curr_orig->val);
            curr_orig = curr_orig->next;
            curr_new = curr_new->next;
        }
        curr_new = res->next;
        curr_orig = head;
        while(curr_orig){
            int index=0;
            Node* tmp_node  = head;
            while ((tmp_node != curr_orig->random) && (curr_orig->random != NULL)){
                tmp_node = tmp_node->next;
                index++;
            }
            if(curr_orig->random == NULL){
                curr_new->random = NULL;
            } else{
                tmp_node = res->next;
                for(int i=0;i<index;i++){
                    tmp_node = tmp_node->next;
                }
                curr_new->random = tmp_node;
            }
            curr_new = curr_new->next;
            curr_orig = curr_orig->next;
        }
        return res->next;
    }
};

int main(){
    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);
    node1->next = node2;
    node1->random = NULL;
    node2->next = node3;
    node2->random = node1;
    node3->next = node4;
    node3->random = node5;
    node4->next = node5;
    node4->random = node3;
    node5->random = node1;

    Solution s;
    Node* result = s.copyRandomList(node1);

    return 0;
}