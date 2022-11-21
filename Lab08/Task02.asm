//arr is a pointer

//  for(i = 0; i < n; i++)
//      *(arr + i) = i;

    @20 //Loads 20 into A register
    D=A //D is assigned the Address 20
    @arr //New variable arr is created at RAM[16]
    M=D //arr = 20
    @R0 //Loads RAM[0] into A register
    D=M //Value at RAM[0] is placed in D register
    @n //New variable n is created at RAM[17]
    M=D //n = *RAM[0]
    @i //New variable i created at RAM[18]
    M=0 //i = 0
(LOOP) //Flag for jump statements
    @i //i is loaded into A register
    D=M //Value at i is loaded into D register
    @n //n is loaded into A register
    D=D-M //i - n
    @END //Setting jump address
    D;JEQ //Jump to END if i - n = 0 ie. i = n
    @arr //arr is loaded into A register
    D=M //Value at arr is loaded into D register. This is an address
    @i //i is loaded into A register
    A=D+M //Data at arr and i are added and stored into A register (arr + i)
    M=A-D // *(arr + i) = i
    @i //i is loaded into A register
    M=M+1 //i++
    @LOOP //Setting flag for jump to start of loop
    0;JMP //Jump to start of loop unconditionally
(END) //Ending flag for infinite loop
    @END //Trap memory
    0;JMP //Trap memory
