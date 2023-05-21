#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef struct SeqList{
    int data[MaxSize];
    int length;
}SeqList;

void PrintList(SeqList L,char c[]){
    printf("%s��",c);
    for(int i=1;i<=L.length;i++)
        printf("%3d",L.data[i]);
    printf("\n");
}

void InsertSort(SeqList L){
    int i,j;
    for(i=2;i<=L.length;i++){
        L.data[0]=L.data[i];//�ڱ����浱ǰҪ�����Ԫ��
        for(j=i-1;j>=1&&L.data[j]>L.data[0];j--)
            L.data[j+1]=L.data[j];
        L.data[j+1]=L.data[0];
    }
    PrintList(L,"ֱ�Ӳ�������");
}

void ShellSort(SeqList L){
    int i,j,d;
    for(d=4;d>=1;d/=2){
        for(i=d+1;i<=L.length;i++){
            L.data[0]=L.data[i];
            for(j=i-d;j>=1&&L.data[j]>L.data[0];j-=d)
                L.data[j+d]=L.data[j];
            L.data[j+d]=L.data[0];
        }
    }
    PrintList(L,"ϣ������");
}

int main()
{
    SeqList L;
    L.length=0;
    for(int i=10;i>=1;i--){
        L.data[10-i+1]=i;
        L.length++;
    }
    PrintList(L,"��������");
    InsertSort(L);
    ShellSort(L);
    return 0;
}