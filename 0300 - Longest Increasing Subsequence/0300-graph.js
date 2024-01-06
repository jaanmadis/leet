/**
 * Make a graph from numbers.
 * Number is a node and it has links to larger numbers on its right side in nums array.
 * Then visit every node and find the deepest longest path possible.
 *
 * This is slow and bad.
 */

function visit(nodes, node, visited) {
  let longestNeighbor = 0;
  nodes[node].forEach((neighbor) => {
    if (visited[neighbor] === undefined) {
      visit(nodes, neighbor, visited);
    }
    if (visited[neighbor] > longestNeighbor) {
      longestNeighbor = visited[neighbor];
    }
  });
  visited[node] = longestNeighbor + 1;
  return visited[node];
}

var lengthOfLIS = function (nums) {
  const nodes = {};
  const visited = {};

  nums.forEach((num, i) => {
    const links = [];
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[j] > num) {
        links.push(j);
      }
    }
    nodes[i] = links;
  });
  let best = 0;
  for (const node in nodes) {
    const curr = visit(nodes, node, visited);
    if (curr > best) {
      best = curr;
    }
  }
  return best;
};

console.log(lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18])); // 4
console.log(lengthOfLIS([0, 1, 0, 3, 2, 3])); // 4
console.log(lengthOfLIS([7, 7, 7, 7, 7, 7, 7])); // 1
console.log(lengthOfLIS([3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12])); // 6
