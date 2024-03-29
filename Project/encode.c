#include <stdio.h>
#include<string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include <unistd.h>

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    //printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    //printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
        sleep(1); 
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

    	return e_failure;
    }
    else
    {
        sleep(1);
        printf("INFO: Opened %s\n", encInfo->src_image_fname);
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
        sleep(1);
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return e_failure;
    }
    else
    {
        sleep(1);
        printf("INFO: Opened %s\n", encInfo->secret_fname);
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
        sleep(1);
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

    	return e_failure;
    }
    else
    {
        sleep(1);
        printf("INFO: Opened %s\n", encInfo->stego_image_fname);
    }

    // No failure return e_success
    return e_success;
}


/* function definition for read and validate arguments */
Status read_and_validate_encode_args(char *argv[],EncodeInfo *encInfo)
{
    //get .bmp file
    if(argv[2] != NULL && strcmp(strstr(argv[2],"."),".bmp")  == 0)
    {
        encInfo -> src_image_fname = argv[2];
    }
    else
    {
        return e_failure;
    }
    if(argv[3] != NULL && strcmp(strstr(argv[3],"."),".txt")  == 0)
    {
        encInfo -> secret_fname = argv[3];
    }
    else
    {
        return e_failure;
    }
    if(argv[4] != NULL)
    {
        encInfo -> stego_image_fname = argv[4];
    }
    else
    {
        sleep(1);
        printf("INFO: output file file not mentioned.creating stego.bmp as default\n");
        encInfo -> stego_image_fname = "stego.bmp";
    }
    return e_success;
}

//function definition for getting file size
uint get_file_size(FILE *fptr)
{
    fseek(fptr,0,SEEK_END);
    return ftell(fptr);
}

/* function definition for check capacity */
Status check_capacity(EncodeInfo *encInfo)
{
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);
    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);
    if(encInfo->image_capacity > (54+(2+4+4+4+encInfo->size_secret_file) * 8))
    {
        return e_success;
    }
    else
    {
        return e_failure;
    }
}

/*function definition for copy bmp header
  -copying first 54 bytes header file
  -return value=e_success
*/
Status copy_bmp_header(FILE *fptr_src_img, FILE *fptr_stego)
{
    //setting pointer to point 0rt position
    fseek(fptr_src_img, 0, SEEK_SET);

    char str[54];

    //reading 54 btyes from beautiful.bmp
    fread(str, sizeof(char), 54, fptr_src_img);

    // Writing 54 bytes to str
    fwrite(str, sizeof(char), 54, fptr_stego);
    return e_success;
}

/* function definiton for byte to lsb */
Status encode_byte_to_lsb(char data, char *image_data)
{
    unsigned int mask = 1 << 7;
    for(int i = 0; i < 8; i++)
    {
        image_data[i] = (image_data[i] & 0xFE) | ((data & mask) >> (7 - i));
        mask = mask >> 1;
    }
    return e_success;
}

/* function definition to encode data to image */
Status encode_data_to_image(const char *data, int size, FILE *fptr_src, FILE *fptr_stego, EncodeInfo *encInfo)
{
    for(int i = 0; i < size; i++)
    {
        //read 8 bytes of info from .bmp
        fread(encInfo->image_data, 8, sizeof(char), fptr_src);
        encode_byte_to_lsb(data[i], encInfo->image_data);
        fwrite(encInfo->image_data, 8, sizeof(char), fptr_stego);
    }
    return e_success;
}

/* function definition to encode magic string */
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    encode_data_to_image(magic_string, strlen(magic_string), encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
    return e_success;
}

//function definition to encode size to lsb
Status encode_size_to_lsb(char *buffer, int size)
{
    unsigned int mask = 1 << 31;
    for(int i = 0; i < 32; i++)
    {
        buffer[i] = (buffer[i] & 0xFE) | ((size & mask) >> (31 - i));
        mask = mask >> 1;
    }
    return e_success;
}


//function def to encode size
Status encode_size(int size, FILE *fptr_src, FILE *fptr_stego)
{
    char str[32];
    fread(str, 32, sizeof(char), fptr_src);
    encode_size_to_lsb(str, size);
    fwrite(str, 32, sizeof(char), fptr_stego);
    return e_success;
}

