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
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//definition struct adresse
	adresse.sin_family = AF_INET;
	adresse.sin_addr.s_addr = INADDR_ANY;
	printf("Adresse IP = %s\n", adresse.sin_addr.s_addr);
	printf("Adresse IP = %lu\n", adresse.sin_addr.s_addr);
	printf("Adresse IP = %llu\n", adresse.sin_addr.s_addr);
	adresse.sin_port = ntohs(INADDR_ANY);
	printf("Adresse Port = %d\n", htons(INADDR_ANY));
	longueur=sizeof(adresse);

	//connexion
	resultat = bind(sockfd, (struct sockaddr *)&adresse, longueur);
	if (resultat == -1) {
		perror("ERREUR : SERVEUR");
		exit(1);
	}


	int nbCo = 2;
	while(nbCo > 0){


		//écoute
		listen(sockfd, 1);
		nbCo--;

		//accept
		sock_resul = accept(sockfd, (struct sockaddr *)&adresse, &longueur);

		//reception données
		read(sock_resul, &ch, 1);
		printf("Caractère reçu par le serveur = %c\n", ch);

		//traitement de donnée
		ch++;
		
		//envoi données
		write(sock_resul, &ch, 1);
		printf("Caractère envoyé par le serveur = %c\n", ch);

		
	}

	//fermeture connexion
	close(sockfd);
	

	exit(0);
}
