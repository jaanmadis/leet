var numberOfArithmeticSlices = function (nums) {
  let result = 0;
  const dp = new Array(nums.length).fill(0);
  for (let i = 2; i < nums.length; i++) {
    if (nums[i] - nums[i - 1] === nums[i - 1] - nums[i - 2]) {
      dp[i] = dp[i - 1] + 1;
      result += dp[i];
    }
  }
  return result;
};

console.log(numberOfArithmeticSlices([1, 2, 3, 4]));
console.log(numberOfArithmeticSlices([1, 3, 5, 7, 9]));
console.log(numberOfArithmeticSlices([7, 7, 7, 7]));
console.log(
  numberOfArithmeticSlices([
    1, 2, 3, 4, 1, 3, 5, 7, 9, 3, -1, -5, -9, 7, 7, 7, 7,
  ])
);
