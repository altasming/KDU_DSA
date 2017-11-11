//#include<stdio.h>
//#include<string.h>
//
//struct node
//{
//	int crs_credit;
//	int grade;
//	struct node *next;
//};
//
//void menu();
//void calculate();
//struct node *initialNode(int, int);
//void push(int, int, struct node *);
//void display(struct node *, struct node *);
//
//char grade[3];
//float gradePointEarn = 0.00;
//float totalGradePoint = 0.00;
//float totalGradePointEarn = 0.00;
//float gpa = 0.00;
//float cgpa = 0.00;
//char subjectCode[10];
//
//void main()
//{
//	/*int count;
//	printf("Enter how many subject?\n");
//	scanf("%d", &count);
//
//	for (int i = 0; i < count; i++)
//	{
//		calculate();
//	}*/
//
//	struct node *head = (struct node *)malloc(sizeof(struct node));
//	struct node *tail = (struct node *)malloc(sizeof(struct node));
//
//	head = initialNode(NULL,NULL);
//	tail = initialNode(NULL,NULL);
//	head->next = tail;
//
//	push(4, 1, head);
//	display(head, tail);
//}
//
//void menu()
//{
//	int selection;
//	printf("Select your ?\n");
//	scanf("%d",&selection);
//	
//	switch (selection)
//	{
//		case 1:
//			printf("%d\n", selection);
//			break;
//		case 2:
//			printf("%d\n", selection);
//			break;
//		default:
//			break;
//	}
//}
//
//void calculate()
//{
//	printf("Enter subject code:\n");
//	scanf("%s", &subjectCode);
//
//	//https://cboard.cprogramming.com/c-programming/371-how-do-i-get-last-character-string.html
//	//#4
//	char c_hour = subjectCode[strlen(subjectCode) - 1];
//	printf("Credit hour %c\n", c_hour);
//
//	//https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
//	int ic_hour = c_hour - '0';
//	printf("Credit hour %d\n", ic_hour);
//
//	printf("Enter grade:\n");
//	scanf("%s", &grade);
//
//	if (strstr(grade, "A"))
//	{
//		printf("A\n");
//		gradePointEarn = ic_hour * 4;
//		totalGradePoint += ic_hour;
//		totalGradePointEarn += gradePointEarn;
//		gradePointEarn = 0.00;
//	}
//	else if (strstr(grade, "B+"))
//	{
//		printf("B+\n");
//		gradePointEarn = ic_hour * 3.5;
//		totalGradePoint += ic_hour;
//		totalGradePointEarn += gradePointEarn;
//		gradePointEarn = 0.00;
//	}
//	else if (strstr(grade, "B"))
//	{
//		printf("B\n");
//		gradePointEarn = ic_hour * 3;
//		totalGradePoint += ic_hour;
//		totalGradePointEarn += gradePointEarn;
//		gradePointEarn = 0.00;
//	}
//	else if (strstr(grade, "C+"))
//	{
//		printf("C+\n");
//		gradePointEarn = ic_hour * 2.5;
//		totalGradePoint += ic_hour;
//		totalGradePointEarn += gradePointEarn;
//		gradePointEarn = 0.00;
//	}
//	else if (strstr(grade, "C"))
//	{
//		printf("C\n");
//		gradePointEarn = ic_hour * 2;
//		totalGradePoint += ic_hour;
//		totalGradePointEarn += gradePointEarn;
//		gradePointEarn = 0.00;
//	}
//	else if (strstr(grade, "D"))
//	{
//		printf("D\n");
//		gradePointEarn = ic_hour * 1;
//		totalGradePoint += ic_hour;
//		totalGradePointEarn += gradePointEarn;
//		gradePointEarn = 0.00;
//	}
//	else if (strstr(grade, "F"))
//	{
//		printf("F\n");
//		gradePointEarn = ic_hour * 0;
//		totalGradePoint += ic_hour;
//		totalGradePointEarn += gradePointEarn;
//		gradePointEarn = 0.00;
//	}
//	else
//		printf("Error\n");
//
//	gpa = totalGradePointEarn / totalGradePoint;
//	printf("Your GPA is %.2f\n", gpa);
//}
//
//struct node *initialNode(int crs_credit, int grade)
//{
//	struct node *temp = (struct node *)malloc(sizeof(struct node));
//	temp->crs_credit = crs_credit;
//	temp->grade = grade;
//	temp->next = NULL;
//	return temp;
//}
//
//void push(int crs_credit, int grade, struct node *head)
//{
//	struct node *newNode = initialNode(crs_credit, grade);
//	newNode = initialNode(crs_credit, grade);
//	newNode->next = head->next;
//	head->next = newNode;
//}
//
//void display(struct node *h, struct node *t)
//{
//	while (h != t)
//	{
//		printf("%d %d\n", h->crs_credit, h->grade);
//		h = h->next;
//	}
//}