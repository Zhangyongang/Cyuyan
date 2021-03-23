// snake.cpp : Defines the entry point for the console application.
#include "stdafx.h"
/*******ͷ  ��  ��*******/
#include<stdio.h>			//��׼�������������
#include<time.h>			//���ڻ�������
#include<windows.h>			//����dos����
#include<stdlib.h>			//��standard library��־��ͷ�ļ������涨����һЩ���ͨ�ù��ߺ���
#include<conio.h>			//���ռ����������

/*******��  ��  ��*******/
#define U 1
#define D 2
#define L 3 
#define R 4    //�ߵ�״̬��U���� ��D���£�L:�� R����

/*******��  ��  ȫ  ��  ��  �� *******/
typedef struct snake 		//������һ���ڵ�
{
    int x;					//�ڵ�x����
    int y;					//�ڵ�y����
    struct snake *next;		//��������һ�ڵ�
}snake;
int score=0;                //�ܵ÷�
int add=10;			        //ÿ�γ�ʳ��÷�
int HighScore = 0;			//��߷�
int status;					//��ǰ��״̬
int sleeptime=200;			//ÿ�����е�ʱ����
snake *head;				//��ͷָ��
snake *food;				//ʳ��ָ��
snake *q;					//�����ߵ�ʱ���õ���ָ��
int endgamestatus=0;		//��Ϸ�����������1��ײ��ǽ��2��ҧ���Լ���3�������˳���Ϸ
HANDLE hOut;				//����̨���

/*******��  ��  ��  �� *******/
void gotoxy(int x,int y);   //���ù��λ��
int color(int c);           //����������ɫ
void printsnake();          //�ַ���
void welcometogame();       //��ʼ����
void createMap();           //���Ƶ�ͼ
void scoreandtips();		//��Ϸ�����Ҳ�ĵ÷ֺ�С��ʾ
void initsnake();           //��ʼ��������������
void createfood();          //�������������ʳ��
int biteself();             //�ж��Ƿ�ҧ�����Լ�
void cantcrosswall();       //������ײǽ�����
void speedup();				//����
void speeddown();			//����
void snakemove();           //������ǰ������
void keyboardControl();     //���Ƽ��̰���
void Lostdraw();            //��Ϸ��������
void endgame();             //��Ϸ����
void choose();				//��Ϸʧ��֮���ѡ��
void File_out();            //���ļ��ж�ȡ��߷�
void File_in();            	//������߷ֽ��ļ�
void explation();           //��Ϸ˵��

/*
	���ù��λ��
*/
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

/*
	������ɫ����
*/
int color(int c)
{
	//SetConsoleTextAttribute��API���ÿ���̨����������ɫ�ͱ���ɫ�ĺ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //����������ɫ
	return 0;
}

/*
	�ַ�ƴ��Ӣ��ͼ��
*/
void printsnake()
{
	color(2);
	printf("                                                                                         \n");
	printf("                       __________                                                        \n");
	printf("                      /          \\                                                      \n");
	printf("                     /  ________  \\                                                     \n");
	printf("                     |  |      |__|                                                      \n");
	printf("                     |  |                                                                \n");
	printf("                     \\  \\_______                                 __                    \n");
	printf("                      \\         \\    ____ ____      ____   __ |  |  ___   ______       \n");
	printf("                       \\_______  \\   |  |/    \\    /    \\_/ / |  | /  /  /      \\   \n");
	printf("                               \\  \\  |    ___  \\  / ____   /  |  |/  /  /  ____  \\   \n");
	printf("                     __        |  |  |   /   \\  \\ | |  |  /   |     /  |  /____\\  |   \n");
	printf("                    \\  \\_______|  |  |  |    |  | | |__|  |   |     \\  |  ________/   \n");
	printf("                     \\            /  |  |    |  |  \\       \\  |  |\\  \\  \\  \\____  \n");
	printf("                      \\__________/   |__|    |__|   \\___/\\__\\ |__| \\__\\  \\______/ \n");
	 



	
}

