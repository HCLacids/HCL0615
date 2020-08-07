var removeDuplicates = function(nums) {
    nums = [...new Set(nums)];
    return nums.length
}; removeDuplicates([1,1,2])
