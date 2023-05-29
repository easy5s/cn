#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>

int main()
{
	struct sockaddr_in saddr;
	int sfd,slen;
	char a[100],b[100];
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	saddr.sin_family=AF_INET;
	saddr.sin_port=8880;
	saddr.sin_addr.s_addr= htonl(INADDR_ANY);
	slen=sizeof(saddr);
	bind(sfd,(struct sockaddr_in *)&saddr,slen);
	
	while(1){
		printf("Waiting for message \n");
		recvfrom(sfd,&a,sizeof(a),0,(struct sockaddr_in *)&saddr,&slen);
		printf("message from client is \n");
		puts(a);
		printf("Enter  message to client \n");
		gets(b);
		sendto(sfd,&b,sizeof(b),0,(struct sockaddr_in *)&saddr,slen);
	}
	return 0;
}

	
