//if RAM[0]==2 && RAM[1]==3
//then max=3

    @R0 //RAM[0]
    D=M
    @R1 //RAM[1]
    D=D-M //If this is > 0 then R0 will be greater
    @RAM0_GREATER
    D;JGT

//IF RAM[1] is greater
    @R1 
    D=M
    @max
    M=D
    @END
    0;JMP

//IF RAM[0] is greater
(RAM0_GREATER)
    @R0
    D=M
    @max
    M=D

(END) //END Trap
    @END
    0;JMP