#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("the file could no be open\n");
        return 1;
    }

    unsigned char buffer[512];

    int count = 0;
    int jpg = 0;
    FILE *img = NULL;

    //as long there is bloks of information do the folowing
    while (fread(buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe0)
        {
            if (jpg == 1)
            {
                fclose(img);
            }
            else
            {
                jpg = 1;
            }

            char name[8];
            sprintf(name, "%03d.jpg", count++);
            img = fopen(name, "w");
            if (img == NULL)
            {
                return 1;
            }
        }

        if (jpg == 1)
        {
            fwrite(&buffer, 512, 1, img);
        }
    }

    fclose(file);
    fclose(img);

    return 0;
}
