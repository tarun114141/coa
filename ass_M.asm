%macro READ 2
	mov rax, 0;
	mov rdi, 0;
	mov rsi, %1;
	mov rdx, %2;
	syscall;
%endmacro

%macro WRITE 2
	mov rax, 1;
	mov rdi, 1;
	mov rsi, %1;
	mov rdx, %2;
	syscall
%endmacro

section .data
	msg1 db "Enter the first number: ", 10;
	len1 equ $-msg1;
	
	msg2 db "Ener the second number: ", 10;
	len2 equ $-msg2
	
	msg3 db "TTHE SUM IS : ";
	len3 equ $-msg3;
	
section .bss
	num1 resq 1;
	num2 resq 1;
	char_buff resb 16;
	
section .text
	global _start
_start: 
	WRITE msg1, len1;
	READ char_buff, 16;
	dec rax;
	mov rcx,rax;
	call Accept;
	mov qword[num1], rbx;
	
	WRITE msg2, len2;
	READ char_buff, 16;
	dec rax;
	mov rcx, rax;
	call Accept;
	mov qword[num2], rbx;
	
	
	WRITE msg3, len3;
	
	
	
	mov rbx, qword[num1];
	add rbx,qword[num2];
	call Display;
	
	mov rax, 60;
	mov rdi, 0;
	syscall;
	
	
	
	
	
	
Accept:
	mov rsi, char_buff;
	mov rbx, 00;
	up:
		mov rdx, 00;
		mov dl, byte[rsi];
		cmp dl, 39H;
		jbe sub30;
		sub dl, 07H;
	sub30:
		sub dl , 30h;
		shl rbx, 04;
		add rbx,rdx;
		inc rsi;
		dec rcx;
		jnz up;
		ret
		
Display: 
	mov rcx, 16;
	mov rsi, char_buff;
	up1:
		rol rbx, 04;
		mov dl, bl;
		and dl, 0FH;
		cmp dl ,09H;
		jbe add30;
		add dl, 07H;
	add30:
		add dl ,30H;
		mov byte[rsi], dl;
		inc rsi;
		dec rcx;
		jnz up1;
		WRITE char_buff, 16;
		ret
		
