#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*
Examples

   0 1 2 3 4 5 6 7
    r a c e c a r
   l^          r^

   0 1 2 3 4
    p e e p
   l^    r^

   0 1 2 3 4 5
    a m a z e
   l^      r^

   0 1 2 3 4
    t i r e
   l^    r^
*/

/*
=== Pseudocode ===

isPalindrome(S):
    Input: array S[0..n-1] of chars
    Output: true if S is a palindrome, false otherwise

    l = 0                   O(1)
    r = n - 1               O(1)

    while l < r:            O(n/2) => O(n)
        if S[l] != S[r]:    O(n)
            return false    O(1)
        l = l + 1           O(n)
        r = r - 1           O(n)

    return true             O(1)

=== Time complexity ===
Best case: O(1)
Worst case: O(n/2) => O(n)
Average case: O(n/2) => O(n)
*/

static bool isPalindrome(char *word) {
  int l = 0;
  int r = strlen(word) - 1;

  while (l < r) {
    if (word[l] != word[r]) {
      return false;
    }
    l++;
    r--;
  }

  return true;
}

int main(int argc, char *argv[]) {
  if (argc == 2) {
    if (isPalindrome(argv[1])) {
      printf("yes, '%s' is a palindrome\n", argv[1]);
    } else {
      printf("no, '%s' is not a palindrome\n", argv[1]);
    }
  } else {
    printf("Usage: ./a.out <word>\n");
  }
  return 0;
}