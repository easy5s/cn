#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>

int main(){
	struct sockaddr_in saddr,caddr;
	int sfd,cfd,slen,clen;
	char a[100],b[100];
	saddr.sin_family=AF_INET;
	saddr.sin_port=8800;
	saddr.sin_addr.s_addr= htonl(INADDR_ANY);
	slen=sizeof(saddr);
	sfd=socket(AF_INET,SOCK_STREAM,0);
	bind(sfd,(struct sockaddr*)&saddr,slen);
	listen(sfd,1);
	printf("SERVER IS WAITING\n");
	clen=sizeof(caddr);
	cfd=accept(sfd,(struct sockaddr*)&caddr,&clen);
	printf("\nConnect to client\n");
	while(1){
		
		read(cfd,a,sizeof(a));
		printf("\nReading message from client: ");
		puts(a);
		printf("\nMessage send to client: ");
		gets(b);
		write(cfd,b,sizeof(b));
		
		
	}
	return 0;
}

