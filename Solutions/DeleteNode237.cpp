#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


void deleteNode(ListNode* node) {
    if (node == nullptr) return;
    node->val = node->next->val;
    ListNode* old = node->next;
    node->next = old->next;
    delete old;
}


