/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 *
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
  if (x < 0) {
    return false;
  }
  num = x;
  rev = 0;
  while (num !== 0) {
    digit = num % 10;
    num = ~~(num / 10);
    rev = rev * 10 + digit;
  }
  return x === rev;
}