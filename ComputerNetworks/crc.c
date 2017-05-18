#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	char rem[50],a[50],s[50],c,msg[50];
	char gen[]="10001000000000101";

	int i,genlen,t,j,flag=0,k,n;

	printf("\nGenerator polynomial is CRC-CCITT:%s",gen);
	
	genlen=strlen(gen);
	k=genlen-1;

	n=0;
	printf("\nEnter the message:");

	while((c=getchar())!='\n')
	{
		msg[n]=c;
		n++;
	}
	msg[n]='\0';

	for(i=0;i<n;i++)
		a[i]=msg[i];
	for(i=0;i<k;i++)
		a[n+i]='0';

	a[n+k]='\0';

	printf("\nMessage polynomial appended with zero's:");
	puts(a);

	for(i=0;i<n;i++)
	{
		if(a[i]=='1')
		{
			t=i;
			for(j=0;j<=k;j++)
			{
				if(a[t]==gen[j])
					a[t]='0';
				else
					a[t]='1';
				t++;
			}
		}
	}

	for(i=0;i<k;i++)
		rem[i]=a[n+i];
	rem[k]='\0';

	printf("\nThe checksum appended:");
	puts(rem);

	printf("\nMessage with checksum appended:");

	for(i=0;i<n;i++)
		a[i]=msg[i];
	for(i=0;i<k;i++)
		a[n+i]=rem[i];

	a[n+k]='\0';

	puts(a);

	n=0;

	printf("\nEnter the received polynomial:");
	while((c=getchar())!='\n')
	{
		s[n]=c;
		n++;
	}
	s[n]='\0';

	for(i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			t=i;
			for(j=0;j<=k;j++,t++)
			{
				if(s[t]==gen[j])
					s[t]='0';
				else
					s[t]='1';
			}
		}
	}

	for(i=0;i<k;i++)
		rem[i]=s[n+i];
	rem[k]='\0';

	for(i=0;i<k;i++)
	{
		if(rem[i]=='1')
			flag=1;
	}

	if(flag==0)
		printf("\nThe received polynomial is error free\n");
	else
		printf("\nThe received polynomial has error\n");
}
