#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    char fileIn[100] = "/Users/gabrielgar/CLionProjects/untitled13/output.tl5";
    char fileOut[100] = "/Users/gabrielgar/CLionProjects/untitled13/output2.tc9";

//    char fileIn[100];
//    char fileOut[100];
//
//    printf("Insert the name and address of the file you want to convert\n");
//    scanf("%s", fileIn); //gets full path, name and extension of file
//    printf("Insert the name and address of the file you want to store the result of format conversion\n");
//    scanf("%s", fileOut); //gets full path, name and extension of file

    FILE* stream = fopen(fileIn, "r");
    FILE* outFile = fopen(fileOut, "w");
    char line[1024];

    char* ext = strrchr(fileIn, '.');
    ext = ext+1;

    char* ext2 = strrchr(fileOut, '.');
    ext2 = ext2+1;



    //checks if format is consistent
    if((strcmp(ext, "csv") != 0 && strcmp(ext, "tl5") != 0 && strcmp(ext, "tr9") != 0 && strcmp(ext, "tc9") != 0 ) ||
            (strcmp(ext2, "csv") != 0 && strcmp(ext2, "tl5") != 0 && strcmp(ext2, "tr9") != 0 && strcmp(ext2, "tc9") != 0))
    {
        printf("File format inconsistent!\n");
        return 0;
    }

    //converts two files of same extension and converts between tc9 and tr9
    if(strcmp(ext, ext2) == 0 || ((strcmp(ext, "tc9") == 0 && strcmp(ext, "tr9") == 0) ) ||
    (strcmp(ext, "tr9") == 0 && strcmp(ext, "tc9") == 0))
    {
        while (fgets(line, 1024, stream)) {
            char *tmp = strdup(line);
            fprintf(outFile, "%s", tmp);
            free(tmp);

            if(outFile != NULL)
            {
                printf("File conversion successful!");
            }
        }
    }

    if((strcmp(ext, "tl5") == 0 || strcmp(ext, "tr9") == 0 ||
    strcmp(ext, "tc9") == 0) && strcmp(ext2, "csv") == 0) //convert from tl5, tr9 or tc9 to csv
    {

        while (fgets(line, 1024, stream)) {
            char *tmp = strdup(line);

            char *token = strtok(tmp, "|");

            while(token != NULL)
            {
                fprintf(outFile, "%s", token);
                token = strtok(NULL, "|");
                if(token != NULL) fprintf(outFile, ",");
            }

            free(tmp);
        }

        if(outFile != NULL)
        {
            printf("File conversion successful!");
        }
    }

    if(strcmp(ext, "csv") == 0 && strcmp(ext2, "tl5") == 0) //convert from csv to tl5
    {

        while (fgets(line, 1024, stream)) {
            char *tmp = strdup(line);

            char *token = strtok(tmp, ",");

            while(token != NULL)
            {
                for(int i = 0; i < (5<=strlen(token)? 5 : strlen(token)); i++)
                {
                    fprintf(outFile, "%c", token[i]);
                }

                int index = strlen(token);
                while(index < 5)
                {
                    fprintf(outFile, "%c", ' ');
                    index++;
                }

                token = strtok(NULL, ",");
                if(token != NULL) fprintf(outFile, "|");
            }

//            fprintf(outFile, "\n");

            free(tmp);
        }
        if(outFile != NULL)
        {
            printf("File conversion successful!");
        }
    }

    if(strcmp(ext, "csv") == 0 && strcmp(ext2, "tr9") == 0) //convert from csv to tl9
    {

        while (fgets(line, 1024, stream)) {
            char *tmp = strdup(line);

            char *token = strtok(tmp, ",");

            while(token != NULL)
            {
                int index = strlen(token);
                while(index < 9)
                {
                    fprintf(outFile, "%c", ' ');
                    index++;
                }

                for(int i = 0; i < (9<=strlen(token)? 9 : strlen(token)); i++)
                {
                    fprintf(outFile, "%c", token[i]);
                }


                token = strtok(NULL, ",");
                if(token != NULL) fprintf(outFile, "|");
            }



            free(tmp);
        }
        if(outFile != NULL)
        {
            printf("File conversion successful!");
        }
    }

//    if(strcmp(ext, "csv") == 0 && strcmp(ext2, "tc9") == 0) //convert from csv to tc9
//    {
//
//        while (fgets(line, 1024, stream)) {
//            char *tmp = strdup(line);
//
//            char *token = strtok(tmp, ",");
//
//            while(token != NULL)
//            {
//                int index = strlen(token);
//                while(index < 9)
//                {
//                    fprintf(outFile, "%c", ' ');
//                    index++;
//                }
//
//                for(int i = 0; i < (9<=strlen(token)? 9 : strlen(token)); i++)
//                {
//                    fprintf(outFile, "%c", token[i]);
//                }
//
//
//                token = strtok(NULL, ",");
//                if(token != NULL) fprintf(outFile, "|");
//            }
//
//
//
//            free(tmp);
//        }
//        if(outFile != NULL)
//        {
//            printf("File conversion successful!");
//        }
//    }

    if(strcmp(ext, "tl5") == 0 && strcmp(ext2, "tr9") == 0) //convert from tl5 to tr9
    {
        while (fgets(line, 1024, stream)) {
            char *tmp = strdup(line);

            char *token = strtok(tmp, "|");

            while(token != NULL)
            {
                int index = strlen(token);

                while(index < 9)
                {
                    fprintf(outFile, "%c", ' ');
                    index++;
                }

                for(int i = 0; i < (9<=strlen(token)? 9 : strlen(token)); i++)
                {
                    fprintf(outFile, "%c", token[i]);
                }

                token = strtok(NULL, "|");
                if(token != NULL) fprintf(outFile, "|");
            }



            free(tmp);
        }
        if(outFile != NULL)
        {
            printf("File conversion successful!");
        }
    }

    if((strcmp(ext, "tr9") == 0 || strcmp(ext, "tc9") == 0) && strcmp(ext2, "tl5") == 0) //convert from tr9 or tc9 to tl5
    {
        while (fgets(line, 1024, stream)) {
            char *tmp = strdup(line);

            char *token = strtok(tmp, "|");

            while(token != NULL)
            {
//                int index = strlen(token);
//
//                while(index < 9)
//                {
//                    fprintf(outFile, "%c", ' ');
//                    index++;
//                }

                for(int i = 0; i < 5; i++)
                {
                    fprintf(outFile, "%c", token[i+4]);
                }

                token = strtok(NULL, "|");
                if(token != NULL) fprintf(outFile, "|");
            }




            free(tmp);
        }
        if(outFile != NULL)
        {
            printf("File conversion successful!");
        }
    }


    if(strcmp(ext, "tl5") == 0 && strcmp(ext2, "tc9") == 0) //convert from tl5 to tc9
    {
        while (fgets(line, 1024, stream)) {
            char *tmp = strdup(line);

            char *token = strtok(tmp, "|");

            while(token != NULL)
            {
//                int index = strlen(token);


            fprintf(outFile, "%c", ' ');
                fprintf(outFile, "%c", ' ');

                for(int i = 0; i < (9<=strlen(token)? 9 : strlen(token)); i++)
                {
                    fprintf(outFile, "%c", token[i]);
                }
                fprintf(outFile, "%c", ' ');
                fprintf(outFile, "%c", ' ');
                token = strtok(NULL, "|");
                if(token != NULL) fprintf(outFile, "|");
            }

            free(tmp);
        }
        if(outFile != NULL)
        {
            printf("File conversion successful!");
        }
    }

    return 0;
}