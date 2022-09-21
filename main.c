/*
 * Sets are assumed to contain only numbers modulo m,
 * and be of size m (unless otherwise stated).
 */

#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

// Computes the set of differences between elements of S
// and elements of T (mathematically, S - T).
uint8_t *differences(uint8_t *S, uint8_t *T, uint8_t k, uint8_t m, uint8_t *res);

// Checks whether every element of set S is unique.
// S may be any size n.
bool unique(uint8_t *S, size_t n);

// Checks whether the pair of sets S and T satisfies all 
// of the properties specified by the "pair of sets" problem.
bool valid(uint8_t *S, uint8_t *T, uint8_t m);

void tests()
{
    uint8_t S[5] = {5, 1, 9, 3, 7};
    assert(unique(S, 5));
    uint8_t T[7] = {5, 1, 9, 3, 7, 3, 10};
    assert(!unique(T, 7));

    uint8_t A[3] = {9, 14, 2};
    uint8_t B[3] = {8, 0, 13}; 
    uint8_t res[9];
    uint8_t expected_res[9] = {1, 9, 15, 6, 14, 1, 13, 2, 8};
    differences(A, B, 3, 19, res);
    for (int i = 0; i < 9; i++)
        assert(res[i] == expected_res[i]);
}

int main()
{
    tests();
}

uint8_t *differences(uint8_t *S, uint8_t *T, uint8_t k, uint8_t m, uint8_t *res)
{
    for(uint8_t i = 0; i < k; i++)
    {
        for(uint8_t j = 0; j < k; j++)
        {
            printf("%d %d\n", S[i], T[j]);
            *res = S[i] - T[j];
            if (S[i] < T[j])
                *res += m;
            res++;
        }
    }
}

bool unique(uint8_t *S, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = i+1; j < n; j++)
        {
            if (S[i] == S[j])
            {
                return false;
            }
        }
    }
    return true;
}
