#include <stdio.h>
#include <stdlib.h>

struct flex{
    size_t n;
    double ava;
    double score[];
};

void showFlex(const struct flex *ptf);

int main(void){

    struct flex *flex1,*flex2;
    int i;

    int n = 5;
    int tot = 0;
    flex1 = malloc(sizeof(struct flex) + n * sizeof(double));
    flex1 ->n = n;
    for(i = 0; i< flex1 -> n; i++){
        flex1 -> score[i] = 20 - i;
        tot += flex1 -> score[i];
    }
    flex1 -> ava = tot / n;
    showFlex(flex1);

    n = 10;
    tot = 0;
    flex2 = malloc(sizeof(struct flex) + n * sizeof(double));
    flex2 ->n = n;
    for(i = 0; i< flex2 -> n; i++){
        flex2 -> score[i] = 20 - i;
        tot += flex2 -> score[i];
    }
    flex2 -> ava = tot / n;
    showFlex(flex2);

    free(flex1);
    free(flex2);

    return 0;
}

void showFlex(const struct flex *ptf){
    int i;
    for(i = 0; i< ptf -> n; i++)
        printf("score%d=%g\n",i, ptf->score[i]);
    printf("n=%d,ava=%g\n",ptf -> n, ptf -> ava);
}