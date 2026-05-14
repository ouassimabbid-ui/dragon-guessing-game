#include <stdio.h>
#include <time.h>
#include <stdlib.h>
char welcome(){
    char n ;
    printf("\nHello warm , if u want to make it out of here alive u have to earn it\n");
    printf("-----==here are the rules-------\n"); 
    printf("u have limited attempts depends on the  difficulty u chose\n");
    printf("u should attemp tp get the right number that it is in my minf thats between 1-100\n");
    printf("are u ready \n");
    while(1){
        printf("Y/N? \n");
        scanf(" %c", &n);
        if(n== 'Y' || n== 'N' || n== 'y' || n== 'n'){
            return n;
        }
        printf("invalide output try again\n");
    }
}
void check(char n){
    if (n == 'Y' || n=='y' ){
        printf(" okey lets begging \n");
    }
    else if(n == 'N' || n == 'n'){
        printf("game over\n");
        exit(0);
    }
    else{
        printf("invalide output\n");
    }
}
int difficulty(){
    char x ;
    printf("well well well, u should choose the difficulty \n");
    printf("easy(10 attemps) : E \n normal(7 atttemps) : N \n Hard(5 attemps) : H\n");
    printf("E/N/H \n");

    while(1){
        scanf(" %c", &x);
        if(x == 'E' || x== 'e'){
            printf("difficulty : easy\n");
            return  10;
        }else if(x== 'N' || x== 'n'){
            printf("defficulty : normal\n") ;
            return 7; 
        }else if(x == 'H' || x== 'h'){
            printf("difficulty : hard\n");
            return  5;
    }
    printf("invalid input, try again\n");
    }
}
int ran(){
    int r;
    srand(time(NULL));
    r=rand() % 100 + 1;
    return r ;
}
void player(int x , int r){
    int t=1 , a;
    printf("the dragon guessed the number , remember between 100-1, ur turn u have %d chances : \n" , x);
    scanf("%d" , &a);
    while(x>t && a != r){
        t++;
        printf("ops try again u have %d tries \n tips : \n ", x-t);
        if (r - a > 0){
            printf("too low \n");
        }else if (r - a < 0){
            printf("too high \n");
        }
        printf("ur geuss again? \n");
        scanf("%d", &a);
    }
    if(r == a){
        printf("congrate u got it in %d\n try" , t);
        printf("----the number was %d \n", r );
    }
    if(x<=t){
        printf("-----------game over----------\n");
        printf("your too weak , u run out of chances\n");
        printf("the number was %d\n" , r);
    }
}
int main(){
    char n;
    int x ,r;
    n=welcome();
    check(n);
    x=difficulty();
    r=ran();
    player(x,r);
    return 0;
}