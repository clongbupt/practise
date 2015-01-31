#include "iostream"

using namespace std;

class Solution{
  public:
    int search(int A[], int n, int target) {
      int left = 0, right = n - 1;
      int mid;
      while(left <= right) {
        mid = (right - left) / 2 + left;
        if(target == A[mid]) {
          return mid;
        } else if (A[mid] >= A[left]) {
          if (target < A[mid] && target >= A[left]) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        } else {
          if (target > A[mid] && target <= A[right]) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
      }

      return -1;
    }

};

int main(void) {
  Solution s = Solution();
  int A[] = {3,1};

  cout << s.search(A, 2, 3) << endl;
}
