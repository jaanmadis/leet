var lengthOfLIS = function (nums) {
  /**
   * Element dp[n] is size of the longest increasing subsequence nums[n] can have.
   *
   * For each number in nums, if any numbers on my left are smaller than me,
   * then I can have their longest increasing subsequence + 1 (myself).
   *
   * For example:
   * nums = [30, 40, 50, ...]
   * dp = [1, 2, 3, ...]
   *
   * If next element after 50 is 60, then it can have the same longest increasing subsequence that 50 has, 3 + 1 = 4.
   * If next element after 50 is 45, then it can have the same longest increasing subsequence that 40 has, 2 + 1 = 3.
   * If next element after 50 is 10, then it can't have anything and we'll set dp value for the number to 1.
   *
   * Initialize dp with 1 for each number as the minimum possible subsequence.
   * Skip processing the 1st number in nums, as it doesn't have any numbers on its left.
   */
  const dp = new Array(nums.length).fill(1);

  for (let curr = 1; curr < nums.length; curr++) {
    for (let left = 0; left < curr; left++) {
      if (nums[curr] > nums[left]) {
        dp[curr] = Math.max(dp[curr], dp[left] + 1);
      }
    }
  }

  return Math.max(...dp);
};

console.log(lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18])); // 4
console.log(lengthOfLIS([0, 1, 0, 3, 2, 3])); // 4
console.log(lengthOfLIS([7, 7, 7, 7, 7, 7, 7])); // 1
console.log(lengthOfLIS([3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12])); // 6
