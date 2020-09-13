	.data	
V1:     .space  64
M:      .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
V2:     .word   -5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10

	.text
	.globl main
main:
        li      $t0, 0          # $t0 = i
        la      $t4, V1         # $t4 = @V1[0]
        la      $t5, M          # $t5 = @M[0][0]
        li      $t3, 16
fori:
        bge     $t0, $t3, end_fori
        li      $t2, 0          # $t2 = tmp
        li      $t1, 0          # $t1 = j
        la      $t6, V2         # $t6 = @V2[0]
forj:
        bge     $t1, $t3, end_forj
        lw      $t7, 0($t5)
        lw      $t8, 0($t6)
        mult    $t7, $t8
        mflo    $t7
        addu    $t2, $t2, $t7
        addiu   $t5, $t5, 4
        addiu   $t6, $t6, 4
        addiu   $t1, $t1, 1
        b       forj
end_forj:
        sw      $t2, 0($t4)
        addiu   $t4, $t4, 4
        addiu   $t0, $t0, 1
        b       fori
end_fori:
	jr	$ra
