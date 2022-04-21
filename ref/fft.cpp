#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int N = 1024;
const float PI = 3.1416;

inline void swap (float &a, float &b)
{
     float t;
     t = a;
     a = b;
     b = t;
}

void bitrp (float xreal [], float ximag [], int n)
{
     // 位反轉置換 Bit-reversal Permutation
     int i, j, a, b, p;

     for (i = 1, p = 0; i < n; i *= 2)
{
         p ++;
}
     for (i = 0; i < n; i ++)
{
         a = i;
         b = 0;
         for (j = 0; j < p; j ++)
   {
             b = (b << 1) + (a & 1);     // b = b * 2 + a % 2;
             a >>= 1;         // a = a / 2;
   }
         if ( b > i)
   {
             swap (xreal [i], xreal [b]);
             swap (ximag [i], ximag [b]);
   }
}
}

void FFT(float xreal [], float ximag [], int n)
{
     // 快速傅立葉變換，將復數 x 變換后仍保存在 x 中，xreal, ximag 分別是 x 的實部和虛部
     float wreal [N / 2], wimag [N / 2], treal, timag, ureal, uimag, arg;
     int m, k, j, t, index1, index2;
    
     bitrp (xreal, ximag, n);

     // 計算 1 的前 n / 2 個 n 次方根的共軛復數 W'j = wreal [j] + i * wimag [j] , j = 0, 1,   , n / 2 - 1
     arg = - 2 * PI / n;
     treal = cos (arg);
     timag = sin (arg);
     wreal [0] = 1.0;
     wimag [0] = 0.0;
     for (j = 1; j < n / 2; j ++)
{
         wreal [j] = wreal [j - 1] * treal - wimag [j - 1] * timag;
         wimag [j] = wreal [j - 1] * timag + wimag [j - 1] * treal;
}

     for (m = 2; m <= n; m *= 2)
{
         for (k = 0; k < n; k += m)
   {
             for (j = 0; j < m / 2; j ++)
    {
                 index1 = k + j;
                 index2 = index1 + m / 2;
                 t = n * j / m;     // 旋轉因子 w 的實部在 wreal [] 中的下標為 t
                 treal = wreal [t] * xreal [index2] - wimag [t] * ximag [index2];
                 timag = wreal [t] * ximag [index2] + wimag [t] * xreal [index2];
                 ureal = xreal [index1];
                 uimag = ximag [index1];
                 xreal [index1] = ureal + treal;
                 ximag [index1] = uimag + timag;
                 xreal [index2] = ureal - treal;
                 ximag [index2] = uimag - timag;
    }
   }
}
}

void   IFFT (float xreal [], float ximag [], int n)
{
     // 快速傅立葉逆變換
     float wreal [N / 2], wimag [N / 2], treal, timag, ureal, uimag, arg;
     int m, k, j, t, index1, index2;
    
     bitrp (xreal, ximag, n);

     // 計算 1 的前 n / 2 個 n 次方根 Wj = wreal [j] + i * wimag [j] , j = 0, 1,   , n / 2 - 1
     arg = 2 * PI / n;
     treal = cos (arg);
     timag = sin (arg);
     wreal [0] = 1.0;
     wimag [0] = 0.0;
     for (j = 1; j < n / 2; j ++)
{
         wreal [j] = wreal [j - 1] * treal - wimag [j - 1] * timag;
         wimag [j] = wreal [j - 1] * timag + wimag [j - 1] * treal;
}

     for (m = 2; m <= n; m *= 2)
{
         for (k = 0; k < n; k += m)
   {
             for (j = 0; j < m / 2; j ++)
    {
                 index1 = k + j;
                 index2 = index1 + m / 2;
                 t = n * j / m;     // 旋轉因子 w 的實部在 wreal [] 中的下標為 t
                 treal = wreal [t] * xreal [index2] - wimag [t] * ximag [index2];
                 timag = wreal [t] * ximag [index2] + wimag [t] * xreal [index2];
                 ureal = xreal [index1];
                 uimag = ximag [index1];
                 xreal [index1] = ureal + treal;
                 ximag [index1] = uimag + timag;
                 xreal [index2] = ureal - treal;
                 ximag [index2] = uimag - timag;
    }
   }
}

     for (j=0; j < n; j ++)
{
         xreal [j] /= n;
         ximag [j] /= n;
}
}

void FFT_test ()
{
     char inputfile [] = "input.txt";     // 從文件 input.txt 中讀入原始數據
     char outputfile [] = "output.txt";     // 將結果輸出到文件 output.txt 中
     float xreal [N] = {}, ximag [N] = {};
     int n, i;
     FILE *input, *output;

     if (!(input = fopen (inputfile, "r")))
{
         printf ("Cannot open file. ");
         exit (1);
}
     if (!(output = fopen (outputfile, "w")))
{
         printf ("Cannot open file. ");
         exit (1);
}

     i = 0;
     while ((fscanf (input, "%f%f", xreal + i, ximag + i)) != EOF)
{
         i ++;
}
     n = i;     // 要求 n 為 2 的整數冪
     while (i > 1)
{
         if (i % 2)
   {
             fprintf (output, "%d is not a power of 2! ", n);
             exit (1);
   }
         i /= 2;
}

     FFT (xreal, ximag, n);
     fprintf (output, "FFT:     i      real imag ");
     for (i = 0; i < n; i ++)
{
         fprintf (output, "%4d     %8.4f     %8.4f ", i, xreal [i], ximag [i]);
}
     fprintf (output, "================================= ");

     IFFT (xreal, ximag, n);
     fprintf (output, "IFFT:     i      real imag ");
     for (i = 0; i < n; i ++)
{
         fprintf (output, "%4d     %8.4f     %8.4f ", i, xreal [i], ximag [i]);
}

     if ( fclose (input))
{
         printf ("File close error. ");
         exit (1);
}
     if ( fclose (output))
{
         printf ("File close error. ");
         exit (1);
}
}

int main ()
{
     FFT_test ();

     return 0;
}