/**
 * initialize your data structure here.
 */
var MinStack = function() {
    this.x_stack = [];
    this.min_stack = [Infinity];
};


/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    this.x_stack.push(x);
    this.min_stack.push(Math.min(this.min_stack[this.min_stack.length - 1], x));
};


/**
 * @return {void}
 */

MinStack.prototype.pop = function() {
    this.x_stack.pop();
    this.min_stack.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.x_stack[this.x_stack.length - 1];
};


/**
 * @return {number}
 */
MinStack.prototype.min = function() {
    return this.min_stack[this.min_stack.length - 1];
};

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.min()
 */
