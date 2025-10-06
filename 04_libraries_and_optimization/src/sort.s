	.file	"sort.c"
	.text
	.p2align 4
	.globl	selectionSort
	.type	selectionSort, @function
selectionSort:
.LFB0:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	testl	%esi, %esi
	jle	.L9
	xorl	%ebp, %ebp
	movl	%esi, %r9d
	movq	%rdi, %r11
	xorl	%r13d, %r13d
	leal	1(%rbp), %ebx
	leaq	4(%rdi), %r10
	cmpl	%ebx, %r9d
	jle	.L3
	.p2align 4
	.p2align 3
.L17:
	movl	-4(%r10), %r12d
	movq	%r10, %rax
	movl	%ebx, %edx
	movl	%ebp, %r8d
	movl	%r12d, %esi
	jmp	.L5
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L16:
	movslq	%r8d, %rcx
	addl	$1, %edx
	addq	$4, %rax
	leaq	(%r11,%rcx,4), %rdi
	cmpl	%r9d, %edx
	je	.L15
.L5:
	movl	(%rax), %ecx
	movq	%rax, %rdi
	cmpl	%esi, %ecx
	jge	.L16
	movl	%edx, %r8d
	addl	$1, %edx
	movl	%ecx, %esi
	addq	$4, %rax
	cmpl	%r9d, %edx
	jne	.L5
.L15:
	cmpl	%r8d, %ebp
	je	.L13
	movl	%esi, -4(%r10)
	addl	$2, %r13d
	addq	$4, %r10
	movl	%ebx, %ebp
	movl	%r12d, (%rdi)
.L18:
	leal	1(%rbp), %ebx
	cmpl	%ebx, %r9d
	jg	.L17
.L3:
	jne	.L13
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	movl	%r13d, %eax
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L13:
	.cfi_restore_state
	addq	$4, %r10
	movl	%ebx, %ebp
	jmp	.L18
.L9:
	xorl	%r13d, %r13d
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	movl	%r13d, %eax
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	selectionSort, .-selectionSort
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
