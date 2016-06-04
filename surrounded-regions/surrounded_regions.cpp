#include <iostream>
#include <vector>
using namespace std;

void inspect(vector<vector<char>> &);

class Solution {
  const static char x = 'X';
  const static char o = 'O';
  const static char mark = 'R';
  public:
    void solve(vector<vector<char>>& board) {
      if( board.empty() || board.front().empty() ) return;
      size_t row = board.size(), col = board[0].size();

      for(size_t i = 0; i < col; ++i ) {
        helper( board, 0, i);
        helper( board, row - 1, i);
      }

      for( size_t i = 1; i < row - 1; ++i ) {
        helper(board, i, 0);
        helper(board, i, col -1);
      }

      for( auto & vec : board )
        for( auto & ch : vec )
          if(ch == o) ch = x;
          else if( ch == mark) ch = o;

    }

    void helper(vector<vector<char>>& board, int x, int y) {
      if( board[x][y] == o ) {
        board[x][y] = mark;
        if( x + 1 < (int)board.size() ) helper( board, x+1, y );
        // TODO: x > 0 Runtime Error??
        if( x > 1 ) helper( board, x-1, y );
        if( y + 1 < (int)board.front().size() ) helper( board, x, y+1 );
        if( y > 1 ) helper( board, x, y-1 );
      }
    }
};

void inspect( vector<vector<char>> & board) {
  for( auto & vec : board ) {
    for( auto ch : vec )
      cout<<ch;
    cout<<endl;
  }
}

void WA() {
  vector<vector<char>> board { {'O','X','O'}, {'X','O','X'}, {'O','X','O'}};
  Solution s;
  s.solve(board);
}

int main() {
  WA();
  return 0;
}