/*
	��ʼ����
*/
void welcometogame()
{
	int n;
	int i,j = 1;
	gotoxy(43,18);
	color(11);
	printf("̰ �� �� �� Ϸ");
	color(14);          			//��ɫ�߿�
	for (i = 20; i <= 26; i++)   	//������±߿�
	{
		for (j = 27; j <= 74; j++)  //������ұ߿�
		{
			gotoxy(j, i);
			if (i == 20 || i == 26)
			{
				printf("-");
            }
			else if (j == 27 || j == 74)
            {
				printf("|");
            }
		}
	}
	color(10);
	gotoxy(35, 22);
	printf("1.��ʼ��Ϸ");
	gotoxy(55, 22);
	printf("2.��Ϸ˵��");
	gotoxy(35, 24);
	printf("3.�˳���Ϸ");
	gotoxy(29,27);
	color(3);
	printf("��ѡ��[1 2 3]:[ ]\b\b");        //\bΪ�˸�ʹ�ù�괦��[]�м�
	color(14);
    scanf("%d", &n);    		//����ѡ��
    switch (n)
    {
    	case 1:					//ѡ��ʼ��Ϸ
    		system("cls");
			createMap();        //������ͼ
			initsnake();        //��ʼ������
			createfood();		//��ʼ��ʳ��
			keyboardControl();	//���Ƽ��̰�ť
        	break;
    	case 2:					//ѡ����Ϸ˵��
        	explation();
        	break;
    	case 3:					//ѡ���˳���Ϸ
        	exit(0);     		//�˳���Ϸ
        	break;
		default:				//�����1~3֮���ѡ��
			color(12);
			gotoxy(40,28);
			printf("������1~3֮�����!");
			getch();			//���������
			system("cls");		//����
			printsnake();
			welcometogame();
    }
}

/*
	������ͼ
*/
void createMap()
{
    int i,j;
    for(i=0;i<58;i+=2)		//��ӡ���±߿�
    {
        gotoxy(i,0);
		color(6);			//����ɫ�ı߿�
        printf("��");
        gotoxy(i,26);
        printf("��");
    }
    for(i=1;i<26;i++)		//��ӡ���ұ߿�
    {
        gotoxy(0,i);
        printf("��");                        
        gotoxy(56,i);
        printf("��");        
    }
	for(i = 2;i<56;i+=2)	//��ӡ�м�����
	{
		for(j = 1;j<26;j++)
		{
			gotoxy(i,j);
			color(3);
			printf("��\n\n");
		}
	}
}

/*
	��Ϸ�����Ҳ�ĵ÷ֺ�С��ʾ
*/
void scoreandtips()
{
	File_out();				//����File_out()����ȡ�ļ�save.txt�е�����
	gotoxy(64,4);			//ȷ����ӡ�����λ��
	color(11);				//������ɫ
	printf("����߼�¼�%d",HighScore);	//��ӡ��߷�
	gotoxy(64,8);
	color(14);
	printf("��ǰ�÷֣�%d  ",score);
	color(15);
	gotoxy(73,11);
	printf("С �� ʾ");
	gotoxy(60,13);
	color(6);
	printf("�p ������������������������������ �p");
	gotoxy(60,25);
	printf("�p ������������������������������ �p");
	color(3);
	gotoxy(64,14);
	printf("ÿ��ʳ��÷֣�%d��",add);
	gotoxy(64,16);
	printf("����ײǽ������ҧ���Լ�");
	gotoxy(64,18);
	printf("�á� �� �� ���ֱ�����ߵ��ƶ�");
	gotoxy(64,20);
	printf("F1�����٣�F2������");
	gotoxy(64,22);
	printf("�ո����ͣ��Ϸ");
	gotoxy(64,24);
    printf("Esc���˳���Ϸ");
}

