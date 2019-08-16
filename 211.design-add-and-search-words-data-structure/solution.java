class DictionaryChar {
	public final char word;
	public final DictionaryChar[] next = new DictionaryChar[27];
	public DictionaryChar(char word) {
		this.word = word;
	}
}

class WordDictionary {

	/** Initialize your data structure here. */
	public WordDictionary() {
	}

	/** Adds a word into the data structure. */
	public void addWord(String word) {
		int length = word.length();
		DictionaryChar p = head;
		for (int i = 0; i < length; i++) {
			char c = word.charAt(i);
			if (p.next[c - 'a'] == null) {
				p.next[c - 'a'] = new DictionaryChar(c);
			}
			p = p.next[c - 'a'];
		}
		p.next[26] = new DictionaryChar('.');
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	public boolean search(String word) {
		return search(word, 0, head);
	}

	private boolean search(String word, int n, DictionaryChar p) {
		if (n == word.length())
			return p.next[26] != null;
		char c = word.charAt(n);
		if (c == '.') {
			for (int i = 0; i < 26; i++) {
				if (p.next[i] != null && search(word, n + 1, p.next[i])) {
					return true;
				}
			}
			return false;
		}
		if (p.next[c - 'a'] == null)
			return false;
		return search(word, n + 1, p.next[c - 'a']);
	}

	private DictionaryChar head = new DictionaryChar('.');

}


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
