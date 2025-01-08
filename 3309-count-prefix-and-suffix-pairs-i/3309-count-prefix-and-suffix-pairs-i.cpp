// class Solution {
// public:
//     int countPrefixSuffixPairs(vector<string>& words) {
//         int n = words.size();
//         int count = 0;

//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 string& str1 = words[i];
//                 string& str2 = words[j];
//                 if (str1.size() > str2.size()) continue;

//                 if (str2.find(str1) == 0 &&
//                     str2.rfind(str1) == str2.size() - str1.size()) {
//                     ++count;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Node {
public:
    Node* links[26] = {};

    // Check if the character is present in the current node
    bool contains(char c) { return links[c - 'a'] != NULL; }

    // Insert a new node for the character
    void put(char c, Node* node) { links[c - 'a'] = node; }

    // Get the next node for the character
    Node* next(char c) { return links[c - 'a']; }
};

class Trie {
public:
    Node* root;

    Trie() { root = new Node(); }
    void insert(string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->contains(c)) {
                node->put(c, new Node());
            }
            node = node->next(c);
        }
    }

    bool startsWith(string& prefix) {
        Node* node = root;
        for (char c : prefix) {
            if (!node->contains(c)) {
                return false;
            }
            node = node->next(c);
        }
        return true;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            Trie prefixTrie, suffixTrie;

            prefixTrie.insert(words[i]);

            string revWord = words[i];
            reverse(revWord.begin(), revWord.end());
            suffixTrie.insert(revWord);

            for (int j = 0; j < i; j++) {
                if (words[j].size() > words[i].size()) continue;

                string prefixWord = words[j];
                string revPrefixWord = prefixWord;
                reverse(revPrefixWord.begin(), revPrefixWord.end());

                if (prefixTrie.startsWith(prefixWord) &&
                    suffixTrie.startsWith(revPrefixWord)) {
                    count++;
                }
            }
        }

        return count;
    }
};