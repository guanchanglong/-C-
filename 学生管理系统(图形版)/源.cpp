/*
�����ˣ��ز�¡(����ʵ��)
		����ɭ(ͼƬ֧�֡����ԡ�bug����)
		����(bug���ҡ�����)
��λ��	�����ʵ��ѧ-�����ѧԺ
*/
#define _CRT_SECURE_NO_DEPRECATE 0;
#define USES_CONVERSION 0;
#define _CRT_NONSTDC_NO_DEPRECATE 0;
#define _CRT_SECURE_NO_WARNINGS 0;

#include<graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <conio.h>
#include<tchar.h>
#include<Windows.h>

/*�궨��*/
#define LENGTH 30				//�����û��������볤��


IMAGE welcome;
IMAGE welcom_button;
IMAGE startup;
IMAGE stu1_exit;
IMAGE end;
IMAGE stu1;
IMAGE stu1_return;
IMAGE stu_register;
IMAGE stu_logon;
IMAGE teacher1;
IMAGE tea_register;
IMAGE tea_logon;
IMAGE teacher1_return;
IMAGE stu_button;
IMAGE tea_button;
IMAGE exit_button;
IMAGE tea_returnwelcome;
IMAGE returnstudentmain_button;
IMAGE stu_resetpassword;
IMAGE stu_scoremanagement1;
IMAGE stu_scoremanagement2;
IMAGE stu_schedulemanagement2_return;
IMAGE teacher_resetpassword;
IMAGE teacher_scoremanagement1;
IMAGE teacher_scoremanagement2;
IMAGE createscore;
IMAGE resetscore;
IMAGE teacher_scoremanagement2_return;
IMAGE returnteachermain_button;
IMAGE returnmainmenu_button;
IMAGE delscore;
IMAGE findscore;
IMAGE statisticsscore1;
IMAGE statisticsscore2;
IMAGE fullmarks;
IMAGE failingstudent;
IMAGE teacher_scoreStatistics2_return;
IMAGE descendingdortscore;
IMAGE averagescore;
IMAGE failingstudent_flipoverbutton_nextpage;
IMAGE failingstudent_flipoverbutton_previouspage;
IMAGE fullmarks_flipoverbutton_nextpage;
IMAGE fullmarks_flipoverbutton_previouspage;
IMAGE findscore_flipoverbutton_nextpage;
IMAGE findscore_flipoverbutton_previouspage;
IMAGE stu_findscore_flipoverbutton_previouspage;
IMAGE stu_findscore_flipoverbutton_nextpage;

int StuLogonFlag = 0;		//�����ж�ѧ���Ƿ��¼�ı�־����
int TeaLogonFlag = 0;	//�����жϽ�ʦ�Ƿ��¼�ı�־����

FILE *fp1, *fp2, *fp3;
char filename1[] = "��ʦע������.txt";
char filename2[] = "ѧ��ע������.txt";
char filename3[] = "ѧ���ɼ�.txt";

void MainMenu();
void Stu_SecondMenu();
void Stu_Register();
void Stu_Logon();
void Tea_Register();
void Tea_Logon();
void Tea_SecondMenu();
void Stu_ResetPassword();
void Stu_ScoreManagement();
void Tea_ResetPassword();
void Tea_ScoreManagement();
void Stu_CreateScore();
void Stu_AmendScore();
void Stu_DeleteScore();
void Stu_FindInformation();
void Stu_ScoreStatistics();
void FullMarks();
void FailingStudent();
void DescendingSortScore();
void AverageScore();
void FlipOverMenu();
void FlipOverMenu1();
void FlipOverMenu2();
void PreviousPage_And_NextPage(int page);
void PreviousPage_And_NextPage1(int page);
void PreviousPage_And_NextPage2(int page);
void FlipOverMenu_Tea_ScoreManagement();
void PreviousPageAndNextPage_Tea_ScoreManagement(int page);
void PreviousPageAndNextPage_Stu_SecondMenu(int page);
void FlipOverMenu_Stu_SecondMenu();

typedef struct teacher
{
	wchar_t Namew[LENGTH];		//�����ʦ�û���
	char Namec[LENGTH];
	wchar_t password1[LENGTH];	//�����ʦ�˻�����
	wchar_t password2[LENGTH];	//�����ʦ������������ 
	char password[LENGTH];
	struct teacher *next;
}tea;

typedef struct student
{
	wchar_t Namew[LENGTH];					//����ѧ���û���
	char Namec[LENGTH];
	wchar_t password1[LENGTH];				//����ѧ���˻�����
	wchar_t password2[LENGTH];				//����ѧ�������������� 
	char password[LENGTH];
	int yu;
	int shu;
	int ying;
	int zongfen;
	struct student *next;
}stu;

int page1 = 1, page2 = 1;//����
int page3 = 1, page4 = 1;//������
int page5 = 1, page6 = 1;//����
int page7 = 1, page8 = 1;//��ʦ�˵�ѧ������
int page9 = 1, page10 = 1;//ѧ���˵�ѧ������
stu *node5[LENGTH];//ѧ���˵�ѧ������
stu *node4[LENGTH];//��ʦ�˵�ѧ������
stu *node3[LENGTH];//����
stu *node2[LENGTH];//������
stu *node1[LENGTH];//����
stu *node[LENGTH];

inline char* UnicodeToAnsi(wchar_t* szStr)	//�����ֽ�wchar_t*����ת��Ϊխ�ֽ�char*����
{
	//�ú�������ӳ��һ��unicode�ַ�����һ�����ֽ��ַ�����ִ��ת���Ĵ���ҳ������ת���ַ������������Ŀ��ƵȲ�����
	int nLen = WideCharToMultiByte(CP_ACP, 0, szStr, -1, NULL, 0, NULL, NULL);
	if (nLen == 0)
	{
		return NULL;
	}
	char* pResult = new char[nLen];
	WideCharToMultiByte(CP_ACP, 0, szStr, -1, pResult, nLen, NULL, NULL);
	return pResult;
}

inline wchar_t*UnicodeToAnsi2(char* str)	//��խ�ֽ�char*����ת��Ϊ���ֽ�wchar_t*����		
{
	//һ��windows API �������ú���ӳ��һ���ַ�����һ�����ַ���unicode�����ַ�����
	int nlen = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	if (nlen == 0)
	{
		return NULL;
	}
	wchar_t*pResult = new wchar_t[nlen];
	MultiByteToWideChar(CP_ACP, 0, str, -1, pResult, nlen);
	return pResult;
}

stu *createlink3(void)								//���ļ������Ϣת����������
{
	fp3 = fopen(filename3, "a+");
	stu *p, *q, *head;
	stu student;
	p = q = (stu*)malloc(sizeof(stu)-4);
	head = p;
	while (fscanf(fp3, "%s %d %d %d %d\n", student.Namec,&student.yu,&student.shu,&student.ying,&student.zongfen) != EOF)
	{
		p = (stu*)malloc(sizeof(stu)-4);
		strcpy(p->Namec, student.Namec);			//strcpy�������Ը���һ���ַ�����������ݵ���һ���ַ�������
		p->yu = student.yu;
		p->shu = student.shu;
		p->ying = student.ying;
		p->zongfen = student.zongfen;
		q->next = p;
		q = p;
	}
	fclose(fp3);
	q->next = NULL;
	return head;
}

stu *createlink2(void)								//���ļ������Ϣת����������
{
	fp2 = fopen(filename2, "a+");
	stu *p, *q, *head;
	stu student;
	p = q = (stu*)malloc(sizeof(stu)-7);
	head = p;
	while (fscanf(fp2, "%s %s\n", student.Namec, student.password) != EOF)
	{
		p = (stu*)malloc(sizeof(stu)-7);
		strcpy(p->Namec, student.Namec);			//strcpy�������Ը���һ���ַ�����������ݵ���һ���ַ�������
		strcpy(p->password, student.password);
		q->next = p;
		q = p;
	}
	fclose(fp2);
	q->next = NULL;
	return head;
}

tea *createlink1(void)								//���ļ������Ϣת����������
{
	fp1 = fopen(filename1, "a+");
	tea *p, *q, *head;
	tea teacher;
	p = q = (tea*)malloc(sizeof(tea)-3);
	head = p;
	while (fscanf(fp1, "%s %s\n", teacher.Namec, teacher.password) != EOF)
	{
		p = (tea*)malloc(sizeof(tea)-3);
		strcpy(p->Namec, teacher.Namec);			//strcpy�������Ը���һ���ַ�����������ݵ���һ���ַ�������
		strcpy(p->password, teacher.password);
		q->next = p;
		q = p;
	}
	fclose(fp1);
	q->next = NULL;
	return head;
}


stu *del2(stu*head, char Namec[])			//ɾ������ڵ�
{
	stu *p1, *p2;
	p2 = NULL;
	if (head == NULL)										//������ǿ�����
	{
		MessageBox(NULL, _T("���ݿ�����ѧ������"), _T("�޸�����"), MB_ICONSTOP | MB_SETFOREGROUND);
		return head;
	}
	p1 = head;
	while (strcmp(p1->Namec, Namec) != 0 && p1->next != NULL)//��������Ѱ��Ŀ��ֵ
	{
		p2 = p1;
		p1 = p2->next;
	}
	if (strcmp(p1->Namec, Namec) == 0)
	{
		if (p1 == head)//Ŀ��ڵ�Ϊͷ�ڵ�
		{
			head = p1->next;
		}
		else
		{
			p2->next = p1->next;
		}
	}
	return head;
}

tea *del1(tea*head, char Namec[])			//ɾ������ڵ�
{
	tea *p1, *p2;
	p2 = NULL;
	if (head == NULL)										//������ǿ�����
	{
		MessageBox(NULL, _T("���ݿ�����ѧ������"), _T("�޸�����"), MB_ICONSTOP | MB_SETFOREGROUND);
		return head;
	}
	p1 = head;
	while (strcmp(p1->Namec, Namec) != 0 && p1->next != NULL)//��������Ѱ��Ŀ��ֵ
	{
		p2 = p1;
		p1 = p2->next;
	}
	if (strcmp(p1->Namec, Namec) == 0)
	{
		if (p1 == head)//Ŀ��ڵ�Ϊͷ�ڵ�
		{
			head = p1->next;
		}
		else
		{
			p2->next = p1->next;
		}
	}
	return head;
}

