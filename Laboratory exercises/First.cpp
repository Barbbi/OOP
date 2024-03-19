#include <stdio.h>
#include <string.h>

typedef struct Transaction{
    int id;
    int comission;
    int sum;
    int type;
} Transaction;

int main() {
    int n, i, f=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        Transaction t;
        scanf("%d %d %d %d", &t.id, &t.sum, &t.comission, &t.type);
        if(t.type==1){
            printf("%d %d \n", t.id, t.comission+t.sum);
            f=1;
        }
    }
    
    if(f==0){
        printf("No credit card transaction");
    }
    
    return 0;
}