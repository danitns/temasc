#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *func1(void *ptr);
void *func2(void *ptr);
double f_ctanh();

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

double e_x = 1;


int main()
{

    pthread_t thread1, thread2;

    //  const char *message1 = "Executie Thread 1";

    //  const char *message2 = "Executie Thread 2";

    int  iret1, iret2;
    int* x;
    printf("x: ");
    scanf("%d", x);

    
    /* creare threaduri independente care au functiile asociate corespunzatoare  */

 

    iret1 = pthread_create( &thread1, NULL, func1, (void*)x);

    if(iret1)

    {

        fprintf(stderr,"Eroare - pthread_create() : %d\n",iret1);

        exit(EXIT_FAILURE);

    }

 

    iret2 = pthread_create( &thread2, NULL, func2, (void*)x);

    if(iret2)

    {

        fprintf(stderr,"Eroare - pthread_create() : %d\n",iret2);

        exit(EXIT_FAILURE);

    }

 

    printf("pthread_create() : %d\n",iret1);

    printf("pthread_create() : %d\n",iret2);

 

    /* se asteapta completarea instructinilor din cele doua threaduri  */

     

    pthread_join( thread1, NULL);

    pthread_join( thread2, NULL);

    printf("Terminare thread!\n");

    printf("Ctanh : %lf\n", f_ctanh());

    return 0;

}

void *func1(void *ptr)
{
    int* x = (int*)ptr;

    for(int i = 0; i < *x/2; i++)
        e_x = e_x * 2.71;
}

void *func2(void *ptr)
{
    int* x = (int*)ptr;

    for(int i = *x/2; i <* x; i++)
        e_x = e_x * 2.71;
}

double f_ctanh()
{
    double e_minusx = 1. / e_x;
    return (e_x + e_minusx) / (e_x - e_minusx);
}