stu *save3(stu*head)																//����ı���
{
	fp3 = fopen(filename3, "w+");												//��w+�ķ�ʽ���ļ������ļ���ԭ����������գ�д���µ�����
	while (head->next != NULL)
	{
		head = head->next;
		fprintf(fp3, "%s %d %d %d %d\n", head->Namec,head->yu,head->shu,head->ying,head->zongfen);//���������ļ���
	}
	fclose(fp3);
	return head;
}

stu *save2(stu*head)																//����ı���
{
	fp2 = fopen(filename2, "w+");												//��w+�ķ�ʽ���ļ������ļ���ԭ����������գ�д���µ�����
	while (head->next != NULL)
	{
		head = head->next;
		fprintf(fp2, "%s %s\n", head->Namec, head->password);//���������ļ���
	}
	fclose(fp2);
	return head;
}

tea *save1(tea*head)																//����ı���
{
	fp1 = fopen(filename1, "w+");												//��w+�ķ�ʽ���ļ������ļ���ԭ����������գ�д���µ�����
	while (head->next != NULL)
	{
		head = head->next;
		fprintf(fp1, "%s %s\n", head->Namec, head->password);//���������ļ���
	}
	fclose(fp1);
	return head;
}

stu *pop_sort(stu *head)								//����ð������
{
	stu *q, *p, *tail, *temp;
	tail = NULL;
	q = head;
	while ((head->next->next) != tail)
	{
		p = head->next;
		q = head;
		while (p->next != tail)
		{
			if ((p->zongfen)<(p->next->zongfen))
			{
				q->next = p->next;
				temp = p->next->next;
				p->next->next = p;
				p->next = temp;
				p = q->next;
			}
			p = p->next;
			q = q->next;
		}
		tail = p;
	}
	return head;
}

stu *Node(stu *head,int n)	//����ṹ��ָ��
{
	node[n] = head;
	return node[n];
}

void Welcome()
{
	loadimage(&welcome, L"begin.jpg");		//���뻶ӭ���棨�ر�ע�⣺˫�������治���пո�Ҫ��ͼƬ������ȫһ�£�
	putimage(0, 0, &welcome);				//��ʾ��ӭ����

	MOUSEMSG msg;							//������������������Ϣ
	FlushMouseMsgBuffer();					// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
	while (true)							// ��ѭ��,ѭ�����������Ϣ
	{
		while (MouseHit())					//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
		{
			msg = GetMouseMsg();			//��ȡ�����Ϣ
			if (WM_LBUTTONDOWN == msg.uMsg)	//�ж������Ϣ;����������
			{
				if (msg.x > 232 && msg.x < 498 && msg.y > 478 && msg.y < 543)//������˳���ť��������
				{
					loadimage(&welcom_button, L"welcome_button.jpg");	//���밴ť��ЧͼƬ
					putimage(0, 0, &welcom_button);						//��ʾ��ť��ЧͼƬ
					Sleep(100);											//��ʱ������CPUռ���ʣ������������Ч��
					MainMenu();											//����һ�����˵�ѡ���
				}
			}
		}
	}
}

//һ�����˵�(ѧ���ˡ���ʦ��)
void MainMenu()
{
	loadimage(&startup, L"4.jpg");
	putimage(0, 0, &startup);
	MOUSEMSG msg;
	FlushMouseMsgBuffer();	
	while (true)
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
			{
				if (msg.x > 185 && msg.x < 492 && msg.y > 541 && msg.y < 678)//�������ѧ���ˡ���ť��������
				{
					loadimage(&stu_button, L"stu_button.jpg");			//���밴ť��ЧͼƬ
					putimage(0, 0, &stu_button);						//��ʾ��ť��ЧͼƬ
					Sleep(100);
					Stu_SecondMenu();								//����ѧ���˺���
				}
				if (msg.x > 787 && msg.x < 1150 && msg.y > 548 && msg.y < 676)//���������ʦ�ˡ���ť��������
				{
					loadimage(&tea_button, L"tea_button.jpg");			//���밴ť��ЧͼƬ
					putimage(0, 0, &tea_button);						//��ʾ��ť��ЧͼƬ
					Sleep(100);
					Tea_SecondMenu();							//���ý�ʦ�˺���
				}
				if (msg.x > 1128 && msg.x < 1293 && msg.y > 28 && msg.y < 75)
				{
					loadimage(&exit_button, L"exit_button.jpg");
					putimage(0, 0, &exit_button);
					Sleep(100);
					loadimage(&end, L"end.jpg");
					putimage(0, 0, &end);
					system("pause");
					exit(0);
				}
			}
		}
	}
}

//�����˵�ѧ����Ŀ¼��ʾ
void Stu_SecondMenu()
{
	loadimage(&stu1, L"stu1.jpg");
	putimage(0, 0, &stu1);
	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
			{
				if (msg.x > 980 && msg.x < 1046 && msg.y > 554 && msg.y < 619)//�������ʦ�ˡ���ť��������
					Tea_SecondMenu();//���ý�ʦ�˺���
				if (msg.x > 683 && msg.x < 759 && msg.y > 563 && msg.y < 621)//����������ء���ť��������
					MainMenu();//����һ�����˵�ѡ���
				if (msg.x > 81 && msg.x < 365 && msg.y > 71 && msg.y < 134)//������������˻�����ť��������
					Stu_Register();//����ѧ�������˻�����
				if (msg.x > 81 && msg.x < 365 && msg.y > 162 && msg.y < 228)//�������ѧ����¼����ť��������
					Stu_Logon();//����ѧ����¼����
				if (msg.x > 81 && msg.x < 365 && msg.y > 252 && msg.y < 318)//��������޸����롱��ť��������
					Stu_ResetPassword();//����ѧ���޸����뺯��
				if (msg.x > 81 && msg.x < 365 && msg.y > 344 && msg.y < 413)//�������ѧ�����ҡ�ͳ�Ƴɼ�����ť��������
				{
					if (StuLogonFlag == 1)//ѧ���ѵ�¼
						Stu_ScoreManagement();//����ѧ���ɼ�������
					else
						MessageBox(NULL, _T("����δ��¼"), _T("ѧ������ϵͳ"), MB_ICONEXCLAMATION | MB_SETFOREGROUND);
				}
				if (msg.x > 21 && msg.x < 103 && msg.y > 613 && msg.y < 688)//��������ذ�ť
				{
					loadimage(&stu1_return, L"stu1_return.jpg");
					putimage(0, 0, &stu1_return);
					Sleep(100);
					Welcome();
				}
				if (msg.x>1063 && msg.x<1295 && msg.y>560 && msg.y<658)		//��������ؽ�ʦ��
				{
					loadimage(&returnteachermain_button, L"returnteachermain_button.jpg");
					putimage(0, 0, &returnteachermain_button);
					Sleep(100);
					Tea_SecondMenu();
				}
				if (msg.x>725 && msg.x<853 && msg.y>542 && msg.y<655)
				{
					loadimage(&returnmainmenu_button, L"returnmainmenu_button.jpg");
					putimage(0, 0, &returnmainmenu_button);
					Sleep(100);
					MainMenu();
				}
				if (msg.x > 1239 && msg.x < 1334 && msg.y > 20 && msg.y < 62)//�����exit��ť
				{
					StuLogonFlag = 0;
					TeaLogonFlag = 0;
					loadimage(&stu1_exit, L"stu1_exit.jpg");
					putimage(0, 0, &stu1_exit);
					Sleep(100);
					loadimage(&end, L"end.jpg");
					putimage(0, 0, &end);
					system("pause");
					exit(0);
				}
			}
		}
	}
}

//�����˵���ѧ�������˻�
void Stu_Register()
{
	stu student;
	stu student1;
	fp2 = fopen(filename2, "a+");//��׷�ӵķ�ʽ���ļ�

	loadimage(&stu_register, L"stu_register.jpg");//����ѧ���˴����˻�����
	putimage(0, 0, &stu_register);
	int i;
	do{
		i = 0;
		InputBox(student1.Namew, 10, _T("�������û���"));//��ʾ�û������û���
		//�����������û���Ϣ���е����ݣ��Ƚ���������û����Ƿ���ڣ�������ڣ�ϵͳ������ʾ
		while (fscanf(fp2, "%s\n", student.Namec) != EOF)
		{
			if (strcmp(student.Namec, UnicodeToAnsi(student1.Namew)) == 0)
			{
				i++;
				MessageBox(NULL, _T("���û��Ѿ����ڣ�����������"), _T("�����˻�"), MB_ICONSTOP | MB_SETFOREGROUND);//�����ʾ�������û�
				break;	//����whileѭ��
			}
		}
		if (i == 0)		//˵��û���ҵ��ظ����û��� 
			break;
	} while (1);		//����û����ظ���һֱѭ����ֱ�����ظ�ʱ����ѭ�� 
	//�����û����������� 
	//�����������
	do{
		InputBox(student1.password1, 7, _T("������6λ������"));//��ʾ�û���������
		InputBox(student1.password2, 7, _T("��ȷ������"));//��ʾ�û�ȷ������
		if (wcscmp(student1.password1, student1.password2) != 0)//�����������벻��� 
			MessageBox(NULL, _T("�������벻һ�£�����������"), _T("�����˻�"), MB_ICONSTOP | MB_SETFOREGROUND);
		else
		{
			MessageBox(NULL, _T("ע��ɹ���"), _T("�����˻�"), MB_SETFOREGROUND);
			fprintf(fp2, "%s %s\n", UnicodeToAnsi(student1.Namew),UnicodeToAnsi(student1.password2));//�ļ�����
			break;
		}
	} while (1);
	fclose(fp2);
}

