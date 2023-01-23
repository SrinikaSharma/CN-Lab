#include<stdio.h>
int main(){
    	int n;
    	printf("Enter no.of bits of data :");
    	scanf("%d",&n);
    	int i,a[n],b[1024],count = 0,k=0;
    	printf("Enter data: ");
    	for(i=0;i<n;i++){
        		scanf("%d",&a[i]);
    	}
    	for(i=0;i<n;i++){
        		if(a[i]==1){
            	count += 1;
            	b[k] = a[i];
            	k+=1;
        	}
        if(a[i]==0){
            count = 0;
            b[k] = a[i];
            k+=1;
        }
        if(count == 5){
            count = 0;
            b[k] = 0;
            k+=1;
        }
    }
    for(i=0;i<k;i++){
        printf("%d ",b[i]);
    }
}

/* Output :
Enter no.of bits of data : 10
Enter data: 1 1 1 1 1 1 0 0 0 1 1 1
1 1 1 1 1 0 1 0 0 0 1 */


// Byte stuffing
#include<stdio.h>
#include<string.h>
int main(){
    char a[100],ans[100];
    printf("Enter the data to be transferred:");
    scanf("%s",a);
    int j=0,i=0;
    for(i=0;i<strlen(a);i++){
        if(a[i]=='F'){
            ans[j]='E';
            j++;
        }
        if(a[i]=='E'){
            ans[j]='E';
            j++;
        }
        ans[j]=a[i];
        j++;
    }
    printf("The String After byte stuffing is : %s",ans);
	return 0;
}

/*Output :
Enter the data to be transferred: AFB
The String After byte stuffing is : AEFB */
