#include <iostream>
#include "_conio.h"
#include <time.h>
#define DER 77
#define IZQ 75
#define ARR 72
#define ABJ 80
#define f 29
#define c 46

		using namespace std;

void imprimir(char mapa[f][c]);
void jugar(char mapa[f][c]);


int main(int argc, char** argv) {
	
		char mapa[f][c]={ 
							 "911111111111111111111191111111111111111111119",
							 "91                   191                   19",
							 "91 1111111 111111111 191 111111111 1111111 19",
					      	 "91 1999991 199999991 191 199999991 1999991 19",
							 "91 1111111 111111111 111 111111111 1111111 19",
							 "91                                         19",
							 "91 1111111 111 111111111111111 111 1111111 19",
							 "91 1111111 191 111111999111111 191 1111111 19",
						  	 "91         191      19991      191         19",
						 	 "9111111111 19111111 19991 11111191 1111111119",
							 "9999999991 19111111 11111 11111191 1999999999",
						     "9999999991 191                 191 1999999999",
							 "8111111111 111 111111191111111 111 1111111118",
							 "9              999999999999999              9",
							 "8111111111 111 111111191111111 111 1111111118",
							 "9999999991 191                 191 1999999999",
							 "9999999991 191 111111111111111 191 1999999999",
							 "9111111111 111 111111999111111 111 1111111119",
							 "91                  19991                  19",
							 "91 1111111 11111111 19991 11111111 1111111 19",
							 "91 1111191 11111111 11111 11111111 1911111 19",
						 	 "91     191                         191     19",
							 "911111 191 111 111111111111111 111 191 111119",
							 "911111 111 191 111111999111111 191 111 111119",
							 "91         191      19991      191         19",
							 "91 1111111119111111 19991 1111119111111111 19",
							 "91 1111111111111111 11111 1111111111111111 19",
							 "91                                         19",
						 	 "911111111111111111111111111111111111111111119"};
		gotoxy(15,10);
	 printf("PRESIONE UNA TECLA PARA JUGAR");
	 int tecla=getch();
	 system("cls");
 jugar(mapa);
}

void imprimir(char mapa[f][c]){
	int x,y;
	system("CLS");
	for(x=0;x<f;x++){
		printf("\n");
		for(y=0;y<c-1;y++){
			gotoxy(y,x);
			if(mapa[x][y]=='1')	
				printf("°");
			else if(mapa[x][y]=='8' && mapa[x][y]=='9')	
				printf(" ");
			else if(mapa[x][y]==' ')	
				printf(".");	
			else if(mapa[x][y]=='3')
				printf("*");			
		}
	}
}


