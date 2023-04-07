#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Turkish");// T�rk�e karakter kullan�m� i�in ekledik.
	printf("Diziyi toplam� e�it alt k�melere b�lme:\nKulllan�c�dan al�nan bo� olmayan tamsay� dizisininin toplamlar� e�it iki alt k�meye b�l�n�p b�l�nemeyece�ini hesaplar.\n \n");
    int n;
    do {
        printf("Lutfen pozitif bir eleman sayisi giriniz: ");// Kullan�c�dan tamsay� dizisinin eleman say�s�n� ald�k.
        scanf("%d", &n);
    } while (n <= 0);

// kullan�c�dan al�nan n elemanl� say� dizisinin elemanlar� toplam�n� hesaplad�k.
    int arr[n];
    int i, sum = 0;
    for (i = 0; i < n; i++) {
        printf("Lutfen %d. elemani giriniz: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

// Elemanlar� toplam�n�n s�f�ra e�it olma durumunu kontrol ediyoruz e�itse yeniden say� ald�r�yoruz.
    if (sum == 0) {
        do {
            printf("Dizinin toplami sifir oldugundan yeni bir dizi girmelisiniz.\n");
            for (i = 0; i < n; i++) {
                printf("Lutfen %d. elemani giriniz: ", i + 1);
                scanf("%d", &arr[i]);
                sum += arr[i];
            }
        } while (sum == 0);
    }

// Dizinin elemanlar� toplam� �ift say� ise alt k�melerin e�it olup olmama durumunu kontrol ediyoruz.
    if (sum % 2 == 0) {
        int target_sum = sum / 2;
        int dp[n+1][target_sum+1];
        for (i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (i = 1; i <= target_sum; i++) {
            dp[0][i] = 0;
        }
        for (i = 1; i <= n; i++) {
            int j;
            for (j = 1; j <= target_sum; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= arr[i-1]) {
                    dp[i][j] |= dp[i-1][j-arr[i-1]];
                }
            }
        }
        // Dizi alt k�melere b�l�nebiliyorsa bu alt k�meleri ekrana yazd�r�yoruz.
        if (dp[n][target_sum]) {
            printf("Dizi esit iki alt kumeye bolunebilir.\n");
            printf("Alt kume 1:\n");
            int j = target_sum;
            for (i = n; i > 0 && j >= 0; i--) {
                if (dp[i-1][j]) {
                    continue;
                }
                printf("%d ", arr[i-1]);
                j -= arr[i-1];
            }
            printf("\nAlt kume 2:\n");
            for (i = 0; i < n; i++) {
                if (dp[i+1][target_sum]) {
                    continue;
                }
                printf("%d ", arr[i]);
            }
            printf("\n");
        } else {
            printf("Dizi esit iki alt kumeye bolunemez.\n");
        }
    } else {
        printf("Dizi esit iki alt kumeye bolunemez.\n");
    }

    return 0;
}




