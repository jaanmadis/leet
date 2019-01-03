var convert = function(s, numRows) {
    if (s.length < 1 || s.length < numRows) {
        return s;
    }

    result = "";

    const skip = Math.max(numRows * 2 - 2, 1);
    zig = skip;
    i = 0;
    currRow = 0;

    while (true) {
        result = result + s[i];
        if (0 < currRow && currRow < numRows - 1 && i + zig < s.length) {
            result = result + s[i + zig];
        }
        i = i + skip;
        if (i >= s.length) {
            ++currRow;
            zig = zig - 2;
            if (currRow < numRows) {
                i = currRow;
            } else {
                break;
            }
        }
    }

    return result;
};
