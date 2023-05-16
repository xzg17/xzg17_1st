#include <stdio.h>
#include "calc.h"

int mypow(int x, int y,int d) {
    if(y==0){
        return 1;
    }else{
        int z = mypow(x,(y/2),d);
        if(y % 2 == 1){
            z = x*z*z;
        }else{
            z = z*z;
        }
        return z % d;
    }
}
