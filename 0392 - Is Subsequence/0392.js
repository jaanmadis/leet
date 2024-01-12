var isSubsequence = function (s, t) {
  if (s === "") return true;
  if (s.length > t.length) return false;
  let ptrS = 0;
  let ptrT = 0;
  while (ptrT < t.length) {
    if (s[ptrS] === t[ptrT]) {
      ptrS++;
      if (ptrS === s.length) {
        return true;
      }
    }
    ptrT++;
  }
  return false;
};

console.log(isSubsequence("bc", "ahbgdc"));
