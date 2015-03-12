#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int data;
	struct list *next;
}list_type;

int list_size(list_type *headfun){
	int counter=0;
	while(headfun){ 	//while(headfun!=NULL){
		counter++;
		headfun=headfun->next;
	}
	return counter;
}

void print_list(list_type *headfun){
	int counter=0;
	printf("----------\n");
	while(headfun){
		counter++;
		printf("%d. %d\n", counter, headfun->data);
		headfun= headfun->next;
	}
	printf("----------");
	printf("\n\n");
}

list_type *addfront(list_type *headfun){
	list_type *p;
	p = malloc(sizeof(list_type));
	printf("type int:");
	scanf_s("%d", &p->data);
	p->next = headfun;

	return p;
}

list_type *add_beforepos(list_type *headfun){
	list_type *p=headfun;
	list_type *e=headfun;
	int n,i;

	printf("podaj nr elementu PRZED ktorym ma byc dodany kolejny: ");
	scanf_s("%d", &n);
	for(i=1; i<n; i++){
		e=e->next;
	}
	if(p==e){ //zwykle wstawianie na poczatek,  czyli przy podaniu n=1
		p=malloc(sizeof(list_type));
		printf("type int:");
		scanf_s("%d", &p->data);
		p->next=headfun; //bo wstawianie PRZED pierwszym elementem, czyli przed head'em
		headfun=p; //ustawienie listy na nowy poczatek
		//free(p);
	}else{
		while((p->next)!=e){
			p=p->next;
		}
		p->next=malloc(sizeof(list_type));
		p->next->next=e;
		printf("type int:");
		scanf_s("%d", &p->next->data);

	}
	return headfun;
}

list_type *add_afterpos(list_type *headfun){
	list_type *p;
	list_type *e=headfun; //e- element ZA ktorym bedziemy dodawac dany element
	int i, n;
	p = malloc(sizeof(list_type));
	printf("podaj nr elementu ZA ktorym ma byc dodany kolejny: ");
	scanf_s("%d", &n);
	printf("type int:");
	scanf_s("%d", &p->data);
	for(i=1; i<n; i++){
		e=e->next;
	}
	if(headfun!=NULL){
		p->next=e->next; //wczepiamy nowy element "p" gdzies w srodek listy
		e->next=p; //wczepiamy cd.
	}else{
		headfun=p;
		p->next=NULL;
	}
	return headfun;
}

list_type *add_afterVAR(list_type *headfun){ //lub podanie wartosci elementu (list_type *headfun, int n) przykladowo
	list_type *p=NULL;
	list_type *e=headfun;
	int n,temp;
	printf("podaj wartosc elementu ZA ktorym ma byc dodany kolejny: ");
	scanf_s("%d", &n);
	printf("type int:");
	scanf_s("%d", &temp);
	if(headfun!=NULL){
		while((e->next)!=NULL){
			if((e->data)==n){
				p=malloc(sizeof(list_type));
				//printf("type int:");
				//scanf_s("%d", &p->data);
				p->next=e->next;
				e->next=p;
				p->data=temp;
			}
			e=e->next;
		}
	}
	return headfun;
}

list_type *addback(list_type *headfun){
	list_type *p, *e;
	e = malloc(sizeof(list_type));
	e->next=NULL;
	printf("type int:");
	scanf_s("%d", &e->data);
	p=NULL;
	p=headfun;
	if(p!=NULL){
		while((p->next)!=NULL){
			p=p->next;
		}
		p->next=e;
	}else(headfun=e); //+ mozna dodac free(e) chyba
	return headfun;
}

list_type *delfront(list_type *headfun){  //void delfront(list_type **headfun) to dziala caly czas na tej samej pamieci, w pierwszym zapisie 
	//...list_type *delfront(list_type *headfun) nastepuje skopiowanie wartosci pamieci do funkcji, ktora nastepnie trzeba zwrocic i przypisac
	list_type *p; 
	p=headfun; //p- zapamietuje stary poczatek
	if(p!=NULL){
		headfun=p->next; //headfun- stary element->next, czyli poczatek jest w miejscu drugiego elementu
		free(p);
	}
	return headfun; //zwrocenie nowego poczatku
}

list_type *delback(list_type *headfun){
	list_type *p;
	p=headfun;
	if(p!=NULL){//jesli lista nie jest pusta
		if((p->next->next)!=NULL){ //wiecej niz jeden element
			while((p->next->next)!=NULL){ //pierwszy next jest ostatnim elementem, drugi next juz jest pusty, czyli po wykonaniu while program stoi na przedostatnim elemencie
				p=p->next; //przejscie z przedostatniego na ostatni element
			}
			free(p->next);
			p->next=NULL;
		}else{//dokladnie jeden element
			free(p);
			headfun=NULL;
		}
	
	}
	return headfun;
}

int main(){
	list_type *head=NULL;
	int n;
	do{
		n=menu();
		switch(n){
			case 1: head=addfront(head);
					break;
			case 2: head=addback(head);
					break;
			case 3:	head=add_beforepos(head);
					break;
			case 4:	head=add_afterpos(head);
					break;
			case 5:	head=add_afterVAR(head);
					break;
			case 6: head=delfront(head);
					break;
			case 7: head=delback(head);
					break;
			case 9: print_list(head);
					break;
			default: break;
		}
	}while(n!=0);
	system("PAUSE");
}

int menu(){
	int n;
	printf("1: dodaj na poczatek\n");
	printf("2: dodaj na koniec\n");
	printf("3: dodaj przed wybrana pozycja\n");
	printf("4: dodaj za wybrana pozycja\n");
	printf("5: dodaj za elementem o okreslonej wartosci\n");
	printf("6: usun z poczatku\n");
	printf("7: usun z konca\n");
	//printf("8: usun z wybranej pozycji");
	printf("9: drukuj liste\n");
	printf("0: wyjscie\n");
	printf("wybierz opcje:");
	scanf_s("%d", &n);
	printf("\n\n");
	return n;
}

//head-pierwszy
//tail- ostatni
//count- licznik

