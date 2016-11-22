#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#define n 30

struct Jugadores{
	
	char Nombre[30];
	char Correo[30];
	char Contrasenia[15];	
	
};

int p=0;
char Lab[30][30];
Jugadores *A;
int reg=0;
char NameStems[][12]={"Pikachu", "Charmander", "Bulbasaur", "Squirtle", "Gengar", "Caterpie", "Weedle", "Pidgey", "Rattata", "Vulpix"};
//A=(Jugadores*)malloc(100*sizeof(Jugadores));	
void NameGen(char *PlayerName);
void registro();
void iniciarSesion();
void opc();
void juego();
void puntuacion();

int main(){
	
	int **B;
	int opcion;
	//int reg=0;
	//int n;
	//char Correo[30], Contrasenia[15];
	//Jugadores *A;
	
	A=(Jugadores*)malloc(100*sizeof(Jugadores));	
	
	do{
		
		system("cls");
		printf("Bienvenido a Pokemon Ball");
		printf("\n1.- Iniciar Sesion");
		printf("\n2.- Registrarse");
		printf("\n3.- Salir");
		printf("\n");
		fflush(stdin);
		scanf("%d",&opcion);
		
		switch(opcion){
			
			case 1:
				iniciarSesion();
				break;

			case 2:
				registro();			
				break;
		}
		
	}while(opcion!=3);
	
}

void registro(){
	
	//Jugadores *A;
	//A=(Jugadores*)malloc(100*sizeof(Jugadores));
	//int reg=0;
	system("cls");
	if(reg==100){
		printf("Ya no hay memoria para registros");
		printf("\n");
		system("PAUSE");
	}
	else{
		for(int i=reg;i<100;i++){
			fflush(stdin);
			printf("Nombre: ");
			scanf("%s",&A[i].Nombre);
			printf("Correo Electronico: ");
			scanf("%s",&A[i].Correo);
			printf("Contrasenia: ");
			scanf("%s",&A[i].Contrasenia);
			reg++;
			break;
		}
	}
}

void iniciarSesion(){
	
	//int n;
	char Correo[30], Contrasenia[15];
	
	system("cls");
	fflush(stdin);
	printf("Correo Electronico: ");
	gets(Correo);
	for(int i=0;i<100;i++){
		if(strcmp(Correo,A[i].Correo)==0){
			printf("Contrasenia: ");
			gets(Contrasenia);
			if(strcmp(Contrasenia,A[i].Contrasenia)==0){
				system("cls");
				printf("Bienvenido %s\n",A[i].Nombre);
				system("PAUSE");
				//printf("Presiona una tecla para continuar");
				//getchar();
				opc();
				//printf("\n");
				//juego();
			}
		}
	}
}

void opc(){
	
	int opcion=0;
	//do{
		system("cls");
		printf("Menu");
		printf("\n1.- Jugar");
		printf("\n2.- Ver puntuacion");
		printf("\n3.- Salir");
		printf("\n");
		fflush(stdin);
		scanf("%d",&opcion);
		
		switch(opcion){
			
			case 1:
				juego();
				break;

			case 2:
				puntuacion();
				break;		
			
			case 3:
				break;
				
		}
	//}while(opcion!=3);
}

void puntuacion(){

system("cls");
printf("%d PX ",p);
printf("\n");
system("PAUSE");	
	
}

void NameGen(char* PlayerName){

    PlayerName[0]=0;


    strcat(PlayerName, NameStems[(rand() % 10)]);


   	PlayerName[0]=toupper(PlayerName[0]);

    return;

}

