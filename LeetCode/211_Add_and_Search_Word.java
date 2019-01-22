class TrieNode {
    Map<Character, TrieNode> children;
    boolean isWord;

    public TrieNode() {
        children = new HashMap<Character, TrieNode>();
        isWord = false;
    }
}


class WordDictionary {

    private TrieNode root_;

    /** Initialize your data structure here. */
    public WordDictionary() {
        root_ = new TrieNode();
    }

    /** Adds a word into the data structure. */
    public void addWord(String word) {

        int length = word.length();
        if (length == 0) {
            return;
        }

        TrieNode curr = root_;

        for (int i = 0 ; i < length ; ++i) {
            char ch = word.charAt(i);

            TrieNode child = curr.children.get(ch);
            if (child == null) {
                child = new TrieNode();
                curr.children.put(ch, child);
            }

            curr = child;
        }

        curr.isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {

        int length = word.length();
        if (length == 0) {
            return false;
        }

        return search(word, 0, length, root_);
    }

    private boolean search(String word, int index, int length, TrieNode curr) {

        if (index == length) {
            return curr.isWord;
        }

        char ch = word.charAt(index);
        if (ch == '.') {
            for (Map.Entry<Character, TrieNode> entry : curr.children.entrySet()) {
                boolean contained = search(word, index + 1, length, entry.getValue());
                if (contained) {
                    return true;
                }
            }

            return false;
        }

        TrieNode child = curr.children.get(ch);
        if (child == null) {
            return false;
        }

        return search(word, index + 1, length, child);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */