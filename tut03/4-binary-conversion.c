/*
=== Example 1 ===

11 base 10 = 1011 base 2

    2^3 2^2 2^1 2^0
     8   4   2   1
     1   0   1   1

     8 + 0 + 2 + 1 = 11

11 % 2 = 1
11 / 2 = 5

5 % 2 = 1
5 / 2 = 2

2 % 2 = 0
2 / 2 = 1

1 % 2 = 1
1 / 2 = 0


=== Example 2 ===

16 base 10 = 1011 base 2

    2^4 2^3 2^2 2^1 2^0
     16  8   4   2   1
     1   0   0   0   0

     16  8 + 0 + 0 + 0 = 16

16 % 2 = 0
16 / 2 = 8

8 % 2 = 0
8 / 2 = 4

4 % 2 = 2
4 / 2 = 0

2 % 2 = 0
2 / 2 = 1

1 % 2 = 1
1 / 2 = 0

0 => done

BinaryConversion:
        Input:  positive integer n
        Output: binary representation of n on a stack

        create empty stack S
        while n > 0 do
                push (n mod 2) onto S
                n = floor(n / 2)
        end while
        return S

*/