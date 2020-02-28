#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	//variables :
	int sockfd, longueur;
	int sock_resul;
	struct sockaddr_in adresse;
	int resultat;
	char ch='A';

	//initialiser le socket
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	//definition struct adresse
	adresse.sin_family = AF_INET;
	adresse.sin_addr.s_addr = inet_addr("127.0.0.1");
	adresse.sin_port = 9734;
	longueur=sizeof(adresse);

	//connexion
	resultat = bind(sockfd, (struct sockaddr *)&adresse, longueur);
	if (resultat == -1) {
		perror("ERREUR : SERVEUR");
		exit(1);
	}



		//reception données
		resultat = recvfrom(sockfd, &ch, 1, 0, (struct sockaddr *)&adresse, &longueur);
		if (resultat == -1) {
			perror("ERREUR : SERVEUR");
			exit(1);
		}
		printf("Caractère reçu par le serveur = %c (%d)\n", ch, resultat);

		//traitement de donnée
		ch++;

		//envoi données
		resultat = sendto(sockfd, &ch, 1, 0, (struct sockaddr *)&adresse, longueur);
		if (resultat == -1) {
			perror("ERREUR : SERVEUR");
			exit(1);
		}
		printf("Caractère envoyé par le serveur = %c (%d)\n", ch, resultat);



	//fermeture connexion
	close(sockfd);


	exit(0);
}
