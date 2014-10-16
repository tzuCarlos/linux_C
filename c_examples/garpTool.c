/*
 * 
 *  Gratuitous ARP spoof tool
 *  
 *
 *  Usage: garpTool br0 192.168.4.100 xx:xx:xx:xx:xx:xx 
 *        
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
  
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <netpacket/packet.h>
#include <net/if_arp.h> // struct arphd

#define ARPOP_REPLY 2
#define ARPHDR_ETHER 1
#define ETH_ALEN 6
#define IP_ALEN 4


struct arp_payload
{
    unsigned char src_addr[ETH_ALEN];     // source MAC address
    unsigned char src_ip[IP_ALEN];        // source IP address
    unsigned char dst_add[ETH_ALEN];      // destination MAC address
    unsigned char dst_ip[IP_ALEN];        // destination IP address
};


void usage( )
{
    printf("Usage: garpTool br0 192.168.4.100 xx:xx:xx:xx:xx:xx  \n");
    exit(-1);
}


int main(int argc, char **argv)
{
   int packetsize = sizeof(struct ether_header) + sizeof(struct arphdr) + sizeof(struct arp_payload);
   unsigned char buf[packetsize];
   struct ether_header *eth = (struct ether_header *) buf;
   struct arphdr *ah = (struct arphdr *) (buf + sizeof(struct ether_header));
   struct arp_payload *p = (struct arp_payload *) (ah + 1);


         
    int sock_fd;
    struct sockaddr addr;
    struct in_addr src_addr;
    unsigned char smac[ETH_ALEN];
    unsigned char dmac[ETH_ALEN]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

    /*check input avoid overflow*/
    if(argc != 4)
    {
             usage();
    }

    if(strlen(argv[3]) != 17) 
    {
             printf("MAC address formet incorrect. \n");
             usage();
    }
         
    if(strlen(argv[2]) != 13)
    {
             printf("IP address formet incorrect. \n");
             usage();
    }
      // open socket
  //  if ((sock_fd= socket(AF_PACKET, SOCK_DGRAM, 0)) < 0)
   if ((sock_fd= socket(PF_INET, SOCK_PACKET, htons(ETH_P_ARP))) < 0)
    {
        perror(" read socket");
        exit(2);
    }

        sscanf(argv[3], "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &smac[0], &smac[1], &smac[2], &smac[3], &smac[4], &smac[5]);
        // build ethernet header
            memcpy(eth->ether_dhost, dmac, ETH_ALEN);         // Destination MAC
            memcpy(eth->ether_shost, smac, ETH_ALEN);                     // Source MAC
            eth->ether_type = htons(ETHERTYPE_ARP);                       // Packet type

         //    addr.sa_family = AF_PACKET;

         inet_aton(argv[2], &src_addr); 
    
            // build arp header
            ah->ar_hrd = htons(ARPHDR_ETHER);                           // Hardware address type
            ah->ar_pro = htons(ETH_P_IP);                         // Protocol address type
            ah->ar_hln  = ETH_ALEN;                                       // Hardware address length
            ah->ar_pln  = IP_ALEN;                                        // Protocol address length
            ah->ar_op  = htons(ARPOP_REPLY);                             // ARP operation type
            memcpy(p->src_addr, smac, ETH_ALEN);    // Sender MAC
            memcpy(p->src_ip, &src_addr, IP_ALEN);                    // Source IP
            memcpy(p->dst_add, smac, ETH_ALEN);                // Target MAC
            memcpy(p->dst_ip, &src_addr, IP_ALEN);                    // Target IP
 
            strncpy(addr.sa_data, argv[1], sizeof(addr.sa_data)); //set device
 
            printf("Sent ARP reply: %s is %02x:%02x:%02x:%02x:%02x:%02x\n",
               inet_ntoa(*(struct in_addr*)&p->src_ip),
                p->src_addr[0],  p->src_addr[1],
                p->src_addr[2], p->src_addr[3],
                p->src_addr[4], p->src_addr[5]);
 
           if (sendto(sock_fd, buf, sizeof(buf), 0, &addr, sizeof(addr)) < 0) {
               perror("sendto");
               close(sock_fd);
               exit(5);
           }

            close(sock_fd);
            exit(0);
   
}

