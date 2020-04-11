#include <stdio.h> //표준 라이브러리가 필요하기에 선언한 헤더.
#include <string.h> //strstr 함수를 사용하기 위해 선언한 헤더.

typedef struct { //typedef를 선언함으로 그 후에 struct를 매번 작성을 안할 수 있게한다.
    char name[20]; //제품의 이름을 문자열로 받기 위한 배열.
    int mass; //제품의 중량을 저장하는 int형 멤버변수.
    int price; //제품의 가격을 저장하는 int형 멤버변수.
    double stdPrice; //제품의 표준가격을 저장하는double형 멤버변수.
    int star; //제품의 별 수를 저장하는 int형 멤버변수.
} Product; //제품의 관한 구조체를 Product라는 타입을 선언.

int selectMenu(); //가장 처음에 출력화면을 나타내어 가능한 기능들을 정렬해서 메뉴판처럼 보여주는 함수. 
int addProduct(Product *s); //제품을 추가하기 위한 Create 함수.
void readProduct(Product s); //제품을 읽기 위한 Read 함수.
int updateProduct(Product *s); //제품의 내용을 수정하는 Update 함수.
int deleteProduct(Product *s); //제품의 내용을 삭제하는 Delete 함수.
void saveData(Product *s, int count); //제품의 정보가 생성된 것을 텍스트 파일로 저장하는 함수.
int loadData(Product *s); //저장된 텍스트 파일을 불러오는 함수.
void searchByName(Product *s, int count); //검색 기능 중에 제품 이름으로 검색하는 함수.
void searchByPrice(Product *s, int count); //제품의 가격으로 검색하는 함수.
void searchByStar(Product *s, int count); //제품의 별 수로 검색하는 함수.
 // 등록되어 있는 제품의 관한 정보를 정렬해서 출력하는 함수.
 //Update Delete 함수에서 몇번째 index의 제품을 선택할 지 나타내는 함수.
