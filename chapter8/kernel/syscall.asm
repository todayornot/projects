%include	"sconst.inc"


INT_VECTOR_SYS_CALL	equ	0x90
;_NR_get_ticks			equ	0
;_NR_write				equ	1
_NR_printx	    equ 0
_NR_sendrec	    equ 1

global	get_ticks
global	write
global	sendrec
global	printx

bits	32
[section	.text]

; ====================================================================
;                              get_ticks
; ====================================================================
;get_ticks:
;	mov		eax,	_NR_get_ticks
;	int		INT_VECTOR_SYS_CALL
;	ret

; ====================================================================================
;                          void write(char* buf, int len);
; ====================================================================================
;write:
;        mov     eax, _NR_write
;        mov     ebx, [esp + 4]
;       mov     ecx, [esp + 8]
;       int     INT_VECTOR_SYS_CALL
;        ret

; ====================================================================================
;                          sendrec
; ====================================================================================
sendrec:
	mov		eax,	_NR_sendrec
	mov		ebx,	[esp + 4]		; function
	mov		ecx,	[esp + 8]		; src_dest
	mov		edx,	[esp + 12]	; p_msg
	int		INT_VECTOR_SYS_CALL
	ret	

; ====================================================================================
;                          printx
; ====================================================================================
printx:
	mov		eax, _NR_printx
	mov		edx, [esp + 4]
	int		INT_VECTOR_SYS_CALL
	ret