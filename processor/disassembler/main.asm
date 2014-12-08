	.file	"main.cpp"
	.section	.rodata
.LC0:
	.string	"rb"
.LC1:
	.string	"bincode.txt"
.LC2:
	.string	"w"
.LC3:
	.string	"sourcecode.txt"
.LC4:
	.string	"%s %i\n"
.LC5:
	.string	"%s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	fopen
	movq	%rax, -80(%rbp)
	movl	$.LC2, %esi
	movl	$.LC3, %edi
	call	fopen
	movq	%rax, -72(%rbp)
.L6:
	movq	-80(%rbp), %rdx
	leaq	-88(%rbp), %rax
	movq	%rdx, %rcx
	movl	$1, %edx
	movl	$4, %esi
	movq	%rax, %rdi
	call	fread
	movl	-88(%rbp), %edx
	leaq	-64(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_Z16getCommandOfCodePci
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L2
	movq	-80(%rbp), %rdx
	leaq	-84(%rbp), %rax
	movq	%rdx, %rcx
	movl	$1, %edx
	movl	$4, %esi
	movq	%rax, %rdi
	call	fread
	movl	-84(%rbp), %ecx
	leaq	-64(%rbp), %rdx
	movq	-72(%rbp), %rax
	movl	$.LC4, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	jmp	.L3
.L2:
	leaq	-64(%rbp), %rdx
	movq	-72(%rbp), %rax
	movl	$.LC5, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
.L3:
	movl	-88(%rbp), %eax
	testl	%eax, %eax
	jne	.L4
	nop
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movl	$0, %eax
	movq	-24(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L8
	jmp	.L9
.L4:
	jmp	.L6
.L9:
	call	__stack_chk_fail
.L8:
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	_Z16getCommandOfCodePci
	.type	_Z16getCommandOfCodePci, @function
_Z16getCommandOfCodePci:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %eax
	testl	%eax, %eax
	je	.L12
	testl	%eax, %eax
	jg	.L13
	cmpl	$-2, %eax
	je	.L14
	cmpl	$-1, %eax
	je	.L15
	jmp	.L11
.L13:
	cmpl	$1000, %eax
	je	.L16
	cmpl	$1001, %eax
	je	.L17
	cmpl	$1, %eax
	jne	.L11
	movq	-8(%rbp), %rax
	movl	$1752397168, (%rax)
	movb	$0, 4(%rax)
	movl	$1, %eax
	jmp	.L10
.L15:
	movq	-8(%rbp), %rax
	movl	$7368560, (%rax)
	movl	$0, %eax
	jmp	.L10
.L16:
	movq	-8(%rbp), %rax
	movl	$6579297, (%rax)
	movl	$0, %eax
	jmp	.L10
.L17:
	movq	-8(%rbp), %rax
	movl	$7107949, (%rax)
	movl	$0, %eax
	jmp	.L10
.L14:
	movq	-8(%rbp), %rax
	movl	$7632239, (%rax)
	movl	$0, %eax
	jmp	.L10
.L12:
	movq	-8(%rbp), %rax
	movl	$6581861, (%rax)
	movl	$0, %eax
	jmp	.L10
.L11:
.L10:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_Z16getCommandOfCodePci, .-_Z16getCommandOfCodePci
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
