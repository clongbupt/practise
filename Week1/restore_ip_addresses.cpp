class Solution{
  public:
    vector<string> restoreIpAddress(string s){
      vector<string> result;
      string tmp;
      dfs(s, 0, 0, tmp, result);
      return result;
    }

    void dfs(string s, int start, int step, string tmp, vector<string> & result) {
      if ( s.size() == start && step == 4) {
        tmp.resize(tmp.size() - 1);
        result.push_back(tmp);
        return;
      }

      if(s.size() - start > (4 - step) * 3) {
        return;
      }

      if(s.size() - start < (4 - step)) {
        return;
      }

      int num = 0;
      for ( int i = start; i < s.size(); i ++ ) {
        num = num * 10 +  s[i] - '0';
        if ( num > 255) {
          break;
        }
        tmp += s[i];
        dfs(s, i + 1, step + 1, tmp + '.', result);

        if ( num == 0 ) {
          break;
        }
      }
    }
}
