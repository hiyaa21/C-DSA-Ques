class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m= matrix.size(), n= matrix[0].size();
        int sr=0, sc=0, er= m-1, ec= n-1;
        vector<int>ans;

        while(sr<=er && sc<=ec){

            // Top
            for(int i=sc; i<=ec; i++){
                ans.push_back(matrix[sr][i]);
            }

            // right
            for(int i=sr+1; i<=er; i++){
                ans.push_back(matrix[i][ec]);
            }

            // bottom
            for(int i=ec-1; i>=sc; i--){
                if(sr==er){
                    break;
                }
                ans.push_back(matrix[er][i]);
            }

            // left
            for(int i=er-1; i>=sr+1; i--){
                if(sc==ec){
                    break;
                }
                ans.push_back(matrix[i][sc]);
            }

            sc++; sr++; ec--; er--;

        }
        return ans;
    }
};