#include <stdio.h>
#include <string.h>
#include <ctype.h>

void place(int[][16],int n);                                            /*�֐��̃v���g�^�C�v�錾*/
void disp(int[][16],int n);


/********************************/
/*���C���֐�
/*   ��Ɣz��̏��������s��
/*
/*�p�����[�^�F�Ȃ�
/*���^�[��  �F0�FOK 
/*******************************/

int main( void )
{
    int work[16][16]={0};
    char dmy[80];
    int i,j,n;
    while(1){
        printf("3�ȏ�15�ȉ��̊����͂��Ă��������F");
        if(scanf("%d",&n)!=1){                                        /*�j���[�����b�N�`�F�b�N*/
            gets(dmy);
            printf("��������͂��Ă��������B\n");
            continue;
        }
        if(n%2==0){
            printf("�����͂��Ă��������B\n");
                
        }else{
            if(n<3){
                printf("3�ȏ�15�ȉ��̊����͂��Ă��������B\n");
            }else{
                    break;
            }
        }
    }
    for(j=0;j<=n+1;j++){                                                /*�s�̏�����*/
        for(i=0;i<=n+1;i++){                                            /*��̏�����*/
            if(i==0||i==n+1||j==0||j==n+1){                             /*��Ɨ̈悩�ǂ������m�p����*/
                work[j][i]=n*n+1;
            }else{
                work[j][i]=0;
            }
            
        }
    }
    place(work,n);
    disp(work,n);


    return 0;
}


/************************************/
/*�����̏ꏊ���߂Ɣz�u���s��
/*
/*�p�����[�^�Fint work[][16] [in/out]
/*            int n[in]
/*���^�[��  �F�Ȃ�
/***********************************/
void place(int work[][16],int n)
{
    int i,j,num;
    num=1;
    while(num<n*n+1){
        if(num==1){                                                        /*i,j�̏����l*/
            i=n/2+1;
            j=n/2+2;
        }
        while(1){
            if(i>n){                                                    /*�E�ɂ݂͂�������*/
                i=1;
            }else if(1>i){                                                /*���ɂ݂͂�������*/
                i=n;
            }
            if(j>n){                                                    /*���ɂ݂͂�������*/
                j=1;
            }

            if(work[j][i]==0){                                            /*�����������Ă��Ȃ�*/
                break;
            }else{                                                        /*���łɓ����Ă���*/
                i--;
                j++;
            }

            
        }

        work[j++][i++]=num++;

    }
    

}

/************************************/
/*���@�w�̕\��
/*
/*�p�����[�^�Fint work[][16][in]
/*            int n[in]
/*���^�[��  �F�Ȃ�
/***********************************/

void disp(int work[][16],int n)
{
    int i,j;
    for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
            printf("%d\t",work[j][i]);
        }
        printf("\n");
    }
    
}

