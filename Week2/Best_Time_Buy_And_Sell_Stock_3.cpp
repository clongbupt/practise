class Solution {
public:
  int maxProfit(vector<int> & prices) {
    int len = prices.size();

    if(len < 2) {
      return 0;
    }

    vector<int> left(len, 0);
    vector<int> right(len, 0);

    int min = prices[0];
    for(int i = 1; i < len; i ++) {
      min = prices[i] < min ? prices[i] : min;
      left[i] = (prices[i] - min) > left[i - 1] ? (prices[i] - min) : left[i - 1];
    }

    int max = prices[len - 1];
    for(int i = len - 2; i >= 0; i --) {
      max = prices[i] > max ? prices[i] : max;
      right[i] = (max - prices[i]) > right[i + 1] ? (max - prices[i]) : right[i + 1];
    }

    int res = right[0];
    for(int i = 1; i < len - 1; i ++) {
      if (res < (left[i] + right[i])){
        res = left[i] + right[i];
      }
    }
    if (res < left[len - 1]) {
      res = left[len - 1];
    }

    return res;
  }
};
