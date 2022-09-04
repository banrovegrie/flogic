#include <stdio.h>

int main() {
    // Take an array as input.
    int n;
    scanf("%d", &n);

    int k;
    scanf("%d", &k);

    int a[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ans[100];
    ans[0] = a[k - 1];
    for (int i = 1; i < k; i++) {
        ans[i] = a[i - 1];
    }

    for (int i = k; i < n; i++) {
        ans[i] = a[i];
    }

    // for (int i = 0; i < n; i++) {
    //     printf("%d ", ans[i]);
    // }

    // I think you will have to return 
    // the array ans.
    return 0;
}