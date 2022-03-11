
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct UnionSet{
    int *father, *size;
    int n;
}UnionSet;

UnionSet *init(int n){
    UnionSet *u = (UnionSet *) malloc(sizeof (UnionSet));
    u -> father = (int *) malloc(sizeof (int ) * (n + 1 ));
    u -> n = n ;
    for (int i = 0; i <= n; ++i) {
        u -> father[i] = i;
    }
    return u;
}


void clear(UnionSet *u){
    if(u == NULL) return;
    free(u -> father);
    free(u -> size);
    free(u);
    return;

}

int find(UnionSet *u, int n){
    if(u -> father[n] == n)return n;
    return find(u, u -> father[n]);
}

int merge(UnionSet *u, int a, int b){
    int fa = find(u, a),fb = find(u, b);
    if(fa == fb)return 0;
    if(u -> size[fa] < u -> size[fb]) {
      u->father[fa] = fb;
      u -> size[fb] += u -> size[fa];
    } else{
        u -> father[fb] = fa;
        u -> size[fa] += u -> size[fb];
    }
    return 1;

}

int main() {
   int n, m;
    scanf("%d %d\n",&n, &m);
    UnionSet  *u = init(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d\n", &a, &b, &c);
        switch (a) {
            case 1:
                merge(u , b, c);
                break;
            case 2:{
                printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No");
            }break;
        }
    }
    return 0;
}
