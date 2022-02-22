/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* sumOfThree(long long num, int* returnSize){
    if (num % 3 != 0) {
        *returnSize = 0;
        return (long long *)malloc(sizeof(long long) * 0);
    }
    long long *a = (long long *)malloc(sizeof(long long) * 3);
    *returnSize = 3;
    num /= 3;
    a[0] = num - 1;
    a[1] = num;
    a[2] = num + 1;
    return a;
}
