#define  _CRT_SECURE_NO_WARNINGS 1

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> ArrayList;
		stack<int> cur;
		ListNode* tmp = head;
		while (tmp != NULL)
		{
			cur.push(tmp->val);
			tmp = tmp->next;
		}
		int size = cur.size();
		for (int i = 0; i<size; i++)
		{
			ArrayList.push_back(cur.top());
			cur.pop();
		}

		return ArrayList;
	}
};