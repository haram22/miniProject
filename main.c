#include <stdio.h>
#include "product.h"
#include "manager.h"

int main(){
#ifdef DEBUG 
	printf("디버그용");
#endif
    int no;
    int count=0;
    s s[20];
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
     else break;
    }
    return 0;
}

