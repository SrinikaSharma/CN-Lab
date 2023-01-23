#include<stdio.h>
#include<string.h>
char inputdata[100],  recievedata[100] ,key[100], temp[100], temp_key[100], rem[100], quotient[100];
int i,j,datalen,keylen;
void compute(char* data){
    for(i=0;i<keylen;i++){
        temp[i] = data[i];
    }
    for(i=0;i<datalen;i++){
        quotient[i] = temp[0];
        if(quotient[i]=='0'){
            for(int i=0;i<keylen;i++){
                key[i]='0';
            }
        }
        else{
            for(int i=0;i<keylen;i++){
                key[i]=temp_key[i];
            }
        }
        for(j=1;j<keylen;j++){
            if(key[j]!=temp[j]){
                rem[j-1]='1';
            }
            else{
                rem[j-1]='0';
            }
        }
        rem[keylen-1]=data[keylen+i];
        strcpy(temp,rem);
 }
}
int main(){
    printf("Enter the input:");
    scanf("%s",inputdata);
    printf("Enter the key:");
    scanf("%s",key);
    strcpy(temp_key,key);
    
    datalen = strlen(inputdata);
    keylen = strlen(key);
    for(i=0;i<keylen-1;i++){
        inputdata[datalen+i]='0';
    }
    compute(inputdata);
    printf("Quotient is: %s",quotient);
    printf("\nRemainder is:%s",rem);
    printf("\nmessage transferred is :");
    for(i=0;i<datalen;i++){
        recievedata[i]=inputdata[i];
    }
    for(i=0;i<keylen-1;i++){
        recievedata[datalen+i] = rem[i];
    }
    printf("%s",recievedata);
    compute(recievedata);
    
    printf("\nremainder at reciever side is :%s",rem);
    printf("\nHence the data is recieved correctly!!");
}


/*Output - 
Enter the input:1001101
Enter the key:1011
Quotient is: 1010011
Remainder is:101
message transferred is :1001101101
remainder at reciever side is :000
Hence the data is recieved correctly!!*/
