#include<stdio.h>
#include<math.h>
#include<time.h>
#include <stdlib.h>
void opration(void);
float numjia(float a,float b);
float numjian(float a,float b);
float numchen(float a,float b);
float numchu(float a,float b);
float numjisuan(int i,float a,float b);
char yunsuanfu(int i);
void main()
{
	int i=0,n;
	printf("��Ҫ�Ķ�������ʽ��");
	scanf("%d",&n);
	do{
		opration();
		i++;
	}while(i<n);
	system("pause");
}
void opration()
{
	float numanswer;
	float x,y,z;
	int a,b,c;
	int j,k;
	char op1,op2;
	srand((unsigned)time(NULL));//���������
	do{
		a=rand()%100;
		b=rand()%100;
		c=rand()%100;
		//0��1Ϊ�Ӽ� 2��3Ϊ�˳�
		j=rand()%4;
		k=rand()%4;
		if(j>1){
			y=(float)a;
			z=(float)b;
			x=numjisuan(j,y,z);
			y=x;
			z=(float)c;
			x=numjisuan(k,y,z);
		}
		else
		{
			if(k<2)
			{
				y=(float)a;
			    z=(float)b;
			    x=numjisuan(j,y,z);
			    y=x;
			    z=(float)c;
			    x=numjisuan(k,y,z);
			}
			else
			{
				y=(float)b;
			    z=(float)c;
		    	x=numjisuan(k,y,z);
			    y=(float)a;
			    z=x;
		    	x=numjisuan(j,y,z);
			}
		}
	}while(x<0.0);
	op1=yunsuanfu(j);
	op2=yunsuanfu(k);
	printf("%d %c %d %c %d = ",a,op1,b,op2,c);
	scanf("%f",&numanswer);
	if(j==3&&k==3)
	{
		if((numanswer-x)<0.01)
		{
			printf("��ϲ�㣬�������\n");
		}
		else
		{
			printf("��ϧ���������������ȷ���ǣ�%.1f\n",x);//�������һλС����
		}
	}
	else
	{
		if((x-numanswer)<0.01)
		{
			printf("��ϲ�㣬�������\n");
		}
		else
		{
			printf("��ϧ���������������ȷ���ǣ�%.1f\n",x);
		}
	}
}
float numjisuan(int i,float a,float b)//��������ʽ�ĺ���
{
	float x;
	switch(i)
	{
	case 0:
		x=numjia(a,b);
		break;
	case 1:
		x=numjian(a,b);
		break;
	case 2:
		x=numchen(a,b);
		break;
	case 3:
		x=numchu(a,b);
		break;
	default:
		break;
	}
	return x;
}
float numjia(float a,float b)
{
	float x;
	x=a+b;
	return x;
}
float numjian(float a,float b)
{
	float x;
	x=a-b;
	return x;
}
float numchen(float a,float b)
{
	float x;
	x=a*b;
	return x;
}
float numchu(float a,float b)
{
	float x;
	x=a/b;
	return x;
}
char yunsuanfu(int i)
{
	char op;
	switch(i)
	{
	case 0:
		op='+';
		break;
	case 1:
		op='-';
		break;
	case 2:
		op='*';
		break;
	default:
		op='/';
		break;
	}
	return op;
}