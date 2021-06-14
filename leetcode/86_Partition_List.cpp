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
    ListNode* partition(ListNode* head, int x){
        ListNode* res = new ListNode(0, head);
        ListNode* left_end = res;
        ListNode* pre = res;
        ListNode* cur = res->next;
        while (cur){
            if(cur->val < x && (left_end->next == cur)){
                left_end = cur;
                pre = cur;
                cur = cur->next;
            } else if(cur->val >= x){
                pre = cur;
                cur = cur->next;
            } else{   //将当前节点插入left_end后面
                ListNode* tmp_left_next = left_end->next;
                ListNode* tmp_cur_next = cur->next;

                left_end->next = cur;
                cur->next = tmp_left_next;
                pre->next = tmp_cur_next;

                left_end = left_end->next;
                cur = tmp_cur_next;
            }
        }
        return res->next;
    }
};

int main(){
    ListNode* test = new ListNode(1);
    test->next = new ListNode(4);
    test->next->next = new ListNode(3);
    test->next->next->next = new ListNode(2);
    test->next->next->next->next = new ListNode(5);
    test->next->next->next->next->next = new ListNode(2);

    ListNode* test1 = new ListNode(2);
    test1->next = new ListNode(1);

    Solution s;
    ListNode* result =  s.partition(test1, 2);
    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}

