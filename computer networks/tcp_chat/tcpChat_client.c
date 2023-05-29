#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
int main()
{
	struct sockaddr_in address;
	int sfd,slen,result;
	char name[100];
	sfd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_port=8800;
	address.sin_addr.s_addr= htonl(INADDR_ANY);
	slen=sizeof(address);
	result=connect(sfd,(struct sockaddr*)&address,slen);
	while(1){
	printf("Enter the message: ");
	gets(name);
	write(sfd,name,sizeof(name));
	read(sfd,name,sizeof(name));
	printf("\nReading from server:  \n");
	puts(name);
	
	}
	return 0;
}


