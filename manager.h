typedef struct{
    char name[20];
    int price;
    int amount;
    char address[20];
} s[20];

void printList(s *s, int count);
int add(s *s, int count);
int deleten(s *s);
void edit(s *s, int count);
int selectNo(s *s);
int title(s *s, int count);
int content(s *s, int count);
int findname(s *s, int count);
int findaddress(s *s, int count);
int findamount(s *s, int count);
int loadData(s *s);
void save(s *s, int count);


