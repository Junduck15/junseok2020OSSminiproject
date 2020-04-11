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

