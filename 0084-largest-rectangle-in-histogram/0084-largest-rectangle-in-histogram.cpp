class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0); // Sentinel
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxRect = 0;

        for (const auto& row : matrix) {
            for (int i = 0; i < n; ++i) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }
            maxRect = max(maxRect, largestRectangleArea(heights));
        }

        return maxRect;
    }
};
