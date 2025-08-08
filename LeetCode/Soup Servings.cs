public class Solution
{
    public double SoupServings(int n)
    {
        if(n>4800)
        {
            return 1;
        }
        n = n/25 + Math.Min(1,n%25);
        var dp = new double[n+1][];
        for(int i = 0; i<=n; i++)
        {
            dp[i] = new double[n+1];
        }
        dp[0][0] = 1.0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                double curr = dp[i][j]*0.25;
                if(curr == 0)
                {
                    continue;
                }
                dp[Math.Min(i+4,n)][j] += curr;
                dp[Math.Min(i+3,n)][Math.Min(j+1,n)] += curr;
                dp[Math.Min(i+2,n)][Math.Min(j+2,n)] += curr;
                dp[Math.Min(i+1,n)][Math.Min(j+3,n)] += curr;
            }
        }
        double sum = dp[n][n]*0.5;
        for(int j = 0; j<n; j++)
        {
            sum += dp[n][j];
        }
        return sum;
    }
}
