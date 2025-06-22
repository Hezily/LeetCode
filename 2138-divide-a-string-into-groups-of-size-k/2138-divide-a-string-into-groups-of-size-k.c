/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** divideString(char* s, int k, char fill, int* returnSize) {
    int n = strlen(s);
    // Calculate the number of groups needed
    *returnSize = (n + k - 1) / k;

    // Allocate memory for the array of strings (groups)
    char** result = (char**)malloc((*returnSize) * sizeof(char*));

    for (int i = 0; i < *returnSize; i++) {
        result[i] = (char*)malloc((k + 1) * sizeof(char)); // +1 for '\0'

        for (int j = 0; j < k; j++) {
            int index = i * k + j;
            if (index < n) {
                result[i][j] = s[index];
            } else {
                result[i][j] = fill;
            }
        }
        result[i][k] = '\0'; // Null-terminate each string
    }

    return result;
}
