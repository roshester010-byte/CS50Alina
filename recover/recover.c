#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument

    if (argc != 2)
    {
        printf ("Usage: ./recover image \n");
        return 1;
    }

    // Open the memory card

    FILE *card = fopen(argv[1], "rb");
    if (card == NULL)
    {
        printf("Forensic image cannot be opened for reading\n");
        return 1;
    }

    // While there's still data left to read from the memory card

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[3] == 0xe0 &&
    buffer[2] >= 0xe0 && buffer[2] <= 0xef)
    {

    }
        // Create JPEGs from the data

        int jpeg_img = 0;
        FILE *img = NULL;
        fclose(img);
        char filename[8];
        sprintf(filename, "%03d", jpeg_img);
}
