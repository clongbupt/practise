class Solution{
public:
  bool hasCycle(ListNode *head){
    if (!head) {
      return false;
    }

    ListNode * slow, * fast;
    
    slow = head;
    fast = head->next;

    while(fast && slow != fast) {
      slow = slow -> next;
      fast = fast -> next;
      if (!fast){
        return false;
      }
      fast = fast -> next;
    }

    if (slow == fast) {
      return true;
    }
    else {
      return false;
    }
  }
};
