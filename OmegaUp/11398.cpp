#include <cstdio>
int p[100001], a[100001], c[100001], cnt[100001];
int main() {
    int n, v;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%d",&v);
        a[i] = v;
        cnt[a[i]]++;
    }
    p[0] = 0;
    for(int i=1; i<=100000; ++i) {
        p[i] = p[i - 1] + cnt[i - 1];
    }
    for(int i=0; i<=100000; ++i) {
        cnt[i] = p[i];
    }
    for(int i=0; i<n; ++i) {
        c[p[a[i]]] = a[i];
        p[a[i]]++;
    }
    for(int i=0; i<n; ++i) {
        printf("%d ", c[i]);
    }
    printf("\n");
    for(int i=0; i<n; ++i) {
        printf("%d ", cnt[c[i]]);
    }
    printf("\n");
    return 0;
}