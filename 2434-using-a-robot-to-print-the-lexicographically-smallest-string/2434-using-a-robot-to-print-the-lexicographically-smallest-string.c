char smallest(int* right_freq) {
    for (int i = 0; i < 26; ++i) {
        if (right_freq[i] > 0)
            return 'a' + i;
    }
    return 'z';
}

char* robotWithString(char* s) {
    int n = strlen(s);
    int right_freq[26] = {0};
    for (int i = 0; i < n; ++i)
        right_freq[s[i] - 'a']++;

    char* t = (char*)malloc(n + 1);
    char* res = (char*)malloc(n + 1);
    int t_top = -1, res_top = -1;
    
    for (int i = 0; i < n; ++i) {
        t[++t_top] = s[i];
        right_freq[s[i] - 'a']--;

        while (t_top >= 0 && t[t_top] <= smallest(right_freq)) {
            res[++res_top] = t[t_top--];
        }
    }

    // Empty remaining stack
    while (t_top >= 0) {
        res[++res_top] = t[t_top--];
    }

    res[res_top + 1] = '\0';
    free(t);
    return res;
}
