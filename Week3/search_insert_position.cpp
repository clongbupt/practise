#include "iostream"

using namespace std;

class Solution{
  public:
    int searchInsert(int A[], int n, int target) {
      int left = 0, right = n - 1;
      int mid;
      while (left <= right) {
        mid = (right - left) / 2 + left;
        if (target == A[mid] ) {
          return mid;
        } else if (target < A[mid]) {
          right = mid - 1;
        } else{
          left = mid + 1;
        }
      }

      if (target < A[mid]) {
        return mid;
      }else {
        return mid + 1;
      }
    }
};

int main(void){
  Solution s = Solution();
  int A[] = {1,2,4};
  cout << s.searchInsert(A, 3, 4) << endl;
  cout << s.searchInsert(A, 3, 0) << endl;
  cout << s.searchInsert(A, 3, 2) << endl;
  cout << s.searchInsert(A, 3, 3) << endl;
}
