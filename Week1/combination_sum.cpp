class Solution{
public:
    vector<vector<int> > combinationSum(vector<int> & candidates, int target ) {
        vector<vector<int> > result;
        vector<int> tmp;

        std::sort(candidates.begin(), candidates.end());

        dfs(0, target, candidates, tmp, result);

        return result;
    }

    void dfs(int cur, int target, vector<int> & candidates, vector<int> tmp, vector<vector<int> > & result) {
        if(target < 0) {
            return;
        }
        if(target == 0) {
            result.push_back(tmp);
            return;
        }

        for(int i = cur; i < candidates.size(); i ++) {
            tmp.push_back(candidates[i]);
            dfs(i, target - candidates[i], tmp, result);
            tmp.pop_back();
        }
    }
};