void Stu_Logon()
{
	stu student;
	loadimage(&stu_logon, L"stu_logon.jpg");//����ѧ����ѧ����¼����
	putimage(0, 0, &stu_logon);

	int i;
	wchar_t username[LENGTH];//����һ����ʱ�洢�û������ַ����� 
	wchar_t password[LENGTH];//����һ����ʱ�洢������ַ����� 
	do{
		i = 0;
		fp2 = fopen(filename2, "a+");
		InputBox(username, 10, _T("�������û���"));//��ʾ�û������û������������ʱ�洢�û������ַ�����
		while (fscanf(fp2, "%s\n", student.Namec) != EOF)
		{
			if (strcmp(UnicodeToAnsi(username), student.Namec) == 0)//��ȡ�û���
			{
				i++;
				break;
			}
		}
		if (i==0)//˵��û���ҵ���Ӧ�û��� 
			MessageBox(NULL, _T("���û�������"), _T("ѧ����¼"), MB_ICONSTOP | MB_SETFOREGROUND);
		else
			break;//�ҵ��˴��û������˳������û�����ѭ����������������ģ�� 
		fclose(fp2);
	} while (1);
	//��������
	int j, k = 3;
	do {
		j = 0;
		fp2 = fopen(filename2, "a+");
		InputBox(password, 7, _T("������6λ����"));//��ʾ�û��������룬�������ʱ�洢������ַ�����
		while (fscanf(fp2, "%s\n", student.password) != EOF)
		{
			if (strcmp(UnicodeToAnsi(password), student.password) == 0)//��ȡ����
			{
				j++;
				MessageBox(NULL, _T("��¼�ɹ���"), _T("ѧ����¼"), MB_SETFOREGROUND);
				StuLogonFlag = 1;//��־���Ѿ��ɹ���¼ 
				break;
			}
		}
		if (j != 0)
		{
			break;
		}
		if (j == 0)
		{
			MessageBox(NULL, _T("�������"), _T("ѧ����¼"), MB_ICONSTOP | MB_SETFOREGROUND);
			k--;
		}
		if (k == 0)
		{
			break;
		}
		fclose(fp2);
	} while (1);
}


//�����˵���ѧ���޸�����
void Stu_ResetPassword()
{
	stu student, *head;
	loadimage(&stu_resetpassword, L"stu_resetpassword.jpg");//����ѧ�����޸��������
	putimage(0, 0, &stu_resetpassword);

	int i;
	wchar_t username[LENGTH];
	wchar_t password[LENGTH];
	wchar_t resetpassword[LENGTH];//����һ����ʱ�洢�޸ĺ�������ַ����� 
	do {
		i = 0;
		fp2 = fopen(filename2, "a+");
		InputBox(username, 10, _T("�������û���"));					//��ʾ�û������û������������ʱ�洢�û������ַ�����
		while (fscanf(fp2, "%s\n", student.Namec) != EOF)
		{
			if (strcmp(UnicodeToAnsi(username), student.Namec) == 0)//��ȡ�û���
			{
				i++;
				break;
			}
		}
		if (i==0)													//˵��û���ҵ���Ӧ�û��� 
			MessageBox(NULL, _T("���û�������"), _T("�޸�����"), MB_ICONSTOP | MB_SETFOREGROUND);
		else
			break;
		fclose(fp2);
	} while (1);
	fclose(fp2);
	int j, k = 3;
	do {
		j = 0;
		fp2 = fopen(filename2, "a+");
		InputBox(password, 7, _T("������ԭʼ����"));
		while (fscanf(fp2, "%s\n", student.password) != EOF)
		{
			if (strcmp(UnicodeToAnsi(password), student.password) == 0)//��ȡ����
			{
				j++;
				InputBox(resetpassword, 7, _T("������ȷ��������6λ���޸�����"));
				MessageBox(NULL, _T("�޸�����ɹ���"), _T("�޸�����"), MB_SETFOREGROUND);
				fclose(fp2);
				head = del2(createlink2(), UnicodeToAnsi(username));		//���ļ�ת����������ɾ��ԭ�е��û���Ϣ
				stu *head1 = head, *p1;
				while (head1->next != NULL)
				{
					head1 = head1->next;
				}
				p1 = (stu*)malloc(sizeof(stu)-7);
				p1->next=NULL;
				strcpy(p1->Namec, UnicodeToAnsi(username));
				strcpy(p1->password, UnicodeToAnsi(resetpassword));
				head1->next = p1;											//���޸ĺ���û���Ϣ�Ž�����
				save2(head);												//�����������Ϣ����д���ļ�
				break;
			}
		}
		if (j != 0)
		{
			break;
		}
		if (j == 0)
		{
			MessageBox(NULL, _T("�������"), _T("�޸�����"), MB_ICONSTOP | MB_SETFOREGROUND);
			k--;
		}
		if (k == 0)
		{
			break;
		}
	} while (1);
}

//�����˵���ѧ���ɼ���ѯ
void Stu_ScoreManagement()
{
	loadimage(&stu_scoremanagement1, L"stu_scoremanagement1.jpg");
	putimage(0, 0, &stu_scoremanagement1);
	stu student, *head, *p, *q, *head1;
	p = q = (stu*)malloc(sizeof(stu)-5);
	head = p;
	int m = 0, m1 = 1;
	int position_x = 430;
	int position_y = 80;
	char yu[LENGTH];
	char shu[LENGTH];
	char ying[LENGTH];
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(30, 0, _T("����"));
	char sequencenum[100];
	wchar_t username[LENGTH];
	InputBox(username, 5, _T("��������Ҫ���ҵ�ѧ��������"));
	outtextxy(position_x, position_y, _T("���     ����     ����     ��ɢ     ��ѧӢ��"));
	fp3 = fopen(filename3, "a+");
	while (fscanf(fp3, "%s %d %d %d %d\n", student.Namec, &student.yu, &student.shu, &student.ying, &student.zongfen) != EOF)
	{
		if (strstr(student.Namec, UnicodeToAnsi(username)) != NULL)
		{
			p = (stu*)malloc(sizeof(stu)-5);
			strcpy(p->Namec, student.Namec);
			p->yu = student.yu;
			p->shu = student.shu;
			p->ying = student.ying;
			q->next = p;
			q = p;
		}
	}
	q->next = NULL;
	head1 = head;
	page9 = 1;
	while (head1 != NULL)
	{
		head1 = head1->next;
		if (m1 == 1)
		{
			node5[page9] = head1;
		}
		if (m1 % 9 == 0)
		{
			page9++;
			node5[page9] = head1;
		}
		m1++;
	}
	head = head->next;
	while (head != NULL)
	{
		m++;
		itoa(head->yu, yu, 10);
		itoa(head->shu, shu, 10);
		itoa(head->ying, ying, 10);
		sprintf(sequencenum, "%d", m);
		position_y += 35;
		outtextxy(445, position_y, UnicodeToAnsi2(sequencenum));
		outtextxy(555, position_y, UnicodeToAnsi2(head->Namec));
		outtextxy(700, position_y, UnicodeToAnsi2(yu));
		outtextxy(842, position_y, UnicodeToAnsi2(shu));
		outtextxy(1010, position_y, UnicodeToAnsi2(ying));
		head = head->next;
		if (m == 8)
		{
			break;
		}
	}
	if (m == 8)
	{
		page10 = 1;
		FlipOverMenu_Stu_SecondMenu();
	}
	if (m == 0)
	{
		MessageBox(NULL, _T("��ʦδ��Ӹ�ѧ�������ݿ�"), _T("ѧ������"), MB_ICONSTOP | MB_SETFOREGROUND);
	}
	fclose(fp3);
}

void FlipOverMenu_Stu_SecondMenu()		//ѧ���˵ķ�ҳ�˵�
{
	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
			{
				if (msg.x > 980 && msg.x < 1046 && msg.y > 554 && msg.y < 619)//�������ʦ�ˡ���ť��������
					Tea_SecondMenu();//���ý�ʦ�˺���
				if (msg.x > 683 && msg.x < 759 && msg.y > 563 && msg.y < 621)//����������ء���ť��������
					MainMenu();//����һ�����˵�ѡ���
				if (msg.x > 81 && msg.x < 365 && msg.y > 71 && msg.y < 134)//������������˻�����ť��������
					Stu_Register();//����ѧ�������˻�����
				if (msg.x > 81 && msg.x < 365 && msg.y > 162 && msg.y < 228)//�������ѧ����¼����ť��������
					Stu_Logon();//����ѧ����¼����
				if (msg.x > 81 && msg.x < 365 && msg.y > 252 && msg.y < 318)//��������޸����롱��ť��������
					Stu_ResetPassword();//����ѧ���޸����뺯��
				if (msg.x > 81 && msg.x < 365 && msg.y > 344 && msg.y < 413)//�������ѧ�����ҡ�ͳ�Ƴɼ�����ť��������
				{
					if (StuLogonFlag == 1)//ѧ���ѵ�¼
						Stu_ScoreManagement();//����ѧ���ɼ�������
					else
						MessageBox(NULL, _T("����δ��¼"), _T("ѧ������ϵͳ"), MB_ICONEXCLAMATION | MB_SETFOREGROUND);
				}
				if (page10>0 && msg.x>491 && msg.x<678 && msg.y>443 && msg.y<503)//��һҳ
				{
					if (page10 <= 1)
						MessageBox(NULL, _T("�Ѿ��ǵ�һҳ"), _T("ѧ������"), MB_ICONSTOP | MB_SETFOREGROUND);
					else
					{
						page10--;
						loadimage(&stu_scoremanagement1, L"stu_scoremanagement1.jpg");
						putimage(0, 0, &stu_scoremanagement1);
						Sleep(100);
						loadimage(&stu_findscore_flipoverbutton_previouspage, L"stu_findscore_flipoverbutton_previouspage.jpg");
						putimage(0, 0, &stu_findscore_flipoverbutton_previouspage);
						PreviousPageAndNextPage_Stu_SecondMenu(page10);
					}
				}
				if (page10 <= page9 && msg.x>723 && msg.x<929 && msg.y>420 && msg.y<503)//��һҳ
				{
					if (page10 == page9)
						MessageBox(NULL, _T("�Ѿ������һҳ"), _T("ѧ������"), MB_ICONSTOP | MB_SETFOREGROUND);
					else
					{
						page10++;
						loadimage(&stu_scoremanagement1, L"stu_scoremanagement1.jpg");
						putimage(0, 0, &stu_scoremanagement1);
						Sleep(100);
						loadimage(&stu_findscore_flipoverbutton_nextpage, L"stu_findscore_flipoverbutton_nextpage.jpg");
						putimage(0, 0, &stu_findscore_flipoverbutton_nextpage);
						PreviousPageAndNextPage_Stu_SecondMenu(page10);
					}
				}
				if (msg.x > 21 && msg.x < 103 && msg.y > 613 && msg.y < 688)//��������ذ�ť
				{
					loadimage(&stu1_return, L"stu1_return.jpg");
					putimage(0, 0, &stu1_return);
					Sleep(100);
					Welcome();
				}
				if (msg.x>1063 && msg.x<1295 && msg.y>560 && msg.y<658)		//��������ؽ�ʦ��
				{
					loadimage(&returnteachermain_button, L"returnteachermain_button.jpg");
					putimage(0, 0, &returnteachermain_button);
					Sleep(100);
					Tea_SecondMenu();
				}
				if (msg.x>725 && msg.x<853 && msg.y>542 && msg.y<655)		//������ص����˵�
				{
					loadimage(&returnmainmenu_button, L"returnmainmenu_button.jpg");
					putimage(0, 0, &returnmainmenu_button);
					Sleep(100);
					MainMenu();
				}
				if (msg.x > 1239 && msg.x < 1334 && msg.y > 20 && msg.y < 62)//�����exit��ť
				{
					StuLogonFlag = 0;
					TeaLogonFlag = 0;
					loadimage(&stu1_exit, L"stu1_exit.jpg");
					putimage(0, 0, &stu1_exit);
					Sleep(100);
					loadimage(&end, L"end.jpg");
					putimage(0, 0, &end);
					system("pause");
					exit(0);
				}
			}
		}
	}
}

