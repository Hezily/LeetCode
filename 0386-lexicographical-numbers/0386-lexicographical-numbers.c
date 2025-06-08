/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct TrieNode {
    int we;
    int digit;
    struct TrieNode* child[10];
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->we = 0;
    node->digit = 0;
    for (int i = 0; i < 10; ++i)
        node->child[i] = NULL;
    return node;
}

void trie_insert(TrieNode* root, int n) {
    char s[12];
    sprintf(s, "%d", n);
    TrieNode* curr = root;
    for (int i = 0; s[i]; ++i) {
        int idx = s[i] - '0';
        if (!curr->child[idx])
            curr->child[idx] = createNode();
        curr = curr->child[idx];
        curr->digit = idx;
    }
    curr->we++;
}

void trie_search(TrieNode* curr, int* ans, int* size, int number) {
    if (!curr) return;
    if (curr->we)
        ans[(*size)++] = number;
    
    for (int i = 0; i < 10; ++i) {
        if (curr->child[i]) {
            trie_search(curr->child[i], ans, size, number * 10 + i);
        }
    }
}

int* lexicalOrder(int n, int* returnSize) {
    TrieNode* root = createNode();
    for (int i = 1; i <= n; ++i)
        trie_insert(root, i);

    int* ans = (int*)malloc(n * sizeof(int));
    *returnSize = 0;
    trie_search(root, ans, returnSize, 0);
    return ans;
}
