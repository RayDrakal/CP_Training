#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n) {
    long long answer = -1;
    int x = sqrt(n);
    for(int i = 1; i <= x; i++) {
        if((double)i == sqrt(n))
            answer = x + 1;
    }
    if(answer > 0)
        answer *= answer;
    return answer;
}