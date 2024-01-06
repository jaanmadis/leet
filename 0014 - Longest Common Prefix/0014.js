/**
 * Find longest common prefix between two strings.
 *
 * Slice the strings to equal length.
 * Keep cutting the last characters of the strings until strings are equal (or empty).
 * Return whatever was left, this is the longest common prefix for these strings.
 */
function stx(A, B) {
  let As = A.slice(0, B.length);
  let Bs = B.slice(0, A.length);
  while (As !== Bs) {
    As = As.slice(0, -1);
    Bs = Bs.slice(0, -1);
  }
  return As;
}

/**
 * Initialize the current longest common prefix to the first string in strs.
 * Iterate over every sting and find the longest common prefix
 * between the current longest common prefix and each string in strs.
 */
var longestCommonPrefix = function (strs) {
  let result = "";
  if (strs.length !== 0) {
    result = strs[0];
    for (let i = 1; i < strs.length; i++) {
      result = stx(result, strs[i]);
      if (result === "") {
        break;
      }
    }
  }
  return result;
};

console.log(longestCommonPrefix(["flower"]));
console.log(longestCommonPrefix(["flower", "flow", "flight"]));
console.log(longestCommonPrefix(["dog", "car", "dogcar"]));