void PreviousPageAndNextPage_Stu_SecondMenu(int page)	//��ҳѧ���˲��ҷ�ҳ
{
	stu *head = node5[page];
	int m;
	if (page == 1)
		m = 0;
	else
		m = (page - 1) * 8;
	int position_x = 430;
	int position_y = 80;
	char yu[LENGTH];
	char shu[LENGTH];
	char ying[LENGTH];
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(30, 0, _T("����"));
	outtextxy(position_x, position_y, _T("���     ����     ����     ��ɢ     ��ѧӢ��"));
	char sequencenum[100];
	while (head != NULL)
	{
		m++;
		itoa(head->yu, yu, 10);
		itoa(head->shu, shu, 10);
		itoa(head->ying, ying, 10);
		sprintf(sequencenum, "%d", m);
		position_y += 35;
		outtextxy(445, position_y, UnicodeToAnsi2(sequencenum));
		outtextxy(555, position_y, UnicodeToAnsi2(head->Namec));
		outtextxy(700, position_y, UnicodeToAnsi2(yu));
		outtextxy(842, position_y, UnicodeToAnsi2(shu));
		outtextxy(1010, position_y, UnicodeToAnsi2(ying));
		head = head->next;
		if (m % 8 == 0)
		{
			break;
		}
	}
}

//�ڶ�����ʦ�˵�
void Tea_SecondMenu()
{
	loadimage(&teacher1, L"teacher1.jpg");
	putimage(0, 0, &teacher1);

	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true) 
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
			{
				if (msg.x > 408 && msg.x < 554 && msg.y > 474 && msg.y < 619)//�������ѧ���ˡ���ť��������
				{
					loadimage(&returnstudentmain_button, L"returnstudentmain_button.jpg");
					putimage(0, 0, &returnstudentmain_button);
					Sleep(100);
					Stu_SecondMenu();//����ѧ���˺���
				}
				if (msg.x > 683 && msg.x < 759 && msg.y > 563 && msg.y < 621)//�������ѧ���ˡ���ť��������
				{
					loadimage(&tea_returnwelcome, L"tea_returnwelcome.jpg");
					putimage(0, 0, &tea_returnwelcome);
					Sleep(100);
					MainMenu();//����һ�����˵�����
				}
				if (msg.x > 81 && msg.x < 365 && msg.y > 69 && msg.y < 135)//������������˻�����ť��������
					Tea_Register();//���ý�ʦ�����˻�����
				if (msg.x > 81 && msg.x < 365 && msg.y > 162 && msg.y < 227)//���������ʦ��¼����ť��������
					Tea_Logon();//���ý�ʦ��¼����
				if (msg.x > 81 && msg.x < 365 && msg.y > 254 && msg.y < 320)//��������޸����롱��ť��������
					Tea_ResetPassword();//���ý�ʦ�޸����뺯��
				if (msg.x > 81 && msg.x < 365 && msg.y > 347 && msg.y < 410)//�����������ѧ���ɼ�����ť��������
				{
					if (TeaLogonFlag == 1)//�ѵ�¼
					{
						loadimage(&teacher_scoremanagement1, L"teacher_scoremanagement1.jpg");
						putimage(0, 0, &teacher_scoremanagement1);
						Sleep(100);
						Tea_ScoreManagement();//���ý�ʦ��ѧ���ɼ�������
					}
					else
						MessageBox(NULL, _T("����δ��¼"), _T("ѧ������ϵͳ"), MB_ICONEXCLAMATION | MB_SETFOREGROUND);
				}
				if (msg.x > 21 && msg.x < 103 && msg.y > 613 && msg.y < 688)//��������ذ�ť
				{
					loadimage(&teacher1_return, L"teacher1_return.jpg");
					putimage(0, 0, &teacher1_return);
					Sleep(100);
					Welcome();
				}
				if (msg.x > 1239 && msg.x < 1334 && msg.y > 20 && msg.y < 62)//�����exit��ť
				{
					StuLogonFlag = 0;
					TeaLogonFlag = 0;
					loadimage(&stu1_exit, L"teacher1_exit.jpg");
					putimage(0, 0, &stu1_exit);
					Sleep(100);
					loadimage(&end, L"end.jpg");
					putimage(0, 0, &end);
					system("pause");
					exit(0);
				}
			}
		}
	}
}

//��ʦע��
void Tea_Register()
{
	tea teacher;
	tea teacher1;
	fp1 = fopen(filename1, "a+");//��׷�ӵķ�ʽ���ļ�

	loadimage(&tea_register, L"teacher_register.jpg");//����ѧ���˴����˻�����
	putimage(0, 0, &tea_register);
	int i;
	do{
		i = 0;
		InputBox(teacher1.Namew, 10, _T("�������û���"));
		while (fscanf(fp1, "%s\n", teacher.Namec) != EOF)
		{
			if (strcmp(teacher.Namec, UnicodeToAnsi(teacher1.Namew)) == 0)
			{
				i++;
				MessageBox(NULL, _T("���û��Ѿ����ڣ�����������"), _T("�����˻�"), MB_ICONSTOP | MB_SETFOREGROUND);//�����ʾ�������û�
				break;	//����whileѭ��
			}
		}
		if (i == 0)		//˵��û���ҵ��ظ����û��� 
			break;
	} while (1);		//����û����ظ���һֱѭ����ֱ�����ظ�ʱ����ѭ�� 


	//��������
	do{
		InputBox(teacher1.password1, 7, _T("������6λ������"));//��ʾ�û���������
		InputBox(teacher1.password2, 7, _T("��ȷ������"));//��ʾ�û�ȷ������
		if (wcscmp(teacher1.password1, teacher1.password2) != 0)//�����������벻��� 
			MessageBox(NULL, _T("�������벻һ�£�����������"), _T("�����˻�"), MB_ICONSTOP | MB_SETFOREGROUND);
		else
		{
			MessageBox(NULL, _T("ע��ɹ���"), _T("�����˻�"), MB_SETFOREGROUND);
			fprintf(fp1, "%s %s\n", UnicodeToAnsi(teacher1.Namew), UnicodeToAnsi(teacher1.password2));//�ļ�����
			break;
		}
	} while (1);
	fclose(fp1);
}

void Tea_Logon()	//��ʦ��¼
{
	tea teacher;
	loadimage(&tea_logon, L"teacher_logon.jpg");
	putimage(0, 0, &tea_logon);
	int i;
	wchar_t username[LENGTH];
	wchar_t password[LENGTH];
	do{
		i = 0;
		fp1 = fopen(filename1, "a+");
		InputBox(username, 10, _T("�������û���"));
		while (fscanf(fp1, "%s\n", teacher.Namec) != EOF)
		{
			if (strcmp(UnicodeToAnsi(username), teacher.Namec) == 0)//��ȡ����
			{
				i++;
				break;
			}
		}
		if (i == 0)//˵��û���ҵ���Ӧ�û��� 
			MessageBox(NULL, _T("���û�������"), _T("��ʦ��¼"), MB_ICONSTOP | MB_SETFOREGROUND);
		else
			break;//�ҵ��˴��û������˳������û�����ѭ����������������ģ�� 
		fclose(fp1);
	} while (1);
	//��������
	int j, k = 3;
	do {
		j = 0;
		fp1 = fopen(filename1, "a+");
		InputBox(password, 7, _T("������6λ����"));
		while (fscanf(fp1, "%s\n", teacher.password) != EOF)
		{
			if (strcmp(UnicodeToAnsi(password), teacher.password) == 0)//��ȡ����
			{
				j++;
				MessageBox(NULL, _T("��¼�ɹ���"), _T("��ʦ��¼"), MB_SETFOREGROUND);
				TeaLogonFlag = 1;//��־��ʦ�û���¼�ɹ� 
				break;
			}
		}
		if (j != 0)
		{
			break;
		}
		if (j == 0)
		{
			MessageBox(NULL, _T("�������"), _T("ѧ����¼"), MB_ICONSTOP | MB_SETFOREGROUND);
			k--;
		}
		if (k == 0)
		{
			break;
		}
		fclose(fp1);
	} while (1);
}

