/**
 * Levenshtein Distance
 */
var editDistance = function (source, target) {
  const sourceLength = source.length;
  const targetLength = target.length;

  // Both strings are empty
  if (sourceLength === 0 && targetLength === 0) {
    return 100;
  }

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

  return (
    100 -
    (dp[sourceLength][targetLength] * 100) /
      Math.max(sourceLength, targetLength)
  );
};

//   console.log("--");

// const r = ;
// //   console.log(sourceLength);
// //   console.log(targetLength);

// console.log((dp[sourceLength][targetLength] * 100) / Math.max(sourceLength, targetLength));

console.log(editDistance("1", "1"));
console.log(editDistance("x", ""));
console.log(editDistance("", "x"));
console.log(editDistance("", ""));
console.log(editDistance("Saturday", "Sunday"));
console.log(editDistance("Sunday", "Saturday"));
console.log(editDistance("kitten", "sitting"));
console.log(editDistance("sitting", "kitten"));
console.log(editDistance("horse", "horsy"));
console.log(
  editDistance(
    `In1 computer science, approximate string (often colloquially referred to as fuzzy string searching) is the technique of
  finding strings that match a pattern approximately (or you now... lol than exactly). The problem of approximate string matching is typically divided into two sub-problems:
  finding approximate substring matches inside a given string and finding dictionary strings that match the pattern approximately.

  Different approximate matchers impose different constraints. Some matchers use a single global unweighted cost, that is,
  the total number of primitive operations necessary to convert the match to the pattern. For example, if the pattern is coil,
  foil differs by one substitution, coils by one insertion, oil by one deletion, and foal by two substitutions. If all operations
  count as a single unit of cost and the limit is set to one, foil, coils, and oil will count as matches while foal will not.

  Traditionally, approximate string matching algorithms are classified into two categories: on-line and off-line. With on-line algorithms the pattern can be processed before searching but the text cannot. In other words, on-line techniques do searching without an index. Early algorithms for on-line approximate matching were suggested by Wagner and Fischer[3] and by Sellers.[2] Both algorithms are based on dynamic programming but solve different problems. Sellers' algorithm searches approximately for a substring in a text while the algorithm of Wagner and Fischer calculates Levenshtein distance, being appropriate for dictionary fuzzy search only.`,
    `In computa science, approximate string matching (often colloquially to as fuzzy string searching) is the technique of
  finding strings that match a pattern approximately (rather than exactly)! The problem of approximate string is typically divided into two sub-problems:
  finding approximate substring inside a given string and finding dictionary strings that match the approximately.

  Different approximate matchers impose different constraints. Some matchers use a single global unweighted cost, that is,
  the total number of primitive operations necessary to convert the match to the pattern. For example, if the pattern is coil,
  foil differs by one substitution, coils by one insertion, oil by one deletion, and foal by two substitutions. If all operations
  count as a single unit of cost and the limit is set to one, foil, coils, and oil will count as matches while foal will not.

  Traditionally, approximate string matching algorithms are classified into two categories: on-line and off-line. With on-line algorithms the pattern can be processed before searching but the text cannot. In other words, on-line techniques do searching without an index. Early algorithms for on-line approximate matching were suggested by Wagner and Fischer[3] and by Sellers.[2] Both algorithms are based on dynamic programming but solve different problems. Sellers' algorithm searches approximately for a substring in a text while the algorithm of Wagner and Fischer calculates Levenshtein distance, being appropriate for dictionary fuzzy search only.`
  )
);

console.log(
  editDistance(
    `In1 computer science, approximate string (often colloquially referred to as fuzzy string searching) is the technique of 
    finding strings that match a pattern approximately (or you now... lol than exactly). The problem of approximate string matching is typically divided into two sub-problems: 
    finding approximate substring matches inside a given string and finding dictionary strings that match the pattern approximately.
    
    Different approximate matchers impose different constraints. Some matchers use a single global unweighted cost, that is, 
    the total number of primitive operations necessary to convert the match to the pattern. For example, if the pattern is coil, 
    foil differs by one substitution, coils by one insertion, oil by one deletion, and foal by two substitutions. If all operations 
    count as a single unit of cost and the limit is set to one, foil, coils, and oil will count as matches while foal will not.
    
    Traditionally, approximate string matching algorithms are classified into two categories: on-line and off-line. With on-line algorithms the pattern can be processed before searching but the text cannot. In other words, on-line techniques do searching without an index. Early algorithms for on-line approximate matching were suggested by Wagner and Fischer[3] and by Sellers.[2] Both algorithms are based on dynamic programming but solve different problems. Sellers' algorithm searches approximately for a substring in a text while the algorithm of Wagner and Fischer calculates Levenshtein distance, being appropriate for dictionary fuzzy search only.`,
    `x111`
  )
);
