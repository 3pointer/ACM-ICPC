#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int a,b;//����С����
	long queue=0;//ץ��С���Ѻ����
	int n;//С���Ѹ���
	int i;//������
	int *line;

	scanf("%d",&n);//����С���Ѹ���
	line=(int*)calloc(n+10,sizeof(int));
	memset(line,-1,sizeof(int)*(n+10));
    //for(i=0;i<n+10;i++) printf("%d ",line[i]);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&a,&b);
		line[a]=b;
		queue+=b;
	}
	queue=( n*(n-1) )/2 -queue; //queue���ڵ��ڶ��׺���

	i=0;
	while(line[queue]!=-1&&i<=n+1)
	{
		queue=line[queue];
		//��ǰһ���ˣ�������һ���ˡ������൱�ھ�̬��������
		//������������TMB�Ĵ���������Ĥ�ݡ�����
		i++;
	}
	printf("%s\n",i==n-1?"Yes":"No");
	free(line);
	return 0;
}