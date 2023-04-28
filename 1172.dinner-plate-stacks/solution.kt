import java.util.*

class DinnerPlates(private val capacity: Int) {
    private val stack = LinkedList<Int>()
    private val top = ArrayList<Int>()
    private var poppedPos = TreeSet<Int>()

    fun push(`val`: Int) {
        if (poppedPos.isEmpty()) {
            val pos = stack.size
            stack.add(`val`)
            if (pos % capacity == 0) {
                top.add(0)
            } else {
                val stackPos = top.size - 1
                val stackTop = top[stackPos]
                top[stackPos] = stackTop + 1
            }
        } else {
            val pos = poppedPos.pollFirst()!!
            stack[pos] = `val`
            val index = pos / capacity
            val stackTop = top[index]
            top[index] = stackTop + 1
        }
    }

    fun pop(): Int {
        while (!stack.isEmpty() && poppedPos.contains(stack.size - 1)) {
            stack.removeLast()
            val pos = poppedPos.pollLast()!!
            if (pos % capacity == 0) {
                top.removeAt(top.size - 1)
            }
        }
        return if (stack.isEmpty()) {
            -1
        } else {
            val pos = stack.size - 1
            val `val` = stack[pos]
            stack.removeAt(pos)
            val index = top.size - 1
            if (pos % capacity == 0) {
                top.removeAt(index)
            } else {
                top[index] = index - 1
            }
            `val`
        }
    }

    fun popAtStack(index: Int): Int {
        if (index >= top.size) {
            return -1
        }
        val stackTop = top[index]
        if (stackTop < 0) {
            return -1
        }
        top[index] = stackTop - 1
        val pos = index * capacity + stackTop
        poppedPos.add(pos)
        return stack[pos]
    }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * var obj = DinnerPlates(capacity)
 * obj.push(`val`)
 * var param_2 = obj.pop()
 * var param_3 = obj.popAtStack(index)
 */
