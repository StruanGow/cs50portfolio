#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    else
    {
        char *input_f_name = argv[1];
        FILE *input_p = fopen(input_f_name, "r");

        if (input_p == NULL)
        {
            printf("Error: cannot open %s\n", input_f_name);
            return 2;
        }
        BYTE buffer[512];
        int count = 0;
        FILE *img_pointer = NULL;
        char filename[8];
        while (fread(&buffer, 512, 1, input_p) == 1)
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                if (!(count == 0))
                {
                    fclose(img_pointer);
                }
                sprintf(filename, "%03i.jpg", count);
                img_pointer = fopen(filename, "w");
                count++;
            }
            if (!(count == 0))
            {
                fwrite(&buffer, 512, 1, img_pointer);
            }
        }
        fclose(input_p);
        fclose(img_pointer);
        return 0;
    }
}
