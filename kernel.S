.global memset
memset:
        beqz    a2, .LBB0_3
        add     a2, a2, a0
        mv      a3, a0
.LBB0_2:
        addi    a4, a3, 1
        sb      a1, 0(a3)
        mv      a3, a4
        bne     a4, a2, .LBB0_2
.LBB0_3:
        ret

