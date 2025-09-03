#include "minimum_flips_in_binary_tree_to_get_result.h"

#include <algorithm>
#include <functional>
#include <utility>
#include "../../common/trees/treenode.h"

using namespace std;

int minimumFlips(TreeNode* root, bool result) {
    function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* node) -> pair<int, int> {
        if (!node) {
            return {1 << 30, 1 << 30};  // Impossible case
        }
        const int x = node->val;
        if (x >= 0 && x <= 1) {
            return {x == 0 ? 0 : 1, x == 1 ? 0 : 1};
        }

        auto [left_false, left_true] = dfs(node->left);
        auto [right_false, right_true] = dfs(node->right);
        if (x == 2) {  // OR
            return {left_false + right_false, min({left_true + right_true, left_true + right_false,
                                                   left_false + right_true})};
        } else if (x == 3) {  // AND
            return {
                min({left_false + right_false, left_true + right_false, left_false + right_true}),
                left_true + right_true};
        } else if (x == 4) {  // XOR
            return {min({left_false + right_false, left_true + right_true}),
                    min({left_true + right_false, left_false + right_true})};
        } else if (x == 5) {  // NOT
            return {left_true, left_false};
        } else {
            return {1 << 30, 1 << 30};  // Invalid operation
        }
    };
    return result ? dfs(root).second : dfs(root).first;
}