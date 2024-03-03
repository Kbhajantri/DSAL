#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char M[200], S[30], R[30], RE[200], C[200];
    int i = 0, j = 0, k = 0, im, is, len, in = 0, l;

    printf("\nENTER THE MAIN STRING : ");
    scanf("%s", M);

    printf("\nENTER THE PATTERN STRING : ");
    scanf("%s", S);

    printf("\nENTER THE REPLACE STRING : ");
    scanf("%s", R);

    strcpy(C, M);

    for (i = 0; i <= strlen(M) - strlen(S); i++) {
        im = 0;
        for (j = 0; j < strlen(S); j++) {
            if (M[i + j] == S[j]) {
                im++;
            }
        }
        if (im == strlen(S)) {
            in++;
            for (k = 0; k < i; k++) {
                RE[k] = M[k];
            }
            is = k;
            for (l = 0; R[l] != '\0'; l++, k++) {
                RE[k] = R[l];
            }
            for (l = i + strlen(S); M[l] != '\0'; l++, k++) {
                RE[k] = M[l];
            }
            RE[k] = '\0';
            strcpy(M, RE);
        }
    }

    printf("\nINPUT TEXT:\n");
    printf("%s\n", C);
    if (in > 0) {
        printf("\n%d MATCHES OCCURRED\nTEXT AFTER REPLACING MATCHED PATTERNS IS SHOWN BELOW\n", in);
        printf("\n%s\n", RE);
    } else {
        printf("\nPATTERN STRING NOT FOUND IN TEXT\n");
    }

    return 0;
}
