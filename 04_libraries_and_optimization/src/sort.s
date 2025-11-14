	.file	"sort.c"
	.text
	.p2align 4
	.globl	selectionSort
	.type	selectionSort, @function
selectionSort:
.LFB0:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	testl	%esi, %esi
	jle	.L7
	movl	%esi, %r8d
	movslq	%esi, %r12
	movq	$-4, %rbx
	xorl	%r10d, %r10d
	movl	$1, %r9d
	xorl	%r11d, %r11d
	xorl	%ebp, %ebp
	.p2align 4
	.p2align 3
.L6:
	cmpl	%r9d, %r8d
	jle	.L3
	leaq	(%r10,%rbx), %rsi
	movq	%r9, %rax
	movl	%r11d, %edx
	addq	%rdi, %rsi
	.p2align 5
	.p2align 4
	.p2align 3
.L5:
	movslq	%edx, %rcx
	movl	(%rdi,%rcx,4), %ecx
	cmpl	%ecx, 4(%rsi,%rax,4)
	cmovl	%eax, %edx
	addq	$1, %rax
	cmpl	%eax, %r8d
	jg	.L5
	cmpl	%edx, %r11d
	je	.L3
	movslq	%edx, %rdx
	movl	(%rdi,%r10), %ecx
	addl	$1, %ebp
	leaq	(%rdi,%rdx,4), %rax
	movl	(%rax), %edx
	movl	%edx, (%rdi,%r10)
	movl	%ecx, (%rax)
.L3:
	addl	$1, %r11d
	addq	$4, %r10
	subq	$4, %rbx
	cmpq	%r12, %r9
	je	.L1
	addq	$1, %r9
	jmp	.L6
.L7:
	xorl	%ebp, %ebp
.L1:
	movl	%ebp, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	selectionSort, .-selectionSort
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
