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
int findname(s *s, int count){
    char find[10];
    int c=0;
    printf("검색할 이름? ");
    scanf("%s",find);
    printf("\nNo  이름 가격 양 주소\n");
    printf("=================================\n");
    for(int i=0;i<count;i++){
        if(strcmp(find, s[i]->name) == 0) {
            printf("%d %s %d %d %s\n", i+1, s[i]->name, s[i]->price, s[i]->amount, s[i]->address);
            c++;
        }
        else continue;
    }
    printf("\n총 %d개의 주문이 있습니다.\n",c);
    if(c==0) printf("=> 검색된 데이터 없음!\n");
    return 0;
}

int findaddress(s *s, int count){
    char find[10];
    int c=0;
    printf("검색할 주소? ");
    scanf("%s",find);
    printf("\nNo  이름 가격 양 주소\n");
    printf("=================================\n");
    for(int i=0;i<count;i++){
        if(strcmp(find, s[i]->address) == 0) {
            printf("%d %s %d %d %s\n", i+1, s[i]->name, s[i]->price, s[i]->amount, s[i]->address);
            c++;
        }
        else continue;
    }
    printf("\n총 %d개의 주문이 있습니다.\n",c);
    if(c==0) printf("=> 검색된 데이터 없음!\n");
    return 0;
}

int findamount(s *s, int count){
    int find;
    int c=0;
    printf("검색할 양? ");
    scanf("%d",&find);
    printf("\nNo  이름 가격 양 주소\n");
    printf("=================================\n");
    for(int i=0;i<count;i++){
        if(find ==s[i]->amount) {
            printf("%d %s %d %d %s\n", i+1, s[i]->name, s[i]->price, s[i]->amount, s[i]->address);
            c++;
        }
        else continue;
    }
    printf("\n총 %d개의 주문이 있습니다.\n",c);
    if(c==0) printf("=> 검색된 데이터 없음!\n");
    return 0;
}

int loadData(s *s){
  int num=0;
  FILE *fp;
  int i=0;
fp= fopen("score.txt", "rt");
if (fp!=NULL){
 for(i=0;i<100;i++){
   fscanf(fp, "%s", s[i]->name);
   if(feof(fp)) break;
    fscanf(fp,"%s", &s[i]->name);
    fscanf(fp,"%d", &s[i]->price);
    fscanf(fp,"%d", &s[i]->amount);
    fscanf(fp,"%s", &s[i]->address);
  }
   fclose(fp);
   printf("=> 로딩 성공!\n");
   return i;
  }
  else {
    printf("=> 파일 없음\n");
    return 0;
   }
}

void save(s *s, int count){
 FILE* file;
 file=fopen("score.txt","wt");
 for(int i=0;i<count;i++){
 if( s[i]->price ==-1 ) continue;
 fprintf(file,"%s %d %d %s\n\n", s[i]->name, s[i]->price, s[i]->amount, s[i]->address);
 }
 fclose(file);
 printf("저장됨!");
}
