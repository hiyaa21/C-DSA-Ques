class Solution {
public:
    bool check(vector<vector<char>>& board, int r, int c, char dig){
        // horizontal
        for(int i=0; i<9; i++){
            if(board[r][i]==dig){
                return false;
            }
        }

        // vertical
        for(int i=0; i<9; i++){
            if(board[i][c]==dig){
                return false;
            }
        }

        // grid
        int sr= (r/3)*3;
        int sc= (c/3)*3;

        for(int i=sr; i<=sr+2; i++){
            for(int j=sc; j<=sc+2; j++){
                if(board[i][j]==dig){
                return false;
                }
            }
        }
        return true;
        
    }

    bool final(vector<vector<char>>& board, int r, int c){
        if(c==9){
            r++;
            c=0;
        }
        // base case 
        if(r==9){
            return true;
        }

        if(board[r][c] != '.'){
            return final(board, r, c+1);
        }

        for(char i='1'; i<= '9'; i++){
            if(check(board, r, c, i)){
                board[r][c]=i;
                // backtracking
                if(final(board,r, c+1))
                  return true; 
                
                board[r][c]='.';
       
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        final(board, 0, 0);
    }
    
};