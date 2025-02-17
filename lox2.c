#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *array;
int j=1;
static int count = 0;

int highestValue(){
	int temp = array[0];
	for(int i=0;i<count;i++){
		if(temp<array[i+1])
			temp = array[i+1];
	}
	return temp;
}
		
	
void *Errcheck(int size){
	void *ptr;
	ptr = malloc(size);
	if(ptr == NULL){
		printf("Error : Memory allocation has been failed");
		exit(-1);
	}
	return ptr;
}
int getinput(int *ptr,int size){
	printf("Enter a integer Numbers : ");
	for(int i =0;i<size;i++){
		if(scanf("%d",(ptr + i))!=1){
			return -1;
		}	
	}
	return 0;
}
void  palindromic(int palin){
	array = (int*) Errcheck(20*sizeof(int));
	count ++;
	do{
		array[j-1] = palin;
	}while(j<0);
	j++;
}

void split(int num){
	char *str;
	char *cp;
	int i = 0;
	// using pointer variable to use this function 
	asprintf(&cp,"%d",num);
	//allocate a memory space
	str = (char *) Errcheck(20 * sizeof(char));
	while(num>0){
		*(str + i) = num % 10 + '0';
		i++;
		num /=10;
	}
	*(str +i) = '\0';
	if(strcmp(str,cp)==0){
		palindromic(atoi(cp));
	}
}
	
int ivreturn(int *ptr,int size){
	for(int i =0;i<size;i++){
		split(*(ptr+i));
	}
}

int main(){
	int num;
	int  *p;
	printf("How many Element do you enter : ");
	if(scanf("%d",&num) == 1 && num<51){
	
		p = (int*) Errcheck(num * sizeof(int));
		if(getinput(p,num)==-1){
			printf("Error : Invalide data Read the term's and condtion (integer only allowed)\n");
			exit(-1);
		}
		ivreturn(p,num);
		num = highestValue();
		if(num==0){
			printf("Given input No one is Palindrome Number ");
			exit(-1);
		}
		printf("The Highest value of Palindrome %d \n",num);
	}
	else{
		printf("Error : Invalide data Read the term's and condtion (integer only allowed)");
		}
}
		
