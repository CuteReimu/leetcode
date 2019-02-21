/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (nullptr == node) return nullptr;
		auto it = cache.find(node);
		if (it != cache.end()) return it->second;
		UndirectedGraphNode *curNode = new UndirectedGraphNode(node->label);
		cache.emplace(node, curNode);
		for (UndirectedGraphNode *p : node->neighbors) {
			curNode->neighbors.push_back(cloneGraph(p));
		}
		return curNode;
	}
private:
	unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> cache;
};
