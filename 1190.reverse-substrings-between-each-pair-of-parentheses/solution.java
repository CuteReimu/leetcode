class Result {
    int end;
    String string;
    Result(int end, String string) {
        this.end = end;
        this.string = string;
    }
}

class Solution {
    public String reverseParentheses(String s) {
        return reverseParentheses1(s, 0).string;
    }

    private Result reverseParentheses1(String s, int begin) {
        StringBuilder sb = new StringBuilder();
        for (int i = begin; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == ')')
                return new Result(i, sb.toString());
            else if (c != '(')
                sb.append(c);
            else {
                Result result = reverseParentheses2(s, i + 1);
                sb.append(result.string);
                i = result.end;
            }
        }
        return new Result(s.length(), sb.toString());
    }

    private Result reverseParentheses2(String s, int begin) {
        Stack<Object> stack = new Stack<>();
        for (int i = begin; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == ')') {
                StringBuilder sb = new StringBuilder();
                while (!stack.empty())
                    sb.append(stack.pop());
                return new Result(i, sb.toString());
            } else if (c != '(')
                stack.push(c);
            else {
                Result result = reverseParentheses1(s, i + 1);
                stack.push(result.string);
                i = result.end;
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!stack.empty())
            sb.append(stack.pop());
        return new Result(s.length(), sb.toString());
    }
}
