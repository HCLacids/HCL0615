function missingNumber(nums: number[]): number {
    const set = new Set();
    const n: number = nums.length;
    for (let i = 0; i < n; i++) {
        set.add(nums[i]);
    }
    let missing: number = -1;
    for (let i = 0; i <= n; i++) {
        if (!set.has(i)) {
            missing = i;
            break;
        }
    }
    return missing;
};
