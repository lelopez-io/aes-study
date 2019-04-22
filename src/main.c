/*

  How to compile and run on Win10 (untested):
  > cl main.c
  > main

  How to compile and run on OSX (must be in src dir):
  $ make clean
  $ ./demo

 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "aes.h"

static void phex(uint8_t* str);
static int test_encrypt_ecb(void);
static int test_decrypt_ecb(void);
static void test_encrypt_ecb_verbose(void);

int main(void)
{
  test_encrypt_ecb_verbose();
  return 0;

}

// prints string as hex
static void phex(uint8_t* str)
{
    uint8_t len = 16;   // AES128


    unsigned char i;
    for (i = 0; i < len; ++i)
        printf("%.2x ", str[i]);
    printf("\n");
}

static void test_encrypt_ecb_verbose(void)
{
    // Example of more verbose verification

    uint8_t i;

    // 128bit key
    uint8_t key[16] =        { (uint8_t) 0x73, (uint8_t) 0x74, (uint8_t) 0x72, (uint8_t) 0x6f, (uint8_t) 0x6e, (uint8_t) 0x67, (uint8_t) 0x70, (uint8_t) 0x61, (uint8_t) 0x73, (uint8_t) 0x73, (uint8_t) 0x77, (uint8_t) 0x6f, (uint8_t) 0x72, (uint8_t) 0x64, (uint8_t) 0x32, (uint8_t) 0x31 };
    // 512bit text
    uint8_t plain_text[64] = { (uint8_t) 0x6c, (uint8_t) 0x65, (uint8_t) 0x6c, (uint8_t) 0x6f, (uint8_t) 0x70, (uint8_t) 0x65, (uint8_t) 0x7a, (uint8_t) 0x20, (uint8_t) 0x6c, (uint8_t) 0x65, (uint8_t) 0x6c, (uint8_t) 0x6f, (uint8_t) 0x70, (uint8_t) 0x65, (uint8_t) 0x7a, (uint8_t) 0x20,
                               (uint8_t) 0x6c, (uint8_t) 0x65, (uint8_t) 0x6c, (uint8_t) 0x6f, (uint8_t) 0x70, (uint8_t) 0x65, (uint8_t) 0x7a, (uint8_t) 0x20, (uint8_t) 0x6c, (uint8_t) 0x65, (uint8_t) 0x6c, (uint8_t) 0x6f, (uint8_t) 0x70, (uint8_t) 0x65, (uint8_t) 0x7a, (uint8_t) 0x20,
                               (uint8_t) 0x6c, (uint8_t) 0x65, (uint8_t) 0x6c, (uint8_t) 0x6f, (uint8_t) 0x70, (uint8_t) 0x65, (uint8_t) 0x7a, (uint8_t) 0x20, (uint8_t) 0x6c, (uint8_t) 0x65, (uint8_t) 0x6c, (uint8_t) 0x6f, (uint8_t) 0x70, (uint8_t) 0x65, (uint8_t) 0x7a, (uint8_t) 0x20,
                               (uint8_t) 0x6c, (uint8_t) 0x65, (uint8_t) 0x6c, (uint8_t) 0x6f, (uint8_t) 0x70, (uint8_t) 0x65, (uint8_t) 0x7a, (uint8_t) 0x20, (uint8_t) 0x6c, (uint8_t) 0x65, (uint8_t) 0x6c, (uint8_t) 0x6f, (uint8_t) 0x70, (uint8_t) 0x65, (uint8_t) 0x7a, (uint8_t) 0x20};

    // print text to encrypt, key and IV
    printf("ECB encrypt verbose:\n\n");
    printf("plain text:\n");
    for (i = (uint8_t) 0; i < (uint8_t) 4; ++i)
    {
        phex(plain_text + i * (uint8_t) 16);
    }
    printf("\n");

    printf("key:\n");
    phex(key);
    printf("\n");

    // print the resulting cipher as 4 x 16 byte strings
    printf("ciphertext:\n");
    
    struct AES_ctx ctx;
    AES_init_ctx(&ctx, key);

    for (i = 0; i < 4; ++i)
    {
      AES_ECB_encrypt(&ctx, plain_text + (i * 16));
      phex(plain_text + (i * 16));
    }
    printf("\n");
}