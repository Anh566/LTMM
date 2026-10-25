#include <stdio.h>

// Nhan 2 da thuc trong GF(2^4) voi m(x) = x^4 + x + 1 
int nhan_gf2_4(int a, int b){
    int kq = 0;
    for (int i = 0; i < 4; i++){
        if (b & 1){
            kq = kq ^ a;
        }
        a = a << 1;
        // Neu vuot qua bac 3 (bit thu 4 bang 1)
        if (a & 0x10) {
            a = a ^ 0x13; // XOR voi da thuc toi gian 0x13
        }
        b = b >> 1;
    }
    return kq;
}

// Nhan 2 da thuc trong GF(2^8) voi m(x) = x^8 + x^4 + x^3 + x + 1 (0x11B)
int nhan_gf2_8(int a, int b){
    int kq = 0;
    for (int i = 0; i < 8; i++){
        if (b & 1){
            kq = kq ^ a;
        }
        a = a << 1;
        // Neu vuot qua bac 7 (bit thu 8 bang 1)
        if (a & 0x100){
            a = a ^ 0x11B; // Rut gon bang cach XOR voi da thuc toi gian 0x11B
        }
        b = b >> 1;
    }
    return kq;
}

int main(){
    int a4, b4;
    printf(" NHAN TRONG GF(2^4)\n");
    printf("Nhap da thuc A (dang hex, vi du B): ");
    scanf("%x", &a4);
    printf("Nhap da thuc B (dang hex, vi du 7): ");
    scanf("%x", &b4);
    printf("Ket qua A * B trong GF(2^4) = 0x%X\n\n", nhan_gf2_4(a4, b4));

    int a8, b8;
    printf("--- NHAN TRONG GF(2^8) ---\n");
    printf("Nhap da thuc A (dang hex, vi du 57): ");
    scanf("%x", &a8);
    printf("Nhap da thuc B (dang hex, vi du 83): ");
    scanf("%x", &b8);
    printf("Ket qua A * B trong GF(2^8) = 0x%02X\n", nhan_gf2_8(a8, b8));

    return 0;
}
