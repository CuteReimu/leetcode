/**
 * @param {number} num
 * @return {number[]}
 */
var sumOfThree = function(num) {
    if (num % 3 != 0) {
        return [];
    }
    num /= 3;
    return [num-1, num, num+1];
};
