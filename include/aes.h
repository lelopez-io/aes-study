#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>

// ECB enables the basic ECB 16-byte block algorithm. All can be enabled simultaneously.

// The #ifndef-guard allows it to be configured before #include'ing or at compile time.
#ifndef ECB
  #define ECB 1
#endif

#define AES128 1
#define AES_BLOCKLEN 16     //Block length in bytes 
#define AES_KEYLEN 16       // Key length in bytes
#define AES_keyExpSize 176


struct AES_ctx
{
  uint8_t RoundKey[AES_keyExpSize];
};

void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);

#if defined(ECB) && (ECB == 1)
// buffer size is exactly AES_BLOCKLEN bytes; 
// you need only AES_init_ctx as IV is not used in ECB 
// NB: ECB is considered insecure for most uses
void AES_ECB_encrypt(struct AES_ctx* ctx, uint8_t* buf);
void AES_ECB_decrypt(struct AES_ctx* ctx, uint8_t* buf);

#endif // #if defined(ECB) && (ECB == 1)

#endif //_AES_H_