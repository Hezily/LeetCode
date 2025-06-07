char* clearStars(char* s) {
    int len = strlen(s);
    
    // Array of positions for each character (0-25)
    int* char_pos[26];
    int char_size[26] = {0};

    for (int i = 0; i < 26; ++i)
        char_pos[i] = (int*)malloc(len * sizeof(int));
    
    // Process the string
    for (int i = 0; i < len; ++i) {
        if (s[i] == '*') {
            for (int j = 0; j < 26; ++j) {
                if (char_size[j] > 0) {
                    s[char_pos[j][char_size[j] - 1]] = '*';
                    char_size[j]--;
                    break;
                }
            }
        } else {
            int idx = s[i] - 'a';
            char_pos[idx][char_size[idx]++] = i;
        }
    }

    // Build the result string
    char* res = (char*)malloc((len + 1) * sizeof(char));
    int k = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] != '*') {
            res[k++] = s[i];
        }
    }
    res[k] = '\0';

    for (int i = 0; i < 26; ++i)
        free(char_pos[i]);

    return res;
}
