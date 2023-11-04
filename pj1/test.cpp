#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    FILE *fp1, *fp2;
    int n, v1, v2, v3;
    float x;
    double y;
    if (argc < 3){
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit (1);
    }
    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit (1);
    }
    fp2 = fopen(argv[2], "w");
    if (fp2 == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
        exit (1);
    }
    v1=fscanf(fp1, "%d", &n);
    v2=fscanf(fp1, "%f", &x);
    v3=fscanf(fp1, "%lf", &y);
    fprintf(fp2, "v1=%d, v2=%d, v3=%d\n", v1, v2, v3);
    fprintf(fp2, "n=%d, n=%4d\n", n, n);
    fprintf(fp2, "x=%f, x=%8.3f\n", x, x);
    fprintf(fp2, "y=%lf, y=%8.3lf\n", y, y);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