//�����˵�����ʦ�޸�����
void Tea_ResetPassword()
{
	tea teacher, *head;
	loadimage(&teacher_resetpassword, L"teacher_resetpassword.jpg");//����ѧ�����޸��������
	putimage(0, 0, &teacher_resetpassword);
 
	int i;
	wchar_t username[LENGTH];
	wchar_t password[LENGTH];
	wchar_t resetpassword[LENGTH];
	do {
		i = 0;
		fp1 = fopen(filename1, "a+");
		InputBox(username, 10, _T("�������û���"));
		while (fscanf(fp1, "%s\n", teacher.Namec) != EOF)
		{
			if (strcmp(UnicodeToAnsi(username), teacher.Namec) == 0)//��ȡ�û���
			{
				i++;
				break;
			}
		}
		if (i == 0)													//˵��û���ҵ���Ӧ�û��� 
			MessageBox(NULL, _T("���û�������"), _T("�޸�����"), MB_ICONSTOP | MB_SETFOREGROUND);
		else
			break;
		fclose(fp1);
	} while (1);
	fclose(fp1);
	int j, k = 3;
	do {
		j = 0;
		fp1 = fopen(filename1, "a+");
		InputBox(password, 7, _T("������ԭʼ����"));
		while (fscanf(fp1, "%s\n", teacher.password) != EOF)
		{
			if (strcmp(UnicodeToAnsi(password), teacher.password) == 0)//��ȡ����
			{
				j++;
				InputBox(resetpassword, 7, _T("������ȷ��������6λ���޸�����"));
				MessageBox(NULL, _T("�޸�����ɹ���"), _T("�޸�����"), MB_SETFOREGROUND);
				fclose(fp1);
				head = del1(createlink1(), UnicodeToAnsi(username));		//���ļ�ת����������ɾ��ԭ�е��û���Ϣ
				tea *head1 = head, *p1;
				while (head1->next != NULL)
				{
					head1 = head1->next;
				}
				p1 = (tea*)malloc(sizeof(tea)-3);
				p1->next = NULL;
				strcpy(p1->Namec, UnicodeToAnsi(username));
				strcpy(p1->password, UnicodeToAnsi(resetpassword));
				head1->next = p1;											//���޸ĺ���û���Ϣ�Ž�����
				save1(head);												//�����������Ϣ����д���ļ�
				break;
			}
		}
		if (j != 0)
		{
			break;
		}
		if (j == 0)
		{
			MessageBox(NULL, _T("�������"), _T("�޸�����"), MB_ICONSTOP | MB_SETFOREGROUND);
			k--;
		}
		if (k == 0)
		{
			break;
		}
	} while (1);
}

//ѧ������˵�(��ʦ��)
void Tea_ScoreManagement()
{
	loadimage(&teacher_scoremanagement2, L"teacher_scoremanagement2.jpg");
	putimage(0, 0, &teacher_scoremanagement2);
	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
			{
				if (msg.x > 68 && msg.x < 314 && msg.y > 69 && msg.y < 146)//�����������ѧ���ɼ�����ť��������
				{
					Stu_CreateScore();//��������ѧ���ɼ�����
				}
				if (msg.x > 59 && msg.x < 314 && msg.y > 149 && msg.y < 231)//��������޸�ѧ���ɼ�����ť��������
					Stu_AmendScore();//���ý�ʦ�޸�ѧ���ɼ�����
				if (msg.x > 62 && msg.x < 314 && msg.y > 231 && msg.y < 319)//�������ɾ��ѧ���ɼ�����ť��������
					Stu_DeleteScore();//���ý�ʦɾ��ѧ���ɼ�����
				if (msg.x > 62 && msg.x < 314 && msg.y > 319 && msg.y < 404)//����ѧ����Ϣ
					Stu_FindInformation();
				if (msg.x > 62 && msg.x < 314 && msg.y > 404 && msg.y < 476)//ͳ��ѧ���ɼ�
					Stu_ScoreStatistics();
				if (msg.x > 62 && msg.x < 314 && msg.y > 476 && msg.y < 623)//��������ذ�ť
				{
					loadimage(&teacher_scoremanagement2_return, L"teacher_scoremanagement2_return.jpg");
					putimage(0, 0, &teacher_scoremanagement2_return);
					Sleep(100);
					Tea_SecondMenu();//���ö����˵���ʦ��
				}
			}
		}
	}
}

void Stu_CreateScore()				//����ѧ���ɼ���Ϣ
{
	loadimage(&createscore, L"createscore.jpg");
	putimage(0, 0, &createscore);
	stu student;
	int m = 0;
	wchar_t Name[LENGTH];
	wchar_t yu[LENGTH];
	wchar_t shu[LENGTH];
	wchar_t ying[LENGTH];
	InputBox(Name, 5, _T("ѧ������"));
	fp3 = fopen(filename3, "a+");
	while (fscanf(fp3, "%s\n", student.Namec) != EOF)
	{
		if (strcmp(student.Namec, UnicodeToAnsi(Name)) == 0)
		{
			m++;
			MessageBox(NULL, _T("���и�ѧ����"), _T("ѧ���ɼ����"), MB_ICONSTOP | MB_SETFOREGROUND);
		}
	}
	if (m == 0)
	{
		InputBox(yu, 4, _T("�����ɼ�(����100)"));
		InputBox(shu, 4, _T("��ɢ�ɼ�(����100)"));
		InputBox(ying, 4, _T("��ѧӢ��ɼ�(����100)"));
		MessageBox(NULL, _T("��ӳɹ�!"), _T("ѧ�����"), MB_SETFOREGROUND);
		student.zongfen = atoi(UnicodeToAnsi(yu)) + atoi(UnicodeToAnsi(shu)) + atoi(UnicodeToAnsi(ying));
		fprintf(fp3, "%s %d %d %d %d\n", UnicodeToAnsi(Name), atoi(UnicodeToAnsi(yu)), atoi(UnicodeToAnsi(shu)), atoi(UnicodeToAnsi(ying)), student.zongfen);//atoi()�������Խ��ַ���ת��Ϊ������
		char sequencenum[10];
		sprintf(sequencenum, "%d", 1);
		int position_x = 580;	//����š�������
		int position_y = 27;	//����š�������
		setbkmode(TRANSPARENT);	//�������屳��Ϊ͸��
		settextcolor(COLORREF(RGB(0, 0, 0)));	//����������ɫΪ��ɫ
		settextstyle(40, 0, _T("����"));		//���������С����ʽ����
		outtextxy(position_x, position_y, _T("���   ����   ����   ��ɢ   ��ѧӢ��"));//��ʾ����һ�б�ͷ
		position_y += 45;//������һ��
		outtextxy(600, position_y, UnicodeToAnsi2(sequencenum));//��ʾ���
		outtextxy(712, position_y, Name);						//����
		outtextxy(865, position_y, yu);
		outtextxy(1018, position_y, shu);
		outtextxy(1200, position_y, ying);
	}
	fclose(fp3);
}

void Stu_AmendScore()			//ѧ���ɼ��޸ĺ���
{
	loadimage(&resetscore, L"resetscore.jpg");
	putimage(0, 0, &resetscore);

	wchar_t Name[LENGTH];
	wchar_t yu[LENGTH];
	wchar_t shu[LENGTH];
	wchar_t ying[LENGTH];
	char yu2[LENGTH];
	char shu2[LENGTH];
	char ying2[LENGTH];
	int m = 0;
	char sequencenum[10];
	stu student, *head;
	sprintf(sequencenum, "%d", 1);
	int position_x = 580;
	int position_y = 27;
	setbkmode(TRANSPARENT);	//�������屳��Ϊ͸��
	settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
	settextstyle(40, 0, _T("����"));//���������С����ʽ����
	fp3 = fopen(filename3, "a+");
	InputBox(Name, 5, _T("��������Ҫ�޸ĳɼ�ѧ��������"));
	while (fscanf(fp3, "%s %d %d %d %d\n", student.Namec,&student.yu,&student.shu,&student.ying,&student.zongfen) != EOF)
	{
		if (strcmp(student.Namec, UnicodeToAnsi(Name)) ==0 )
		{
			itoa(student.yu, yu2, 10);
			//char *itoa(int value, char *str, int base);
			//int value ��ת����������char *string ת���󴢴���ַ����飬int radix ת������������2, 8, 10, 16 ���Ƶȣ���СӦ��2 - 36֮�䡣
			itoa(student.shu, shu2, 10);
			itoa(student.ying, ying2, 10);
			outtextxy(position_x, position_y, _T("���   ����   ����   ��ɢ   ��ѧӢ��"));//��ʾ����һ�б�ͷ
			position_y += 45;											//������һ��
			outtextxy(600, position_y, UnicodeToAnsi2(sequencenum));	//���
			outtextxy(712, position_y, Name);							//����
			outtextxy(865, position_y, UnicodeToAnsi2(yu2));
			outtextxy(1018, position_y, UnicodeToAnsi2(shu2));
			outtextxy(1200, position_y, UnicodeToAnsi2(ying2));
			m++;
		}
	}
	if (m == 0)
	{
		MessageBox(NULL, _T("�޸�ѧ����"), _T("ѧ���ɼ��޸�"), MB_ICONSTOP | MB_SETFOREGROUND);
	}
	else
	{
		InputBox(yu, 4, _T("��������������ɼ�(����100)"));
		InputBox(shu, 4, _T("������������ɢ�ɼ�(����100)"));
		InputBox(ying, 4, _T("�����������ѧӢ��ɼ�(����100)"));
		head = del2(createlink3()->next, UnicodeToAnsi(Name));		//���ļ�ת����������ɾ��ԭ�е��û���Ϣ
		stu *head1 = head, *p1;
		while (head1->next != NULL)
		{
			head1 = head1->next;
		}
		p1 = (stu*)malloc(sizeof(stu)-4);
		p1->next = NULL;
		strcpy(p1->Namec, UnicodeToAnsi(Name));
		p1->yu = atoi(UnicodeToAnsi(yu));
		p1->shu = atoi(UnicodeToAnsi(shu));
		p1->ying = atoi(UnicodeToAnsi(ying));
		p1->zongfen = atoi(UnicodeToAnsi(yu)) + atoi(UnicodeToAnsi(shu)) + atoi(UnicodeToAnsi(ying));	//�����ܷ�
		head1->next = p1;										//���޸ĺ���û���Ϣ�Ž�����
		save3(head);											//�����������Ϣ����д���ļ�
		MessageBox(NULL, _T("�޸ĳɹ���"), _T("ѧ���ɼ��޸�"), MB_SETFOREGROUND);
		loadimage(&resetscore, L"resetscore.jpg");
		putimage(0, 0, &resetscore);
		position_x = 580;
		position_y = 27;
		outtextxy(position_x, position_y, _T("���   ����   ����   ��ɢ   ��ѧӢ��"));//��ʾ����һ�б�ͷ
		position_y += 45;
		outtextxy(600, position_y, UnicodeToAnsi2(sequencenum));
		outtextxy(712, position_y, Name);
		outtextxy(865, position_y, yu);
		outtextxy(1018, position_y, shu);
		outtextxy(1200, position_y, ying);
	}
	fclose(fp3);
}

