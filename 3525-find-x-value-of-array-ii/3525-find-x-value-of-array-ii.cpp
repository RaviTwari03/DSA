class Solution {
public:
    struct Node {
        int prod;
        long long cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int k;
    int size;
    vector<Node> tree;

    Node mergeNode(const Node &L, const Node &R) {
        Node res;

        res.prod = (L.prod * R.prod) % k;

        // Prefixes completely inside left
        for (int r = 0; r < k; r++) {
            res.cnt[r] += L.cnt[r];
        }

        // Prefixes that continue from left into right
        for (int r = 0; r < k; r++) {
            int rem = (L.prod * r) % k;
            res.cnt[rem] += R.cnt[r];
        }

        return res;
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->k = k;

        int n = nums.size();

        // Iterative segment tree
        size = 1;
        while (size < n)
            size *= 2;

        tree.assign(2 * size, Node());

        // Build leaves
        for (int i = 0; i < n; i++) {
            int x = nums[i] % k;

            tree[size + i].prod = x;
            tree[size + i].cnt[x] = 1;
        }

        // Build tree
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = mergeNode(tree[2 * i], tree[2 * i + 1]);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update
            nums[index] = value;

            int pos = size + index;
            int rem = value % k;

            tree[pos] = Node();
            tree[pos].prod = rem;
            tree[pos].cnt[rem] = 1;

            pos /= 2;

            while (pos >= 1) {
                tree[pos] = mergeNode(tree[2 * pos], tree[2 * pos + 1]);
                pos /= 2;
            }

            // Query [start, n)
            int l = size + start;
            int r = size + n;

            Node leftRes;
            Node rightRes;

            while (l < r) {

                if (l & 1) {
                    leftRes = mergeNode(leftRes, tree[l]);
                    l++;
                }

                if (r & 1) {
                    --r;
                    rightRes = mergeNode(tree[r], rightRes);
                }

                l /= 2;
                r /= 2;
            }

            Node res = mergeNode(leftRes, rightRes);

            ans.push_back((int)res.cnt[x]);
        }

        return ans;
    }
};