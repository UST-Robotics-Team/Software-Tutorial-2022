#include <stdio.h>

const char* const error_msg_decimal = "Error! That set of number is not a decimal number.\n";
const char* const error_msg_binary = "Error! That set of number is not a binary number.\n";
const char* const error_msg_hex = "Error! That set of number is not a hexadecimal number.\n";
const char* const error_msg_unsupported_system = "Error! The number system is not supported.\n";

const char* const msg_prompt_number = "Please enter a set of number:\n";
const char* const msg_prompt_current_number_system = "Please enter the current number system:\n";
const char* const msg_prompt_number_system_to_convert = "Please enter the number system you want the set of number be converted to:\n";
const char* const msg_output = "Output=";

int main(){
    printf("%s", msg_prompt_number);
    
    /**
     * @brief 
     * Get user input for number to be convert
     */

    // TODO:

    printf("%s", msg_prompt_current_number_system);

    /**
     * @brief 
     * Get user input for current number system
     */

    // TODO:
    printf("%s", msg_prompt_number_system_to_convert);

    /**
     * @brief 
     * Get user input for the number system for conversion.
     * Print converted number in format of "Output=12", e.g Output=ABCDEF
     * No space should be inserted in the asnwer "Output=XXX".
     * In case of wrong number system for conversion, please use the above error msgs.
     */

    // TODO:


    return 0;
}