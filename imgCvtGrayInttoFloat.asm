section .data
DIVISOR dd 255.0 

section .text
bits 64
default rel 

global imgCvtGrayInttoFloat

imgCvtGrayInttoFloat:
    movss xmm1, [DIVISOR]
    xor r9, r9 
    
_loop:
    cmp r9, r8
    jge end_func 
    
    mov eax, [rcx + r9 * 4] 
    cvtsi2ss xmm0, eax 
    divss xmm0, xmm1
    movss [rdx + r9 * 4], xmm0 

    inc r9
    jmp _loop
    
end_func:
    ret