#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool IsPrime(int num);

int main(void){
    int r1, r0, r_1, f1, f0, f_1, g1, g0, g_1, d, e, L, i, q, tmp, counter;
    int lcm = 0;
    //bool primeFlag1, primeFlag2;
    tmp= 0;
    counter = 1;
    
    printf("異なる整数を二つ入力してください\n");
    printf("整数1:\n>>");
    scanf("%d", &e);
    printf("整数2:\n>>");
    scanf("%d", &L);

    /*
    primeFlag1 = IsPrime(e);
    primeFlag2 = IsPrime(L);
    */

    if(e == L){
        printf("エラー: 異なる整数を入力してください\n");
        return 1;
    }/*else if(primeFlag1 == false || primeFlag2 == false){
        printf("素数を入力してください\n");
        return 1;
    }*/else if(e < L){
        tmp = L;
        L = e;
        e = tmp;
    }
    
    r_1 = e; 
    r0 = L;
    r1 = 1;
    f_1 = 1;
    f0 = 0;
    g_1 = 0;
    g0 = 1;

    while(r1 > 0){
        r1 = r_1 % r0;
        q = (r_1 - r1)*1.0/r0;

        f1 = f_1 -q*f0;
        g1 = g_1 -q*g0;

        d = f1*e + g1*L;
        
        printf("r%d(f*a + g*b) = %d\n", counter, d);
        printf("f%d = %d\n",counter, f1);
        printf("g%d = %d\n",counter, g1);
        printf("r%d = %d\n", counter, r1);
        printf("q%d = %d\n\n", counter, q);

        tmp = r0 % r1;
        if(tmp == 0){break;}

        r_1 = r0;
        r0 = r1;
        f_1 = f0;
        f0 = f1;
        g_1 = g0;
        g0 = g1;
        counter = counter + 1;
    }
    printf("d_%d = %d\n",e, f1);
    printf("gcd(%d, %d) = %d\n", e, L, r1);

    return 0;
}

/*
bool IsPrime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    int i;
    double sqrtNum;
    sqrtNum = sqrt(num);
    for (i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
*/
