#ifndef RC4_H
#define RC4_H

#define KEY_LENGTH 7
#define TEXT_LENGTH 10

typedef struct RC4_KEY_S{
    unsigned char S[256];
}RC4_KEY;


void RC4_key(RC4_KEY *rc4_key, unsigned char *key, int *keylength);


void RC4(RC4_KEY *rc4_key, unsigned char *plaintext, int *plaintext_length, unsigned char *ciphertext);

#endif


void RC4_key(RC4_KEY *rc4_key, unsigned char *key, int *keylength){
    int i, j, temp;

    /*初始化 S*/
    for (i = 0; i < 256; i++)
	rc4_key -> S[i] = i;

    j = 0;
    for (i = 0; i < 256; i++){
	j = (j + rc4_key -> S[i] + *(key + i % *keylength)) % 256;
	/*交换 rc4_key -> S[i] 和 rc4_key -> S[j]*/
	temp = rc4_key -> S[i];
	rc4_key -> S[i] = rc4_key -> S[j];
	rc4_key -> S[j] = temp;
    }
}

/*生成与明文长度一样的流密钥，输出密文*/
void RC4(RC4_KEY *rc4_key, unsigned char *plaintext, int *plaintext_length, unsigned char *ciphertext){
    int i = 0, j = 0, k = 0, n, temp;

    for (k = 0; k < *plaintext_length; k++){
	i = (i + 1) % 256;
	j = (j + rc4_key -> S[i]) % 256;
	/*交换 rc4_key -> S[i] 和 rc4_key -> S[j]*/
	temp = rc4_key -> S[i];
	rc4_key -> S[i] = rc4_key -> S[j];
	rc4_key -> S[j] = temp;

	n = rc4_key -> S[(rc4_key -> S[i] + rc4_key -> S[j]) % 256];

	/*加密*/
	*(ciphertext + k) = *(plaintext + k) ^ n;
    }
}
