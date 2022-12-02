#include <stdio.h>
#include <math.h>
#include <conio.h>
float y=1, x, ypow;
double delta=1, epsilon, counter;
int k, i=1,epsi;
char er, symbol;
float ycount();
int main( ) {
  do {
     do //Введення х
     {
         er = 0;
         printf("Enter radicand (x) (The fractional number should be indicated with a dot)\n");
         scanf("%f%c", &x, &symbol);
         if (symbol != '\n')
         {
             er = 1;
             while ((getchar()) != '\n');
             printf("Enter number without symbol\n");
         }
     } while (er != 0);
     symbol = 0;

     do //Введення k
     {
         er = 0;
         printf("Enter the degree of the root (k)\n");
         scanf("%i%c", &k, &symbol);
         if (symbol != '\n')
         {
             er = 1;
             while ((getchar()) != '\n');
             printf("Enter number without symbol\n");
         } else {
             if (k == 0) {
                 er = 1;
                 while ((getchar()) != '\n');
                 printf("k cannot be zero\n");
             }
         }
     } while (er != 0);

     if ((k > 0 && k % 2 == 0 && x < 0) ||
         (k < 0 && k % 2 == 0 && x <= 0) ||
         (k < 0 && k % 2 == -1 && x == 0)) {
             er = 1;
             printf("It is impossible to calculate\n");
     }
 }while (er != 0);

 symbol = 0;

 do //Введення епсілон
    {
        er = 0;
        printf("Enter accuracy of calculations from 1e-1 to 1e-7\n");
        scanf ("%lf%c", &epsilon, &symbol);
        if (symbol != '\n')
        {
            er = 1;
            while ((getchar()) != '\n');
            printf("Enter number without symbol\n");
        } else {
            if ((epsilon <= 0) || (epsilon>1e-8)){
                er = 1;
                while ((getchar()) != '\n');
                printf("Not correct epsilon\n");
            }
        }
 } while (er != 0);

   counter=epsilon;
    while (counter < 1) {
        counter*= 10;
        epsi++;
    }

    if(x!=0) {
           ycount();
    } else {
        y=0;
        printf ("y=%f",y);
    }

    getch();
    return 0;
}

float ycount() {
    while (fabs(delta)>=epsilon){
        ypow=1;
        for (i = 1; i <abs(k); i++) {
            ypow *= y;
        }
        delta = (x / ypow - y) / abs(k);
        y += delta;

        if (y == 0) {
            y = -1;
        }
        printf ("y=%lf\n", y);
        printf ("delta=%lf\n", delta);
    }
    if (k<0) {
        y=1/y;
    }
    printf ("\nFinally y=%.*lf\n",epsi, y);
    return 0;
}
