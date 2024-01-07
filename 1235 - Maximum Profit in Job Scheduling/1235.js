var jobSchedulingA = function (startTime, endTime, profit) {
  const jobs = [];
  for (let i = 0; i < startTime.length; i++) {
    jobs.push({
      startTime: startTime[i],
      endTime: endTime[i],
      profit: profit[i],
    });
  }
  /**
   * Sorting order is important.
   * If sorted by start time in asc order,
   * then we should travel the jobs from last to first.
   */
  jobs.sort(
    (a, b) =>
      a.startTime - b.startTime || a.endTime - b.endTime || a.profit - b.profit
  );

  const dp = new Array(jobs.length).fill(0);
  dp[dp.length - 1] = jobs[jobs.length - 1].profit;

  for (let curr = dp.length - 2; curr >= 0; curr--) {
    let profits = jobs[curr].profit;
    for (let next = curr + 1; next < dp.length; next++) {
      if (jobs[curr].endTime <= jobs[next].startTime) {
        profits = jobs[curr].profit + dp[next];
        break;
      }
    }
    dp[curr] = Math.max(profits, dp[curr + 1]);
  }

  return dp[0];
};

var jobSchedulingB = function (startTime, endTime, profit) {
  const jobs = [];
  for (let i = 0; i < startTime.length; i++) {
    jobs.push({
      startTime: startTime[i],
      endTime: endTime[i],
      profit: profit[i],
    });
  }
  /**
   * Sorting order is important.
   * If sorted by end time in asc order,
   * then we should travel the jobs from first to last.
   */
  jobs.sort(
    (a, b) =>
      a.endTime - b.endTime || a.startTime - b.startTime || a.profit - b.profit
  );

  const dp = new Array(jobs.length).fill(0);
  dp[0] = jobs[0].profit;

  /**
   * Iterate though jobs.
   *
   * Starts:    4   18              18
   * Ends:      13  28              39
   * Profit:    12  5               14
   * DP:        12  5 + 12 -> 17    14 + 12 vs 5 + 12 -> 26
   *
   * First job's DP is its price - 12.
   * Second job's start after first job's end, its DP is its price + previous fitting job - 5 + 12
   * Third job's start is before second job's end, keep looking.
   * Third job's start is after first job's end, its DP is its price + previous fitting job - 14 + 12.
   *
   * However, we should also check our immidiate left side neighbour.
   * If the neighbour has better DP value, then we should just copy it.
   * This is the situation where two jobs have overlap.
   * If our DP is better, then the neighbour job won't be optimal to do at the current time.
   * If neighbour's DP is better, then this job won't be optimal to do at the current time.
   *
   * End times must be sorted in ascending order to make sure that neighbour is a chronological neighbour when we compare neighbour's end times.
   */
  for (let curr = 1; curr < dp.length; curr++) {
    let profits = jobs[curr].profit;
    for (let prev = curr - 1; prev >= 0; prev--) {
      if (jobs[curr].startTime >= jobs[prev].endTime) {
        profits = jobs[curr].profit + dp[prev];
        break;
      }
    }
    dp[curr] = Math.max(profits, dp[curr - 1]);
  }

  return dp[dp.length - 1];
};

var jobScheduling = function (startTime, endTime, profit) {
  console.log(jobSchedulingA(startTime, endTime, profit));
  console.log(jobSchedulingB(startTime, endTime, profit));
};

let startTime;
let endTime;
let profit;

startTime = [2, 5, 11, 13, 13, 16, 28, 31, 36, 40, 43, 47];
endTime = [21, 13, 39, 22, 35, 26, 48, 41, 41, 47, 44, 48];
profit = [1, 8, 1, 20, 13, 15, 2, 19, 3, 16, 8, 11];
jobScheduling(startTime, endTime, profit); // 66

startTime = [1, 2, 3, 3];
endTime = [3, 4, 5, 6];
profit = [50, 10, 40, 70];
jobScheduling(startTime, endTime, profit); // 120

startTime = [1, 2, 3, 4, 6];
endTime = [3, 5, 10, 6, 9];
profit = [20, 20, 100, 70, 60];
jobScheduling(startTime, endTime, profit); // 150

startTime = [1, 1, 1];
endTime = [2, 3, 4];
profit = [5, 6, 4];
jobScheduling(startTime, endTime, profit); // 6

startTime = [33, 8, 9, 18, 16, 36, 18, 4, 42, 45, 29, 43];
endTime = [40, 16, 32, 39, 46, 43, 28, 13, 44, 46, 39, 44];
profit = [2, 6, 5, 14, 5, 19, 5, 12, 19, 14, 14, 17];
jobScheduling(startTime, endTime, profit); // 67
