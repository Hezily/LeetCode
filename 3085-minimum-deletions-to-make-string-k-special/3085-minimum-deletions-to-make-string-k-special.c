int minimumDeletions(char* word, int k) {
    int freq[26] = {0};
    int n = strlen(word);
    
    // Count frequency of each character
    for (int i = 0; i < n; i++) {
        freq[word[i] - 'a']++;
    }

    int ans = n;

    // Try each non-zero frequency as the base frequency
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) continue;
        int f1 = freq[i];
        int del = 0;

        for (int j = 0; j < 26; j++) {
            if (freq[j] == 0) continue;
            int f2 = freq[j];
            int diff = f2 - f1;

            if (f1 > f2) {
                del += f2;
            } else if (diff > k) {
                del += (f2 - f1 - k);
            }
        }
        if (del < ans) {
            ans = del;
        }
    }

    return ans;
}
