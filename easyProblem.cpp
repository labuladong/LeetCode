//
// Created by admin on 2018/10/16.
//

 struct ListNode {
     int val;
     ListNode *next;

     explicit ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }

    ListNode* addTwoNumber(ListNode *l1, ListNode *l2){
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 ||extra){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->val = sum % 10;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            if (l1 || l2 || extra){
                p->next = new ListNode(extra);
                p = p->next;
            }
        }
    }

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2){
        auto* root = new ListNode(0);
        return helper(l1, l2, root);
    }

    ListNode* helper(ListNode* l1, ListNode* l2, ListNode* root) {
        if (!l1 && !l2)
            return nullptr;
        if (!l1 || !l2){
            return l1 ? l1: l2;
        }
        int sum = 0;
        ListNode *cur = root;

        while(l1 && l2){
            sum = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            if (sum >= 10){
                cur->val += sum % 10;
                cur->next = new ListNode(1);
            } else {
                cur->val += sum;
                if (l1 && l2){
                    cur->next = new ListNode(0);

                }
                if (cur->val >= 10){
                    cur->val = cur->val %10;
                    cur->next = new ListNode(1);
                }
            }

            if (l1 && l2)
                cur = cur->next;
        }//while

        if (l1){
            if (cur->next)
                l1->val += cur->next->val;
            cur->next = l1;
        }

        if (l2){
            if (cur->next)
                l2->val += cur->next->val;
            cur->next = l2;
        }

        while (cur->next){
            cur = cur->next;
            if (cur->val >= 10){
                cur->val = cur->val % 10;
                if (cur->next)
                    cur->next->val += 1;
                else
                    cur->next = new ListNode(1);
            } else {
                break;
            }
        }
        return root;
    }
};