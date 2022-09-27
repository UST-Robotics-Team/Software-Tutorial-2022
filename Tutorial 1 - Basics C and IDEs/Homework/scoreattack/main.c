#include <stdio.h>

const char* const msg_prompt_input = "Please enter a string:\n";
const char* const msg_max_scores = "Maximum Score:\n";

int main(){
    printf("%s", msg_prompt_input);
    // get input from the command line interface, for format please refer to the Problem_Set.md

    // output the result
    printf("%s", msg_max_scores);
    return 0;
}
