//#include<stdio.h>
//#include<string.h>
//
//struct node
//{
//	char crs_code[10];
//	int crs_credit;
//	char crs_grade[3];
//	struct node *next;
//}*top,*top1,*temp;
//
//char subjectCode[10];
//char grade[3];
//
//float gradePointEarn = 0.00;
//float totalGradePoint = 0.00;
//float totalGradePointEarn = 0.00;
//float gpa = 0.00;
//float cgpa = 0.00;
//
//void menu();
//void inputResult();
//void push(char[], int, char[]);
//void calculateResult();
//void display();
//int gradeConvert(char []);
//
//void main()
//{
//	top = NULL;
//
//	menu();
//
//	//display();
//
//	calculateResult();
//}
//
//void menu()
//{
//	int selection;
//	int count;
//	printf("Select your choice ");
//	scanf("%d",&selection);
//	
//	switch (selection)
//	{
//	case 1:
//		printf("How many subject? ");
//		scanf("%d", &count);
//		for (int i = 0; i < count; i++)
//		{
//			inputResult();
//		}
//		break;
//	case 2:
//		printf("%d\n", selection);
//		break;
//	default:
//		break;
//	}
//}
//
//void inputResult()
//{
//	char temp;
//	printf("Enter subject code: ");
//
//	//This code used to clear buffer (Read string after integer input)
//	//http://www.includehelp.com/c/c-program-to-read-string-with-spaces-using-scanf-function.aspx
//	scanf("%c", &temp);
//	scanf("%[^\n]s", &subjectCode);
//
//	//https://cboard.cprogramming.com/c-programming/371-how-do-i-get-last-character-string.html
//	//#4
//	char c_hour = subjectCode[strlen(subjectCode) - 1];
//	//printf("Credit hour %c\n", c_hour);
//
//	//https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
//	int ic_hour = c_hour - '0';
//	//printf("Credit hour %d\n", ic_hour);
//
//	printf("Enter grade: ");
//	scanf("%s", &grade);
//
//	push(subjectCode, ic_hour, grade);
//}
//
//void push(char code[], int credit, char grade[])
//{
//	if (top == NULL)
//	{
//		top = (struct node *)malloc(sizeof(struct node));
//		strcpy(top->crs_code, code);
//		top->crs_credit = credit;
//		strcpy(top->crs_grade, grade);
//		top->next = NULL;
//	}
//	else
//	{
//		temp = (struct node *)malloc(sizeof(struct node));
//		strcpy(temp->crs_code, code);
//		temp->crs_credit = credit;
//		strcpy(temp->crs_grade, grade);
//		temp->next = top;
//		top = temp;
//	}
//}
//
//void calculateResult()
//{
//	top1 = top;
//
//	if (top1 == NULL)
//	{
//		printf("NULL");
//	}
//	while (top1 != NULL)
//	{
//		if (strstr(top1->crs_grade, "A"))
//		{
//			printf("A\n");
//			gradePointEarn = top1->crs_credit * 4;
//			totalGradePoint += top1->crs_credit;
//			totalGradePointEarn += gradePointEarn;
//			gradePointEarn = 0.00;
//		}
//		else if (strstr(grade, "B+"))
//		{
//			printf("B+\n");
//			gradePointEarn = top1->crs_credit * 3.5;
//			totalGradePoint += top1->crs_credit;
//			totalGradePointEarn += gradePointEarn;
//			gradePointEarn = 0.00;
//		}
//		top1 = top1->next;
//	}
//
//	cgpa = totalGradePointEarn / totalGradePoint;
//	printf("Your CGPA is %.2f\n", cgpa);
//}
//
//void display()
//{
//	top1 = top;
//
//	if (top1 == NULL)
//	{
//		printf("NULL");
//	}
//	while (top1 != NULL)
//	{
//		printf("%s %d %s\n", top1->crs_code, top1->crs_credit, top1->crs_grade);
//		top1 = top1->next;
//	}
//}
//
//int gradeConvert(char grade[])
//{
//	if (strstr(grade, "A"))
//	{
//		return 1;
//	}
//	else if(strstr(grade, "B+"))
//	{
//		return 2;
//	}
//	else if (strstr(grade, "B"))
//	{
//		return 3;
//	}
//	else if (strstr(grade, "C+"))
//	{
//		return 4;
//	}
//	else if (strstr(grade, "C"))
//	{
//		return 5;
//	}
//	else if (strstr(grade, "D"))
//	{
//		return 6;
//	}
//	else if (strstr(grade, "F"))
//	{
//		return 7;
//	}
//	else
//	{
//		return 8;
//	}
//}