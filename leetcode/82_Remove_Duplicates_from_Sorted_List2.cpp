#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {};
    explicit ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode *next): val(x), next(next) {};
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode(0, head);
        ListNode* p=res->next;
        ListNode* front = res;
        while (p){
            int v=p->val;
            int count = 0;
            ListNode* q=p;
            while (q != nullptr && (q->val == v)){
                q = q->next;
                count++;
            }
            if(count >= 2){  //有重复节点，需删除
                front->next = q;
                p=q;
            } else{
                front = p;
                p = q;
            }
        }
        return res->next;
    }
};

int main(){
    ListNode *l0 = new ListNode(1);
    l0->next = new ListNode(1);
    l0->next->next = new ListNode(1);
    l0->next->next->next = new ListNode(2);
    l0->next->next->next->next = new ListNode(3);

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(3);
    l1->next->next->next->next = new ListNode(4);
    l1->next->next->next->next->next = new ListNode(4);
    l1->next->next->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode *ll = s.deleteDuplicates(l1);

    while (ll){
        cout<<ll->val<<" ";
        ll=ll->next;
    }
    return 0;
}