void Stu_DeleteScore()			//ѧ����Ϣɾ������
{
	loadimage(&delscore, L"delscore.jpg");
	putimage(0, 0, &delscore);

	wchar_t Name[LENGTH];//����һ��"����"�ַ�����
	char yu2[LENGTH];
	char shu2[LENGTH];
	char ying2[LENGTH];
	int m = 0;
	char sequencenum1[10];
	stu student, *head;
	sprintf(sequencenum1, "%d", 1);
	int position_x = 580;
	int position_y = 27;
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(40, 0, _T("����"));
	fp3 = fopen(filename3, "a+");
	InputBox(Name, 5, _T("��������Ҫɾ��ѧ��������"));
	while (fscanf(fp3, "%s %d %d %d %d\n", student.Namec, &student.yu, &student.shu, &student.ying,&student.zongfen) != EOF)
	{
		if (strcmp(student.Namec, UnicodeToAnsi(Name)) == 0)
		{
			itoa(student.yu, yu2, 10);
			itoa(student.shu, shu2, 10);
			itoa(student.ying, ying2, 10);
			outtextxy(position_x, position_y, _T("���   ����   ����   ��ɢ   ��ѧӢ��"));//��ʾ����һ�б�ͷ
			position_y += 45;//������һ��
			outtextxy(600, position_y, UnicodeToAnsi2(sequencenum1));//��ʾ���
			outtextxy(712, position_y, Name);//����
			outtextxy(865, position_y, UnicodeToAnsi2(yu2));//�ɼ�
			outtextxy(1018, position_y, UnicodeToAnsi2(shu2));//�ɼ�
			outtextxy(1200, position_y, UnicodeToAnsi2(ying2));//�ɼ�
			m++;
		}
	}
	if (m == 0)
	{
		MessageBox(NULL, _T("�޸�ѧ����"), _T("ѧ��ɾ��"), MB_ICONSTOP | MB_SETFOREGROUND);
	}
	else
	{
		head = del2(createlink3()->next, UnicodeToAnsi(Name));		//���ļ�ת����������ɾ��ԭ�е��û���Ϣ
		save3(head);											//�����������Ϣ����д���ļ�
		MessageBox(NULL, _T("ɾ���ɹ���"), _T("ѧ��ɾ��"), MB_SETFOREGROUND);
		loadimage(&delscore, L"delscore.jpg");
		putimage(0, 0, &delscore);
	}
	fclose(fp3);
}

void Stu_FindInformation()				//����ѧ��
{
	loadimage(&findscore, L"findscore.jpg");
	putimage(0, 0, &findscore);

	stu student, *head, *p, *q, *head1;
	p = q = (stu*)malloc(sizeof(stu)-5);
	head = p;
	int m = 0, m1 = 1;
	int position_x = 580;
	int position_y = 27;
	char yu[LENGTH];
	char shu[LENGTH];
	char ying[LENGTH];
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(40, 0, _T("����"));
	char sequencenum[100];
	wchar_t username[LENGTH];
	InputBox(username, 5, _T("��������Ҫ���ҵ�ѧ��������"));
	outtextxy(position_x, position_y, _T("���   ����   ����   ��ɢ   ��ѧӢ��"));
	fp3 = fopen(filename3, "a+");
	while (fscanf(fp3, "%s %d %d %d %d\n", student.Namec, &student.yu, &student.shu, &student.ying,&student.zongfen) != EOF)
	{
		if (strstr(student.Namec, UnicodeToAnsi(username)) != NULL)
		{
			p = (stu*)malloc(sizeof(stu)-5);
			strcpy(p->Namec, student.Namec);
			p->yu = student.yu;
			p->shu = student.shu;
			p->ying = student.ying;
			q->next = p;
			q = p;
		}
	}
	q->next = NULL;
	head1 = head;
	page7 = 1;
	while (head1 != NULL)
	{
		head1 = head1->next;
		if (m1 == 1)
		{
			node4[page7] = head1;
		}
		if (m1 % 14 == 0)
		{
			page7++;
			node4[page7] = head1;
		}
		m1++;
	}
	head = head->next;
	while (head != NULL)
	{
		m++;
		itoa(head->yu, yu, 10);
		itoa(head->shu, shu, 10);
		itoa(head->ying, ying, 10);
		sprintf(sequencenum, "%d", m);
		position_y += 45;
		outtextxy(600, position_y, UnicodeToAnsi2(sequencenum));
		outtextxy(712, position_y, UnicodeToAnsi2(head->Namec));
		outtextxy(865, position_y, UnicodeToAnsi2(yu));
		outtextxy(1018, position_y, UnicodeToAnsi2(shu));
		outtextxy(1200, position_y, UnicodeToAnsi2(ying));
		head = head->next;
		if (m == 13)
		{
			break;
		}
	}
	if (m == 13)
	{
		page8 = 1;
		FlipOverMenu_Tea_ScoreManagement();
	}
	if (m == 0)
	{
		MessageBox(NULL, _T("û�и�ѧ��"), _T("ѧ������"), MB_ICONSTOP | MB_SETFOREGROUND);
	}
	fclose(fp3);
}

void FlipOverMenu_Tea_ScoreManagement()
{
	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
			{
				if (msg.x > 68 && msg.x < 314 && msg.y > 69 && msg.y < 146)//�����������ѧ���ɼ�����ť��������
				{
					Stu_CreateScore();//��������ѧ���ɼ�����
				}
				if (msg.x > 59 && msg.x < 314 && msg.y > 149 && msg.y < 231)//��������޸�ѧ���ɼ�����ť��������
					Stu_AmendScore();//���ý�ʦ�޸�ѧ���ɼ�����
				if (msg.x > 62 && msg.x < 314 && msg.y > 231 && msg.y < 319)//�������ɾ��ѧ���ɼ�����ť��������
					Stu_DeleteScore();//���ý�ʦɾ��ѧ���ɼ�����
				if (msg.x > 62 && msg.x < 314 && msg.y > 319 && msg.y < 404)//����ѧ����Ϣ
					Stu_FindInformation();
				if (msg.x > 62 && msg.x < 314 && msg.y > 404 && msg.y < 476)//ͳ��ѧ���ɼ�
					Stu_ScoreStatistics();
				if (page8>0 && msg.x>402 && msg.x<552 && msg.y>60 && msg.y<113)//��һҳ
				{
					if (page8 <= 1)
						MessageBox(NULL, _T("�Ѿ��ǵ�һҳ"), _T("ѧ������"), MB_ICONSTOP | MB_SETFOREGROUND);
					else
					{
						page8--;
						loadimage(&findscore, L"findscore.jpg");
						putimage(0, 0, &findscore);
						Sleep(100);
						loadimage(&findscore_flipoverbutton_previouspage, L"findscore_flipoverbutton_previouspage.jpg");
						putimage(0, 0, &findscore_flipoverbutton_previouspage);
						PreviousPageAndNextPage_Tea_ScoreManagement(page8);
					}
				}
				if (page8 <= page7 && msg.x>402 && msg.x<554 && msg.y>139 && msg.y<203)//��һҳ
				{
					if (page8 == page7)
						MessageBox(NULL, _T("�Ѿ������һҳ"), _T("ѧ������"), MB_ICONSTOP | MB_SETFOREGROUND);
					else
					{
						page8++;
						loadimage(&findscore, L"findscore.jpg");
						putimage(0, 0, &findscore);
						Sleep(100);
						loadimage(&findscore_flipoverbutton_nextpage, L"findscore_flipoverbutton_nextpage.jpg");
						putimage(0, 0, &findscore_flipoverbutton_nextpage);
						PreviousPageAndNextPage_Tea_ScoreManagement(page8);
					}
				}
				if (msg.x > 62 && msg.x < 314 && msg.y > 476 && msg.y < 623)//��������ذ�ť
				{
					loadimage(&teacher_scoremanagement2_return, L"teacher_scoremanagement2_return.jpg");
					putimage(0, 0, &teacher_scoremanagement2_return);
					Sleep(100);
					Tea_SecondMenu();//���ö����˵���ʦ��
				}
			}
		}
	}
}

void PreviousPageAndNextPage_Tea_ScoreManagement(int page)//ͳ��ѧ����Ϣ�˵�������·�ҳ(����)
{
	stu *head = node4[page];
	int m;
	if (page == 1)
		m = 0;
	else
		m = (page - 1) * 13;
	int position_x = 580;
	int position_y = 27;
	char yu[LENGTH];
	char shu[LENGTH];
	char ying[LENGTH];
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(40, 0, _T("����"));
	outtextxy(position_x, position_y, _T("���   ����   ����   ��ɢ   ��ѧӢ��"));
	char sequencenum[100];
	while (head != NULL)
	{
		m++;
		itoa(head->yu, yu, 10);
		itoa(head->shu, shu, 10);
		itoa(head->ying, ying, 10);
		sprintf(sequencenum, "%d", m);
		position_y += 45;
		outtextxy(600, position_y, UnicodeToAnsi2(sequencenum));
		outtextxy(710, position_y, UnicodeToAnsi2(head->Namec));
		outtextxy(865, position_y, UnicodeToAnsi2(yu));
		outtextxy(1020, position_y, UnicodeToAnsi2(shu));
		outtextxy(1200, position_y, UnicodeToAnsi2(ying));
		head = head->next;
		if (m % 13 == 0)
		{
			break;
		}
	}
}

void Stu_ScoreStatistics()			//ѧ���ɼ�ͳ��
{
	loadimage(&statisticsscore1, L"statisticsscore1.jpg");
	putimage(0, 0, &statisticsscore1);
	Sleep(100);
	loadimage(&statisticsscore2, L"statisticsscore2.jpg");
	putimage(0, 0, &statisticsscore2);
	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
			{
				if (msg.x > 74 && msg.x < 277 && msg.y > 89 && msg.y < 166)//����������������ߡ���ť��������
					FullMarks();
				if (msg.x > 74 && msg.x < 277 && msg.y > 166 && msg.y < 250)//��������������ߡ���ť��������
					FailingStudent();
				if (msg.x > 74 && msg.x < 277 && msg.y > 250 && msg.y < 340)//����������ɼ��ֽܷ������򡱰�ť��������
					DescendingSortScore();
				if (msg.x>74 && msg.x<277 && msg.y>340 && msg.y<403)//"ƽ����"��ť
					AverageScore();
				if (msg.x > 74 && msg.x < 277 && msg.y > 505 && msg.y < 580)//��������ذ�ť
				{
					loadimage(&teacher_scoreStatistics2_return, L"teacher_scoreStatistics2_return.jpg");
					putimage(0, 0, &teacher_scoreStatistics2_return);
					Sleep(100);
					Tea_ScoreManagement();
				}
			}
		}
	}
}

