#include <iostream>
#include <cstring>
using namespace std;
const int N = 100005;
int p[N],cnt[N];
// find 函数
int find(int x){
    if(p[x]!= x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    int n,m,a,b;
    char op[3];
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=n;i++){
         p[i] = i;
         cnt[i] = 1;
    }
       
    while(m--){
        scanf("%s",op);
        if(!strcmp(op,"C")) {// node a - node b undirected
            scanf("%d%d",&a,&b);
            a=find(a),b=find(b);
            if(a != b){
                p[a] = b;
                cnt[b] +=cnt[a];
            }
        }
        else if(!strcmp(op,"Q1")){
            scanf("%d%d",&a,&b);
            if(find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
        else if(!strcmp(op,"Q2")){
            
            scanf("%d",&a);
          
            printf("%d\n",cnt[a]);
        }


    }
    return 0;
}