#include"asslib.h"

const int NO_LABEL = -1;
enum CONSTS_OF_GETCODEOFCOMMAND
{
    NO_VALUE = 0,
    INT_VALUE = 1,
    PUSH_VALUE = 2,
    POP_VALUE = 3,
    MOV_VALUE = 4,
    CMP_VALUE = 5,
    JMP_VALUE = 6,
    NO_COMMAND = 7
};
enum CONSTS_OF_GETREGORVAL
{
    NEXT_IS_NOTHING = 0,
    NEXT_IS_INT = 1,
    NEXT_IS_REGISTER = 2,
    SHIT_HAPPENED = -1,
    AX = 0,
    BX = 1,
    CX = 2,
    DX = 3
};


struct constsForGetCodeOfCommand
{
    char NAME_OF_COMMAND[10];
    int CODE_OF_COMMAND;
    int CODE_OF_VALUE;
};
const int NUMBER_OF_CODES_OF_COMMANDS = 15;
const struct constsForGetCodeOfCommand CODES_OF_COMMANDS [NUMBER_OF_CODES_OF_COMMANDS] = 
{
    { "push", 1, PUSH_VALUE },
    { "pop", -1, POP_VALUE },
    { "add", 1000, NO_VALUE },
    { "mul", 1001, NO_VALUE },
    { "div", 1002, NO_VALUE },
    { "sub", 1003, NO_VALUE },
    { "out", -2, NO_VALUE },
    { "end", 0, NO_VALUE },
    { "mov", 500, MOV_VALUE },
    { "cmp", -500, CMP_VALUE },
    { "jne", 10000, JMP_VALUE },
    { "je", 10001, JMP_VALUE },
    { "jl", 10002, JMP_VALUE },
    { "jb", 10003, JMP_VALUE },
    { "jmp", 10004, JMP_VALUE }
};

    


