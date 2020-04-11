#include "manager.h"

int main(){
  Product s[100];
  int count = 0, menu;
  int curcount = 0;
  #ifdef DEBUG
  printf("debug[main.c] : call loadData()");
  #endif
  count = loadData(s);
  curcount = count;
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
		#ifdef DEBUG
		printf("debug[main.c] : call saveData()");
		#endif
           	 saveData(s,curcount);
		}	
	 else if (menu == 6) {
                int searchType = 0;
                printf("\n1. 제품명으로 검색\n");
                printf("2. 제품 가격으로 검색\n");
                printf("3. 제품 별개수로 검색\n");
                printf("   번호를 고르시오(취소:0) ");
                scanf("%d", &searchType);
                if (searchType==0) {
                printf("취소됨.\n");
                continue;
                }
                if (searchType==1) {
		#ifdef DEBUG
		printf("debug[main.c] : call searchByName()");
		#endif
                searchByName(s, curcount);
                }
                if (searchType==2) {
		#ifdef DEBUG
		printf("debug[main.c] : call searchByPrice()");
		#endif
                searchByPrice(s, curcount);
                }
                if (searchType==3) {
		#ifdef DEBUG
		printf("debug[main.c] : call searchByStar()");
		#endif
                searchByStar(s, curcount);
                }
		}


	}
    printf("종료됨!\n");
    return 0;

}
