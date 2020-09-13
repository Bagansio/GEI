f: addiu $sp, $sp, -52
 sw $s0, 44($sp)
 sw $ra, 48($sp)
 move $s0, $a0
 addiu $a0, $sp, 8
 addiu $a1, $sp, 40
 jal g
 lwc1 $f2, 8($s0)
 add.s $f0, $f0, $f2
 lw $s0, 44($sp)
 lw $ra, 48($sp)
 addiu $sp, $sp, 52
 jr $ra