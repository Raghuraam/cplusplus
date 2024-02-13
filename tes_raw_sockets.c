#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<signal.h>
#include<stdbool.h>
#include<sys/socket.h>
#include<sys/types.h>

#include<linux/if_packet.h>
#include<netinet/in.h>		 
#include<netinet/if_ether.h>    // for ethernet header
#include<netinet/ip.h>		// for ip header
#include<netinet/udp.h>		// for udp header
#include<netinet/tcp.h>
#include<arpa/inet.h>           // to avoid warning at inet_ntoa


int main()
{
	
	int sock_r,saddr_len,buflen;
	struct sockaddr saddr;
	FILE* log_txt;
	int count =0;

	unsigned char* buffer = (unsigned char *)malloc(65536); 
	memset(buffer,0,65536);
	
	log_txt=fopen("log.txt","w");
	if(!log_txt)
	{
		printf("unable to open log.txt\n");
		return -1;

	}

	printf("starting .... \n");
	// open raw socket
	sock_r=socket(AF_PACKET,SOCK_RAW,htons(ETH_P_ALL)); 
	
	while(1)
	{
		saddr_len=sizeof saddr;
		buflen=recvfrom(sock_r,buffer,65536,0,&saddr,(socklen_t *)&saddr_len); // need sudo access

		if(buflen<0)
		{
			printf("error in reading recvfrom function\n");
			return -1;
		}
		
		struct ethhdr *eth = (struct ethhdr *)(buffer); // eth layer
		struct iphdr *ip = (struct iphdr*)(buffer + sizeof(struct ethhdr)); // IP layer
		/* getting actual size of IP header*/
		int iphdrlen = ip->ihl*4;
		struct tcphdr *tcp =(struct tcphdr*)(buffer + iphdrlen + sizeof(struct ethhdr)); // TCP layer
		fprintf(log_txt,"\nPacket %d\n", ++count);
		fprintf(log_txt,"\nEthernet Header\n");
		fprintf(log_txt,"\t|-Source Address	: %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",eth->h_source[0],eth->h_source[1],eth->h_source[2],eth->h_source[3],eth->h_source[4],eth->h_source[5]);
		fprintf(log_txt,"\t|-Destination Address	: %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",eth->h_dest[0],eth->h_dest[1],eth->h_dest[2],eth->h_dest[3],eth->h_dest[4],eth->h_dest[5]);
		fprintf(log_txt,"\t|-Protocol		: %d\n",eth->h_proto);
		
	}
}
