class Solution {
public:
    bool issafe(int col,vector<string> ans, int n, int row){
        for(int j=0; j<n; j++ ){
            if(ans[row][j] == 'Q'){
                return false;
            }
        }

        for(int j=0; j<n; j++ ){
            if(ans[j][col]== 'Q'){
                return false;
            }
        }
            
        for(int i=row, k= col; i>=0  && k>=0; i--, k--){
            if(ans[i][k] == 'Q'){
            return false;
            }
        }

        for(int i=row, k= col; i>=0  && k<n; i--, k++){
            if(ans[i][k] == 'Q'){
            return false;
            }
        }

        return true;
    }

    void func(vector<string>& ans ,vector<vector<string>>& final, int row, int n ){
        if(row==n){
            final.push_back({ans});
            return;
        }

        for(int i=0; i<n; i++){
            if(issafe(i, ans, n, row)){
                ans[row][i]= 'Q';
                func(ans, final, row+1 , n);
                // Queen is removed from there during backtracking
                ans[row][i]= '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>ans(n, string(n,'.'));
        vector<vector<string>>final;
        
        func(ans,final,0, n);
        return final;
    }
};