void jugar(char mapa[f][c]){
	int tecla;
	int x=23,y=21;
	int p=0;
	int vidas=3;
	int aux=0;
	int i=22,j=13;
	int nube=0;
	char n='9';
	imprimir(mapa);

	gotoxy(x,y);
	printf("<");
				
    	srand(time(0));
	
	do{

	
		if(_kbhit())
			tecla=getch();
		
		
		if(tecla==DER){
		 		if(mapa[y][x+1]!='8' && mapa[y][x+1]!='1'){
					gotoxy(x,y); 
					cout<<" ";
				    x++;
					if(x==44 && y==13){
						x=1; y=13;
						mapa[y][x]; 
					}
					gotoxy(x,y); 
					printf("<");
				}
		}
				
		else if(tecla==IZQ){
			    if(mapa[y][x-1]!='1' && mapa[y][x-1]!='8'){
				    gotoxy(x,y); 
					printf(" ");
					x--;
					if(x==0 && y==13){
						x=44; y=13;
						mapa[y][x];
					}	
					gotoxy(x,y); 
					printf(">");
				}
		} 
			
		else if(tecla==ARR){
		    	if(mapa[y-1][x]!='1' && mapa[y-1][x]!='8'){
				    gotoxy(x,y); 
					printf(" ");
					y--;	
					gotoxy(x,y); 
					printf("V");
				}	
		}
		
		else if(tecla==ABJ){
				if(mapa[y+1][x]!='1' && mapa[y+1][x]!='8'){
					gotoxy(x,y);
					printf(" ");
					y++;	
					gotoxy(x,y);
    				printf("^");			
				}
	 	}
	 	
		if(mapa[y][x]==' '){
				gotoxy(50,10);
				printf("****************");
				gotoxy(50,11);
				printf("*              *");
				gotoxy(50,12);
				printf("* Puntos: %3d  *",p);
				p++;
				gotoxy(50,13);
				printf("*              *");
				gotoxy(50,15);
				printf("*              *");
				gotoxy(50,16);
				printf("****************");
				mapa[y][x]='9';
		}
		
		if(vidas!=0){
			gotoxy(50,14);
			printf("* Vidas: %d     *",vidas);	
			gotoxy(50,17);
			printf("fp=%d - cp=%d - ff=%d - cf=%d ",y,x,j,i);		
		}	
		
		
	    
	   if(nube==5){
	   	
	   
	    if(j<y){
			//abj	
	    	if(mapa[j+1][i]!='1' && mapa[j+1][i]!='8'){		
				gotoxy(i,j);
				printf(" ");
				j++;
				gotoxy(i,j);	
				printf("*"); 
			}		
		}
	    
		
		if(j>y){
	    	//arr
	    	if(mapa[j-1][i]!='1' && mapa[j-1][i]!='8'){		
				gotoxy(i,j);
				printf(" ");
				j--;
				gotoxy(i,j);	
				printf("*");
			}
	    	
		}
		
	    if(j==y){
	    	if(i>x){
				//izq
		   	  if(mapa[j][i-1]!='1' && mapa[j][i-1]!='8'){
			   	  gotoxy(i,j);
			 	  printf(" ");
			      i--;
			   	  gotoxy(i,j);
				  printf("*");
			     }		
			}
	       if(i<x){
	       		//der
		    	if(mapa[j][i+1]!='1' && mapa[j][i+1]!='8'){
					
					gotoxy(i,j);
					printf(" ");
			 		i++;
			 		gotoxy(i,j);
			 		printf("*");
				}		
		   }
		}
	    
		    if(i<x){
		    	//der
	    		if(mapa[j][i+1]!='1' && mapa[j][i+1]!='8'){
					
					gotoxy(i,j);
					printf(" ");
			 		i++;
			 		gotoxy(i,j);
			 		printf("*");
				}		
	    	
			}
	        if(i>x){
	        	//izq
				if(mapa[j][i-1]!='1' && mapa[j][i-1]!='8'){
				 	gotoxy(i,j);
			 		printf(" ");
					 i--;
			 		gotoxy(i,j);
					 printf("*");
				}		
			}
	    	if(i==x){
	    		if(j<y){	
	   				//abj
			   	 	if(mapa[j+1][i]!='1' && mapa[j+1][i]!='8'){		
							gotoxy(i,j);
							printf(" ");
							j++;
							gotoxy(i,j);	
							printf("*");
					}		
				}
	    	  if(j>y){
	    		//arr
				if(mapa[j-1][i]!='1' && mapa[j-1][i]!='8'){		
							gotoxy(i,j);
							printf(" ");
							j--;
							gotoxy(i,j);	
							printf("*");
				}
	    	
			 }
	    		
			}
			nube=0;
			}//nube
					
		if(nube!=5){			
		nube++; 
		 aux=rand()%4;
	   
		//arr
		if(aux==0){
				
			if(mapa[j-1][i]!='1' && mapa[j-1][i]!='8'){		
			gotoxy(i,j);
			printf(" ");
			j--;
			gotoxy(i,j);	
			printf("*");
			}
		}
	
		//abj	
		if(aux==1){
			if(mapa[j+1][i]!='1' && mapa[j+1][i]!='8'){		
			gotoxy(i,j);
			printf(" ");
			j++;
			gotoxy(i,j);	
			printf("*");
			}
			
		}
		
		//izq
		if(aux==2){
			 if(mapa[j][i-1]!='1' && mapa[j][i-1]!='8'){
			 gotoxy(i,j);
			 printf(" ");
			 i--;
			 gotoxy(i,j);
			 printf("*");
			 }
		}
		
		//der
		if(aux==3){
			if(mapa[j][i+1]!='1' && mapa[j][i+1]!='8'){
			 gotoxy(i,j);
			 printf(" ");
			 i++;
			 gotoxy(i,j);
			 printf("*");
			 }
		}
		
		}
	
		if(x==i && y==j){
			vidas--;
			x=23; y=21;
			
		}

		Sleep(70);
	}while(vidas!=0 && p!=400);
	
	while(p==400){
			system("cls");
			gotoxy(15,10);
			printf("GANASTE!!!!");
			tecla=getch();
		
	}
		
	system("cls");
	gotoxy(15,10);
	printf("GAME OVER");
	fflush(stdin);
	tecla=getch();
			
}
