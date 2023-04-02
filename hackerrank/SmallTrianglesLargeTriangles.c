#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle* tr, int n) {
  
    double areas[n];
    for (int i = 0; i < n; i++) {
        double p = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
        areas[i] = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c));
    }
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (areas[j] < areas[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            triangle temp = tr[i];
            tr[i] = tr[min_idx];
            tr[min_idx] = temp;
            double temp_area = areas[i];
            areas[i] = areas[min_idx];
            areas[min_idx] = temp_area;
        }
    }
    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
