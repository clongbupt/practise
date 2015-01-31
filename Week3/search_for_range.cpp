#include "iostream"
#include "vector"

using namespace std;

class Solution {
  public:
    vector<int> searchRange(int A[], int n, int target) {

      vector<int> res(2, -1);
      
      if (target < A[0] || target > A[n - 1]) {
        return res;
      }

      int left = 0, right = n;
      int mid;
      while (left < right) {
        mid = (right - left) / 2 + left;
        if (target <= A[mid]) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      if (A[left] == target) {
        res[0] = left;
      }

      left = 0;
      right = n;
      while(left < right) {
        mid = (right - left) / 2 + left;
        if (target >= A[mid]) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      if (A[left - 1] == target) {
        res[1] = left - 1;
      }

      return res;
    }
};

int main(void) {
  Solution s = Solution();


  int test[] = {0,1,1,1};

  cout << s.searchRange(test, 4, 1)[0] << " ";
  cout << s.searchRange(test, 4, 1)[1] << endl;
  
}
