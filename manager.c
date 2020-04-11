#include "manager.h"
void listProduct (Product *s, int count) {
	for (int i=0; i<count; i++) {
	if(s[i].price == -1) continue;
	printf("%3d번째 Product\n ", i+1);
	printf("**************");
	readProduct(s[i]);
}
printf("\n");
}
int selectDataNo (Product *s, int count) {
	int no;
	listProduct(s,count);
	printf("번호는 (취소:0)? ");
	scanf("%d",&no);
	return no;
}
