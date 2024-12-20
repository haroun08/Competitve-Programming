class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();

        vector<vector<int>> height(m, vector<int>(n, 0));
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    height[i][j] = 0;
                } else {
                    height[i][j] = (i == 0) ? 1 : height[i - 1][j] + 1;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            int area = maxAreaInHist(height[i]);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

private:
    int maxAreaInHist(vector<int>& height) {
        stack<int> s;
        int maxArea = 0;
        int i = 0;
        int n = height.size();

        while (i < n) {
            if (s.empty() || height[s.top()] <= height[i]) {
                s.push(i++);
            } else {
                int top = s.top();
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height[top] * width);
            }
        }

        while (!s.empty()) {
            int top = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height[top] * width);
        }

        return maxArea;
    }
};
