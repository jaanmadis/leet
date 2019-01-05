/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer. 
Input is guaranteed to be within the range from 1 to 3999.
*/

var romanToInt = function(s) {
  result = 0;
  for(i = 0; i < s.length; ++i) {
    if (i < s.length - 1) {
    }
    switch(s[i]) {
      case "I":
        if ((i + 1 < s.length) && ((s[i + 1] === "V") || (s[i + 1] === "X"))) {
          num = -1;
        }
        else {
          num = 1;
        }
        break;
      case "V":
        num = 5;
        break;
      case "X":
        if ((i + 1 < s.length) && ((s[i + 1] === "L") || (s[i + 1] === "C"))) {
          num = -10;
        }
        else {
          num = 10;
        }
        break;
      case "L":
        num = 50;
        break;
      case "C":
        if ((i + 1 < s.length) && ((s[i + 1] === "D") || (s[i + 1] === "M"))) {
          num = -100;
        }
        else {
          num = 100;
        }
        break;
      case "D":
        num = 500;
        break;
      case "M":
        num = 1000;
        break;
      default:
        num = 0;
        break;
    }
    result = result + num;
  }
  return result;
};