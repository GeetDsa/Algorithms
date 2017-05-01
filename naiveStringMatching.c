#include<stdio.h>
#include<string.h>
void main()
{
	char S1[30],S2[30];
	int i,j,flag=0,m,n;

	printf("Enter the string\n");
	scanf("%s",S1);
	printf("Enter the sub-string\n");
	scanf("%s",S2);

	m=strlen(S1);
	n=strlen(S2);

	for(i=0;i<=m-n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(S1[i+j]!=S2[j])
				break;
		}
		if(j==n)
		{
			printf("String matched at position %d \n",i);
			flag=1;
			break;
		}
	}

	if(!flag)
		printf("substring did not match any part of the string\n");
}
