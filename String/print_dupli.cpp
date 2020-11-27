#include<iostream>
using namespace std;
#define NO_OF_CHARS 256

class solution{
    public:
    void printDups(char *str){
        int *count=(int *)calloc(NO_OF_CHARS,sizeof(int));
        int i;
        for(i=0;*(str+i);i++)
            count[*(str+i)]++;
        for(i=0;i<NO_OF_CHARS;i++){
             if(count[i] > 1)
               printf("%c, count=%d\n",i,count[i]);
        }
        free(count);
    }
};

int main(){
    solution s;
    char str[]="Test String Is Here";
    s.printDups(str);
    return 0;
}
