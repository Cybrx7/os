#include <stdio.h>

int main()
{
    int n, m, i, j, k, pf = 0, f = 0, index;
    
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the size of Cache memory: ");
    scanf("%d", &m);
    int a[n], b[m], c[m];
    
    
    printf("Enter the page number of each page: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    
    for(i = 0; i < m; i++) {
        b[i] = -1;  
        c[i] = 0;   
    }

    
    for(i = 0; i < n; i++) {
        f = 1;
        
        
        for(j = 0; j < m; j++) {
            if(a[i] == b[j]) {
                f = 0;    
                c[j]++;    
                break;
            }
        }

        
        if(f == 1) {
            
            int min = c[0];
            index = 0;
            for(k = 1; k < m; k++) {
                if(c[k] < min) {
                    min = c[k];
                    index = k;
                }
            }
            b[index] = a[i];    
            c[index] = 1;       
            pf++;                
        }
        
        // Print the current cache state
        printf("Cache: ");
        for(k = 0; k < m; k++) {
            printf("%d ", b[k]);
        }
        printf("\n");
    }

    // Print the total number of page faults
    printf("\nNumber of page faults: %d\n", pf);
    
    return 0;
}

