#include"proclib.h"




int fGetCode( int** codepointer, FILE* inp )
{
    int* code;
    int numberOfCommands = 0, command = 0, i = 0;
    code = *codepointer;
    if( inp == NULL )
    {
        fprintf( stderr, "In function fGetCode: File wasn't opened\n" );
        return 0;
    }
    if( code != NULL )
    {
        fprintf( stderr, "In function fGetCode: NULL pointer expected\n" );
        return 0;
    }
    fseek( inp, 0, SEEK_SET );
    {//How many commands in the file
        fseek( inp, 0, SEEK_END );
        numberOfCommands = ftell( inp );
        numberOfCommands = numberOfCommands / sizeof( int );
        fseek( inp, 0, SEEK_SET );
    }
    code = (int*)calloc( numberOfCommands, sizeof( *code ) );
    if( code == NULL )
    {
        fprintf( stderr, "In function fGetCode: Memory limit exceeded\n" );
        return 0;
    }
    i = 0;
    while( fread( &command, sizeof(command), 1, inp ) )
    {
        code[i] = command;
        i++;
    }
    *codepointer = code;
    return numberOfCommands;
}

int runCode( int* code, int numberOfCommands )
{
    struct mystack stack;
    double test;
    int value[2];
    int reg[4];
    for(int i = 0; i < numberOfCommands; i++ )
    {
        switch( code[i] )
        {
        case PUSH:
            i++;
            stack.push(code[i]);
            break;
        case ADD:
            value[0] = safetyPop( &stack );
            value[1] = safetyPop( &stack );
            stack.push( value[0] + value[1] );
            break;
        case MUL:
            value[0] = safetyPop( &stack );
            value[1] = safetyPop( &stack );
            stack.push( value[0] * value[1] );
            break;
        case DIV:
            value[0] = safetyPop( &stack );
            value[1] = safetyPop( &stack );
            if( !value[1] )
            {
                fprintf( stderr, "Dividing by zero\n" );
                exit( EXIT_FAILURE );
            }
            stack.push( value[0] / value[1] );
            break;
        case SUB:
            value[0] = safetyPop( &stack );
            value[1] = safetyPop( &stack );
            stack.push( value[0] - value[1] );
            break;
            
        case OUT:
            printf("%d\n", safetyPop( &stack ) );
            break;
        case POP:
            value[0] = safetyPop( &stack );
            break;
        case END:
            free( code );
            return 1;
            break;
        case PUSHX:
            i++;
            value[0] = safetyReg( code[i] );
            stack.push(reg[value[0]]);
            break;
        case POPX:
            i++;
            value[0] = safetyReg( code[i] );
            reg[value[0]] = safetyPop( &stack );
            break;
        case MOV:
            i++;
            value[0] = safetyReg( code[i] );
            i++;
            value[1] = code[i];
            reg[value[0]] = value[1];
            break;
        case MOVX:
            i++;
            value[0] = safetyReg( code[i] );
            i++;
            value[1] = safetyReg( code[i] );
            reg[value[0]] = value[1];
            break;
        case CMP:
            value[0] = safetyPop( &stack );
            value[1] = safetyPop( &stack );
            stack.push( value[0] - value[1] );
            break;
        case CMPX:
            i++;
            value[0] = safetyReg( code[i] );
            value[0] = reg[value[0]];
            i++;
            value[1] = safetyReg( code[i] );
            value[1] = reg[value[1]];
            stack.push( value[0] - value[1] );
            break;
        case JNE:
            i++;
            value[0] = safetyPop( &stack );
            if( value[0] != 0 )
                i = code[i] - 1;
            break;
        case JE:
            i++;
            value[0] = safetyPop( &stack );
            if( value[0] == 0 )
                i = code[i] - 1;
            break;
        case JL:
            i++;
            value[0] = safetyPop( &stack );
            if( value[0] < 0 )
                i = code[i] - 1;
            break;
        case JB:
            i++;
            value[0] = safetyPop( &stack );
            if( value[0] > 0 )
                i = code[i] - 1;
            break;
        case JMP:
            i++;
            i = code[i] - 1;
            break;
        }
    }
    free( code );
    fprintf( stderr, "No end command" );
    return 0;
}

int dumpCode( int* code, int numberOfCommands )
{
    for( int i = 0; i < numberOfCommands; i++ )
        printf( ":%d\n", code[i] );
    return 0;
}
    
int safetyPop( struct mystack* stackp )
{
    double test;
    test = stackp->pop();
    if( test == NAN )
    {
        fprintf( stderr, "Stack is empty" );
        exit( EXIT_FAILURE );
    }
    return test;
}

int safetyReg( int value )
{
    if( value < 0 || value > 3 )
    {
        fprintf( stderr, "FATAL_ERROR_REGISTER_EXPECTED" );
        exit( EXIT_FAILURE );
    }
    return value;
}

