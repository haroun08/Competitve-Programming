public class Solution {
    public int CountDays(int days, int[][] meetings) {
        int result = 0;
        int lastEnd = 0;
        var sortedMeetings = meetings.OrderBy(m => m[0]).ThenBy(m => m[1]).ToArray();
        foreach (var meeting in sortedMeetings) {
            int start = meeting[0];
            int end = meeting[1];
            if (start > lastEnd + 1) {
                result += start - (lastEnd + 1);
            }
            lastEnd = System.Math.Max(lastEnd, end);
        }
        result += days - lastEnd;
        return result;
    }
}
