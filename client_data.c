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
	sockclient = socket(AF_INET, SOCK_DGRAM, 0);

	//definition struct adresse
	adresse.sin_family = AF_INET;
	adresse.sin_addr.s_addr = inet_addr("127.0.0.1");
	adresse.sin_port = 9734;
	longueur=sizeof(adresse);

	//envoi données
	sendto(sockclient, &ch, 1, 0, (struct sockaddr *)&adresse, longueur);
	printf("Caractère envoyé par le client = %c\n", ch);



	//reception données
	recvfrom(sockclient, &ch, 1, 0, (struct sockaddr *)&adresse, &longueur);
	printf("Caractère reçu par le client = %c\n", ch);

	//fermeture connexion
	close(sockclient);

	exit(0);
}