void FullMarks()			//��ʾ�������ֵ�ѧ��
{
	loadimage(&fullmarks, L"fullmarks.jpg");
	putimage(0, 0, &fullmarks);

	stu student, *head, *p, *q, *head1;
	p = q = (stu*)malloc(sizeof(stu)-5);
	head = p;
	int m = 0, m1 = 1;
	int position_x = 580;
	int position_y = 27;
	char yu[LENGTH];
	char shu[LENGTH];
	char ying[LENGTH];
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(40, 0, _T("����"));
	char sequencenum[100];
	outtextxy(position_x, position_y, _T("���   ����   ����   ��ɢ   ��ѧӢ��"));
	fp3 = fopen(filename3, "a+");
	while (fscanf(fp3, "%s %d %d %d %d\n", student.Namec, &student.yu, &student.shu, &student.ying,&student.zongfen) != EOF)
	{
		if (student.yu==100||student.shu==100||student.ying==100)
		{
			p = (stu*)malloc(sizeof(stu)-5);
			strcpy(p->Namec, student.Namec);
			p->yu = student.yu;
			p->shu = student.shu;
			p->ying = student.ying;
			q->next = p;
			q = p;
		}
	}
	q->next = NULL;
	head1 = head;
	page5 = 1;
	while (head1 != NULL)
	{
		head1 = head1->next;
		if (m1 == 1)
		{
			node3[page5] = head1;
		}
		if (m1 % 15 == 0)
		{
			page5++;
			node3[page5] = head1;
		}
		m1++;
	}
	while (head != NULL)
	{
		m++;
		head = head->next;
		itoa(head->yu, yu, 10);
		itoa(head->shu, shu, 10);
		itoa(head->ying, ying, 10);
		sprintf(sequencenum, "%d", m);
		position_y += 45;
		outtextxy(600, position_y, UnicodeToAnsi2(sequencenum));
		outtextxy(710, position_y, UnicodeToAnsi2(head->Namec));
		outtextxy(865, position_y, UnicodeToAnsi2(yu));
		outtextxy(1020, position_y, UnicodeToAnsi2(shu));
		outtextxy(1200, position_y, UnicodeToAnsi2(ying));
		if (m == 14)
		{
			break;
		}
	}
	if (m == 14)
	{
		page6 = 1;
		FlipOverMenu();
	}
	if (m == 0)
	{
		MessageBox(NULL, _T("û�е������ֵ�ѧ��"), _T("ѧ��ͳ��"), MB_ICONSTOP | MB_SETFOREGROUND);
	}
	fclose(fp3);
}

void FailingStudent()				//��ʾ�������ѧ��
{
	loadimage(&failingstudent, L"failingstudent.jpg");
	putimage(0, 0, &failingstudent);

	stu student, *head, *p, *q, *head1;
	p = q = (stu*)malloc(sizeof(stu)-5);
	head = p;
	int m = 0,m1 = 1;
	int position_x = 580;
	int position_y = 27;
	char yu[LENGTH];
	char shu[LENGTH];
	char ying[LENGTH];
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(40, 0, _T("����"));
	char sequencenum[100];
	outtextxy(position_x, position_y, _T("���   ����   ����   ��ɢ   ��ѧӢ��"));
	fp3 = fopen(filename3, "a+");
	while (fscanf(fp3, "%s %d %d %d %d\n", student.Namec, &student.yu, &student.shu, &student.ying,&student.zongfen) != EOF)
	{
		if (student.yu < 60 || student.shu < 60 || student.ying < 60)
		{
			p = (stu*)malloc(sizeof(stu)-5);
			strcpy(p->Namec, student.Namec);
			p->yu = student.yu;
			p->shu = student.shu;
			p->ying = student.ying;
			q->next = p;
			q = p;
		}
	}
	q->next = NULL;
	head1 = head;
	page3 = 1;
	while (head1 != NULL)
	{
		head1 = head1->next;
		if (m1 == 1)
		{
			node2[page3] = head1;
		}
		if (m1 % 15 == 0)
		{
			page3++;
			node2[page3] = head1;
		}
		m1++;
	}
	while (head != NULL)
	{
		m++;
		head = head->next;
		itoa(head->yu, yu, 10);
		itoa(head->shu, shu, 10);
		itoa(head->ying, ying, 10);
		sprintf(sequencenum, "%d", m);
		position_y += 45;
		outtextxy(600, position_y, UnicodeToAnsi2(sequencenum));
		outtextxy(710, position_y, UnicodeToAnsi2(head->Namec));
		outtextxy(865, position_y, UnicodeToAnsi2(yu));
		outtextxy(1020, position_y, UnicodeToAnsi2(shu));
		outtextxy(1200, position_y, UnicodeToAnsi2(ying));
		if (m == 14)
		{
			break;
		}
	}
	if (m == 14)
	{
		page4 = 1;
		FlipOverMenu1();
	}
	if (m == 0)
	{
		MessageBox(NULL, _T("û�в������ѧ��"), _T("ѧ��ͳ��"), MB_ICONSTOP | MB_SETFOREGROUND);
	}
	fclose(fp3);
}

void DescendingSortScore()		//��������
{
	loadimage(&descendingdortscore, L"descendingdortscore.jpg");
	putimage(0, 0, &descendingdortscore);

	stu *head, *head1, *head2;
	head = createlink3();
	head1 = pop_sort(head);		//�������������򣬷���ͷ�ڵ�
	head1 = head1->next;
	head2 = head1;
	int m = 0, m1 = 1;
	int position_x = 580;
	int position_y = 27;
	char yu[LENGTH];
	char shu[LENGTH];
	char ying[LENGTH];
	char zongfen[LENGTH];
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(30, 0, _T("����"));
	char sequencenum[100];
	outtextxy(position_x, position_y, _T("���    ����    ����    ��ɢ    Ӣ��   �����ܷ�"));
	page1 = 1;
	while (head2!= NULL)
	{
		if (m1 == 1)
		{
			node1[page1] = head2;
		}
		head2 = head2->next;
		if (m1 % 18 == 0)
		{
			page1++;
			node1[page1] = head2;
		}
		m1++;
	}
	while (head1!=NULL)
	{
		m++;
		itoa(head1->yu, yu, 10);
		itoa(head1->shu, shu, 10);
		itoa(head1->ying, ying, 10);
		itoa(head1->zongfen, zongfen, 10);
		sprintf(sequencenum, "%d", m);
		position_y += 35;
		outtextxy(600, position_y, UnicodeToAnsi2(sequencenum));
		outtextxy(680, position_y, UnicodeToAnsi2(head1->Namec));
		outtextxy(825, position_y, UnicodeToAnsi2(yu));
		outtextxy(945, position_y, UnicodeToAnsi2(shu));
		outtextxy(1070, position_y, UnicodeToAnsi2(ying));
		outtextxy(1200, position_y, UnicodeToAnsi2(zongfen));
		head1 = head1->next;
		if (m == 18)
		{
			break;
		}
	}
	if (m == 18)
	{
		page2 = 1;
		FlipOverMenu2();
	}
	if (m == 0)
	{
		MessageBox(NULL, _T("���ݿ���δ���ѧ��"), _T("ѧ��ͳ��"), MB_ICONSTOP | MB_SETFOREGROUND);
	}
}

void AverageScore()			//��ʾѧ�����Ƶ�ƽ����
{
	loadimage(&averagescore, L"averagescore.jpg");
	putimage(0, 0, &averagescore);
	int count = 0;
	double x = 0, y1 = 0, y2 = 0, y3 = 0, y4 = 0;
	double yu, shu, ying, zongfen;
	char yu2[LENGTH];
	char shu2[LENGTH];
	char ying2[LENGTH];
	char zongfen2[LENGTH];
	stu *head;
	head = createlink3();
	while (head->next != NULL)
	{
		head = head->next;
		y1 = y1 + head->yu;
		y2 = y2 + head->shu;
		y3 = y3 + head->ying;
		y4 = y4 + head->zongfen;
		count = count + 1;	//count����ѧ������
	}
	yu = y1/ count;			//ƽ����
	shu = y2 / count;
	ying = y3 / count;
	zongfen = y4 / count;
	sprintf(yu2, "%.1lf", yu);
	sprintf(shu2, "%.1lf", shu);
	sprintf(ying2, "%.1lf", ying);
	sprintf(zongfen2, "%.1lf", zongfen);
	int position_x = 580;
	int position_y = 35;
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(25, 0, _T("����"));
	outtextxy(position_x, position_y, _T("����ƽ����   ��ɢƽ����   Ӣ��ƽ����   ������ƽ����"));
	position_y += 40;
	outtextxy(600, position_y, UnicodeToAnsi2(yu2));
	outtextxy(790, position_y, UnicodeToAnsi2(shu2));
	outtextxy(950, position_y, UnicodeToAnsi2(ying2));
	outtextxy(1115, position_y, UnicodeToAnsi2(zongfen2));
}

void FlipOverMenu()		//ͳ��ѧ����Ϣ�˵������ֵķ�ҳ�˵�
{
	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
			{
				if (msg.x > 74 && msg.x < 277 && msg.y > 89 && msg.y < 166)//����������������ߡ���ť��������
					FullMarks();
				if (msg.x > 74 && msg.x < 277 && msg.y > 166 && msg.y < 250)//��������������ߡ���ť��������
					FailingStudent();
				if (msg.x > 74 && msg.x < 277 && msg.y > 250 && msg.y < 340)//����������ɼ��ֽܷ������򡱰�ť��������
					DescendingSortScore();
				if (msg.x>74 && msg.x<277 && msg.y>340 && msg.y<403)//"ƽ����"��ť
					AverageScore();
				if (page6>0 && msg.x>478 && msg.x<558 && msg.y>155 && msg.y<317)//��һҳ
				{
					if (page6 <= 1)
						MessageBox(NULL, _T("�Ѿ��ǵ�һҳ"), _T("ѧ��ͳ��"), MB_ICONSTOP | MB_SETFOREGROUND);
					else
					{
						page6--;
						loadimage(&fullmarks, L"fullmarks.jpg");
						putimage(0, 0, &fullmarks);
						Sleep(100);
						loadimage(&fullmarks_flipoverbutton_previouspage, L"fullmarks_flipoverbutton_previouspage.jpg");
						putimage(0, 0, &fullmarks_flipoverbutton_previouspage);
						PreviousPage_And_NextPage(page6);
					}
				}
				if (page6 <= page5 && msg.x>478 && msg.x<558 && msg.y>352 && msg.y<514)//��һҳ
				{
					if (page6 == page5)
						MessageBox(NULL, _T("�Ѿ������һҳ"), _T("ѧ��ͳ��"), MB_ICONSTOP | MB_SETFOREGROUND);
					else
					{
						page6++;
						loadimage(&fullmarks, L"fullmarks.jpg");
						putimage(0, 0, &fullmarks);
						Sleep(100);
						loadimage(&fullmarks_flipoverbutton_nextpage, L"fullmarks_flipoverbutton_nextpage.jpg");
						putimage(0, 0, &fullmarks_flipoverbutton_nextpage);
						PreviousPage_And_NextPage(page6);
					}
				}
				if (msg.x > 74 && msg.x < 277 && msg.y > 505 && msg.y < 580)//��������ذ�ť
				{
					loadimage(&teacher_scoreStatistics2_return, L"teacher_scoreStatistics2_return.jpg");
					putimage(0, 0, &teacher_scoreStatistics2_return);
					Sleep(100);
					Tea_ScoreManagement();
				}
			}
		}
	}
}

