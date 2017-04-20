// LeetCode61.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode *res = head;
		ListNode *ret = head;
		int cnt = 0;
		if (head == NULL) return head;
		while (head->next != NULL) {
			cnt++;
			head = head->next;
		}
		cnt++;
		k = k%cnt;
		if (k == 0 || k >= cnt) return res;
		head->next = res;
		for (int i = 1; i <= cnt - k; i++) {
			if (i == cnt - k) {
				head = res->next;
				res->next = NULL;
			}
			res = res->next;
		}
		return head;
	}
};
int main()
{
	ListNode *l1 = new ListNode(1);
	l1->next= new ListNode(2);/*
	l1->next->next= new ListNode(3);
	l1->next->next->next=new ListNode(4);
	l1->next->next->next->next=new ListNode(5);*/
	Solution a;
	l1 = a.rotateRight(l1,1);
	while (l1 != NULL) {
		cout << l1->val;
		l1 = l1->next;
		if (l1 != NULL) cout << "->";
	}
	cout << endl;
    return 0;
}

