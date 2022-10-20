#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

void PrimeiraEtapa(char frase[]){
	int i;
	char troca;
	for (i = 0; frase[i] != '\0'; i++){	
		if(frase[i] == 'a'){
			frase[i] = '@';
		}
		else if (frase[i] == 'o'){
			frase[i] = '0';
		}
		else if (frase[i] == '@'){
			frase[i] = 'a';
		}
		else if (frase[i] == '0'){
			frase[i] = 'o';
		} 
	}
}

void SegundaEtapa(char frase[],char par[], char impar[]){
	int i,p,imp,contador;
	char parInv[200];
	p = 0;
	imp = 0;
	contador = 0;
	
	for (i = 0; frase[i]!= '\0'; i = i+2){
		impar[imp] = frase[i];
		imp++;
	}
	
	for(i = 1; frase[i]!='\0'; i = i+2){
		parInv[p] = frase[i];
		p++;
	}
	
	for(i = p-1; i>=0; i--){
		par[contador] = parInv[i];
		contador++;
	}
	
	par[p+1] = '\0';
	impar[contador+1] = '\0';
}

void TerceiraEtapa(char crip[],char par[],char impar[]){
	int i;
	int a = 0;
	for(i = 0;par[i] != NULL || impar[i] != NULL; i++){
		crip[a] = impar[i];
		a++;
		crip[a] = par[i];
		a++;
		
	}
}

void Descriptografar(char frase[],char crip[], char par[],char impar[]){
	setbuf(stdin, NULL);
	printf("\nDigite a frase:");
	scanf ("%199[^\n]s", frase);
	PrimeiraEtapa(frase);
	printf("\nA frase: %s",frase);
	SegundaEtapa(frase,par,impar);
	printf("\n%s",par);
	printf("\n%s",impar);
	TerceiraEtapa(crip,par,impar);
	printf("\nMensagem Descriptografada:%s",crip);	
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	char frase[200];
	memset(&frase,0,200);
	char par[200],impar[200];
	memset(&par,0,200);
	memset(&impar,0,200);
	char crip[200];
	memset(&crip,0,200);


	
	printf("Digite a frase:");
	scanf ("%199[^\n]s", frase);
	PrimeiraEtapa(frase);
	printf("A frase: %s",frase);
	SegundaEtapa(frase,par,impar);
	printf("\nSegunda Etapa:%s",par);
	printf("\nSegunda Etapa:%s",impar);
	TerceiraEtapa(crip,par,impar);
	printf("\nMensagem Criptografada:%s",crip);
	
	Descriptografar(frase,crip,par,impar);
	
	
	
	

	
	
	
}