/*
	��ʼ��������������
*/
void initsnake()
{
    snake *tail;
    int i;
    tail=(snake*)malloc(sizeof(snake));	//����β��ʼ��ͷ�巨����x,y�趨��ʼ��λ��
    tail->x=24;				//�ߵĳ�ʼλ�ã�24,5��
    tail->y=5;
    tail->next=NULL;
    for(i=1;i<=4;i++)       //��������������Ϊ5
    {
        head=(snake*)malloc(sizeof(snake)); //��ʼ����ͷ
        head->next=tail;    //��ͷ����һλΪ��β
        head->x=24+2*i;     //������ͷλ��
        head->y=5;
        tail=head;          //��ͷ�����β��Ȼ���ظ�ѭ��
    }
    while(tail!=NULL)		//��ͷ��β���������
    {
        gotoxy(tail->x,tail->y);
		color(14);
        printf("��");       //�������������ʹ�á����
        tail=tail->next;    //��ͷ�����ϣ������ͷ����һλ��һֱ�������β
    }
}

/*
	�������ʳ��
*/
void createfood()
{
    snake *food_1;
    srand((unsigned)time(NULL));        	//��ʼ�������
    food_1=(snake*)malloc(sizeof(snake));   //��ʼ��food_1
    while((food_1->x%2)!=0)    				//��֤��Ϊż����ʹ��ʳ��������ͷ���룬Ȼ��ʳ����������������
    {
        food_1->x=rand()%52+2;              //ʳ��������֣�ʳ���x������2~53
    }
    food_1->y=rand()%24+1;					//ʳ���y������1~24
    q=head;
    while(q->next==NULL)
    {
        if(q->x==food_1->x && q->y==food_1->y) //�ж������Ƿ���ʳ���غ�
        {
            free(food_1);               //���������ʳ���غϣ���ô�ͷ�ʳ��ָ��
            createfood();               //���´���ʳ��
        }
        q=q->next;
    }
    gotoxy(food_1->x,food_1->y);
    food=food_1;
	color(12);
    printf("��");           //���ʳ��
}

/*
	�ж��Ƿ�ҧ�����Լ�
*/
int biteself()
{
    snake *self;            //����selfΪ�����ϵ�һ���ڵ�
    self=head->next;        //self����ͷ֮��������ϵĽڵ�
    while(self!=NULL)
    {
        if(self->x==head->x && self->y==head->y)    //���self�������ϵĽڵ��غ�
        {
            return 1;       //����1
        }
        self=self->next;
    }
    return 0;
}

/*
	������ײǽ�����
*/
void cantcrosswall()
{  
    if(head->x==0 || head->x==56 ||head->y==0 || head->y==26) //�����ͷ������ǽ��
    {
        endgamestatus=1;        //���ص�һ�����
        endgame();              //������Ϸ��������
    }
}

/*
	���٣��߳Ե�ʳ����Զ����٣����Ұ�F1�����
*/
void speedup()
{
	if(sleeptime>=50)
	{
		sleeptime=sleeptime-10;
		add=add+2;

    }
}

/*
	���٣���F2�����
*/
void speeddown()
{
	if(sleeptime<350)               //���ʱ����С��350
    {
        sleeptime=sleeptime+30;     //ʱ��������30
        add=add-2;                  //ÿ��һ��ʳ��ĵ÷ּ�2

    }
}

