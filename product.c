#include "product.h"
//Functions for CRUD
int selectMenu(){
  int menu;
  printf("\n제품 CRUD\n");
  printf("1. 조회\n");
  printf("2. 추가\n");
  printf("3. 수정\n");
  printf("4. 삭제\n");
  printf("5. 저장\n");
  printf("6. 검색\n");
  printf("0. 종료\n\n");
  printf("=> 원하는 메뉴는? ");
  scanf("%d", &menu);
  return menu;
}

int addProduct (Product *s) {
printf("제품명은? ");
scanf("\n%[^\n]s", s->name);
printf("중량은? ");
getchar();
scanf("%d", &s->mass);
printf("가격은? ");
scanf("%d", &s->price);
//printf("표준 가격은?(10g당) ");
//scanf("%3f" &s->stdPrice);
printf("별개수는? ");
scanf("%d", &s->star);
printf("\n추가됨! \n");
return 1;
}

void readProduct (Product s) {
if (s.price == -1){
printf ("제품이 없음\n");
return;
}
s.stdPrice = (double)(s.price)/(s.mass)*(10.0);
printf("\n%s %dg\n", s.name, s.mass);
printf("%d원\n",s.price);
printf("(10g당 %.2f원)\n",s.stdPrice);
for (int i = 0; i < s.star; i++)
printf("*");
printf("\n");
}

int updateProduct (Product *s) {

printf("새 제품명은? ");
scanf("\n%[^\n]s", s->name);
printf("중량은? ");
getchar();
scanf("%d", &s->mass);
printf("가격은? ");
scanf("%d", &s->price);
//printf("표준 가격은?(10g당) ");
//scanf("%d", &s->stdPrice);
printf("별개수는? ");
scanf("%d", &s->star);
printf("\n 수정됨! \n");
return 0;
}

int deleteProduct (Product *s) {
s->price = -1;
s->stdPrice = -1;
s->mass = -1;
s->star = -1;
printf("\n 삭제됨!!!\n");
return 0;
}
