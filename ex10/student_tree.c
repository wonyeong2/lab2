#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

typedef struct
{
    char* name; 
    int mid_score; 
    int final_score; 
} STUDENT;

STUDENT* nodetable;
STUDENT* root = NULL; // 루트 노드

int compare(const void *cp1, const void *cp2)
{
    return strcmp(((STUDENT *)cp1)->name, ((STUDENT *)cp2) ->name);
}

void print_node(const void *nodeptr, VISIT order, int level)
{
    if(order == preorder || order == leaf)
        printf("이름 = %-10s, 중간 점수 = %d, 기말 점수 = %d\n", (*(STUDENT **)nodeptr)->name, (*(STUDENT **)nodeptr)->mid_score, (*(STUDENT **)nodeptr)->final_score);
}

void main()
{
    int student_num = 0; 

    printf("학생 수를 입력하세요 : ");
    scanf("%d", &student_num);

    char *name = (char *)malloc(sizeof(char) * 20);
    nodetable = (STUDENT*)malloc(sizeof(STUDENT) * student_num);

    STUDENT *nodeptr = nodetable;
    STUDENT **ret;

    for(int i = 0; i < student_num; i++) {

        printf("학생 정보 입력(이름, 중간, 기말) : ");
        scanf("%s %d %d", name, &nodeptr->mid_score, &nodeptr->final_score);
        nodeptr->name = name;

        ret = (STUDENT **) tsearch((void*) nodeptr, (void**) &root, compare);

        if(*ret == nodeptr){
            printf("트리에 추가 완료\n");
            name += strlen(name) + 1;
            nodeptr++;
        }
    }

    twalk((void*) root, print_node);

}
