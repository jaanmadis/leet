var reverse = function(x) {
  result = 0;

  while (x !== 0) {
    digit = x % 10;
    result = result * 10 + digit;
    x = ~~(x / 10);
  }

  if (result > 2147483647 || result < -2147483648) {
    return 0;
  }
  
  return result;  
};