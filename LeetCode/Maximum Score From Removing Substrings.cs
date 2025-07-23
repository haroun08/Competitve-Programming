public class Solution {
    public int MaximumGain(string s, int x, int y) {
        int totalPoints = 0;
        if (x > y) {
            // Remove "ab" first (higher points), then "ba"
            totalPoints += RemoveSubstring(ref s, "ab", x);
            totalPoints += RemoveSubstring(ref s, "ba", y);
        } else {
            // Remove "ba" first (higher or equal points), then "ab"
            totalPoints += RemoveSubstring(ref s, "ba", y);
            totalPoints += RemoveSubstring(ref s, "ab", x);
        }
        return totalPoints;
    }
    
    private int RemoveSubstring(ref string inputString, string targetSubstring, int pointsPerRemoval) {
        int totalPoints = 0;
        char[] chars = inputString.ToCharArray();
        int writeIndex = 0;
        
        // Iterate through the string
        for (int readIndex = 0; readIndex < chars.Length; readIndex++) {
            // Add the current character
            chars[writeIndex++] = chars[readIndex];
            
            // Check if we've written at least two characters and
            // they match the target substring
            if (writeIndex > 1 &&
                chars[writeIndex - 2] == targetSubstring[0] &&
                chars[writeIndex - 1] == targetSubstring[1]) {
                writeIndex -= 2;  // Move write index back to remove the match
                totalPoints += pointsPerRemoval;
            }
        }
        
        // Trim the string to remove any leftover characters
        inputString = new string(chars, 0, writeIndex);
        return totalPoints;
    }
}
