#include <stdio.h>

#define LEN 54

// a)

int calc (unsigned char arg[LEN]) {
    int res = 0 ;
    for (int i = 0 ; i < LEN ; i++) {
        for (int y = 0; y < 8; y++) {
            if ((arg[i] & (1 << y) )!=0) res++;
        }
    }
    printf("res -> %i ",res);
    return res;
}

// b)

void revele(unsigned char arg[LEN], unsigned char cle) {
    printf("\n=================================\n");
    for (int i = 0; i < LEN; ++i) {
        unsigned char mdp = arg[i] ^ cle;
        printf("%c",mdp);
        cle = (cle << 1)|(cle >> 7);
    }
    printf("\n");
}


int main(int argc, char *argv[]) {
    unsigned char cle = 0b11001011;  // 0xCB en hexa, 203 en décimal
    unsigned char msg[LEN] = {
        233, 251, 74, 126, 207, 28, 145, 151, 174, 227, 3, 126, 223, 94, 151, 150, 191, 183, 94, 43, 155, 16, 158, 197,
        165, 176, 86, 126, 221, 89, 147, 144, 168, 226, 65, 126, 213, 23, 149, 151, 174, 243, 70, 59, 210, 13, 210, 150,
        174, 244, 93, 59, 200, 91
    };

    calc(msg);
    revele(msg, cle);

    return 0;
}