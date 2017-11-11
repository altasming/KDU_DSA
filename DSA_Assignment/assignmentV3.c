#include<stdio.h>
#include<string.h>

#define MaxSem 5

struct node
{
	char crs_code[10];
	int crs_credit;
	char crs_grade[3];
	struct node *next;
}*top[MaxSem], *top1[MaxSem], *temp[MaxSem];

char subjectCode[10];
char grade[3];

double gradePointEarn = 0.00;
int semesterCreditHour = 0;
int totalCreditHour = 0;
double semesterGradePointEarn = 0.00;
double totalGradePointEarn = 0.00;
double gpa = 0.00;
double cgpa = 0.00;
int semester = -1;
int firstInput;

void menu();
void inputResult();
void push(char[], int, char[]);
void pop();
void calculateResult();
void display();
int gradeConvert(char[]);

void main()
{
	menu();

	//display();
}

void menu()
{
	int selection;
	int count;
	char decision;

	while (1)
	{
		printf("\n");
		printf("1 - New Semester\n");
		printf("2 - Continue Current Semester\n");
		printf("3 - Remove Last Result\n");
		printf("4 - Display Current Semester\n");
		printf("5 - Display All Semester\n");

		printf("Select your choice ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			semester++;
			top[semester] = NULL;
			printf("How many subject? ");
			scanf("%d", &count);
			for (int i = 0; i < count; i++)
			{
				inputResult();
			}
			break;
		case 2:
			if (semester != -1)
			{
				printf("How many subject? ");
				scanf("%d", &count);
				for (int i = 0; i < count; i++)
				{
					inputResult();
				}
			}
			else
			{
				printf("No record found!\n");
			}
			break;
		case 3:
			pop();
			break;
		case 4:
			display();
			break;
		case 5:
			calculateResult();
			break;
		default:
			break;
		}
	}
}

void inputResult()
{
	char temp;

	//if (firstInput == 0)
	printf("Enter subject code: ");
	//else
	//	printf("Enter subject code (Type \"Undo\" to remove previous input):\n");


	//This code used to clear buffer (Read string after integer input)
	//http://www.includehelp.com/c/c-program-to-read-string-with-spaces-using-scanf-function.aspx
	scanf("%c", &temp);
	scanf("%[^\n]s", &subjectCode);

	//https://cboard.cprogramming.com/c-programming/371-how-do-i-get-last-character-string.html
	//#4
	char c_hour = subjectCode[strlen(subjectCode) - 1];
	//printf("Credit hour %c\n", c_hour);

	//https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
	int ic_hour = c_hour - '0';
	//printf("Credit hour %d\n", ic_hour);

	printf("Enter grade: ");
	scanf("%s", &grade);

	push(subjectCode, ic_hour, grade);
}

void push(char code[], int credit, char grade[])
{
	if (top[semester] == NULL)
	{
		top[semester] = (struct node *)malloc(sizeof(struct node));
		strcpy(top[semester]->crs_code, code);
		top[semester]->crs_credit = credit;
		strcpy(top[semester]->crs_grade, grade);
		top[semester]->next = NULL;
	}
	else
	{
		temp[semester] = (struct node *)malloc(sizeof(struct node));
		strcpy(temp[semester]->crs_code, code);
		temp[semester]->crs_credit = credit;
		strcpy(temp[semester]->crs_grade, grade);
		temp[semester]->next = top[semester];
		top[semester] = temp[semester];
	}
}

void pop()
{
	top1[semester] = top[semester];

	if (top1[semester] == NULL)
	{
		printf("NULL");
	}
	else
	{
		top1[semester] = top1[semester]->next;
		free(top[semester]);
		top[semester] = top1[semester];
	}
}

