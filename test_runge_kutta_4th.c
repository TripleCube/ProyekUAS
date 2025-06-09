#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
Konstanta
Nilai Mu, Beta, Gamma, Delta, dan Phi berasal dari Tabel I
Nilai Alpha dan Epsilon berasal dari model SIR Transmisi TB
*/
#define Mu 0.000046
#define Beta 0.326666
#define Gamma 0.123111
#define Delta 0.041230
#define Phi 0.003700
#define Alpha (Mu + Delta)
#define Epsilon (Mu + Phi)

/* 
Fungsi turunan 
dx_dt menghitung nilai (dx/dt)
dy_dt menghitung nilai (dy/dt)
dz_dt menghitung nilai (dz/dt)
*/

typedef struct {
    double x, y, z;
} State;

double dx_dt(double x, double y) {
    return Mu - Beta * x - (Gamma * Beta) * x * y - Mu * x;
}

double dy_dt(double x, double y) {
    return Beta * x - Alpha * y;
}

double dz_dt(double x, double y, double z) {
    return (Gamma * Beta) * x * y - Epsilon * z;
}

// RK4 step for one time step
State rk4_step(State s, double h) {
    double k1x = dx_dt(s.x, s.y);
    double k1y = dy_dt(s.x, s.y);
    double k1z = dz_dt(s.x, s.y, s.z);

    double k2x = dx_dt(s.x + h * k1x / 2, s.y + h * k1y / 2);
    double k2y = dy_dt(s.x + h * k1x / 2, s.y + h * k1y / 2);
    double k2z = dz_dt(s.x + h * k1x / 2, s.y + h * k1y / 2, s.z + h * k1z / 2);

    double k3x = dx_dt(s.x + h * k2x / 2, s.y + h * k2y / 2);
    double k3y = dy_dt(s.x + h * k2x / 2, s.y + h * k2y / 2);
    double k3z = dz_dt(s.x + h * k2x / 2, s.y + h * k2y / 2, s.z + h * k2z / 2);

    double k4x = dx_dt(s.x + h * k3x, s.y + h * k3y);
    double k4y = dy_dt(s.x + h * k3x, s.y + h * k3y);
    double k4z = dz_dt(s.x + h * k3x, s.y + h * k3y, s.z + h * k3z);

    State result;
    result.x = s.x + h / 6.0 * (k1x + 2 * k2x + 2 * k3x + k4x);
    result.y = s.y + h / 6.0 * (k1y + 2 * k2y + 2 * k3y + k4y);
    result.z = s.z + h / 6.0 * (k1z + 2 * k2z + 2 * k3z + k4z);

    return result;
}

void run_with_error_estimation(State initial, double t0, double h, int steps) {
    FILE *fp = fopen("hasil_runge_kutta.csv", "w");
    if (!fp) {
        printf("Gagal membuka file.\n");
        return;
    }

    fprintf(fp, "Step,Time,X,Y,Z,Ex,Ey,Ez\n");

    double t = t0;
    State coarse = initial;
    State fine = initial;

    for (int i = 0; i <= steps; i++) {
        // Refined solution (two half-steps of RK4)
        State temp = fine;
        temp = rk4_step(temp, h / 2);
        temp = rk4_step(temp, h / 2);

        // Error estimation: E = (y_half - y_full) / (2^p - 1)
        double ex = fabs(temp.x - coarse.x) / 15.0;
        double ey = fabs(temp.y - coarse.y) / 15.0;
        double ez = fabs(temp.z - coarse.z) / 15.0;

        fprintf(fp, "%d,%.4f,%.6f,%.6f,%.6f,%.6e,%.6e,%.6e\n",
            i, t, coarse.x, coarse.y, coarse.z, ex, ey, ez);

        // Advance time
        coarse = rk4_step(coarse, h);
        fine = temp;
        t += h;
    }

    fclose(fp);
    printf("Hasil disimpan ke 'hasil_runge_kutta.csv'\n");
}

int main() {
    /* 
	Nilai awal
    Nilai sH, iH, iI, dan rH diambil dari Tabel I
    Nilai nH, x0, y0, dan z0 diambil dari model SIR transmisi TB
    Nilai 
    */
    double sH = 8377828; 
    double iH = 8000;
    double iI = 939;
    double rH = 4;
    double nH = sH + iH + iI + rH;
    
    double x0 = sH/nH;
    double y0 = iH/nH;
    double z0 = iI/nH;
    State s0 = {x0, y0, z0};
    double t0 = 0.0;
    double h = 1.0;     // langkah waktu, diatur sehingga mengukur satu t
    int steps;    // jumlah iterasi (total waktu = steps * h)

	printf("Masukkan jumlah unit waktu t yang diinginkan: ");
	scanf("%d", &steps);
    run_with_error_estimation(s0, t0, h, steps);
    return 0;
}

