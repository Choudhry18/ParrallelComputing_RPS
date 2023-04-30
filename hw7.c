#include <stdio.h>
#include <pthread.h>

int dice = 1;
char opp = 'a';
char play;
void *Rat1(void *arg)
{
    int i;
    for (i = 1; i < 1000000; i++)
    {
        dice = dice * i; // critical section
    }
    return NULL;
}

void *Rat2(void *arg)
{
    int i;
    for (i = 1; i < 1000000; i++)
    {
        dice = dice - i; // critical section
    }
    return NULL;
}

int main()
{
    while (1)
    {
        dice = 1;
        printf("\nEnter Rock(r), Paper(p) or Scissor(r): ");
        pthread_t thread1, thread2;
        pthread_create(&thread1, NULL, Rat1, NULL);
        pthread_create(&thread2, NULL, Rat2, NULL);
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        if (dice == 0)
            play = 'r';
        if (dice > 0)
            play = 'p';
        if (dice < 0)
            play = 's';
        scanf(" %c", &opp);
        printf("You played %c\n", opp);
        printf("Computer played %c\n", play);
        switch (opp)
        {
        case 'r':
            if (play == 'r')
                printf("It's a draw.");
            if (play == 'p')
                printf("Computer won.");
            if (play == 's')
                printf("You won.");
            break;
        case 'p':
            if (play == 'p')
                printf("It's a draw.");
            if (play == 's')
                printf("Computer won.");
            if (play == 'r')
                printf("You won.");
            break;
        case 's':
            if (play == 's')
                printf("It's a draw.");
            if (play == 'r')
                printf("Computer won.");
            if (play == 'p')
                printf("You won.");
            break;
        }
    }
}