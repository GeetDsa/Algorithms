#include<stdio.h>
void main()
{
	int inflow[100],N,outflow,capacity=0,i,t,buffSize;


	printf("Enter the number of times(in terms of seconds) that packets are entering the bucket:\n");
	scanf("%d",&N);

	printf("Enter the inflow packetSize at every second(bits or packets)\n");
	for(i=0;i<N;i++)
		scanf("%d",&inflow[i]);

	printf("Enter the outflow rate (bits per sec or packets per second)\n");
	scanf("%d",&outflow);

	printf("Enter the capacity of the bucket:n");
	scanf("%d",&capacity);

	buffSize=0,i=0;

	while(i<N)
	{
		if(buffSize+inflow[i]<=capacity)
			buffSize+=inflow[i];
		else
			printf("The packet size exceeds the available capacity,packet entering at time %d Dropped\n",i);

		if(buffSize>0&&buffSize<=outflow)
		{
			printf("At time %d the outflow was %d bits or packets\n",i,buffSize);
			buffSize=0;
		}
		else if(buffSize>outflow)
		{
			printf("At time %d the outflow was %d bits or packets\n",i,outflow);
			buffSize-=outflow;
		}
		else
			printf("At time %d No packets to send\n",i);
		i++;
	}

	while(buffSize!=0)
	{
		if(buffSize>0&&buffSize<=outflow)
                {
                        printf("At time %d the outflow was %d bits or packets\n",i,buffSize);
                        buffSize=0;
                }
                else if(buffSize>outflow)
                {
                        printf("At time %d the outflow was %d bits or packets\n",i,outflow);
                        buffSize-=outflow;
                }
                else
                        printf("At time %d No packets to send\n",i);
                i++;
	}
}