/*
	���Ʒ���
*/
void snakemove()	//��ǰ��,��U,��D,��L,��R
{
	snake * nexthead;
    cantcrosswall();
    nexthead=(snake*)malloc(sizeof(snake));		//Ϊ��һ�����ٿռ�
    if(status==U)
    {
        nexthead->x=head->x;        //����ǰ��ʱ��x���겻����y����-1
        nexthead->y=head->y-1;
        nexthead->next=head;
        head=nexthead;
        q=head;						//ָ��qָ����ͷ
        if(nexthead->x==food->x && nexthead->y==food->y)	//�����һ����ʳ�� ��һ��λ�õ������ʳ���������ͬ
        {
            
            while(q!=NULL)
            {
                gotoxy(q->x,q->y);
				color(14);
                printf("��");       //ԭ��ʳ���λ�ã��ӡ񻻳ɡ�
                q=q->next;          //ָ��qָ�����������һλҲִ��ѭ����Ĳ���
				
            }
            score=score+add;        //����һ��ʳ����ܷ��ϼ���ʳ��ķ�
			speedup();
            createfood();           //����ʳ��
        }
        else                        
        {
            while(q->next->next!=NULL)	//���û����ʳ��
            {
                gotoxy(q->x,q->y);
                color(14);
                printf("��");           //��������ǰ�ߣ������ǰλ�õ�����
                q=q->next;              //���������������
            }
            gotoxy(q->next->x,q->next->y);  //���������ѭ����qָ����β����β����һλ���������߹�ȥ��λ��
			color(3);
            printf("��");
            free(q->next);			//���������֮���ͷ�ָ����һλ��ָ��
            q->next=NULL;			//ָ����һλָ���
        }
    }
    if(status==D)
    {
        nexthead->x=head->x;        //����ǰ��ʱ��x���겻����y����+1
        nexthead->y=head->y+1;
        nexthead->next=head;
        head=nexthead;
        q=head;
        if(nexthead->x==food->x && nexthead->y==food->y)  //��ʳ��
        {
            
            while(q!=NULL)
            {
                gotoxy(q->x,q->y);
                color(14);
                printf("��");
                q=q->next;
            }
            score=score+add;
			speedup();
            createfood();
        }
        else                               //û��ʳ��
        {
            while(q->next->next!=NULL)
            {
                gotoxy(q->x,q->y);
                color(14);
                printf("��");
                q=q->next;
            }
            gotoxy(q->next->x,q->next->y);
			color(3);
            printf("��");
            free(q->next);
            q->next=NULL;
        }
    }
    if(status==L)
    {
        nexthead->x=head->x-2;        //����ǰ��ʱ��x���������ƶ�-2��y���겻��
        nexthead->y=head->y;
        nexthead->next=head;
        head=nexthead;
        q=head;
        if(nexthead->x==food->x && nexthead->y==food->y)//��ʳ��
        {
            while(q!=NULL)
            {
                gotoxy(q->x,q->y);
                color(14);
                printf("��");
                q=q->next;
            }
            score=score+add;
			speedup();
            createfood();
        }
        else                                //û��ʳ��
        {
            while(q->next->next!=NULL)
            {
                gotoxy(q->x,q->y);
                color(14);
                printf("��");
                q=q->next;        
            }
            gotoxy(q->next->x,q->next->y);
			color(3);
            printf("��");
            free(q->next);
            q->next=NULL;
        }
    }
    if(status==R)
    {
        nexthead->x=head->x+2;        //����ǰ��ʱ��x���������ƶ�+2��y���겻��
        nexthead->y=head->y;
        nexthead->next=head;
        head=nexthead;
        q=head;
        if(nexthead->x==food->x && nexthead->y==food->y)//��ʳ��
        {
            while(q!=NULL)
            {
                gotoxy(q->x,q->y);
                color(14);
                printf("��");
                q=q->next;
            }
            score=score+add;
			speedup();
            createfood();
        }
        else                                         //û��ʳ��
        {
            while(q->next->next!=NULL)
            {
                gotoxy(q->x,q->y);
                color(14);
                printf("��");
                q=q->next;        
            }
            gotoxy(q->next->x,q->next->y);
			color(3);
            printf("��");
            free(q->next);
            q->next=NULL;
        }
    }
    if(biteself()==1)       //�ж��Ƿ��ҧ���Լ�
    {
        endgamestatus=2;
        endgame();
    }
}

