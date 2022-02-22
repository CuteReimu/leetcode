class Solution {

    /**
     * @param Integer $num
     * @return Integer[]
     */
    function sumOfThree($num) {
        if ($num % 3 != 0) {
            return [];
        }
        $num /= 3;
        return [$num-1, $num, $num+1];
    }
}
