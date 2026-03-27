int main() {
}


void simpleFunc() {
    int temp1 = 0;
    int temp2 = 0;
    int num = 0;
    int n = 100;
    for (int c = 1; c <= n; c++) {
        temp1 = 0;
        for (int b = 1; b <= n; b++) {
            for (int a = 1; a <= b; a++) {
                temp1 += 1;
            }
        }
        num += temp1;
    }
    for (int c = 1; c <= n; c++) {
        temp2 = 0;
        for (int b = 1; b <= n; b++) {
            for (int a = 1; a <= b; a++) {
                temp2 += 1;
            }
        }
        num += temp2;
    }
}
