# Proyek UAS
## Judul: Implementasi Runge-Kutta Method Dalam Program Untuk Simulasi Transmisi Tuberkulosis
### Penulis: Farhan Ramadhani Zakiyyandi (2306220412)

### Deskripsi

Program ini mengimplementasikan metode numerik 4th Order Runge-Kutta Method untuk menghitung model SIR Transmisi TB pada rentang waktu yang bersifat variabel. Metode tersebut, yang dijelaskan dalam buku Numerical Methods for Engineers oleh Chapra dan Canale, digunakan untuk mengaproksimasi model laju data secara persis.

Program ditulis dalam bahasa pemrograman C, dan disimpan outputnya dalam sebuah file .csv, yang kemudian bisa dibuat grafik untuk menunjukkan laju semua persamaan modelnya.

### Cara Menjalankan

1. Pastikan punya sebuah compiler C terinstall, seperti GCC.
2. Kompilasikan kode. Berikut adalah instruksi bila memakai CLI:
   ```
   gcc test_runge_kutta_4th.c -o test_runge_kutta_4th
   ```
3. Jalankan file executable yang dihasilkan. Berikut adalah instruksi bila memakai CLI:
   ```
   ./test_runge_kutta_4th
   ```
4. Output: Program akan menyimpan output dalam file csv, yang menunjukkan nilai step, waktu t, nilai RK4 x(t), y(t), dan z(t), serta nilai estimasi error masing-masing ketiga kolom terakhir.
   
### Struktur File

- `test_runge_kutta_4th.c`: File c RK4
- `test_runge_kutta_4th.exe`: Program RK4
- `hasil_runge_kutta.csv`: Tempat output program RK4
- `ProyekUAS_2306220412_Farhan.docx`: Laporan tertulis "Implementasi Runge-Kutta Method Dalam Program Untuk Simulasi Transmisi Tuberkulosis" dengan LATEX.
- `ProyekUAS_2306220412_Farhan.pdf`: Salinan PDF laporan.
- `README.md`: File dokumentasi ini.

### Contoh Output

Program C

![](https://cdn.imgchest.com/files/4z9cvxj6aa7.png)

File .csv
```
Step	Time	X	        Y	        Z	        Ex	        Ey	        Ez
0	0	0.998934	0.000954	0.000112	1.88E-02	1.81E-02	3.14E-04
1	1	0.716385	0.272789	0.004816	1.38E-02	1.22E-02	5.93E-04
2	2	0.509142	0.455834	0.013699	9.97E-03	7.94E-03	5.92E-04
3	3	0.3597	        0.574911	0.022563	7.11E-03	4.92E-03	4.93E-04
4	4	0.253164	0.648621	0.029938	5.03E-03	2.80E-03	3.76E-04
5	5	0.177787	0.690554	0.035565	3.54E-03	1.33E-03	2.73E-04
6	6	0.124713	0.710468	0.039645	2.49E-03	3.23E-04	1.92E-04
7	7	0.087453	0.715288	0.042504	1.74E-03	3.59E-04	1.31E-04
8	8	0.061338	0.709892	0.044453	1.22E-03	8.13E-04	8.75E-05
9	9	0.043048	0.697693	0.045747	8.55E-04	1.11E-03	5.67E-05
10	10	0.030242	0.68107	        0.04658	        5.99E-04	1.29E-03	3.54E-05
```
