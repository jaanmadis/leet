/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const map = {};
    for(let i = 0; i < nums.length; i++) {
        map[nums[i]] = i;
    }
    for(let i = 0; i < nums.length; i++) {
        const lookFor = target - nums[i];
        if (map[lookFor] !== undefined && map[lookFor] !== i) {
            return [i, map[lookFor]]
        }
    }
};