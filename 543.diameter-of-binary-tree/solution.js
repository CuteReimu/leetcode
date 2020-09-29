/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
    return diameterOfBinaryTree2(root)[0];
};

var diameterOfBinaryTree2 = function(root) {
    if (!root)
        return [0, 0];
    var left = diameterOfBinaryTree2(root.left);
    var right = diameterOfBinaryTree2(root.right);
    return [Math.max(left[1] + right[1], Math.max(left[0], right[0])), Math.max(left[1], right[1]) + 1];
};
