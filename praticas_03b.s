.section .data
output: .asciz "O ID do fabricante eh '%s'\n"
output2: .asciz "Valores dos Regristradores: EAX = '%d', ECX = '%d', EDX = '%d'\n"

.section .bss
.lcomm fabri, 16

.section .text
.globl _start
_start:
	movl $0, %eax
	cpuid

movl $fabri, %edi
movl %ebx, 0(%edi)
movl %edx, 4(%edi)
movl %ecx, 8(%edi)
movl $0, 12(%edi)

pushl $fabri
pushl $output
pushl %ebx
pushl %ecx
pushl %edx
pushl $output2
call printf
popl %eax
popl %eax

pushl $0
call exit
