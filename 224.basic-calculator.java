/*
 * @lc app=leetcode id=224 lang=java
 *
 * [224] Basic Calculator
 */

import java.util.ArrayDeque;
import java.util.Deque;

// @lc code=start
// TODO: 19ms beats 10.02% - improve performance
class Solution {
    public int calculate(String s) {
        final Deque<Token> stack = new ArrayDeque<>(256);
        final Parser parser = new Parser(s);

        if (parser.hasNext()) {
            stack.addLast(parser.next());
        }

        while (parser.hasNext()) {
            final Token next = parser.next();
            if (next.type() == TokenType.NUMBER) {
                evalNextNum(next, stack);
            } else if (next.type() == TokenType.RIGHT_BRACKET) {
                final Token num = stack.removeLast();
                if (stack.removeLast().type() != TokenType.LEFT_BRACKET) {
                    throw new IllegalArgumentException("Invalid expression");
                }
                if (stack.isEmpty()) {
                    stack.addLast(num);
                } else { 
                    evalNextNum(num, stack);
                }
            } else {
                stack.addLast(next);
            }
        }

        final Token result = stack.peekLast();
        if (result == null || result.type() != TokenType.NUMBER) {
            throw new IllegalArgumentException("Invalid expression");
        }
        return result.value();
    }

    private static void evalNextNum(Token next, Deque<Token> stack) {
        final Token curr = stack.getLast();
        switch (curr.type()) {
            case BINARY_ADD -> {
                stack.removeLast();
                final Token num = stack.removeLast();
                stack.addLast(new NumberToken(num.value() + next.value()));
            }
            case BINARY_SUB -> {
                stack.removeLast();
                final Token num = stack.removeLast();
                stack.addLast(new NumberToken(num.value() - next.value()));
            }
            case UNARY_SUB -> {
                stack.removeLast();
                stack.addLast(new NumberToken(-next.value()));
            }
            case LEFT_BRACKET -> {
                stack.addLast(next);
            }
            default -> throw new IllegalArgumentException("Invalid expression");
        }
    }

    private static class Parser {
        private final String s;
        private int index;
        private Token preToken;

        public Parser(String s) {
            this.s = s;
            this.index = 0;
            this.preToken = null;
            skipWhiteSpace();
        }

        public boolean hasNext() {
            return index < s.length();
        }

        public Token next() {
            final char ch = s.charAt(index);
            final Token token = switch (ch) {
                case '+' -> {
                    ++index;
                    yield new OperatorToken(TokenType.BINARY_ADD);
                }
                case '-' -> {
                    ++index;
                    yield preToken == null || preToken.type() == TokenType.LEFT_BRACKET
                            ? new OperatorToken(TokenType.UNARY_SUB)
                            : new OperatorToken(TokenType.BINARY_SUB);
                }
                case '(' -> {
                    ++index;
                    yield new OperatorToken(TokenType.LEFT_BRACKET);
                }
                case ')' -> {
                    ++index;
                    yield new OperatorToken(TokenType.RIGHT_BRACKET);
                }
                default -> {
                    final int begin = index;
                    for (; index < s.length() && Character.isDigit(s.charAt(index)); ++index)
                        ;
                    yield new NumberToken(Integer.parseInt(s.substring(begin, index)));
                }
            };
            preToken = token;
            skipWhiteSpace();
            return token;
        }

        private void skipWhiteSpace() {
            for (int len = s.length(); index < len && s.charAt(index) == ' '; ++index)
                ;
        }
    }

    private interface Token {
        TokenType type();

        int value();
    }

    private static record OperatorToken(TokenType type) implements Token {
        @Override
        public int value() {
            throw new UnsupportedOperationException("Unimplemented method 'value'");
        }
    }

    private static record NumberToken(int num) implements Token {
        @Override
        public TokenType type() {
            return TokenType.NUMBER;
        }

        @Override
        public int value() {
            return num;
        }
    }

    private static enum TokenType {
        NUMBER,
        BINARY_ADD,
        BINARY_SUB,
        UNARY_SUB,
        LEFT_BRACKET,
        RIGHT_BRACKET
    }
}
// @lc code=end