/*
	���Ƽ��̰���
*/
void keyboardControl()
{
	status=R;       //��ʼ�������ƶ�
    while(1)
    {
		scoreandtips();
        if(GetAsyncKeyState(VK_UP) && status!=D)            //GetAsyncKeyState���������жϺ�������ʱָ���������״̬
        {
            status=U;           //����߲�������ǰ����ʱ�򣬰��ϼ���ִ������ǰ������
        }
        else if(GetAsyncKeyState(VK_DOWN) && status!=U)     //����߲�������ǰ����ʱ�򣬰��¼���ִ������ǰ������
        {
            status=D;
        }
        else if(GetAsyncKeyState(VK_LEFT)&& status!=R)      //����߲�������ǰ����ʱ�򣬰������ִ������ǰ��
        {
            status=L;
        }
        else if(GetAsyncKeyState(VK_RIGHT)&& status!=L)     //����߲�������ǰ����ʱ�򣬰��Ҽ���ִ������ǰ��
        {
            status=R;
        }
        if(GetAsyncKeyState(VK_SPACE))		//����ͣ����ִ��pause��ͣ����
        {
            while(1)
			{
				Sleep(300); //sleep()������ͷ�ļ�#include <unistd.h>  �������ͣ��ֱ���ﵽ�����趨�Ĳ�����ʱ��
				if(GetAsyncKeyState(VK_SPACE))      //���ո����ͣ
				{
					break;
				}
				
			}       
        }
        else if(GetAsyncKeyState(VK_ESCAPE))
        {
            endgamestatus=3;    //��esc����ֱ�ӵ���������
            break;
        }
        else if(GetAsyncKeyState(VK_F1))    //��F1��������
        {
            speedup();
        }
        else if(GetAsyncKeyState(VK_F2))    //��F2��������
        {
        	speeddown();
            
        }
        Sleep(sleeptime);
        snakemove();
    }
}

/*
	������߷ֽ��ļ�
*/
void File_in()
{
	FILE *fp;
	fp = fopen("save.txt", "w+");       //�Զ�д�ķ�ʽ����һ����Ϊsave.txt���ļ�
	fprintf(fp, "%d", score);           //�ѷ���д���ļ���
	fclose(fp);                         //�ر��ļ�
}

/*
	���ļ��ж�ȡ��߷�
*/
void File_out()
{
	FILE *fp;
	fp = fopen("save.txt", "a+");       //���ļ�save.txt
	fscanf(fp, "%d", &HighScore);       //���ļ��е���߷ֶ�����
	fclose(fp);                         //�ر��ļ�
}

/*
	��Ϸ˵��
*/
void explation()
{
	int i,j = 1;
    system("cls");
    color(15);
    gotoxy(44,3);
    printf("��Ϸ˵��");
    color(2);
    for (i = 6; i <= 22; i++)   //������±߿�===
	{
		for (j = 20; j <= 76; j++)  //������ұ߿�||
		{
			gotoxy(j, i);
			if (i == 6 || i == 22) printf("=");
			else if (j == 20 || j == 75) printf("||");
		}
	}
    color(3);
    gotoxy(30,8);
    printf("tip1: ����ײǽ������ҧ���Լ�");
    color(10);
    gotoxy(30,11);
    printf("tip2: �á�.��.��.���ֱ�����ߵ��ƶ�");
    color(14);
    gotoxy(30,14);
    printf("tip3: F1 Ϊ���٣�F2 Ϊ����");
    color(11);
    gotoxy(30,17);
    printf("tip4: ���ո����ͣ��Ϸ���ٰ��ո������");
    color(4);
    gotoxy(30,20);
    printf("tip5: Esc ���˳���Ϸ");
    getch();                //�����������������
    system("cls");
    printsnake();
    welcometogame();
}

