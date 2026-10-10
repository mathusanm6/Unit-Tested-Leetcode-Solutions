#include "minimum_flips_in_binary_tree_to_get_result.h"

#include <algorithm>
#include <functional>
#include <utility>
#include "../../common/trees/treenode.h"

using namespace std;

int minimumFlips(TreeNode* root, bool result) {
    constexpr int Infinity = 1U << 30U;
    function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* node) -> pair<int, int> {
        if (node == nullptr) {
            return {Infinity, Infinity};  // Impossible case
        }
        const int x = node->val;
        if (x >= 0 && x <= 1) {
            return {x == 0 ? 0 : 1, x == 1 ? 0 : 1};
        }

        auto [leftFalse, leftTrue] = dfs(node->left);
        auto [rightFalse, rightTrue] = dfs(node->right);
        if (x == 2) {  // OR
            return {leftFalse + rightFalse,
                    min({leftTrue + rightTrue, leftTrue + rightFalse, leftFalse + rightTrue})};
        } else if (x == 3) {  // AND
            return {min({leftFalse + rightFalse, leftTrue + rightFalse, leftFalse + rightTrue}),
                    leftTrue + rightTrue};
        } else if (x == 4) {  // XOR
            return {min({leftFalse + rightFalse, leftTrue + rightTrue}),
                    min({leftTrue + rightFalse, leftFalse + rightTrue})};
        } else if (x == 5) {  // NOT
            if (node->left != nullptr && node->right == nullptr) {
                return {leftTrue, leftFalse};
            } else if (node->left == nullptr && node->right != nullptr) {
                return {rightTrue, rightFalse};
            } else {
                return {Infinity, Infinity};  // Invalid operation
            }
        } else {
            return {Infinity, Infinity};  // Invalid operation
        }
    };
    return result ? dfs(root).second : dfs(root).first;
}