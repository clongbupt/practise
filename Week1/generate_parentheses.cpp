class Solution{
  public:
    vector<string> generateParenthesis(int n) {
      vector<string> result;
      dfs(n, n, "", result);
      return result;
    }

    void dfs(int left, int right, string & tmp, vector<string> & result) {
      if(left == 0 && right == 0) {
        result.push_back(tmp);
        return;
      }
      if(left > 0) {
        tmp += "(";
        dfs(left-1, right, tmp, result);
        tmp.pop_back();
      } else if (right > 0 && right > left){
        tmp += ")";
        dfs(left, right-1, tmp, result);
        tmp.pop_back();
      }
      return;
    }
};