int assemblation( FILE* input, FILE* output, long labels[], int numberOfLabels )
{
    fseek( input, 0, SEEK_SET );
    char command[30] = ""; 
	char charOfCommand = 0;  //It will contain first char of command
	int codeOfCommand, value, value1;  //Binary command
    if( input == NULL )
    {
        fprintf( stderr, "In function assemblation: NULL input file pointer" );
        return 0;
    }
    if( output == NULL )
    {
        fprintf( stderr, "In function assemblation: NULL output file pointer" );
        return 0;
    }
    if( labels == NULL && numberOfLabels != 0 )
    {
        fprintf( stderr, "In fuction assemblation: no labels array, but number of labels not equals to zero" );
        return 0;
    }
    while(1)
    {
        strcpy( command, "" );
        charOfCommand = 0;
        while(1)   //pass all shit before command
        {
            charOfCommand = fgetc(input);
            if( isalpha( charOfCommand ) ) break;
        }
        fseek( input, -1, SEEK_CUR );
        fscanf( input, "%s", command );	
	    switch( getCodeOfCommand( &codeOfCommand, command ) )  //switch text of command to code of command
        {
        case NO_VALUE:
            fwrite( &codeOfCommand, sizeof( codeOfCommand ), 1, output );
            break;
        case INT_VALUE:
            fscanf( input, "%i", &value);
            fwrite( &codeOfCommand, sizeof( codeOfCommand ), 1, output );
            fwrite( &value, sizeof( value ), 1, output );
            break;
        case PUSH_VALUE:
            switch( getRegOrVal( input, &value ) )
            {
            case NEXT_IS_NOTHING:
                fprintf( stderr, "Code is incorrect(push)\n" );
                return 0;
                break;
            case NEXT_IS_INT:
                fwrite( &codeOfCommand, sizeof( codeOfCommand ), 1, output );
                fwrite( &value, sizeof( value ), 1, output );
                break;
            case NEXT_IS_REGISTER:
                codeOfCommand *= 100;
                fwrite( &codeOfCommand, sizeof( codeOfCommand ), 1, output );
                fwrite( &value, sizeof( value ), 1, output );
                break;
            }
            break;
        case POP_VALUE:
            switch( getRegOrVal( input, &value ) )
            {
            case NEXT_IS_INT:
                fprintf( stderr, "Code is incorrect(pop)\n" );
                return 0;
                break;
            case NEXT_IS_NOTHING:
                fwrite( &codeOfCommand, sizeof( codeOfCommand ), 1, output );
                break;
            case NEXT_IS_REGISTER:
                codeOfCommand *= 100;
                fwrite( &codeOfCommand, sizeof( codeOfCommand ), 1, output );
                fwrite( &value, sizeof( value ), 1, output );
                break;
            }
            break;
        case MOV_VALUE:
            if( getRegOrVal( input, &value ) == NEXT_IS_REGISTER )
            {
                switch(  getRegOrVal( input,  &value1 ) )
                {
                case NEXT_IS_NOTHING:
                    fprintf( stderr, "Code is incorrect(mov)\n" );
                    return 0;
                    break;
                case NEXT_IS_INT:
                    fwrite( &codeOfCommand, sizeof( codeOfCommand ), 1, output );
                    fwrite( &value, sizeof( value ), 1, output );
                    fwrite( &value1, sizeof( value1 ), 1, output );
                    break;
                case NEXT_IS_REGISTER:
                    codeOfCommand ++;
                    fwrite( &codeOfCommand, sizeof( codeOfCommand ), 1, output );
                    fwrite( &value, sizeof( value ), 1, output );
                    fwrite( &value1, sizeof( value1 ), 1, output );
                    break;
                }   
            } 
            else
            {
                fprintf( stderr, "Code is incorrect(mov)\n" );
                return 0;
            }
            break;
        case CMP_VALUE:
            switch( getRegOrVal( input, &value ) )
            {
            case NEXT_IS_REGISTER:
                if( getRegOrVal( input, &value1 ) == NEXT_IS_REGISTER )
                {
                    codeOfCommand--;
                    fwrite( &codeOfCommand, sizeof( codeOfCommand ), 1, output );
                    fwrite( &value, sizeof( value ), 1, output );
                    fwrite( &value1, sizeof( value1 ), 1, output );
                } 
                else
                {
                    fprintf( stderr, "Code is incorrect(cmp)\n" );
                    return 0;
                }
                break;
            case NEXT_IS_INT:
                fprintf( stderr, "Code is incorrect(cmp)\n" );
                return 0;
                break;
            case NEXT_IS_NOTHING:
                fwrite( &codeOfCommand, sizeof( codeOfCommand ), 1, output );
                break;
            }
            break;
        case JMP_VALUE:
            getLabel( input, &value );
            if( value >= 0 && value < numberOfLabels && labels[value] != NO_LABEL )
                value = labels[value];
            else
            {
                fprintf( stderr, "No such label" );
                return 0;
            }
            fwrite( &codeOfCommand, sizeof( codeOfCommand ), 1, output );
            fwrite( &value, sizeof( value ), 1, output );
            break;
        case NO_COMMAND:
            fprintf( stderr, "No such command\n" );
            return 0;
            break;
        }
        if( !codeOfCommand ) break;
	}
	return 1;
}



int getCodeOfCommand( int* code, char* command )
{
    for( int i = 0; i < NUMBER_OF_CODES_OF_COMMANDS; i++ )
    {
        if( !strcmp( command, CODES_OF_COMMANDS[i].NAME_OF_COMMAND ) )
        {
            *code = CODES_OF_COMMANDS[i].CODE_OF_COMMAND;
            return CODES_OF_COMMANDS[i].CODE_OF_VALUE;
        }
    }
    return NO_COMMAND;
}


int getRegOrVal ( FILE* input, int* value )
{
    char ch = 0;
    while(1)
    {
        ch = fgetc( input );
        switch( ch )
        {
        case '\n':
            return NEXT_IS_NOTHING;
            break;
        case 'A':
            ch = fgetc( input );
            if( ch == 'X' )
            {
                *value = AX;
                return NEXT_IS_REGISTER;
            }
            else
            {
                fprintf( stderr, "Code is incorrect(reg)\n" );
                exit( EXIT_SUCCESS );
            }
            break;
        case 'B':
            ch = fgetc( input );
            if( ch == 'X' )
            {
                *value = BX;
                return NEXT_IS_REGISTER;
            }
            else
            {
                fprintf( stderr, "Code is incorrect(reg)\n" );
                exit( EXIT_SUCCESS );
            }
            break;
        case 'C':
            ch = fgetc( input );
            if( ch == 'X' )
            {
                *value = CX;
                return NEXT_IS_REGISTER;
            }
            else
            {
                fprintf( stderr, "Code is incorrect(reg)\n" );
                exit( EXIT_SUCCESS );
            }
            break;
        case 'D':
            ch = fgetc( input );
            if( ch == 'X' )
            {
                *value = DX;
                return NEXT_IS_REGISTER;
            }
            else
            {
                fprintf( stderr, "Code is incorrect(reg)\n" );
                exit( EXIT_SUCCESS );
            }
            break;
        default:
            if ( isdigit( ch ) || ch == '-' )
            {
                fseek( input, -1, SEEK_CUR );
                if( fscanf( input, "%d", value ) )
                    return NEXT_IS_INT;
                else
                {
                    fprintf( stderr, "Code is incorrect( minus with no int)" );
                    exit( EXIT_SUCCESS );
                }
            }
            else
            {
                if( ch > 32 ) //if not control or space
                {
                fprintf( stderr, "Code is incorrect(some shit after and not reg)\n" );
                exit( EXIT_SUCCESS );
                }
                else
                    break;
            }
        }
    }
    return SHIT_HAPPENED;
}

