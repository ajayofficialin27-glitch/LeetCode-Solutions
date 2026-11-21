class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> last(26, -1);

        function<void(int, int)> dfs = [&](int node, int prev) {
            int ch = s[node] - 'a';

            int old = last[ch];

            newParent[node] = (old == -1) ? prev : old;

            last[ch] = node;

            for (int child : tree[node]) {
                dfs(child, node);
            }

            last[ch] = old;
        };

        dfs(0, -1);

        vector<vector<int>> newTree(n);

        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        vector<int> answer(n, 0);

        function<int(int)> calculateSize = [&](int node) {
            int size = 1;

            for (int child : newTree[node]) {
                size += calculateSize(child);
            }

            answer[node] = size;

            return size;
        };

        calculateSize(0);

        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna