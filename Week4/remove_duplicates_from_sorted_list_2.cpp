class Solution{
  public:
    ListNode * deleteDuplicates(ListNode * head){
      if (!head) {
        return NULL;
      }

      ListNode *prev_head, *prev_left, *left, *prev_right, *right;
      
      prev_head = new ListNode(0);
      prev_head->next = head;

      bool flag;
      prev_left = prev_head;
      left = prev_right = head;
      right = head->next;
      while (right || (left != prev_right && left->val == prev_right->val)) {
        if ((!right && left != prev_right && left->val == prev_right->val) || left->val != right->val) {
          while (left != prev_right) {
            ListNode * tmp;
            tmp = left;
            left = left->next;
            prev_left->next = left;
            delete tmp;
            flag = true;
          }
          if (flag) {
            ListNode * tmp;
            tmp = left;
            left = left->next;
            prev_left->next = left;
            delete tmp;
            flag = false;
          }
          else {
            prev_left = left;
            left = left->next;
          }
        }
        prev_right = right;
        if (right) {
          right = right->next;
        }
      }
      return prev_head->next;
    }
};
