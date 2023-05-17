#include<stdio.h>

void getfake(int *arr, int left, int right, int know){
    //cout << left <<" "<<right <<" "<<know<<endl;
    //system("pause");
    int total = right-left;
    if(total==1){
        printf("%d\n",left);
        return;
    }
    else if(total==2){
        if(arr[left]==arr[know]){
            printf("%d\n",left+1);
        }else{
            printf("%d\n",left);
        }
        return;
    }
    int pile = (right-left)/3;
   // printf("%d\n",pile);
    int A=0, B=0, C=0;
    //int result;
    for(int i = 0;i<pile;i++){
        A+= arr[i];
        B+= arr[pile+i];
        C+= arr[2*pile+i];
    }
   //printf("%d %d %d\n",A,B,C);
    if(A==B){
        if(A==C){// A=B=C
            getfake(arr,left+3*pile,right,left);
        }else{ //A=B!=C
            getfake(arr,left+2*pile,left+3*pile,left);
        }
    }else{
        if(B==C){//A!=B=C
            getfake(arr,left,left+pile,left+pile);
        }else{//A==C!=B
            getfake(arr,left+pile,left+2*pile,left);
        }
    }
}

int main(){  
    int length;
    int ans = 0;
    while(scanf("%d", &length) != EOF){ 
        int coin[101];
        for(int i=0; i<length; i++){
            scanf("%d", &coin[i]); 
            //printf("%d",coin[i]);
        }            
        getfake(coin, 0, length, -1);
        //printf("%d", ans);
        //getFake(0, length, length, coin);  
        //return 0;
    }
    return 0;
}


