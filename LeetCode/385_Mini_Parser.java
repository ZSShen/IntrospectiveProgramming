/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    public NestedInteger deserialize(String str) {

        Stack<NestedInteger> stack = new Stack<NestedInteger>();

        StringBuilder buf = new StringBuilder();
        int sign = 1;

        for (int i = 0 ; i < str.length() ; ++i) {
            char ch = str.charAt(i);
            switch (ch) {
                case '[': {
                    NestedInteger elem = new NestedInteger();
                    stack.push(elem);
                    break;
                }
                case ']': {
                    if (buf.length() > 0) {
                        int num = sign * Integer.valueOf(buf.toString());

                        NestedInteger elem = new NestedInteger(num);
                        stack.peek().add(elem);

                        buf.setLength(0);
                        sign = 1;
                    }

                    if (stack.size() > 1) {
                        NestedInteger elem = stack.pop();
                        stack.peek().add(elem);
                    }
                    break;
                }
                case ',': {
                    if (buf.length() > 0) {
                        int num = sign * Integer.valueOf(buf.toString());

                        NestedInteger elem = new NestedInteger(num);
                        stack.peek().add(elem);

                        buf.setLength(0);
                        sign = 1;
                    }
                    break;
                }
                case '-': {
                    sign = -1;
                    break;
                }
                case ' ': {
                    break;
                }
                default: {
                    buf.append(ch);
                }
            }
        }

        // Single nemeric element.
        if (buf.length() > 0) {
            int num = sign * Integer.valueOf(buf.toString());
            return new NestedInteger(num);
        }

        return stack.pop();
    }
}