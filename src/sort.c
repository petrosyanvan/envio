/* Simple C program to sort an array of 0s 1s and 2s. */

#include <stdio.h>

/*
 * Function to print the array values
 *
 *
 * @Param arr - [in] actual array to be printed
 * @Param len - [in] length of the array
 */
void print_array(int* arr, size_t len) {
    printf("[ ");
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

/*  
 * Function to swap the variables in given two addresses
 *
 * @Param a - [in] address of the first variable
 * @Param b - [in] address of the second variable
 *
 */
void swap(int* a, int* b) {
    int t;
    t = *b;
    *b = *a;
    *a = t;
}

/*
 * Function to sort an array of 0's, 1's and 2's
 *
 * @Param arr - [in] array to be sorted. The same array will be modified
 * @Param len - [in] length of the array
 *
 * Return - [out]  0 on success, and -1 if an invalid array was passed 
 */
int asort(int* arr, size_t len) {
    size_t left = 0, mid = 0;
    if (len == 0) {
        /* empty array was passed*/
        return -1;
    }
    size_t right = len - 1;

    // 1 will be our pivot, 0s will be placed on the left side of the pivot and 2s on
    // the right side of the pivot
    while (mid <= right) {
        switch (arr[mid]) {
            case 0:
                swap(&arr[left], &arr[mid]);
                ++left;
                ++mid;
                break;
            case 1:
                ++mid;
                break;
            case 2:
                swap(&arr[mid], &arr[right]);  
                --right;     
                break;
            default:
                /* not allowed value */
                return -1;
        }
    }

    return 0;
}

int main() {
    /* perform several tests on asort function */
    int a[] = { 2, 2, 1, 0, 1, 0, 1, 1, 0, 2, 2, 1, 1, 1, 2, 0, 0, 1, 1, 0, 1, 0, 1, 2, 0, 0, 0, 1, 1, 2 };
    size_t len = sizeof(a) / sizeof(a[0]);
    if (!asort(a, len)) {
        print_array(a, len);
    }
    else {
        printf("Invalid array was passed\n");
    }

    int b[] = { 2, 0, 1, 0, 1, 2, 1 };
    len = sizeof(b) / sizeof(b[0]);
    if (!asort(b, len)) {
        print_array(b, len);
    }
    else {
        printf("Invalid array was passed\n");
    }

    int c[] = { 2, 0, 1, 0, 1, 2, -1 };
    len = sizeof(c) / sizeof(c[0]);
    if (!asort(c, len)) {
        print_array(c, len);
    }
    else {
        printf("Invalid array was passed\n");
    }

    int d[] = { };
    len = sizeof(d) / sizeof(d[0]);
    if (!asort(d, len)) {
       print_array(d, len);
    }
    else {
       printf("Invalid array was passed\n");
    }

    return 0;
}