bool isSubsequence(string s, string t) {
    int current = 0;
    int found = 0;
    for(char c : t) {
        if(s[current] == c) {
            current++;
            found++;
        }
    }
    return found == s.size();
}
