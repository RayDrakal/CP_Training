#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    int tday = 0;
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(sizeof(char)*4);
    int days[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i = 0; i < 13; i++) {
        if(i < a)
            tday += days[i];
        if(i == a) {
            tday += b;
            break;
        }
    }
    switch(tday%7) {
        case 0 :
            answer = "THU";
            break;
        case 1 :
            answer = "FRI";
            break;
        case 2 :
            answer = "SAT";
            break;
        case 3 :
            answer = "SUN";
            break;
        case 4 :
            answer = "MON";
            break;
        case 5 :
            answer = "TUE";
            break;
        case 6 :
            answer = "WED";
            break;
    }
    return answer;
}