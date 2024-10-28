#include <stdio.h>
#include <stdlib.h>
#define TYPE struct stu
#define LEN sizeof (struct stu)
struct stu {
	int num;
	char name[20];
	int grade;
	struct stu *next;
};
struct stu *head;
TYPE *creat(int n) {
	struct stu *pf, *pb;
	int i;
	head = (TYPE*)malloc(LEN);
	head->next=NULL;
	pf = head;
	for (i = 0; i<n; i++) {
		pb = (TYPE*)malloc(LEN);
		printf("input Number and Name and grade\n");
		scanf("%d%s%d", &pb->num, pb->name,&pb->grade);
		pf->next = pb;
		pf = pb;
	}
	return(head);
}
void print(TYPE * head) {
	printf("Number\t\tName\t\tgrade\n");
	while (head!= NULL) {
		printf("%d\t\t%s\t\t%d\n", head->num, head->name,head->grade);
		 head=head->next;
	}
}
int main(void) {
	creat(3);
	print(head->next);
	return 0;
}
