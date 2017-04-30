#include<stdio.h>
int A[10][10],D[10],D2[10],P[10],V,H[10],W[10][10],DW[10][10];
int bellmanford(int s);
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

	//new vertices s
	s=V;
	for(i=0;i<=V;i++)
		A[s][i]=0;
	for(i=0;i<V;i++)
		A[i][s]=999;
		
	V=V+1;

	if(!bellmanford(s))
	{
		printf("The graph contains negative cycles\n");
	}
	else
	{
		/*printf("The shortes path are as follows:\n");
		for(i=0;i<V;i++)
		{
			printf("D[%d]=%d\n",i,D[i]);
			printf("P[%d]=%d\n",i,P[i]);
		}*/

		V=V-1;
		for(i=0;i<V;i++)
			for(j=0;j<V;j++)
			{
				if(A[i][j]!=999)
					W[i][j]=A[i][j]+D[i]-D[j];
				else
					W[i][j]=999;
			}

/*		printf("The distance matrix W is:\n");

                for(i=0;i<V;i++)
                {
                        for(j=0;j<V;j++)
                                printf("%d\t",W[i][j]) ;
                        printf("\n");
                }

		
		printf("The distance matrix D is:\n");
		for(i=0;i<V;i++)
			printf("%d\t",D[i]);
		printf("\n");

*/
		for(i=0;i<V;i++)
		{
			dijkstras(i);

			for(j=0;j<V;j++)
			{
					DW[i][j]=D2[j]+D[j]-D[i];
			}
		}
	
		printf("The distance matrix is:\n");

		for(i=0;i<V;i++)
		{	
			for(j=0;j<V;j++)	
				printf("%d\t",DW[i][j])	;
			printf("\n");
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
void dijkstras(int s)
{

	int i,j,flag[10],count=1,min,u;
	for(i=0;i<V;i++)
	{
		D2[i]=W[s][i];
		flag[i]=0;
	}
	D2[s]=0;
	flag[s]=1;
	while(count<V)
	{
		min=999;
		for(i=0;i<V;i++)
			if(D2[i]<min && !flag[i])
			{
				min= D2[i]; 
				u=i;
			}

		flag[u]=1;
		count++;
		for(i=0;i<V;i++)
                        if(D2[u]+W[u][i]<D2[i] && !flag[i])
                        {
				D2[i]=D2[u]+W[u][i];
                        }

		
	}
/*	for(i=0;i<V;i++)
		printf("%d\t",D2[i]);
	printf("\n");*/
}
