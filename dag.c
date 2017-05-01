#include<stdio.h>
int A[10][10],V,i,j,S[10],D[10],DM[10][10];
void topoSort();
void main()
{
	int count=0,s;
	printf("Enter the number of vertices:\n");
	scanf("%d",&V);

	printf("Enter the adjacency matrix (999 for INF)\n");
	for(i=0;i<V;i++)
	{	D[i]=999;
		for(j=0;j<V;j++)
			scanf("%d",&A[i][j]);
	}

	topoSort();

	printf("Topological order:\n");

	for(i=0;i<V;i++)
		printf("%d\t",S[i]);
	printf("\n");

	printf("Enter the source:\n");
	scanf("%d",&s);
	D[s]=0;

	for(i=0;i<V;i++)
	{
		if(S[i]==s)
			break;
		count++;	
	}
	
	while(count<V)
	{
		for(j=0;j<V;j++)
		{
			if(A[S[count]][j]!=999&&D[j]>A[S[count]][j]+D[S[count]])
				D[j]=A[S[count]][j]+D[S[count]];
			DM[S[count]][j]=D[j];
		}
		count++;
	}

	printf("Distance matrix:\n");
        for(i=0;i<V;i++)
	{
                for(j=0;j<V;j++)
                        printf("%d\t",DM[i][j]);
		printf("\n");
        }
	
	printf("Distances:\n");
        for(i=0;i<V;i++)
		printf("%d\t",D[i]);
	printf("\n");
}

void topoSort()
{
	int count=0,in_deg[10];


	for(j=0;j<V;j++)
	{
		in_deg[j]=0;
		for(i=0;i<V;i++)
		{
			if(A[i][j]!=0&&A[i][j]<999)
				in_deg[j]++;
		}
	}

	while(count<V)
	{
		for(i=0;i<V;i++)
		{
			if(in_deg[i]==0)
			{
				S[count++]=i;
				in_deg[i]--;
				for(j=0;j<V;j++)
					if(A[i][j]!=0&&A[i][j]!=999)
						in_deg[j]--;
				
			}
		}
	}

}
