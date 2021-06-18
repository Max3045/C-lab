#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fIn = fopen("Pic.bmp", "rb");
    FILE* fOut = fopen("WbPic.bmp", "wb");
    if (!fIn || !fOut)
    {
        printf("File error.\n");
        return 1;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fIn);      // Чтение заголовка из исходного файла
    fwrite(header, sizeof(unsigned char), 54, fOut);    // Запись заголовка в новый файл

    int width = *(int*)&header[18];                     // Считывание из заголовка ширину изображения
    int height =abs( *(int*)&header[22]);                    // Считывание из заголовка высоту изображения
    int stride = (width * 3 + 3) & ~3;
    int padding = stride - width * 3;


    unsigned char pixel[3];
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            fread(pixel, 3, 1, fIn);    // Чтение пикселя из исходного файла
            unsigned char gray = pixel[0] * 0.3 + pixel[1] * 0.58 + pixel[2] * 0.11;    // Модификация пикселя
            memset(pixel, gray, sizeof(pixel));
            fwrite(&pixel, 3, 1, fOut);     // Запись модифицированного пикселя в новый файл
        }
        fread(pixel, padding, 1, fIn);
        fwrite(pixel, padding, 1, fOut);
    }
    fclose(fOut);
    fclose(fIn);

    printf("Complite!");
    return 0;
}