public class Solution
{
    private readonly HashSet<char> vowels = new HashSet<char> { 'a', 'e', 'i', 'o', 'u' };
    private HashSet<string> wordsPerfect;
    private Dictionary<string, string> wordsCap;
    private Dictionary<string, string> wordsVow;
    
    public string[] Spellchecker(string[] wordlist, string[] queries)
    {
        InitializeDictionaries(wordlist.Length);
        BuildWordMaps(wordlist);
        return ProcessQueries(queries);
    }
    
    private void InitializeDictionaries(int capacity)
    {
        wordsPerfect = new HashSet<string>(capacity);
        wordsCap = new Dictionary<string, string>(capacity);
        wordsVow = new Dictionary<string, string>(capacity);
    }
    
    private void BuildWordMaps(string[] wordlist)
    {
        foreach (string word in wordlist)
        {
            wordsPerfect.Add(word);
            
            string wordLow = word.ToLowerInvariant();
            wordsCap.TryAdd(wordLow, word);
            
            string wordLowDevoweled = Devowel(wordLow);
            wordsVow.TryAdd(wordLowDevoweled, word);
        }
    }
    
    private string[] ProcessQueries(string[] queries)
    {
        string[] results = new string[queries.Length];
        for (int i = 0; i < queries.Length; i++)
        {
            results[i] = Solve(queries[i]);
        }
        return results;
    }
    
    private string Solve(string query)
    {
        // Check exact match first
        if (wordsPerfect.Contains(query))
            return query;
        
        // Check case-insensitive match
        string queryLower = query.ToLowerInvariant();
        if (wordsCap.TryGetValue(queryLower, out string caseMatch))
            return caseMatch;
        
        // Check vowel-error match
        string queryDevoweled = Devowel(queryLower);
        if (wordsVow.TryGetValue(queryDevoweled, out string vowelMatch))
            return vowelMatch;
        
        return "";
    }
    
    private string Devowel(string word)
    {
        if (string.IsNullOrEmpty(word))
            return word;
            
        Span<char> buffer = stackalloc char[word.Length];
        for (int i = 0; i < word.Length; i++)
        {
            buffer[i] = vowels.Contains(word[i]) ? '*' : word[i];
        }
        return new string(buffer);
    }
}
