#include <iostream>
#include <cstdlib> 
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200
using namespace std;

//variaveis globais

char nome [SIZE][50];
char sobrenome[SIZE][50];
char email[SIZE][50];
int matricula[SIZE];
char setor[SIZE][50];
int codsetor[SIZE];
int op; 

void cadastro();
void pesquisa();
void lista();


int main(void){
	setlocale(LC_ALL,"Portuguese");

	do{
		system("cls");
		printf("\n ///// MENU /////\n");
		printf("\n\n [1] Cadastrar \n\n [2] Listar todos \n\n [3] Pesquisar \n\n [4] Sair \n\n");
		scanf("%d",&op);
		switch(op){
			
			case 1:
				cadastro();
				break;	
				
			case 2:
				lista();
				break;
				
			case 3:
				pesquisa();
				break;
				
			case 4:
				system("exit");
				break;
				
			default:
				printf("\n Opção inválida!\n");
				getchar();
				getchar();
				break;
		}
		
	}while(op!=4);
	
}
void lista(){
	int i;
	system("cls");
	printf("\n ///// LISTA /////\n");
	for(i=0;i<SIZE;i++){
		if(matricula[i]>0){
			printf("\n Nome: %s %s\n Mátricula: %d\n Setor: %s\n Email: %s\n", nome[i],sobrenome[i],matricula[i],setor[i],email[i]);
		}else{
			break;
		}
	}
	printf("\n Pressione qualquer tecla para voltar. ");
	getchar();
	getchar();
}
void cadastro(){
	static int linha;
	do{
		system("cls");
		printf("\n ////// CADASTRO //////\n");
		printf("\n Nome: ");
		scanf("%s",&nome[linha]);
		fflush(stdin);
		
		printf("\n Sobrenome: ");
		scanf("%s",&sobrenome[linha]);
		fflush(stdin);
		
		printf("\n Número da matrícula: ");
		scanf("%d",&matricula[linha]);
		fflush(stdin);
		
		printf("\n Código do setor: ");
		scanf("%d",&codsetor[linha]);
		fflush(stdin);
		
		printf("\n Nome do setor: ");
		scanf("%s",&setor[linha]);
		fflush(stdin);
		
		printf("\n Digite seu email: ");
		scanf("%s",&email[linha]);
		fflush(stdin);
	
		printf("\n [1] Continuar cadastro \n [2] Voltar para Menu Principal \n");
		scanf("%d",&op);
		fflush(stdin);
		linha++;
		while(op>2){
			printf("\n Opção inválida! Digite novamente: \n");
			printf("\n [1] Continuar cadastro \n [2] Voltar para Menu Principal \n");
			scanf("%d",&op);
			fflush(stdin);
		}
	}while(op==1);
}
void pesquisa(){
	int i,matriculapesq,codsetorpesq;
	do{
	system("cls");
	printf("\n /////////// PESQUISA ///////////\n");
	printf("\n [1] Pesquisa por número da matrícula");
	printf("\n [2] Pesquisa por código do setor\n");
	scanf("%d",&op);
	fflush(stdin);
	
	switch(op){
		case 1:
			printf("\n -> Informe o número da matrícula: ");
			scanf("%d",&matriculapesq);
			fflush(stdin);
			for(i=0;i<SIZE;i++){
					if(matricula[i]==matriculapesq){
						printf("\n Nome: %s %s\n Mátricula: %d\n Setor: %s\n Email: %s\n\n", nome[i],sobrenome[i],matricula[i],setor[i],email[i]);
					}else{
						printf("\n Mátricula não encontrada!\n");
					}break;
			}
			break;
		case 2:
			printf("\n -> Informe o código do setor: ");
			scanf("%d",&codsetorpesq);
			fflush(stdin);
			for(i=0;i<SIZE;i++){
				if(codsetor[i]==codsetorpesq){
					printf("\n Nome: %s %s\n Mátricula: %d\n Setor: %s\n Email: %s\n\n", nome[i],sobrenome[i],matricula[i],setor[i],email[i]);
				}else if (codsetor[i]!=codsetorpesq){
					printf("\n Código não encontrado!\n");
				}break;
			}
			break;
		default:
			printf("\n Opção inválida.\n");
			break;
	}
		printf("\n [1] Continuar pesquisa");
		printf("\n [2] Voltar para Menu Principal\n");
		scanf("%d",&op);
					
	}while(op==1);
	
}
