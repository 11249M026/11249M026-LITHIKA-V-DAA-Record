#include <stdio.h>

int main() {
    int n, i, j;
    float cap;

    printf("Enter number of items: ");
    scanf("%d", &n);

    float item[n], bin[n];

    printf("Enter bin capacity: ");
    scanf("%f", &cap);

    for (i = 0; i < n; i++) {
        printf("Enter size of item %d: ", i + 1);
        scanf("%f", &item[i]);
    }

    for (i = 0; i < n; i++) {
        bin[i] = cap;
    }

    for (i = 0; i < n; i++) {
        int placed = 0;
        for (j = 0; j < n; j++) {
            if (bin[j] >= item[i]) {
                bin[j] -= item[i];
                placed = 1;
                break;
            }
        }
        if (!placed) {
            printf("Item %d cannot be placed\n", i + 1);
        }
    }

    printf("Remaining space in bins:\n");
    for (i = 0; i < n; i++) {
        if (bin[i] != cap) {
            printf("Bin %d: %.2f\n", i + 1, bin[i]);
        }
    }

    return 0;
}
