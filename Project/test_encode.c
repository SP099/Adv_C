/*
Name             : Sushant Patil
Date             : 19/03/2023
Description      : LSB Steganography
Sample Execution : 1)Encoding
                     emertxe@ubuntu:~./a.out -e beautiful.bmp secret.txt
                     INFO: Selected Encoding..
                     INFO: output file file not mentioned. creating stego.bmp as default
                     INFO: Read and validate is successful
                     INFO: Opening required files INFO: Opened beautiful.bmp
                     INFO: Opened secret.txt INFO: Opened stego.bmp
                     INFO: Done
                     INFO: ##--> Started Encoding <--## INFO: checking for file size
                     INFO: Done. Not Empty
                     INFO: Encoding is possible...
                     INFO: copying image header INFO: Done
                     INFO: Encoding Magle String Signature
                     INFO: Done
                     INFO: Encoding secret.txt File Extenstion Size INFO: Done
                     INFO: Encoding secret.txt File Extenstion INFO: Done
                     INFO: Encoding secret.txt File Size
                     INFO: Done
                     INFO: Encoding secret.txt File Data INFO: Done
                     INFO: Copying Left Over Data
                     INFO: Done
                     INFO: Completed Encoding Successfully

                   2)Decoding
                     emertxe@ubuntu:~./a.out -d stego.bmp
                     INFO: Selected Decoding.. decode.txt as default
                     INFO: output file is not mentioned.creating
                     INFO: Read and validate is successful INFO: Opening the requried files
                     INFO: Opened stego.bmp
                     INFO: ##-->Started Decoding-->##
                     INFO: Decoding the magte string signature INFO: Done INFO: Decoding output file Extenstion size
                     INFO: Done
                     INFO: Decoding decode.txt file Extenstion
                     INFO: Done
                     INFO: Decoding decode.txt file size INFO: Done
                     INFO: Decoding decode.txt file data INFO: Done
                     INFO: Completed Decoding Successfully                     
*/

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"
#include <unistd.h>

/* Passing arguments through command line arguments */
int main(int argc, char *argv[])
{
    //validation for arguments
    if (argc >= 3)
    {
        //check the operation type
        if(check_operation_type(argv) == e_encode)
        {
            //declartion of structure variable
            EncodeInfo encInfo;

            printf("INFO: Selected Encoding..\n");
            
            //function call for read and validate encode arguments
            if(read_and_validate_encode_args(argv,&encInfo) == e_success)
            {
                sleep(1);
                printf("INFO: Read and validate is successful\n");

                //function call for encoding
                if(do_encoding(&encInfo) == e_success)
                {
                    sleep(1);
                    printf("INFO: Completed Encoding Successfully\n");
                }
                else
                {
                    sleep(1);
                    printf("INFO: Failure: Encoding is unsuccessfull\n");
                } 
            }
            else
            {
                sleep(1);
                printf("INFO: Failure: Read and validate arguments\n");
            }
        }

        //check operation type
        else if(check_operation_type(argv) == e_decode)
        {
            //declaration of structure vaiable
            DecodeInfo decInfo;
            printf("INFO: Selected Decoding..\n");   
            
            //function call for read and validate decode arguments     
            if(read_and_validate_decode_args(argv,&decInfo) == d_success)
            {
                sleep(1);
                printf("INFO: Read and Validate is successful\n");

                //function call for decoding
                if(do_decoding(&decInfo) == d_success)
                {
                    sleep(1);
                    printf("INFO: Completed Decoding Successfully\n");
                }
                else
                {
                    sleep(1);
                    printf("Failure: Decoding is unsuccessfull\n");
                }    
            }
            else
            {
                sleep(1);
                printf("Failure: Read and validate arguments\n");
            }
        }
        else
        {
            printf("Invalid Option\nUsage:\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp\n");
        }
    }
    else
    {
        printf("Error : Please pass for\n Encoding: 4 arguments\nDecoding: 3 arguments\n");
    }
    return 0;
 }


/* function definition for checking operation type */
OperationType check_operation_type(char *argv[])
{
    if(strcmp(argv[1], "-e") == 0)
    {
        return e_encode;
    }
    else if(strcmp(argv[1], "-d") == 0)
    {
        return e_decode;
    }
    else
    {
        return e_unsupported;
    }
}
