#ifndef ERROR_CODE_H
#define ERROR_CODE_H

typedef enum ErrorCode {
	None = 0,
	NegativeInput = 1,
	FactorialOverflow = 2
} ErrorCode;

void handle_error_codes(ErrorCode, int);

#endif
