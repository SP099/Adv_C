#ifndef DECODE_H
#define DECODE_H

#include "types.h" // Contains user defined types

/*
 * Structure to store information required for
 * decoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)

typedef struct _DecodeInfo
{
    /* Stego image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;

    /* Decoding information */
    char *secret_fname;
    FILE *fptr_secret;
    FILE *fptr_dec;

    uint image_data_size;
	char image_data[MAX_IMAGE_BUF_SIZE];
    char *magic_data;

    char *secret_file_extn;
    int secret_file_size;

} DecodeInfo;


/* Decoding Function Prototypes */

/* Read and validate decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the decoding */
Status do_decoding(DecodeInfo *decInfo);

/* opening files */
Status open_files_decode(DecodeInfo *decInfo);

/* performs decoding magic string */
Status decode_magic_string(DecodeInfo *decInfo);

/* Decode data from image */
Status decode_data_from_image(int size, FILE *fptr_stego_image,DecodeInfo *decInfo);

/* Decode byte from lsb */
Status decode_byte_from_lsb(char *data, char *image_buffer);

/* Decode file extn size */
Status decode_file_extn_size (int size, FILE *fptr_stego_image);

/* Decode size from lsb */
Status decode_size_from_lsb (char *buffer, int *size);

/* Decode secret file extn */
Status decode_secret_file_extn (char *file_ext, DecodeInfo *decInfo) ;

/* Decode extension data from image */
Status decode_extension_data_from_image ( int size, FILE *fptr_stego_image, DecodeInfo *decInfo);

#endif
