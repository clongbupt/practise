#include "iostream"
using namespace std;

struct ListNode{
  int val;
  ListNode * next;
  ListNode (int x) : val(x), next(NULL) {}
};

class Solution{
public:
  ListNode * insertionSortList(ListNode *head) {

    if (!head) {
      return NULL;
    }
    ListNode * sortedHead,* sortedPrev, * sortedCur, * curr;

    curr = head -> next;

    sortedHead = new ListNode(-1);

    sortedCur = new ListNode(head -> val);
    sortedHead -> next = sortedCur;

    bool flag = false;

    while (curr) {
      sortedPrev = sortedHead;
      sortedCur = sortedHead -> next;
      flag = false;
      while (sortedCur) {
        if (curr -> val >= sortedCur -> val) {
          sortedPrev = sortedCur;
          sortedCur = sortedCur -> next;
        } else {
          sortedPrev -> next = curr;
          curr = curr -> next;
          sortedPrev -> next -> next = sortedCur;
          flag = true;
          break;
        }
      }
      if (!flag) {
        sortedPrev -> next = curr;
        curr = curr -> next;
        sortedPrev -> next -> next = sortedCur;
        flag = false;
      }
    }
    return sortedHead -> next;
  }

  ListNode * createList(int a[], int n){
    ListNode *head, *cur, *tmp;
    head = new ListNode(a[0]);
    cur = head;
    for(int i = 1; i < n; i ++) {
      tmp = new ListNode(a[i]);
      cur -> next = tmp;
      cur = cur -> next;
    }

    return head;
  }

  void printList(ListNode *head) {
    ListNode *cur = head;
    while (cur) {
      cout << cur -> val << " -> ";
      cur = cur -> next;
    }
    cout << "NULL" << endl;
  }

};


int main(void) {

  Solution s = Solution();

  int a[] = {2, 1, 5, 3, 4};
  ListNode * listHead = s.createList(a, 5);

  s.printList(listHead);

  listHead = s.insertionSortList(listHead);

  s.printList(listHead);

}
