section .data
DIVISOR dd 255.0 

section .text
bits 64
default rel 

global imgCvtGrayInttoFloat

imgCvtGrayInttoFloat:
    movss xmm1, [DIVISOR]
    rcpss xmm1, xmm1
    mov rax, r8
    xor r9, r9 
    
_loop:
    mov r15d, [rdx + r9 * 4] 
    cvtsi2ss xmm0, r15d 
    mulss xmm0, xmm1
    movss [rax + r9 * 4], xmm0 
    inc r9
    
    loop _loop
    
end_func:

    ret