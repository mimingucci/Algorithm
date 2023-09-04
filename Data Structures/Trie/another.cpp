class TrieNode {

    public:
        TrieNode * children[26];
        // A flag that marks if the word ends on this particular node.
        bool end_of_word;
        // Character stored in this node
        char letter;
        TrieNode() {
            end_of_word = false;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            letter = '\0';
        }
};

class Trie {

    public:

    TrieNode root;

    // Insert the word in the trie.
    // Check each character in the string 
    // If none of the children of the current node contains the character, 
    // create a new child of the current node for storing the character. */
    void Insert (string str) {
        TrieNode * current = &root;
        for (size_t i = 0; i < str.size(); i++) {
            if (current->children[str.at(i)-'a'] == NULL) {
                current->children[str.at(i)-'a'] = new TrieNode;
                current->children[str.at(i)-'a']->letter = str.at(i);
            }
            current = current->children[str.at(i)-'a'];
        }
        current->end_of_word = true;
    }

    // Search the word in trie
    TrieNode * Search (string str) {
        TrieNode * current = &root;
        for (size_t i = 0; i < str.size(); i++) {
            if (current->children[str.at(i)-'a']) {
                current = current->children[str.at(i)-'a'];
             } else {
                current = NULL;
                break;
             }
        }
        return current;
    }

    // Print the words with the specified prefix in lexical order
    void PrintLexical (TrieNode * current, string prefix, string suffix) {
        if (current->end_of_word and suffix.size() != 0) {
            cout << prefix+suffix << endl;
        }
        for (int i=0; i<26; i++) {
            string temp = suffix;
            if (current->children[i]) {
                temp += current->children[i]->letter;
                PrintLexical(current->children[i], prefix, temp);
            }
        }
    }
};

//count number of diff strings
class TrieNode {

    public:

    TrieNode * children[26];

    TrieNode() {
        for (int i=0; i<26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {

    public:

    TrieNode root;
    int node_count;

    Trie () {
        // Track the number of nodes in the trie.
        node_count = 0;
    }

    // Insert a string into the trie.
    void Insert(string str) {

        TrieNode * parent = &root;

        for (size_t i=0; i<str.size(); i++) {
            int N = str.at(i)-97;
            if (parent->children[N] == NULL) {
                parent->children[N] = new TrieNode;
                node_count++;
            }
            parent = parent->children[N];
        }
    }
};