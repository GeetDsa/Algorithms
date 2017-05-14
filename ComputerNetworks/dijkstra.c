#include<stdio.h>
int A[10][10],D[10],P[10],V,DW[10][10],P2[10][10];
void dijkstras(int);
void main()
{
	int i,j,s;
	printf("Enter the number of vertices\n");
	scanf("%d",&V);

	printf("Enter the weight matrix (999 for infinity):\n");
	for(i=0;i<V;i++)	
		for(j=0;j<V;j++)
			scanf("%d",&A[i][j]);

	for(i=0;i<V;i++)
	{
		dijkstras(i);

		for(j=0;j<V;j++)
		{
			DW[i][j]=D[j];
			P2[i][j]=P[j];
		}
	}
	
	printf("The previous node-->distance matrix is:\n");

	for(i=0;i<V;i++)
	{	
		for(j=0;j<V;j++)	
			printf("%d-->%d\t",P2[i][j],DW[i][j])	;
		printf("\n");
	}
	
}
void dijkstras(int s)
{

	int i,j,flag[10],count=1,min,u;
	for(i=0;i<V;i++)
	{
		D[i]=A[s][i];
		flag[i]=0;
		P[i]=s;
	}
	D[s]=0;
	P[s]=s;
	flag[s]=1;

	while(count<V)
	{

		min=999;
                for(i=0;i<V;i++)
                        if(D[i]<min && !flag[i])
                        {
                                min= D[i];
                                u=i;
                        }

		flag[u]=1;
		count++;
		for(i=0;i<V;i++)
                        if(D[u]+A[u][i]<D[i])
                        {
				D[i]=D[u]+A[u][i];
				P[i]=u;
                        }
	}
}
