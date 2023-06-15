#include <stdbool.h>
#include <stdio.h>

/*
=== Examples ===

    val = 5
    arr = [1, 2, 5, 3]
    answer is (2, 3)

    val = 6
    arr = [3, 2, 6, 7]
    answer is none

    // Cannot use duplicates
    // Cannot use single number itself

=== Pseudocode ===
hasTwoSum(arr, val):
    Input:
        int[n] arr an array of n integers
        int val
    Output: true if there exist two distinct numbers in arr that sum to val,
otherwise false

    for i is 0 to n-1:                  O(n)
        for j is i+1 to n-1:            n-1 + n-2 + ... 1 => n*(n-1)/2 => O(n^2)
            if arr[i] + arr[j] == val:  O(n^2)
                return true             O(1)

    return false                        O(1)

Time: O(n^2)

*/

bool hasTwoSum(int arr[], int length, int val) {
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      if (arr[i] + arr[j] == val) {
        return true;
      }
    }
  }
  return false;
}

int main(void) {
  int arr[4] = {1, 2, 5, 3};
  int length = 4;
  int val = 5;
  //   int arr[4] = {3, 2, 6, 7};
  //   int length = 4;
  //   int val = 6;

  if (hasTwoSum(arr, length, val)) {
    printf("true, has two sum\n");
  } else {
    printf("false, does not have two sum\n");
  }
}