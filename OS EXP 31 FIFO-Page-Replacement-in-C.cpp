#include <stdio.h>

int main() {
    int frames[10], pages[30];
    int total_pages, total_frames, page_faults = 0;
    int i, j, k = 0, available;

    printf("Enter number of frames: ");
    scanf("%d", &total_frames);

    printf("Enter number of pages: ");
    scanf("%d", &total_pages);

    printf("Enter page reference string:\n");
    for (i = 0; i < total_pages; i++)
        scanf("%d", &pages[i]);

    // Initialize frames
    for (i = 0; i < total_frames; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < total_pages; i++) {
        available = 0;

        // Check if page already exists
        for (j = 0; j < total_frames; j++) {
            if (frames[j] == pages[i]) {
                available = 1;
                break;
            }
        }

        // FIFO replacement
        if (available == 0) {
            frames[k] = pages[i];
            k = (k + 1) % total_frames;
            page_faults++;
        }

        // Print current frames
        printf("%d\t", pages[i]);
        for (j = 0; j < total_frames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    return 0;
}

