/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
// var buildTree = function(preorder, inorder) {
//     if(!preorder.length) return null;
//     let head = new TreeNode(preorder[0]);

//     let index = inorder.indexOf(head.val);
//     head.left = buildTree(preorder.slice(1, index + 1),inorder.slice(0, index));
//     head.right = buildTree(preorder.slice(index + 1), inorder.slice(index + 1));
//     return head;
// };

var buildTree = function(preorder, inorder){
    if(!preorder.length) return null;
    let head = new TreeNode(preorder[0]);
    let stack = [head];
    let index = 0;

    for(let a = 1; a < preorder.length; a++) {
        let node = stack[stack.length - 1];
        if(node.val !== inorder[index]){
            node.left = new TreeNode(preorder[a]);
            stack.push(node.left);
        } else {
            while(stack.length !== 0 && stack[stack.length - 1].val === inorder[index]){
                node = stack.pop();
                index++;
            }
            node.right = new TreeNode(preorder[a]);
            stack.push(node.right);
        }
    }
    return head;
}
