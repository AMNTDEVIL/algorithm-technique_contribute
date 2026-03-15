.section .text

# function to for signed and unsigned bit shifting

.global asm_shr
asm_shr:
    movl %edi,%eax
    movl %esi,%ecx
    shrl %cl,%eax #eax=eax>>cl
    ret
.global asm_sar
asm_sar:
    movl %edi, %eax
    movl %esi, %ecx
    sarl %cl, %eax
    ret
.global asm_shl

asm_shl:
    movl %edi, %eax
    movl %esi, %ecx
    shll %cl, %eax
    ret
.global asm_sal
asm_sal:
    movl %edi, %eax
    movl %esi, %ecx
    sall %cl,%eax
    ret
