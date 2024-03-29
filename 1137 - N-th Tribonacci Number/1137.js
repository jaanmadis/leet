var tribonacci = function (n) {
  const dp = new Array(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  for (let i = 3; i <= n; i++) {
    dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
  }
  return dp[n];
};

console.log(tribonacci(4)); // 4
console.log(tribonacci(25)); // 1389537
