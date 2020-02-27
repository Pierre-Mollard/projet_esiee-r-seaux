#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	//variables : 
	int sockclient, longueur;
	struct sockaddr_in adresse;
	int resultat;
	char ch='A';

	//initialiser le socket
	sockclient = socket(AF_INET, SOCK_STREAM, 0);

	//definition struct adresse
	adresse.sin_family = AF_INET;
	adresse.sin_addr.s_addr = INADDR_ANY;
	adresse.sin_port = ntohs(INADDR_ANY);
	longueur=sizeof(adresse);

	//connexion
	resultat = connect(sockclient, (struct sockaddr *)&adresse, longueur);
	if (resultat == -1) {
		perror("ERREUR : CLIENT");
		exit(1);
	}

	//envoi données
	write(sockclient, &ch, 1);
	printf("Caractère envoyé par le client = %c\n", ch);

		

	//reception données
	read(sockclient, &ch, 1);
	printf("Caractère reçu par le client = %c\n", ch);

	//fermeture connexion
	close(sockclient);

	exit(0);
}
