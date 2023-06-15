/*
P(x) = a0 + a1*x + a2*x^2 + a3*x^3 + ... + an*x^n

P(x) = a0 + x * (a1 + x * (a2 + x * (... + x * an)))

=== Pseudocode O(n^2) ===

evalPolynomial(A, n, x):
    Inputs:
        int[n] A an array of coefficients
        int n the degree of the polynomial
        int x
    Output:
        int the result

    result = 0

    for i = 0 up to n:                  O(n+1) = O(n)
        result = result + A[i] * x^i    O(n+1) * O(n) = O(n^2)

    return result

Time: O(n^2)

=== Pseudocode O(n) ===

evalPolynomial(A, n, x):
    result = 0
    xPower = 1

    for i = 0 up to n:                      O(n+1) = O(n)
        result = result + A[i] * xPower     O(n)
        xPower = xPower * x

    return result

Time: O(n)

*/