void FlipOverMenu1()		//ͳ��ѧ����Ϣ�˵��ﲻ����ķ�ҳ�˵�
{
	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
			{
				if (msg.x > 74 && msg.x < 277 && msg.y > 89 && msg.y < 166)//����������������ߡ���ť��������
					FullMarks();
				if (msg.x > 74 && msg.x < 277 && msg.y > 166 && msg.y < 250)//��������������ߡ���ť��������
					FailingStudent();
				if (msg.x > 74 && msg.x < 277 && msg.y > 250 && msg.y < 340)//����������ɼ��ֽܷ������򡱰�ť��������
					DescendingSortScore();
				if (msg.x>74 && msg.x<277 && msg.y>340 && msg.y<403)//"ƽ����"��ť
					AverageScore();
				if (page4>0 && msg.x>478 && msg.x<558 && msg.y>155 && msg.y<317)//��һҳ
				{
					if (page4 <= 1)
						MessageBox(NULL, _T("�Ѿ��ǵ�һҳ"), _T("ѧ��ͳ��"), MB_ICONSTOP | MB_SETFOREGROUND);
					else
					{
						page4--;
						loadimage(&failingstudent, L"failingstudent.jpg");
						putimage(0, 0, &failingstudent);
						Sleep(100);
						loadimage(&failingstudent_flipoverbutton_previouspage, L"failingstudent_flipoverbutton_previouspage.jpg");
						putimage(0, 0, &failingstudent_flipoverbutton_previouspage);
						PreviousPage_And_NextPage1(page4);
					}
				}
				if (page4 <= page3 && msg.x>478 && msg.x<558 && msg.y>352 && msg.y<514)//��һҳ
				{
					if (page4 == page3)
						MessageBox(NULL, _T("�Ѿ������һҳ"), _T("ѧ��ͳ��"), MB_ICONSTOP | MB_SETFOREGROUND);
					else
					{
						page4++;
						loadimage(&failingstudent, L"failingstudent.jpg");
						putimage(0, 0, &failingstudent);
						Sleep(100);
						loadimage(&failingstudent_flipoverbutton_nextpage, L"failingstudent_flipoverbutton_nextpage.jpg");
						putimage(0, 0, &failingstudent_flipoverbutton_nextpage);
						PreviousPage_And_NextPage1(page4);
					}
				}
				if (msg.x > 74 && msg.x < 277 && msg.y > 505 && msg.y < 580)//��������ذ�ť
				{
					loadimage(&teacher_scoreStatistics2_return, L"teacher_scoreStatistics2_return.jpg");
					putimage(0, 0, &teacher_scoreStatistics2_return);
					Sleep(100);
					Tea_ScoreManagement();
				}
			}
		}
	}
}


void FlipOverMenu2()		//ͳ��ѧ����Ϣ�˵��ﵹ��ķ�ҳ�˵�
{
	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
			{
				if (msg.x > 74 && msg.x < 277 && msg.y > 89 && msg.y < 166)//����������������ߡ���ť��������
					FullMarks();
				if (msg.x > 74 && msg.x < 277 && msg.y > 166 && msg.y < 250)//��������������ߡ���ť��������
					FailingStudent();
				if (msg.x > 74 && msg.x < 277 && msg.y > 250 && msg.y < 340)//����������ɼ��ֽܷ������򡱰�ť��������
					DescendingSortScore();
				if (msg.x>74 && msg.x<277 && msg.y>340 && msg.y<403)//"ƽ����"��ť
					AverageScore();
				if (page2>0 && msg.x>360 && msg.x<511 && msg.y>464 && msg.y<538)//��һҳ
				{
					if (page2<=1)
						MessageBox(NULL, _T("�Ѿ��ǵ�һҳ"), _T("ѧ��ͳ��"), MB_ICONSTOP | MB_SETFOREGROUND);
					else
					{
						page2--;
						loadimage(&descendingdortscore, L"descendingdortscore.jpg");
						putimage(0, 0, &descendingdortscore);
						PreviousPage_And_NextPage2(page2);
					}
				}
				if (page2<=page1 && msg.x>372 && msg.x<501 && msg.y>576 && msg.y<654)//��һҳ
				{
					if (page2==page1)
						MessageBox(NULL, _T("�Ѿ������һҳ"), _T("ѧ��ͳ��"), MB_ICONSTOP | MB_SETFOREGROUND);
					else
					{
						page2++;
						loadimage(&descendingdortscore, L"descendingdortscore.jpg");
						putimage(0, 0, &descendingdortscore);
						PreviousPage_And_NextPage2(page2);
					}
				}
				if (msg.x > 74 && msg.x < 277 && msg.y > 505 && msg.y < 580)//��������ذ�ť
				{
					loadimage(&teacher_scoreStatistics2_return, L"teacher_scoreStatistics2_return.jpg");
					putimage(0, 0, &teacher_scoreStatistics2_return);
					Sleep(100);
					Tea_ScoreManagement();
				}
			}
		}
	}
}

void PreviousPage_And_NextPage(int page)//ͳ��ѧ����Ϣ�˵�������·�ҳ(����)
{
	stu *head = node3[page];
	int m;
	if (page == 1)
		m = 0;
	else
		m = (page - 1) * 14;
	int position_x = 580;
	int position_y = 27;
	char yu[LENGTH];
	char shu[LENGTH];
	char ying[LENGTH];
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(40, 0, _T("����"));
	outtextxy(position_x, position_y, _T("���   ����   ����   ��ɢ   ��ѧӢ��"));
	char sequencenum[100];
	while (head != NULL)
	{
		m++;
		itoa(head->yu, yu, 10);
		itoa(head->shu, shu, 10);
		itoa(head->ying, ying, 10);
		sprintf(sequencenum, "%d", m);
		position_y += 45;
		outtextxy(600, position_y, UnicodeToAnsi2(sequencenum));
		outtextxy(710, position_y, UnicodeToAnsi2(head->Namec));
		outtextxy(865, position_y, UnicodeToAnsi2(yu));
		outtextxy(1020, position_y, UnicodeToAnsi2(shu));
		outtextxy(1200, position_y, UnicodeToAnsi2(ying));
		head = head->next;
		if (m % 14 == 0)
		{
			break;
		}
	}
}

void PreviousPage_And_NextPage1(int page)//ͳ��ѧ����Ϣ�˵�������·�ҳ(������)
{
	stu *head = node2[page];
	int m;
	if (page == 1)
		m = 0;
	else
		m = (page - 1) * 14;
	int position_x = 580;
	int position_y = 27;
	char yu[LENGTH];
	char shu[LENGTH];
	char ying[LENGTH];
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(40, 0, _T("����"));
	outtextxy(position_x, position_y, _T("���   ����   ����   ��ɢ   ��ѧӢ��"));
	char sequencenum[100];
	while (head != NULL)
	{
		m++;
		itoa(head->yu, yu, 10);
		itoa(head->shu, shu, 10);
		itoa(head->ying, ying, 10);
		sprintf(sequencenum, "%d", m);
		position_y += 45;
		outtextxy(600, position_y, UnicodeToAnsi2(sequencenum));
		outtextxy(710, position_y, UnicodeToAnsi2(head->Namec));
		outtextxy(865, position_y, UnicodeToAnsi2(yu));
		outtextxy(1020, position_y, UnicodeToAnsi2(shu));
		outtextxy(1200, position_y, UnicodeToAnsi2(ying));
		head = head->next;
		if (m % 14 == 0)
		{
			break;
		}
	}
}

void PreviousPage_And_NextPage2(int page)//ͳ��ѧ����Ϣ�˵�������·�ҳ(����)
{
	stu *head = node1[page];
	int m;
	if (page == 1)
		m = 0;
	else
		m = (page - 1) * 18;
	int position_x = 580;
	int position_y = 27;
	char yu[LENGTH];
	char shu[LENGTH];
	char ying[LENGTH];
	char zongfen[LENGTH];
	setbkmode(TRANSPARENT);
	settextcolor(COLORREF(RGB(0, 0, 0)));
	settextstyle(30, 0, _T("����"));
	outtextxy(position_x, position_y, _T("���    ����    ����    ��ɢ    Ӣ��   �����ܷ�"));
	char sequencenum[100];
	while (head != NULL)
	{
		m++;
		itoa(head->yu, yu, 10);
		itoa(head->shu, shu, 10);
		itoa(head->ying, ying, 10);
		itoa(head->zongfen, zongfen, 10);
		sprintf(sequencenum, "%d", m);
		position_y += 35;
		outtextxy(600, position_y, UnicodeToAnsi2(sequencenum));
		outtextxy(680, position_y, UnicodeToAnsi2(head->Namec));
		outtextxy(825, position_y, UnicodeToAnsi2(yu));
		outtextxy(945, position_y, UnicodeToAnsi2(shu));
		outtextxy(1070, position_y, UnicodeToAnsi2(ying));
		outtextxy(1200, position_y, UnicodeToAnsi2(zongfen));
		head = head->next;
		if (m%18==0)
		{
			break;
		}
	}
}

int main()
{
	initgraph(1400, 701);//���崰�ڴ�С
	Welcome();				//�������
	return 0;
}