void juego(){
	
	srand(time(NULL));
	int i,j,f,c;
	char Player1Name[12];
	//int PC=rand()%400;
	
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
    		Lab[i][j]=' ';
    	
	for(i=0;i<30;i++)
		Lab[i][0]='X';
    
    for(j=0;j<30;j++)
		Lab[0][j]='X';
			
	for(i=0;i<30;i++)
		Lab[i][30]='X';

	for(j=0;j<30;j++)
		Lab[30][j]='X';
	
			
	Lab[3][4]=Lab[4][5]=Lab[2][11]=Lab[24][13]=Lab[18][27]=Lab[27][18]=Lab[21][10]=Lab[8][16]=Lab[6][7]=Lab[19][11]=Lab[23][17]=Lab[17][28]='P';

   	int elemento,b=0;
   	char opcion;

    i=1,j=1;//Coordenadas de inicio

	do{
 		  	
    	printf("Presiona Esc para salir del juego. Presiona flecha arriba, abajo, derecha o izquierda.\n");
      	fflush(stdin);
      	opcion=getch();
      
      	switch ( opcion ){
      	
        	case 72:
         		i--;
        		system("cls");
         		printf("Estas en la coordenada %i %i\n",i,j);  
         		if(Lab[i][j]=='X'){
      				printf("intenta de nuevo\n");
         			i++;    
      				Lab[i][j]='X';
         			break;                  
            	}
				else if(Lab[i][j]=='P'){
					NameGen(Player1Name);
      				printf("Haz encontrado un %s de %d PC\n", Player1Name,rand()%400);
      				p++;
         			i++;
      
      				Lab[i][j]='P';
      
         		break;                  
                } 	         
            	
        		else if(Lab[i][j]==' '||Lab[i][j]=='0'){
         			Lab[i][j]='*';
         			Lab[i+1][j]='0';
    	     		break;
        	 	}
 
         	case 80:
            	i++;
            	system("cls");
         		printf("Estas en la coordenada %i %i\n",i,j); 
	            if(Lab[i][j]=='X'){
    	        	printf("intenta de nuevo\n");
        	    	i--;                  
    
      				Lab[i][j]='X';
         		break;                  
            	}
				else if(Lab[i][j]=='P'){
					NameGen(Player1Name);
      				printf("Haz encontrado un %s de %d PC\n", Player1Name,rand()%400);
         			p++;
    				i++;  
      				Lab[i][j]='P';
      
         		break;                  
                }         
            	
         		else if(Lab[i][j]==' '||Lab[i][j]=='0'){
         			Lab[i][j]='*';
         			Lab[i-1][j]='0';
         		break;
         		}
         
         	case 75:
     	    	j--;
     	    	system("cls");
         		printf("Estas en la coordenada %i %i\n",i,j); 
        	 	if(Lab[i][j]=='X'){
      				printf("intenta de nuevo\n");
   		      		j++;                  
    	  			Lab[i][j]='X';
         		break;                  
         		
      			}
				else if(Lab[i][j]=='P'){
					NameGen(Player1Name);
      				printf("Haz encontrado un %s de %d PC\n", Player1Name,rand()%400);
         			p++;
      				i++;
      				Lab[i][j]='P';
      
         		break;                  
                } 	         
         		else if(Lab[i][j]==' '||Lab[i][j]=='0'){
         			Lab[i][j]='*';
         			Lab[i][j+1]='0';
         		break;
         		}
         
         	case 77:
        	    j++;
    			system("cls");
         		printf("Estas en la coordenada %i %i\n",i,j); 
         		if(Lab[i][j]=='X'){
      				printf("intenta de nuevo\n");
         			j--;                  
				    Lab[i][j]='X';
        		break;                  
            	}
				else if(Lab[i][j]=='P'){
					NameGen(Player1Name);
      				printf("Haz encontrado un %s de %d PC\n", Player1Name,rand()%400);
         			p++;
      				i++;
      				Lab[i][j]='P';
      
         		break;                  
                }         
            	
        		else if(Lab[i][j]==' '||Lab[i][j]=='0'){
         			Lab[i][j]='*';

        			Lab[i][j-1]='0';
         		break;
         		}
        
            
		}
   }while(opcion!=27);
   opc();
	
}
