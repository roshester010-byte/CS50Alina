#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument

    if (argc != 2)
    {
        printf("Usage: ./recover image \n");
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

    BYTE buffer[512];
    int jpeg_count = 0;
    FILE *img = NULL;
    while (fread(buffer, 1, 512, card) == 512)
    { // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 &&
            buffer[3] <= 0xef)
        {
            if (jpeg_count != 0)
            {
                fclose(img);
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", jpeg_count);
            img = fopen(filename, "wb");
            if (img == NULL)
            {
                fclose(card);
                return 1;
            }
            jpeg_count++;
        }

        if (jpeg_count != 0)
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    if (jpeg_count != 0)
    {
        fclose(img);
    }
    fclose(card);
    return 0;
}
