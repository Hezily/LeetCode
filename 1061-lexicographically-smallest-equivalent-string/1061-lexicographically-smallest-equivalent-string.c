int find(int* dsuf, int v) {
    if (dsuf[v] == -1)
        return v;
    return dsuf[v] = find(dsuf, dsuf[v]);
}

char* smallestEquivalentString(char* s1, char* s2, char* baseStr) {
    int dsuf[26];
    for (int i = 0; i < 26; i++)
        dsuf[i] = -1;

    // Step 1: Union the characters
    int len = strlen(s1);
    for (int i = 0; i < len; i++) {
        int px = find(dsuf, s1[i] - 'a');
        int py = find(dsuf, s2[i] - 'a');

        if (px == py)
            continue;

        // Union by keeping the smaller char as root
        if (px < py)
            dsuf[py] = px;
        else
            dsuf[px] = py;
    }

    // Step 2: Build the result string
    int baseLen = strlen(baseStr);
    char* res = (char*)malloc(sizeof(char) * (baseLen + 1));
    for (int i = 0; i < baseLen; i++) {
        int parent = find(dsuf, baseStr[i] - 'a');
        res[i] = 'a' + parent;
    }
    res[baseLen] = '\0';
    return res;
}
