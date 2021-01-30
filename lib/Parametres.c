#include <stdlib.h>
#include <stdio.h>

void generate(char name) {
	FILE *fichier;	
	fichier = fopen(name,"w");
	fprintf(fichier,"NAME : %s",name);
}

int main(int argc, char **argv) {
	printf("Quel est votre nom ?\n");
	char name[100];  
	scanf("%s",&name);
	generate(name);

}