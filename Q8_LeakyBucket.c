#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define np 5

int ran(int a){
    int rn = (random() % 10) % a;
    return  rn == 0 ? 1 : rn;
}

int main(){
    int packets[np], i, clk, bucket_size, o_rate, p_rm=0, p_sz, p_time, op;
    for(i = 0; i<np; ++i)
        packets[i] = ran(6) * 10;
    for(i = 0; i<np; ++i)
        printf("\npacket[%d]:%d bytes\t", i, packets[i]);
        
    printf("\nEnter the Output rate:");
    scanf("%d", &o_rate);
    printf("Enter the Bucket Size:");
    scanf("%d", &b_size);
    for(i = 0; i<np; ++i){
        if( (packets[i] + p_rm) > b_size)
            if(packets[i] > b_size)
                printf("\n\nIncoming packet size (%dbytes) is Greater than bucket capacity (%dbytes)-PACKET REJECTED", packets[i], b_size);
            else
                printf("\n\nBucket capacity exceeded-PACKETS REJECTED!!");
        else{
            p_rm += packets[i];
            printf("\n\nIncoming Packet size: %d", packets[i]);
            printf("\nBytes remaining to Transmit: %d", p_rm);
            p_time = ran(4) * 10;
            printf("\nTime left for transmission: %d units", p_time);
            for(clk = 10; clk <= p_time; clk += 10){
                sleep(1);
                if(p_rm){
                    if(p_rm <= o_rate)
                        op = p_rm, p_rm = 0;
                    else
                        op = o_rate, p_rm -= o_rate;
                        
                    printf("\nPacket of size %d Transmitted", op);
                    printf("----Bytes Remaining to Transmit: %d", p_rm);
                }
                else{
                    printf("\nTime left for transmission: %d units", p_time-clk);
                    printf("\nNo packets to transmit!!");
                }
            }
        }
    }
}

/*Output :
packet[0]:30 bytes	
packet[1]:10 bytes	
packet[2]:10 bytes	
packet[3]:50 bytes	
packet[4]:30 bytes	
Enter the Output rate:5
Enter the Bucket Size:15
Incoming packet size (30bytes) is Greater than bucket capacity (15bytes)-PACKET REJECTED

Incoming Packet size: 10
Bytes remaining to Transmit: 10
Time left for transmission: 10 units
Packet of size 5 Transmitted----Bytes Remaining to Transmit: 5

Incoming Packet size: 10
Bytes remaining to Transmit: 15
Time left for transmission: 20 units
Packet of size 5 Transmitted----Bytes Remaining to Transmit: 10
Packet of size 5 Transmitted----Bytes Remaining to Transmit: 5

Incoming packet size (50bytes) is Greater than bucket capacity (15bytes)-PACKET REJECTED

Incoming packet size (30bytes) is Greater than bucket capacity (15bytes)-PACKET REJECTED*/