//function def to encode secret file extn
Status encode_secret_file_extn(const char *file_ext, EncodeInfo *encInfo)
{
    file_ext = ".txt";
    encode_data_to_image(file_ext, strlen(file_ext), encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
    return e_success;
}

//function definition to encode secret file size
Status encode_secret_file_size(long int file, EncodeInfo *encInfo)
{ 
    char str[32];
    fread(str, 32, sizeof(char), encInfo->fptr_src_image);
    encode_size_to_lsb(str, file);
    fwrite(str, 32, sizeof(char), encInfo->fptr_stego_image);
    return e_success;
}

//function definition to encode secret file data
Status encode_secret_file_data(EncodeInfo *encInfo)
{
    char ch;
    fseek(encInfo->fptr_secret, 0, SEEK_SET);
    for(int i = 0; i < encInfo->size_secret_file; i++)
    {
        fread(encInfo->image_data, 8, sizeof(char), encInfo->fptr_src_image);
        fread(&ch, 1, sizeof(char), encInfo->fptr_secret);
        encode_byte_to_lsb(ch, encInfo->image_data);
        fwrite(encInfo->image_data, 8, sizeof(char), encInfo->fptr_stego_image);
    }
    return e_success;
}

//function definition to copy emaining image data
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_stego)
{
    char ch;
    while(fread(&ch, 1, 1, fptr_src) > 0)
    {
        fwrite(&ch, 1, 1, fptr_stego);
    }
    return e_success;
}

//function definition for encoding
Status do_encoding(EncodeInfo *encInfo)
{
    //call rest of the required functions
    //open files
    sleep(1);
    printf("INFO: Opening required files\n");
    if(open_files(encInfo) == e_success)
    {
        sleep(1);
        printf("INFO: Done\n");
        sleep(1);
        printf("INFO: ##--> Started Encoding <--##\n");
        sleep(1);
        printf("INFO: checking for file size\n");
        if(check_capacity(encInfo) == e_success)
        {
            sleep(1);
            printf("INFO: Done. Not Empty\n");
            sleep(1);
            printf("INFO: Encoding is possible...\n");
            sleep(1);
            printf("INFO: copying image header\n");
            if(copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
            {
                sleep(1);
                printf("INFO: Done\n");
                sleep(1);
                printf("INFO: Encoding Magic String Signature\n");
                if(encode_magic_string(MAGIC_STRING, encInfo) == e_success)
                {
                    sleep(1);
                    printf("INFO: Done\n");
                    sleep(1);
                    printf("INFO: Encoding %s File Extenstion Size\n", encInfo->secret_fname);
                    if(encode_size(strlen(".txt"), encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
                    {
                        sleep(1);
                        printf("INFO: Done\n");
                        sleep(1);
                        printf("INFO: Encoding %s File Extenstion\n", encInfo->secret_fname);
                        if(encode_secret_file_extn(encInfo->extn_secret_file, encInfo) == e_success)
                        {
                            sleep(1);
                            printf("INFO: Done\n");
                            sleep(1);
                            printf("INFO: Encoding %s File Size\n", encInfo->secret_fname);
                            if(encode_secret_file_size(encInfo->size_secret_file, encInfo) == e_success)
                            {
                                sleep(1);
                                printf("INFO: Done\n");
                                sleep(1);
                                printf("INFO: Encoding %s File Data\n", encInfo->secret_fname);
                                if(encode_secret_file_data(encInfo) == e_success)
                                {
                                    sleep(1);
                                    printf("INFO: Done\n");
                                    sleep(1);
                                    printf("INFO: Copying Left Over Data\n");
                                    if(copy_remaining_img_data(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
                                    {
                                        sleep(1);
                                        printf("INFO: Done\n");
                                    }
                                    else
                                    {
                                        sleep(1);
                                        printf("INFO: Failed to copy remaining bytes\n");
                                        return e_failure;
                                    }
                                }
                                else
                                {
                                    sleep(1);
                                    printf("INFO: Failed to encode the data\n");
                                    return e_failure;
                                }    
                            }
                            else
                            {
                                sleep(1);
                                printf("INFO: Failed to encode secret file size\n");
                                return e_failure;
                            }
                        }
                        else
                        {
                            sleep(1);
                            printf("INFO: failed to encode secret file extension\n");
                            return e_failure;
                        }
                    }
                    else
                    {
                        sleep(1);
                        printf("INFO Failed to encode secret file extension size\n");
                        return e_failure;
                    }   
                }
                else
                {
                    sleep(1);
                    printf("INFO Failure: encoding MAGIC STRING\n");
                    return e_failure;
                }
            }
            else
            {
                sleep(1);
                printf("INFO: Failure: Copying header\n");
                return e_failure;
            }
        }
        else
        {
            sleep(1);
            printf("INFO: Failure: Image file size is not sufficient\n");
            return e_failure;
        }
    }
    else
    {
        sleep(1);
        printf("INFO: Failed to open the files\n");
        return e_failure;
    }
    return e_success;
}


