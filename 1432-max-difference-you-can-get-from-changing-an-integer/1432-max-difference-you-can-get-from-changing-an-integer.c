
int maxDiff(int num) {
    char s[12], max_s[12], min_s[12];
    sprintf(s, "%d", num);
    strcpy(max_s, s);
    strcpy(min_s, s);

    int n = strlen(s);

    // Maximize number: First digit < 9 should be changed to 9
    for (int i = 0; i < n; ++i) {
        if (s[i] != '9') {
            for (int j = 0; j < n; ++j) {
                if (max_s[j] == s[i])
                    max_s[j] = '9';
            }
            break;
        }
    }

    // Minimize number
    if (s[0] > '1') {
        for (int i = 0; i < n; ++i) {
            if (min_s[i] == s[0])
                min_s[i] = '1';
        }
    } else {
        // Find first digit > '1' from index 1
        for (int i = 1; i < n; ++i) {
            if (s[i] > '1') {
                for (int j = 0; j < n; ++j) {
                    if (min_s[j] == s[i])
                        min_s[j] = '0';
                }
                break;
            }
        }
    }

    int max_val = atoi(max_s);
    int min_val = atoi(min_s);
    return max_val - min_val;
}
