#include <stdio.h>
#include<stdlib.h>


// Dugum dizayn edilmesi

struct Dugum {
      int data;
      struct Dugum* ileri;
    };

typedef struct Dugum Dugum;    
typedef struct Dugum* DugumPointer;

//Liste Tasarimi
struct liste{
	DugumPointer bas;
	DugumPointer son;
};
typedef struct liste Liste;
typedef Liste* Listeptr;


//tek yonlu bos bagli liste olusturma
Listeptr newList(){
	Listeptr liste=(Listeptr)malloc(sizeof(Liste));
	liste->bas=NULL;
	liste->son=NULL;
	return liste;
}

//listenin basina eleman ekleme O(1)
void addHead(Listeptr liste, DugumPointer dugum){
	if(liste->son==NULL)
		liste->son=dugum;
	dugum->ileri=liste->bas;
	liste->bas=dugum;
}

//listenin sonuna ekleme
void addTailer(Listeptr liste, DugumPointer node){
	if(liste->bas==NULL)
		liste->bas=node;
	else
		liste->son->ileri=node;
	liste->son=node;
}

//listede istenilden bir dügümden sonra eleman ekleme O(1)
void addMiddle(DugumPointer prevNode, DugumPointer newNode){
	newNode->ileri=prevNode->ileri;
	prevNode->ileri=newNode;
}

int listSize(Listeptr liste){
	DugumPointer temp=liste->bas;
	int sayac=0;
	while(temp){
		sayac++;
		temp=temp->ileri;
	}
	return sayac;
}
 
void addMiddle2(Listeptr liste, DugumPointer node){
	DugumPointer temp=liste->bas;
	int boyut=listSize(liste);
	int middle=boyut/2-1;
	for(int i=0;i<middle;i++){
		temp=temp->ileri;
	}
	node->ileri=temp->ileri;
	temp->ileri=node;	
	//printf("ortasi %d \n", temp->data);
}

//listede eleman arama
DugumPointer listSearch(Listeptr liste, int value){
	DugumPointer temp=liste->bas;
	while(temp){
		if(temp->data==value)
			return temp;
		temp=temp->ileri;
	}
	return NULL;
}

//listeden istenilen syradaki elemany getiren fonk
DugumPointer listSearch2(Listeptr liste, int value){
	DugumPointer temp=liste->bas;
	for(int i=0; i<value; i++)
		temp=temp->ileri;
	//printf("x. eleman %d \n", temp->data);
	return temp;
}

//listenin ba?yndan eleman silme
void removeHead(Listeptr liste){
	if(liste->bas != NULL)
		liste->bas=liste->bas->ileri;
	if(liste->bas == NULL)
		liste->son==NULL;
}

//listenin son elemany silme
void removeTailer(Listeptr liste){
	DugumPointer temp, once;
	temp=liste->bas;
	once=NULL;
	while(temp->ileri!=NULL){
		once=temp;
		temp=temp->ileri;
	}
	//printf("neredeyim %d ", temp->data);
	if(once==NULL)
		liste->bas=NULL;
	else
		once->ileri=NULL;
	liste->son=once;
}

//listenin tam ortasyndaki elemany silme
void removeMiddle(Listeptr liste){
	DugumPointer temp, once;
	temp=liste->bas;
	once=NULL;
	int middle=listSize(liste)/2;
	for(int i=0;i<middle;i++){
		once=temp;
		temp=temp->ileri;
	}
	//printf("neredeyim %d ", temp->data);
	once->ileri=temp->ileri;
}
//shallow copy
//deep copy???
Listeptr mergeList(Listeptr l1, Listeptr l2){
	if(l1->bas==NULL)
		return l2;
	if(l2->bas=NULL)
		return l1;
	Listeptr liste3=(Listeptr)malloc(sizeof(Liste));
	liste3->bas=l1->bas;
	liste3->son=l2->son;
	l1->son->ileri=l2->bas;
	return liste3;
}	
	
//listeyi yazdyr
void show(Listeptr liste){
	DugumPointer temp = liste->bas;
	while(temp){
		printf("%d --> ", temp->data);
		temp=temp->ileri;
	}
}
int main(){
	DugumPointer n1, n2, n3, n4, n5, n6;
	n1 = newNode(10);
	n2 = newNode(20);
	n3 = newNode(30);
	n4 = newNode(40);
	n5 = newNode(50);
	n6 = newNode(60);
	Listeptr liste1, liste2, liste3;
	liste1=newList();
	liste2=newList();
	addHead(liste1, n1);
	addHead(liste1, n2);
	addHead(liste1, n3);
	addTailer(liste2, n4);
	addTailer(liste2, n5);
	addTailer(liste2, n6);
	//addTailer(liste1, n5);
	//addMiddle(n1, n5); O(1)
	//addMiddle2(liste1, n5);
	/*
	int sayi=listSize(liste1);
	printf("liste eleman sayisi: %d ", sayi);
	*/
	/*
	if(listSearch(liste1, 300))
		printf("Aranan dugum bulundu\n");
	else 
		printf("Aranan dugum bulunamadi\n");
	*/
	//listSearch2(liste1, 3);
	//removeHead(liste1);
	//removeTailer(liste1);
	//removeMiddle(liste1);
	show(liste1);
	printf("\n");
	show(liste2);
	printf("\n");
	liste3=mergeList(liste1, liste2);
	show(liste3);
	printf("\n");
	show(liste1);
	//ödev iki listenin yapısı bozulmadan yeni bir liste oluşturma
	return 0;
}