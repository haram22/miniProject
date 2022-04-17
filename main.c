#include <stdio.h>
#include "product.h"
#include "manager.h"

int main(){
#ifdef DEBUG 
        printf("디버그용");
#endif
    s s[20];
    int no;
    int count=0;
    count= loadData(s);
while(1){
     menu();
     printf("=> 원하는 메뉴는? ");
     scanf("%d", &no);
     if(no==1) printList(s, count);
     else if(no==2) count+= add(s, count);
     else if(no==3) edit(s, count);
     else if(no==4) {
         if(deleten(s)!=0) {
             printf("deleted!\n");
         }
         else break;
     }
     else if(no==5) findname(s, count);
     else if(no==6) save(s,count);
     else break;
    }
    return 0;
}
