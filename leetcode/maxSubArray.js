/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let res = nums[0];
    for(let i = 1; i < nums.length; i++) {
        nums[i] += Math.max(nums[i - 1], 0);
        res = Math.max(nums[i], res);
    }
    return res;
};
