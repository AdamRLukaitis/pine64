
;@-------------------------------------------------------------------
;@-------------------------------------------------------------------

.globl _start
_start:
    b   reset

.space 0x20000-4,0

reset:
    mov sp,#0x42000000
    bl notmain
hang: b hang


.globl PUT8
PUT8:
    strb r1,[r0]
    bx lr

.globl PUT32
PUT32:
    str r1,[r0]
    bx lr

.globl GET32
GET32:
    ldr r0,[r0]
    bx lr

.globl ASMDELAY
ASMDELAY:
    subs r0,r0,#1
    bne ASMDELAY
    bx lr

.globl BRANCHTO
BRANCHTO:
    bx r0


;@-------------------------------------------------------------------
;@-------------------------------------------------------------------
