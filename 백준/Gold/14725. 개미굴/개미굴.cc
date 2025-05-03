#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct Node {
	map<string, Node*> children;
};
void dfs(Node* node, int level) {
	for (auto child : node->children) {
		for (int i = 0; i < level; i++) cout << "--";
		cout << child.first << '\n';
		dfs(child.second, level + 1);
	}
}
int main() {
	FASTIO;
	int n;
	cin >> n;
	Node* root = new Node();

	while (n--) {
		int k;
		cin >> k;
		vector<string> arr(k);

		for (int i = 0; i < k; i++) cin >> arr[i];
		Node* tmp = root;
		for (const auto& str : arr) {
			if (tmp->children.count(str) == 0)
				tmp->children[str] = new Node();
			tmp = tmp->children[str];
		}
	}
	dfs(root, 0);
}