int getLabel ( FILE* input, int* value )
{
    char ch = 0;
    while(1)
    {
        ch = fgetc( input );
        switch( ch )
        {
        case ':':
            if( fscanf( input, "%d", value ) )
                return 1;
            else
            {
                fprintf( stderr, "Code is incorrect(no value after :)\n" );
                exit( EXIT_SUCCESS );
            }
            break;
        case ' ':
            break;
        default:
            fprintf( stderr, "Code is incorrect(some shit after jump)\n" );
            exit( EXIT_SUCCESS );
            break;
        }
    }
    return 0;
}


int fillLabels( FILE* input, long** labelsp )
{
    int ch = 0;
    int someInt = 0, maxLabel = -1;
    long count = -1;
    char someStr[30] = "";
    long* labels;
    labels = *labelsp;
    if( labels != NULL )
    {
        fprintf( stderr, "Pointer to NULL expected" );
        exit( EXIT_FAILURE );
    }
    if( input == NULL )
    {
        fprintf( stderr, "NULL FILE pointer" );
        exit( EXIT_FAILURE );
    }
    fseek( input, 0, SEEK_SET );
    while(1)//Walk through to to find maxLabel
    {
        ch = fgetc( input );
        if( ch == EOF )
            break;
        if( isalpha( ch ) )
        {
            fseek( input, -1, SEEK_CUR );
            fscanf( input, "%s", someStr );
            continue;
        }
        if( ch == '-' )
            if( fscanf( input, "%d", &someInt ) )
            {
                continue;
            }
            else
            {
                fprintf( stderr, "Code is incorrect( minus without value )\n" );
                exit( EXIT_SUCCESS );
            }
        if( isdigit( ch ) )
        {
            fseek( input, -1, SEEK_CUR );
            fscanf( input, "%d", &someInt );
            ch = fgetc( input );
            if( ch == ':' && someInt > maxLabel )
                maxLabel = someInt;
        }
    }
    if( maxLabel == -1 ) //No Labels
        return 0;
    labels = (long*)calloc( maxLabel + 1, sizeof( *labels ) );
    for( int i = 0; i < maxLabel +1; i++ )
        labels[i] = NO_LABEL;
    if( labels == NULL )
    {
        fprintf( stderr, "Memory limit exceeded" );
        exit( EXIT_FAILURE );
    }
    fseek( input, 0, SEEK_SET );
    while(1)
    {
        ch = fgetc( input );
        if( ch == EOF )
            break;
        if( isalpha( ch ) )
        {
            fseek( input, -1, SEEK_CUR );
            fscanf( input, "%s", someStr );
            count++;
            continue;
        }
        if( ch == '-' || isdigit( ch ) )
        {
            fseek( input, -1, SEEK_CUR );
            if( fscanf( input, "%d", &someInt ) )
            {
                ch = fgetc( input );
                if( ch == ':' )
                    if( someInt < 0 )
                    {
                        fprintf( stderr, "Label can't be negative" );
                        exit( EXIT_SUCCESS );
                    }
                    else
                    {
                        if( someInt > maxLabel )
                        {
                            fprintf( stderr, "In function fillLabels: label bigger than maxLabel was found" );
                            exit( EXIT_FAILURE );
                        }
                        labels[someInt] = count + 1;
                        //printf( "jmp :%d -> %li\n", someInt, count + 1 );
                        continue;
                    }
                else
                {
                    count++;
                    continue;
                }
            }
            else
            {
                fprintf( stderr, "Code is incorrect( minus without value )\n" );
                exit( EXIT_SUCCESS );
            }
        }
    }
    *labelsp = labels;
    return maxLabel + 1;
}


