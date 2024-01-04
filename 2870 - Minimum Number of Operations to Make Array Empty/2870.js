var minOperations = function (nums) {
  const map = {};
  nums.forEach((num) => {
    map[num] = map[num] === undefined ? 1 : +map[num] + 1;
  });
  let ops = 0;
  for (freq in map) {
    let best = Number.MAX_SAFE_INTEGER;
    /**
     * map[freq] = 3 * x + 2 * y
     * Find all integer values of x and y that satisfy the equation.
     */
    for (let x = 0; ; x++) {
      let d = map[freq] - 3 * x;
      if (d < 0) {
        break;
      }
      let y = d / 2;
      if (y % 1 === 0 && x + y < best) {
        best = x + y;
      }
    }
    if (best === Number.MAX_SAFE_INTEGER) {
      return -1;
    } else {
      ops += best;
    }
  }
  return ops;
};

console.log(minOperations([2, 3, 3, 2, 2, 4, 2, 3, 4])); // 4
console.log(minOperations([2, 1, 2, 2, 3, 3])); // -1
