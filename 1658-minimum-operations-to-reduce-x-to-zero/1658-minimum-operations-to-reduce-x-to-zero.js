/**
 * @param {number[]} nums
 * @param {number} x
 * @return {number}
 */
var minOperations = function(nums, x) {
    let target = -x;
    target = nums.reduce((tot, cur) => tot+cur, target);
    if (target == 0) return nums.length;
    if (target < 0) return -1;

    let map = new Map();
    map.set(0, -1);
    let sum = 0, res = Number.MIN_SAFE_INTEGER;
    
    for (let i = 0; i < nums.length; i++){
        sum += nums[i];
        if (map.has(sum - target)){
            res = Math.max(res, i - map.get(sum - target));
        }

        map.set(sum, i);
    }

    return res === Number.MIN_SAFE_INTEGER ? -1 : nums.length - res;
};