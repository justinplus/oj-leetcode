public class Solution {
  // Note: char [] is more suitable than StringBuilder here
  public String reverseString(String s) {
    if( s == null ) return null;

    char[] arr = s.toCharArray();
    int size = arr.length;
    for( int i = 0; i < size / 2; ++i ) {
      char ch = arr[i];
      arr[i] = arr[size - 1 - i];
      arr[size - 1 - i] = ch;
    }
    return new String(arr);
  }

  public String reverseString1(String s) {
    if( s == null ) return null;

    char[] arr = s.toCharArray();
    int bg = 0;
    int end = arr.length - 1;
    for( ; bg < end; ++bg, --end ) {
      char ch = arr[bg];
      arr[bg] = arr[end];
      arr[end] = ch;
    }
    return new String(arr);

  }

  public static void main(String[] args) {
    String str = "hello";
    Solution s = new Solution();
    System.out.println(s.reverseString(str));
    System.out.println(s.reverseString1(str));
  }
}
