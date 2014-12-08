#include"disasslib.h"


enum CONSTS_OF_GETCOMMANDOFCODE
{
    NO_VALUE = 0,
    ONE_INT = 1,
    ONE_REG = 2,
    REG_AND_INT = 3,
    TWO_REG = 4,
    NO_COMMAND = -1
};
struct constsForGetCommandOfCode
{
    char NAME_OF_COMMAND[10];
    int CODE_OF_COMMAND;
    int CODE_OF_VALUE;
};
const int NUMBER_OF_CODES_OF_COMMANDS = 19;
const struct constsForGetCommandOfCode CODES_OF_COMMANDS [NUMBER_OF_CODES_OF_COMMANDS] = 
{
    { "push", 1, ONE_INT },
    { "push", 100, ONE_REG },
    { "pop", -1, NO_VALUE },
    { "pop", -100, ONE_REG },
    { "add", 1000, NO_VALUE },
    { "mul", 1001, NO_VALUE },
    { "div", 1002, NO_VALUE },
    { "sub", 1003, NO_VALUE },
    { "out", -2, NO_VALUE },
    { "end", 0, NO_VALUE },
    { "mov", 500, REG_AND_INT },
    { "mov", 501, TWO_REG },
    { "cmp", -500, NO_VALUE },
    { "cmp", -501, TWO_REG },
    { "jne", 10000, ONE_INT },
    { "je", 10001, ONE_INT },
    { "jl", 10002, ONE_INT },
    { "jb", 10003, ONE_INT },
    { "jmp", 10004, ONE_INT }
};

int disassemblation( FILE* input, FILE* output )
{
    char command[30] = "";
    char reg = -1;
    int code = 0, value = 0, value1 = 0;
    if( input == NULL )
    {
        fprintf( stderr, "In function disassemblation: NULL input file pointer" );
        return 0;
    }
    if( output == NULL )
    {
        fprintf( stderr, "In function disassemblation: NULL output file pointer" );
        return 0;
    }
	while(1)
	{
        strcpy( command, "" );
        reg = -1;
        code = 0;
        value = 0;
        value1 = 0;
		fread( &code, sizeof(code), 1, input );
		switch( getCommandOfCode( command, code ) )
		{
        case ONE_INT:
			fread( &value, sizeof(value), 1, input );
			fprintf( output, "%s %i\n", command, value );
		    break;
        case NO_VALUE:
			fprintf( output, "%s\n", command );
            break;
        case ONE_REG:
			fread( &value, sizeof(value), 1, input );
            if( value < 0 || value > 3 )
            {
                fprintf( stderr, "Bincode is incorrect" );
                return 0;
            }
            reg = 'A' + value;
			fprintf( output, "%s %cX\n", command, reg );
		    break;
        case REG_AND_INT:
			fread( &value, sizeof(value), 1, input );
            fread( &value1, sizeof(value), 1, input );
            if( value < 0 || value > 3 )
            {
                fprintf( stderr, "Bincode is incorrect" );
                return 0;
            }
            reg = 'A' + value;
			fprintf( output, "%s %cX %d\n", command, reg, value1 );
		    break;
        case TWO_REG:
			fread( &value, sizeof(value), 1, input );
            fread( &value1, sizeof(value), 1, input );
            if( value < 0 || value > 3 )
            {
                fprintf( stderr, "Bincode is incorrect" );
                return 0;
            }
            if( value1 < 0 || value1 > 3 )
            {
                fprintf( stderr, "Bincode is incorrect" );
                return 0;
            }
            reg = 'A' + value;
			fprintf( output, "%s %cX ", command, reg );
            reg = 'A' + value1;
            fprintf( output, " %cX\n", reg );
		    break;
        case NO_COMMAND:
            fprintf( stderr, "No such code of command" );
            return 0;
        }
		if( !code )
			break;
	}
	return 1;
}



int getCommandOfCode( char* command, int code )
{
    for( int i = 0; i < NUMBER_OF_CODES_OF_COMMANDS; i++ )
    {
        if( code == CODES_OF_COMMANDS[i].CODE_OF_COMMAND )
        {
            strcpy( command, CODES_OF_COMMANDS[i].NAME_OF_COMMAND );
            return CODES_OF_COMMANDS[i].CODE_OF_VALUE;
        }
    }
	return NO_COMMAND;
}
