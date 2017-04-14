#include<stdio.h>
int A[10][10],D[10],P[10],V;
int bellmanford(int s);
void main()
{
	int i,j,s;
	printf("Enter the number of vertices\n");
	scanf("%d",&V);

	printf("Enter the weight matrix (999 for infinity):\n");
	for(i=0;i<V;i++)	
		for(j=0;j<V;j++)
			scanf("%d",&A[i][j]);

	printf("Enter the souce vertex\n");
	scanf("%d",&s);

	if(!bellmanford(s))
	{
		printf("The graph contains negative cycles\n");
	}
	else
	{
		printf("The shortes path are as follows:\n");
		for(i=0;i<V;i++)
		{
			printf("D[%d]=%d\n",i,D[i]);
			printf("P[%d]=%d\n",i,P[i]);
		}
	}
}
int bellmanford(int s)
{
	int i,j,k;

	for(i=0;i<V;i++)
	{
		D[i]=999;
		P[i]=i;
	} 

	D[s]=0;

	for(k=0;k<V-1;k++)
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			if(A[i][j]!=999)
			{
				if((D[i]+A[i][j])<D[j])
				{
					D[j]=D[i]+A[i][j];
					P[j]=i;
				}
			}
		}
	}
	
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			if((D[i]+A[i][j])<D[j])
			{
				return 0;
			}

	return 1;
}
