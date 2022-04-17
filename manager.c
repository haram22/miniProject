
#include <stdio.h>
#include <string.h>
#include "manager.h"

int add(s *s, int count){
    getchar();
    printf("상품명은? ");
    fgets(s[count]->name, 100, stdin);
    s[count]->name[strlen(s[count]->name) -1]= '\0';
    printf("가격은? ");
    scanf("%d", &s[count]->price);
    printf("양은 ?");
    scanf("%d", &s[count]->amount);
    printf("주소는? ");
    scanf("%s", s[count]->address);
    return 1;
}

void printList(s *s, int count){
    for(int i=0;i<count;i++){
        if(s[i]->price !=-1) printf("\n%s %s %d %d\n",s[i]->address,s[i]->name, s[i]->price, s[i]->amount);
        else printf("\n등록된 상품이 없음.\n");
    }
}

void edit(s *s, int count){
#ifdef DEBUG
	printf("다음은 디버그용 입니다.");
#endif
    getchar();
    printf("상품명은? ");
    fgets(s[count]->name, 100, stdin);
    s[count]->name[strlen(s[count]->name) -1]= '\0';
    printf("가격은? ");
    scanf("%d", &s[count]->price);
    printf("양은 ?");
    scanf("%d", &s[count]->amount);
    printf("주소는? ");
    scanf("%s", s[count]->address);
    printf("success!!\n\n");
}

int deleten(s *s){
    int no;
    int real;
    printf("delete number? ");
    scanf("%d", &no);
    printf("you really want? (y:1, n:0) ");
    scanf("%d", &real);
    if(real==0) return 0;
    else {
        s[no-1]->price=-1;
        return 1;
    } 
}

