#include <stdio.h>
int main(void)
{
    int lsl, lsr, ror, asr, bic;

    __asm__ __volatile__(
        "nop\n"

        "mov r0, #0x78\n"
    
        "lsl %[lsl], r0, #4\n"

        /*
            0x78 --> 0111 1000
            1    --> 1111 0000
            2    --> 1111 0000 0
            3    --> 1111 0000 00
            4    --> 111 1000 0000  --> 0x780 

        */

        "lsr %[lsr], %[lsl], #4\n"
        "ror %[ror], r0, #4\n"
        "mov r0, #-2\n"
        "asr %[asr], r0, #10\n"
        
        "mov r0, #0x78\n"
        "bic %[bic], r0, #0x8\n"

        "nop\n"

        :[lsl]"+&r"(lsl),[lsr]"+&r"(lsr),
          [ror]"+&r"(ror),[asr]"+&r"(asr),[bic]"+&r"(bic)
        :
        :"r0"
    );

    printf("lsl : %#X\n",lsl); 
    printf("lsr : %#x\n",lsr);
    printf("ror : %#x\n",ror);
    printf("asr : %#x\n",asr);
    printf("bic : %#x\n",bic);

    return 0;
}
