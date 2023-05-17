class Solution {
    fun haveConflict(event1: Array<String>, event2: Array<String>): Boolean =
        event1[0] <= event2[1] && event2[0] <= event1[1]
}
