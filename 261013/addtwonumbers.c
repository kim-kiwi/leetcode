struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* ans = calloc(1,sizeof(struct ListNode));
	struct ListNode* next = ans;
	int foo = 0;
	for (;;) {
		int val1 = l1 ? l1->val : 0;
		int val2 = l2 ? l2->val : 0;
		next->val = (val1 + val2 + foo)%10;
		foo = (val1 + val2 + foo)/10;
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
		if (!l1 && !l2 && foo==0) break;
		next->next = calloc(1,sizeof(struct ListNode));
		next = next->next;
	}
	return ans;
}
