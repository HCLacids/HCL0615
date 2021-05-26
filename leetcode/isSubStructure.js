/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} A
 * @param {TreeNode} B
 * @return {boolean}
 */

let preVisited = (A, B) => {
    if(B === null) return true;
    if(A === null || A.val !== B.val) return false;
    return preVisited(A.left, B.left) && preVisited(A.right, B.right);
}


var isSubStructure = function(A, B) {
    return (B !== null && A !== null) && (preVisited(A,B) || isSubStructure(A.left, B) ||isSubStructure(A.right, B)) 
};
