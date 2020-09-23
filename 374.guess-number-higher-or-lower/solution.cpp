/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int minval = 1;
        int maxval = n;
        while (true) {
            int val = (int)(((long)minval + (long)maxval) / 2);
            switch (guess(val)) {
                case 0 : return val;
                case 1 :
                    minval = val + 1;
                    break;
                case -1 :
                    maxval = val - 1;
            }
        }
    }
};
