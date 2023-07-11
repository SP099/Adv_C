#include <stdio.h>
#include <string.h>
#include "decode.h"
#include "types.h"
#include "common.h"
#include <stdlib.h>
#include <unistd.h>

// Function definition for read and validate decode args
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    if (argv[2] != NULL && strcmp(strstr(argv[2], "."), ".bmp") == 0)
    {
        decInfo->stego_image_fname = argv[2];
    }
    else
    {
        return d_failure;
    }
    if (argv[3] != NULL)
    {
        decInfo->secret_fname = argv[3];
    }
    else
    {
        sleep(1);
        printf("INFO: output file is not mentioned.creating decode.txt as default\n");
        decInfo->secret_fname = "decode.txt";
    }
    return d_success;
}

/* function definition to open files */
Status open_files_decode(DecodeInfo *decInfo)
{
    // Secret file
    decInfo->fptr_secret = fopen(decInfo->secret_fname, "w");

    if (decInfo->fptr_secret == NULL)
    {
	    perror("fopen");    
	    fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->secret_fname);

	    return d_failure;
    }
    else
 

    //stego image file
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");

    if (decInfo->fptr_stego_image == NULL)
    {
	    perror("fopen");    
	    fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);

	    return d_failure;
    }
    else
    {
        sleep(1);
        printf("INFO: Opened %s\n",decInfo->stego_image_fname);
    }

    //retun e_success
    return d_success;
}

/* function definition to decode magic string */
Status decode_magic_string(DecodeInfo *decInfo)
{
    rewind(decInfo -> fptr_stego_image);
    fseek(decInfo -> fptr_stego_image, 54, SEEK_SET);
    int i = strlen(MAGIC_STRING);

    decInfo->magic_data = malloc(strlen(MAGIC_STRING) + 1);
    decode_data_from_image(strlen(MAGIC_STRING), decInfo->fptr_stego_image, decInfo);

    decInfo->magic_data[i] = '\0';

    if (strcmp(decInfo->magic_data, MAGIC_STRING) == 0)
    {
        return d_success;
    }
    else
    {
        return d_failure;
    }
}	

/* function definition to decode data from image */
Status decode_data_from_image(int size, FILE *fptr_stego_image, DecodeInfo *decInfo)
{
    int i;
    char str[8];
    for (i = 0; i < size; i++)
    {
        fread(str, 8, sizeof(char), fptr_stego_image);
        decode_byte_from_lsb(&decInfo->magic_data[i], str);
    }
    return d_success;
}

//function definition to decode byte from lsb */
Status decode_byte_from_lsb(char *data, char *image_buffer)
{
    int bit = 7;
    unsigned char ch = 0x00;
    for (int i = 0; i < 8; i++)
    {
        ch = ((image_buffer[i] & 0x01) << bit--) | ch;
    }
    *data = ch;
    return d_success;
}

/* functio definition to decode file extn size */
Status decode_file_extn_size(int size, FILE *fptr_stego_image)
{
    char str[32];
    int length;

    fread(str, 32, sizeof(char), fptr_stego_image);
    decode_size_from_lsb(str, &length);

    if (length == size)
        return d_success;
    else
        return d_failure;
}

/* function definition to decode size from lsb */
Status decode_size_from_lsb(char *buffer, int *size)
{
    int i = 31;
    int num = 0x00;
    for (int j = 0; j < 32; j++)
    {
        num = ((buffer[j] & 0x01) << i--) | num;
    }
    *size = num;
}

/* function definition to decode secret file extn*/
Status decode_secret_file_extn(char *file_ext, DecodeInfo *decInfo)
{
    file_ext = ".txt";
    int i = strlen(file_ext);
    decInfo->secret_file_extn = malloc(i + 1);
    decode_extension_data_from_image(strlen(file_ext), decInfo->fptr_stego_image, decInfo);

    decInfo->secret_file_extn[i] = '\0';

    if (strcmp(decInfo->secret_file_extn, file_ext) == 0)
        return d_success;
    else
        return d_failure;
}

/* function dfinition to decode extn data from image */
Status decode_extension_data_from_image(int size, FILE *fptr_stego_image, DecodeInfo *decInfo)
{
    for (int i = 0; i < size; i++)
    {
        fread(decInfo->stego_image_fname, 8, 1, fptr_stego_image);
        decode_byte_from_lsb(&decInfo->secret_file_extn[i], decInfo->stego_image_fname);
    }
    return d_success;
}

/* function definition to decode secret file size */
Status decode_secret_file_size(int file_size, DecodeInfo *decInfo)
{
    char str[32];
    fread(str, 32, sizeof(char), decInfo->fptr_stego_image);
    decode_size_from_lsb(str, &file_size);
    decInfo->secret_file_size = file_size;

    return d_success;
}

/* function definition to decode secret file data */
Status decode_secret_file_data(DecodeInfo *decInfo)
{
    char ch;
    for (int i = 0; i < decInfo->secret_file_size; i++)
    {
        fread (decInfo->stego_image_fname, 8, sizeof(char), decInfo->fptr_stego_image);
        decode_byte_from_lsb(&ch, decInfo->stego_image_fname);
        fputc(ch, decInfo->fptr_secret);
    }
    return d_success;
}

/* function definition for decoding */
Status do_decoding(DecodeInfo *decInfo)
{
    sleep(1);
    printf("INFO: Opening the requried files\n");
    if(open_files_decode(decInfo) == d_success)
    {
        sleep(1);
        printf("INFO: ##<--Started Decoding-->##\n");
        sleep(1);
        printf("INFO: Decoding the magic string Signature\n"); 
        if (decode_magic_string(decInfo) == d_success)
        {
            sleep(1);
            printf("INFO: Done\n");

            sleep(1);
            printf("INFO: Decoding output file Extenstion size\n");
            if (decode_file_extn_size(strlen(".txt"), decInfo->fptr_stego_image) == d_success)
            {
                sleep(1);
                printf("INFO: Done\n");
                sleep(1);
                printf("INFO: Decoding %s file Extenstion\n",decInfo->secret_fname);
                if (decode_secret_file_extn(decInfo->secret_file_extn, decInfo) == d_success)
                {
                    sleep(1);
                    printf("INFO: Done\n");

                    sleep(1);
                    printf("INFO: Decoding %s file size\n",decInfo->secret_fname);
                    if (decode_secret_file_size(decInfo->secret_file_size, decInfo) == d_success)
                    {
                        sleep(1);
                        printf("INFO: Done\n");
                        sleep(1);
                        printf("INFO: Decoding %s file data\n",decInfo->secret_fname);
                        if (decode_secret_file_data(decInfo) == d_success)
                        {
                            sleep(1);
                            printf("INFO: Done\n");
                        }
                        else
                        {
                            sleep(1);
                            printf("INFO: Failed to Decode secret file data\n");
                            return d_failure;
                        }
                    }
                    else
                    {
                        printf("Error: failed to decode secret file size\n");
                        return d_failure;
                    }
                }
                else
                {
                    printf("Error: failed to decode secret file extension\n");
                    return d_failure;
                }
            }
            else
            {
                printf("Error: failed to decode dile extension size\n");
                return d_failure;
            }
        }
        else
        {
            printf("Error: failed to decode magic string\n");
            return d_failure;
        }
    }
    else
    {
        printf("ERROR: Error in opening the required file\n");
	    return d_failure;
    }
    return d_success;
}