void calculateResult()
{
	for (int i = 0; i <= semester; i++)
	{
		top1[i] = top[i];
		semesterCreditHour = 0;
		semesterGradePointEarn = 0.00;

		if (top1[i] == NULL)
		{
			printf("NULL");
		}

		printf("\nSubject Code\t\tGrade\tCourse Credit\tGrade Points\n");
		while (top1[i] != NULL)
		{
			gradePointEarn = 0.00;
			if (strstr(top1[i]->crs_grade, "A"))
			{
				//Grade Point * Credit hour
				gradePointEarn = top1[i]->crs_credit * 4;
				//Semester GP * CH
				semesterGradePointEarn += gradePointEarn;
				//Total Credit Hour
				totalCreditHour += top1[i]->crs_credit;
				//Semester Credit Hour
				semesterCreditHour += top1[i]->crs_credit;
				//(GP x CH)
				totalGradePointEarn += gradePointEarn;

				printf("%s\t\t%s\t%d\t\t%.2f\n", top1[i]->crs_code, top1[i]->crs_grade, top1[i]->crs_credit, gradePointEarn);
			}
			else if (strstr(top1[i]->crs_grade, "B+"))
			{
				gradePointEarn = top1[i]->crs_credit * 3.5;
				semesterGradePointEarn += gradePointEarn;
				totalCreditHour += top1[i]->crs_credit;
				semesterCreditHour += top1[i]->crs_credit;
				totalGradePointEarn += gradePointEarn;

				printf("%s\t%s\t%d\t%.2f\n", top1[i]->crs_code, top1[i]->crs_grade, top1[i]->crs_credit, gradePointEarn);
			}
			else if (strstr(top1[i]->crs_grade, "B"))
			{
				gradePointEarn = top1[i]->crs_credit * 3;
				semesterGradePointEarn += gradePointEarn;
				totalCreditHour += top1[i]->crs_credit;
				semesterCreditHour += top1[i]->crs_credit;
				totalGradePointEarn += gradePointEarn;

				printf("%s\t%s\t%d\t%.2f\n", top1[i]->crs_code, top1[i]->crs_grade, top1[i]->crs_credit, gradePointEarn);
			}
			else if (strstr(top1[i]->crs_grade, "C+"))
			{
				gradePointEarn = top1[i]->crs_credit * 2.5;
				semesterGradePointEarn += gradePointEarn;
				totalCreditHour += top1[i]->crs_credit;
				semesterCreditHour += top1[i]->crs_credit;
				totalGradePointEarn += gradePointEarn;

				printf("%s\t%s\t%d\t%.2f\n", top1[i]->crs_code, top1[i]->crs_grade, top1[i]->crs_credit, gradePointEarn);
			}
			else if (strstr(top1[i]->crs_grade, "C"))
			{
				gradePointEarn = top1[i]->crs_credit * 2;
				semesterGradePointEarn += gradePointEarn;
				totalCreditHour += top1[i]->crs_credit;
				semesterCreditHour += top1[i]->crs_credit;
				totalGradePointEarn += gradePointEarn;

				printf("%s\t%s\t%d\t%.2f\n", top1[i]->crs_code, top1[i]->crs_grade, top1[i]->crs_credit, gradePointEarn);
			}
			else if (strstr(top1[i]->crs_grade, "D"))
			{
				gradePointEarn = top1[i]->crs_credit * 1;
				semesterGradePointEarn += gradePointEarn;
				totalCreditHour += top1[i]->crs_credit;
				semesterCreditHour += top1[i]->crs_credit;
				totalGradePointEarn += gradePointEarn;

				printf("%s\t%s\t%d\t%.2f\n", top1[i]->crs_code, top1[i]->crs_grade, top1[i]->crs_credit, gradePointEarn);
			}
			else if (strstr(top1[i]->crs_grade, "F"))
			{
				gradePointEarn = top1[i]->crs_credit * 0;
				semesterGradePointEarn += gradePointEarn;
				totalCreditHour += top1[i]->crs_credit;
				semesterCreditHour += top1[i]->crs_credit;
				totalGradePointEarn += gradePointEarn;

				printf("%s\t%s\t%d\t%.2f\n", top1[i]->crs_code, top1[i]->crs_grade, top1[i]->crs_credit, gradePointEarn);
			}
			top1[i] = top1[i]->next;
		}
		cgpa = totalGradePointEarn / totalCreditHour;
		printf("\n\t\tSemester Total:\t%d\t\t%.2f\n", semesterCreditHour, semesterGradePointEarn);
		printf("\t\tCumulative GPA: \t\t %.2f\n", cgpa);
	}
}

void display()
{
	top1[semester] = top[semester];

	if (top1[semester] == NULL)
	{
		printf("NULL");
	}
	while (top1[semester] != NULL)
	{
		printf("%s %d %s\n", top1[semester]->crs_code, top1[semester]->crs_credit, top1[semester]->crs_grade);
		top1[semester] = top1[semester]->next;
	}
}

int gradeConvert(char grade[])
{
	if (strstr(grade, "A"))
	{
		return 1;
	}
	else if (strstr(grade, "B+"))
	{
		return 2;
	}
	else if (strstr(grade, "B"))
	{
		return 3;
	}
	else if (strstr(grade, "C+"))
	{
		return 4;
	}
	else if (strstr(grade, "C"))
	{
		return 5;
	}
	else if (strstr(grade, "D"))
	{
		return 6;
	}
	else if (strstr(grade, "F"))
	{
		return 7;
	}
	else
	{
		return 8;
	}
}