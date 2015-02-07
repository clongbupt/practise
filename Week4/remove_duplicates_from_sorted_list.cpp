#include "iostream"

using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
  ListNode * deleteDuplicates(ListNode *head){
    if (! head) {
      return NULL;
    }
    ListNode * prev, *cur;
    prev = head;
    cur = head->next;

    while(cur) {
      if (prev->val == cur->val) {
        ListNode * tmp = cur;
        cur = cur->next;
        prev->next = cur;
        delete tmp;
      } else {
        prev = cur;
        cur = cur->next;
      }
    }
    return head;
  }
};

ListNode * createLinkedList (int a[], int n) {
  if (n == 0){
    return NULL;
  }
  ListNode * head = new ListNode(a[0]);
  ListNode * cur = head;
  for (int i =; i < n; i ++) {
    ListNode * tmp = new ListNode(a[i]);
    cur->next = tmp;
    cur = cur->next;
  }

  return head;
  
}

int main(void) {

  Solution s = Solution();

  int a[] = {1,1,2};
  int n = 3;
  ListNode * head = createLinkedList(a, n);

  ListNode * list = s.deleteDuplicates(head);
  while (list) {
    cout << list->val << " ";
    list = list->next;
  }
  cout << endl;

  return 0;
}
