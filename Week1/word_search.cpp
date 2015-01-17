class Solution{
public:
  bool exist(vector<vector<char>> & board, string word) {
    int rows = board.size();
    int cols = board[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for(int i = 0; i < rows; i ++ ) {
      for(int j = 0; j < cols; j ++ ) {
        if (board[i][j] == word[0]) {
          visited[i][j] = true;
          if(dfs(i, j, 1, board, rows, cols, word, word.size(), visited)){
            return true;
          }
        }
      }
    }

    return false;
  }

  bool dfs(int x, int y, int step, vector<vector<char>> & board, int rows, int cols, string & word, int len, vector<vector<bool>> & visited) {
    if (step == len) {
      return true;
    }

    int newx, newy;
    int dirx[] = {1,0,-1,0};
    int diry[] = {0,-1,0,1};
    for (int i = 0; i < 4; i ++) {
      newx = x + dirx[i];
      newy = y + diry[i];
      if(newx > 0 && newx < rows && newy > 0 && newy < cols && ! visited[newx][newy]){
        if (board[newx][newy] == word[step]) {
          visited[newx][newy] = true;
          if(dfs(newx, newy, step+1, board, rows, cols, word, len, visited)) {
            return true;
          }
          visited[newx][newy] = false;
        }
      }
    }

    return false;
  }
};
