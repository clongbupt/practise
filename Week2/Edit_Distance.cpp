#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution{
public:
  int minDistance(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();

    vector<vector<int> > f(n1 + 1, vector<int>(n2 + 1, 0));

    for(int i = 1; i <= n1; i ++) {
      f[i][0] = i;
    }

    for(int j = 1; j <= n2; j ++) {
      f[0][j] = j;
    }

    for(int i = 1; i <= n1; i ++) {
      for (int j = 1; j <= n2; j ++) {
        if (word1[i - 1] != word2[j - 1]) {
          f[i][j] = minimal(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1;
        } else {
          f[i][j] = f[i - 1][j - 1];
        }
      }
    }

    return f[n1][n2];
  }

  int minimal(int a, int b, int c) {
    if(a > b) {
      if(b > c) {
        return c;
      } else {
        return b;
      }
    }
    else{
      if (a > c) {
        return c;
      } else {
        return a;
      }
    }
  }

};

int main(void){
  Solution s = Solution();
  cout << s.minDistance("a", "b") << endl;
  return 0;
}
