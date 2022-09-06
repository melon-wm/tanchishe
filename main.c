#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define WIDE 60
#define HEIGHT 30

/*void ui(){
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDE;j++){
            printf("#");
        }
        printf("\n");
    }
}*/

typedef struct _body{
    int x;
    int y;
}BODY;

typedef struct snake{
    BODY list[WIDE*HEIGHT];
    int size;
    BODY food;
}SNAKE;

void init_food(SNAKE* snake){
    srand(time(NULL));
    snake->food.x=rand()%WIDE;
    snake->food.y=rand()%HEIGHT;
}

void init_snake(SNAKE* snake){
    snake->list[0].x=WIDE/2;
    snake->list[0].y=HEIGHT/2;
    snake->list[1].x=WIDE/2-1;
    snake->list[1].y=HEIGHT/2;
    snake->size=2;
    init_food(snake) ;
}

void show_ui(SNAKE* snake){
    for(int i =0;i<snake->size;i++){
        if(i==0){
            printf("@");
        } else{
            printf("*");
        }
    }
    printf("#");
}

int main() {
    /*ui();*/
    SNAKE* snake= (SNAKE*)malloc(sizeof(SNAKE));
    init_snake(snake);
    show_ui(snake);
    return 0;
}
