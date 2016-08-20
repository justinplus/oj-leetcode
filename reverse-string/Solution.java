public class Solution {
  // TODO: improve
  public String reverseString(String s) {
    StringBuilder sb = new StringBuilder(s);
    int size = sb.length();
    for( int i = 0; i < size / 2; ++i ) {
      char ch = sb.charAt(i);
      sb.setCharAt(i, sb.charAt(size - 1 - i) );
      sb.setCharAt(size - 1 - i, ch);
    }
    return sb.toString();
  }

  public static void main(String[] args) {
    String str = "hello";
    Solution s = new Solution();
    System.out.println(s.reverseString(str));
  }
}
