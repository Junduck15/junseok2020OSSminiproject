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

void saveData (Product*s, int count) {
        FILE *fp;
        fp = fopen("menu.txt","wt");

        for(int i =0; i<count; i++){
                if (s[i].price !=-1)
                fprintf(fp,"%d %d %f %d %s\n", s[i].price, s[i].mass, s[i].stdPrice, s[i].star, s[i].name);
        }
}
int loadData (Product*s) {
        int count = 0;
        FILE *fp;
        fp = fopen("menu.txt","rt");
        if(fp==NULL){
        printf("=>No File \n");
        return 0;
        }
        for (;;count++){
        fscanf(fp,"%d %d %f %d %[^\n]s", &s[count].price, &s[count].mass, &s[count].stdPrice, &s[count].star, s[count].name);

        if (feof(fp)) break;
}
        fclose(fp);
        printf("Load Success\n");
        return count;
}
void searchByName (Product *s, int count) {
        int scount =0;
        char search[40];
        printf("검색할 제품의 제품명은? ");
        scanf("\n %[^\n]s", search);
	getchar();
        for (int i =0; i<count; i++){
        if (s[i].price!=-1){
                if(strstr(s[i].name,search)){
                printf("\n %s의 정보", s[i].name);
                readProduct(s[i]);
                printf("\n");
                scount++;
                }
        }
}
        if (scount == 0) printf("=>검색된 데이터가 없음 \n");
}
void searchByPrice (Product *s, int count) {
        int scount =0;
        int search = 0;
        printf("검색할 메뉴의 가격은?");
        scanf("%d", &search);

        for (int i =0; i<count; i++){
        if (s[i].price!=-1){
                if(s[i].price == search){
                printf("\n%s의 정보", s[i].name);
                readProduct(s[i]);
                printf("\n");
                scount++;
                }
        }
}
        if (scount == 0) printf("=>검색된 데이터가 없음 \n");
}
void searchByStar (Product *s, int count) {
        int scount =0;
        int search = 0;
        printf("검색할 메뉴의 별개수는?");
        scanf("%d", &search);

        for (int i =0; i<count; i++){
        if (s[i].price!=-1){
                if(s[i].star == search){
                printf("\n%s의 정보\n", s[i].name);
                readProduct(s[i]);
printf("\n");
                scount++;
                }
        }
}
        if (scount == 0) printf("=>검색된 데이터가 없음 \n");

}

