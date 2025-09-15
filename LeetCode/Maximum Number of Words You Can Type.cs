public class Solution {
    public int CanBeTypedWords(string text, string brokenLetters) {
        string[] words = text.Split(' ');
        int result = words.Length;

        foreach(string word in words){
            foreach(char c in brokenLetters){
                if(word.Contains(c)){
                    result--;
                    break;
                }
            }
        }
        return result;
    }
}
