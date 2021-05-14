/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    for(let a = 0; a < nums.length ; a++){
        for(let b = a + 1; b < nums.length ; b++){
            if(nums[a] === nums[b]) return nums[a];
        }
    }
};
