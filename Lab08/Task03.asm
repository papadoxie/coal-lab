    //Prints n number of lines on screen separated by a gap of width of one row
    //eg. n = 2
    // ................................
    //
    // ................................
    
    @R0 //R0 is loaded into A register
    D=M //Value at R0 is loaded into D register
    @n //Create new variable n at RAM[16]
    M=D // n = R0
    @i //Create new variable i at RAM[17]
    M=0 // i = 0
    @SCREEN //Load SCREEN into A register
    D=A //Load starting address of SCREEN into D register
    @addr //Create new variable addr at RAM[18]
    M=D // addr = address of SCREEN
(LOOP) //Flag for jump statements
    @i //i is loaded into A register
    D=M //Value at i is loaded into D register
    @n //n is loaded into A register
    D=D-M // i - n
    @END //Setting flag for jump to END
    D;JGT //if i > n then jump to END
    @addr //addr is loaded into A register
    A=M //Value at addr (address of some location on SCREEN) is loaded into A register
    M=-1 // Set all bits on addr to 1
    @i //i is loaded into A register
    M=M+1 //i++
    @64 //64 is loaded into A register
    D=A //64 is loaded into D register
    @addr //addr is loaded into A register
    M=D+M // addr = addr + 64 (Jump 2 rows down on screen) 
    @LOOP //Setting flag for jump to start of loop
    0;JMP //Unconditional jump
(END) //Ending flag for infinite loop
    @END //Trap memory
    0;JMP //Trap memory