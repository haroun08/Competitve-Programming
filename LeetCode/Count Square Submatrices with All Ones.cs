public class Solution {
    public int CountSquares(int[][] matrix) {
        int row = matrix.Length;
        int col = matrix[0].Length;
        int[,] dp = new int[row + 1, col + 1];
        int result = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1) {
                    dp[i + 1, j + 1] = Math.Min(
                        Math.Min(dp[i, j + 1], dp[i + 1, j]),
                        dp[i, j]
                    ) + 1;

                    result += dp[i + 1, j + 1];
                }
            }
        }

        return result;
    }
}