/*
	������Ϸ
*/
void endgame()
{
    system("cls");
    if(endgamestatus==1)
    {
        
		Lostdraw();
		gotoxy(35,9);
    	color(7);
		printf("�Բ�����ײ��ǽ�ˡ���Ϸ������");
    }
    else if(endgamestatus==2)
    {
        
        Lostdraw();
        gotoxy(35,9);
    	color(7);
        printf("�Բ�����ҧ���Լ��ˡ���Ϸ������");
    }
    else if(endgamestatus==3)
    {
		Lostdraw();
		gotoxy(40,9);
    	color(7);
        printf("���Ѿ���������Ϸ��");
    }
    gotoxy(43,12);
    color(14);
    printf("���ĵ÷��� %d",score);

	if(score >= HighScore)
	{
		color(10);
		gotoxy(33,16);
		printf("����¼������߷ֱ���ˢ���������������");
		File_in();              //����߷�д���ļ�
	}
	else
	{
		color(10);
		gotoxy(33,16);
		printf("����Ŭ����~ ������߷ֻ��%d",HighScore-score);
	}
	choose();
}

/*
	�߿�����ķ�֧ѡ��
*/
void choose()
{
	int n;
	gotoxy(30,23);
	color(12);
	printf("����һ�� [1]");
	gotoxy(55,23);
	printf("�������� [2]");
	gotoxy(45,25);
	color(11);
	printf("ѡ��");
	scanf("%d", &n);
    switch (n)
    {
	case 1:
		system("cls");          //����
		score=0;                //��������
		sleeptime=200;			//�趨��ʼ�ٶ�
		add = 10;				//ʹadd�趨Ϊ��ֵ����һ��ʳ��÷�10��Ȼ���ۼ�
		printsnake();           //���ػ�ӭ����
		welcometogame();
		break;
	case 2:
		exit(0);                //�˳���Ϸ
		break;
	default:
		gotoxy(35,27);
		color(12);
		printf("�����������������������������");
		system("pause >nul");
		endgame();
		choose();
		break;
	}

}

/*
	ʧ�ܽ���
*/
void Lostdraw()
{
	system("cls");
	int i;
	gotoxy(45,1);
	color(6);
	printf(" |-----|   ");		//ƥŵ�ܵ�ñ��
	gotoxy(45,2);
	color(6);
	printf(" |     |   ");
	gotoxy(43,3);
	color(6);
	printf("-------------");

	gotoxy(44,4);
	color(14);
	printf("(");

	gotoxy(47,4);
	color(15);
	printf(" > <");				//�۾�

	gotoxy(54,4);
	color(14);
	printf(")");

	gotoxy(17,5);
	color(11);
	printf("+------------------------");	//�ϱ߿�

	gotoxy(35,5);
	color(14);
	printf("oOOo");

	gotoxy(39,5);
	color(11);
	printf("----------");					//�ϱ߿�

	gotoxy(48,5);
	color(14);
	printf("| |");				//����
	gotoxy(48,6);
	color(14);
	printf("|_|");

	gotoxy(51,5);
	color(11);
	printf("----------");					//�ϱ߿�

	gotoxy(61,5);
	color(14);
	printf("oOOo");

	gotoxy(65,5);
	color(11);
	printf("-----------------+");			//�ϱ߿�
	
	for(i = 6;i<=19;i++)					//���߿�
	{
		gotoxy(17,i);
		printf("|");
		gotoxy(82,i);
		printf("|");
	}

	gotoxy(17,20);
	printf("+------------------------------------------");	//�±߿�

	gotoxy(60,20);
	color(11);
	printf("----------------------+");						//�±߿�

}

/*
	������
*/
int main(int argc, char* argv[])
{
	system("mode con cols=110 lines=30");	//���ÿ���̨����
	printsnake();							//�����ַ���
	welcometogame();						//��ӭ����
	//File_out();								//��ȡ�ļ���Ϣ
	//keyboardControl();						//���Ƽ��̰�ť
	endgame();								//��Ϸ����
	return 0;
}