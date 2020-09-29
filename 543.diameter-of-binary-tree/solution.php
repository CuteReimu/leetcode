/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($value) { $this->val = $value; }
 * }
 */
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function diameterOfBinaryTree($root) {
        return $this->diameterOfBinaryTree2($root)[0];
    }


    function diameterOfBinaryTree2($root) {
        if (!$root)
            return [0, 0];
        $left = $this->diameterOfBinaryTree2($root->left);
        $right = $this->diameterOfBinaryTree2($root->right);
        return [max($left[1] + $right[1], $left[0], $right[0]), max($left[1], $right[1]) + 1];
    }
}
