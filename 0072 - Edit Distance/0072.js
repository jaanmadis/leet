/**
 * Levenshtein Distance
 */
var editDistance = function (source, target) {
  const sourceLength = source.length;
  const targetLength = target.length;

  // Initialize matrix with zeros
  const dp = new Array(sourceLength + 1)
    .fill(0)
    .map(() => new Array(targetLength + 1).fill(0));

  // Base case: source vs empty string
  // Source prefixes can be transformed to empty string by deleting every character.
  for (let i = 0; i <= sourceLength; ++i) {
    dp[i][0] = i;
  }

  // Base case: empty string vs target
  // Target prefixes can be achieved from empty string by inserting every character.
  for (let j = 0; j <= targetLength; ++j) {
    dp[0][j] = j;
  }

  let replaceCost = 0;
  for (let j = 1; j <= targetLength; ++j) {
    for (let i = 1; i <= sourceLength; ++i) {
      if (source[i - 1] === target[j - 1]) {
        replaceCost = 0; // Characters match, replaceCost is zero.
      } else {
        replaceCost = 1;
      }
      dp[i][j] = Math.min(
        dp[i - 1][j] + 1, // Delete case
        dp[i][j - 1] + 1, // Insert case
        dp[i - 1][j - 1] + replaceCost // Replace case, replaceCost is be zero if characters matched.
      );
    }
  }

  return dp[sourceLength][targetLength];
};
