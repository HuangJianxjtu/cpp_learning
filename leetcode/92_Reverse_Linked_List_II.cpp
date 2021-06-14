#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {};
    explicit ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode *next): val(x), next(next) {};
};

class Solution{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right){
        ListNode* res = new ListNode(0, head);
        ListNode* right_node = res->next;
        ListNode* left_node = res->next;
        ListNode* pre_left = res;
        int i=1;
        while (i<left){
            pre_left = left_node;
            left_node = left_node->next;
            i++;
        }
        i=1;
        while (i<right){
            right_node = right_node->next;
            i++;
        }
        while (left_node != right_node){//翻转
            ListNode* tmp_left_next = left_node->next;
            ListNode* tmp_right_next = right_node->next;
            right_node->next = left_node;
            left_node->next = tmp_right_next;
            pre_left->next = tmp_left_next;
            left_node = tmp_left_next;
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

    Solution s;
    ListNode* result = s.reverseBetween(test1,1,1);
    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}