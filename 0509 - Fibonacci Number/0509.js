function fibdp(n, dp) {
  if (n === 0 || n === 1) {
    return n;
  }
  if (!dp[n - 1]) {
    dp[n - 1] = fibdp(n - 1, dp);
  }
  return dp[n - 1] + dp[n - 2];
}

var fib = function (n) {
  const dp = [0, 1];
  return fibdp(n, dp);
};

console.log(fib(50));
