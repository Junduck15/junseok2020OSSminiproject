#include "manager.h"

int main(){
  Product s[100];
  int count = 0, menu;
  int curcount = 0;

    while (1){
	#ifdef DEBUG
	printf("debug[main.c] : call selectMenu()");
	#endif
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
	#ifdef DEBUG
	printf("debug[main.c] : call listProduct()\n");
	#endif
	  if (count>0) listProduct(&s[0], curcount);
	  else printf("데이터가 없습니다!\n");
        }
        else if (menu == 2){
	#ifdef DEBUG
	printf("debug[main.c] : call addProduct()\n");
	#endif
          count+=addProduct(&s[curcount]);
	  curcount++;
        }
        else if (menu == 3){
	  if (count==0){
		printf("수정할 제품이 없습니다.\n");
		}
	  else {
	#ifdef DEBUG
	printf("debug[main.c] : call selectDataNo()\n");
	#endif
	  int no = selectDataNo(&s[0], curcount);
	  if (no==0){
		printf("=>취소됨!\n");
		continue;
	}
	  else {
	#ifdef DEBUG
	printf("debug[main.c] : call updateProduct()\n");
	#endif
	  updateProduct(&s[no-1]);
	}
	}
	}
         
        else if (menu == 4){
	#ifdef DEBUG
	printf("debug[main.c] : call selectDataNo()\n");
	#endif
	  int no = selectDataNo(&s[0], curcount);
	  if (no == 0) {
		printf("=>취소됨!\n");
		continue;
		}
	  int deleteok;
	  printf("정말로 삭제하시겠습니까?(삭제:1)");
	  scanf("%d", &deleteok);
	  if (deleteok==1) {
	#ifdef DEBUG
	printf("debug[main.c] : call deleteProduct()\n");
	#endif
		if (deleteProduct(&s[no-1]))
		count--;
		}
   	 }
	else if (menu == 5) {
                 if (count == 0)
                 printf ("데이터가 없습니다!\n");
                 else
           	 saveData(s,curcount);
		}	

	}
    printf("종료됨!\n");
    return 0;

}
