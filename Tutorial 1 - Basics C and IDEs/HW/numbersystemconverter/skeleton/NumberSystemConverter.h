#ifndef _NUMBERSYSTEMCONVERTER_H_
#define _NUMBERSYSTEMCONVERTER_H_

char* error_msg_decimal = "Error! That set of number is not a decimal number.";
char* error_msg_binary = "Error! That set of number is not a binary number.";
char* error_msg_hex = "Error! That set of number is not a hexadecimal number.";

int BinaryToDecimal(int number);

const char* BinaryToHexadecimal(int number);

int DecimalToBinary(int number);

const char* DecimalToHexadecimal(int number);

int HexadecimalToBinary(char hex[]);

int HexadecimalToDecimal(char hex[]);

#endif