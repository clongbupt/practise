#include "iostream"

using namespace std;

class Solution{
  public:
    int sqrt(int x) {
      if (x == 0) {
        return 0; 
      }
      int start = 0, end = x;
      long long mid;
      while (start <= end) {
        mid = (end - start) / 2 + start;
        if (mid * mid <= x && (mid + 1) * (mid + 1) > x) {
          return mid;
        } else if (mid * mid < x){
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }

      return mid;
    }
};

int main(void) {
  Solution s = Solution();
  cout << s.sqrt(2) << endl;
  cout << s.sqrt(25) << endl;
  cout << s.sqrt(2147483647) << endl;

  return 0;
}
