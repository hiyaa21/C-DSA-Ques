class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        stack <int> s;
        vector<int> right(n,0);
        vector<int> left(n,0);

        // right greatest 
        for(int i=n-1; i>=0; i-- ){
            while(!s.empty() && heights[s.top()]>=heights[i] ){
                s.pop();
            }
            right[i] = s.empty() ? n: s.top();
            // using n becoz of formula
            s.push(i);
            
        }

        while(!s.empty()) s.pop();  // Clear the stack


        // left greatest
        for(int i=0; i<n; i++ ){
            while(!s.empty() && heights[s.top()]>=heights[i] ){
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
            
        }

        int area = 0;

        for(int i=0; i<heights.size(); i++){
            int width= right[i]- left[i]- 1;
            int currentarea= heights[i]* width;
            area= max(area, currentarea);
        }

        return area;

    }
};