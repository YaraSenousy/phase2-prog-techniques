
#include "HelperFn.h"

bool IsValue(string input)
{
	// checks if the input string is a double value
	// return true if it's double value, false otherwise

	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc. 

	//TODO: complete this function
	int n;
	int dotcount=0;
	n = input.length();
	//check that it is not empty
	if (n != 0) {
		for (int i = 0; i < n; i++) {
			//check that it is a negative and not the first character
			if (input[i] == 45 && i != 0) {   
				return false;
			}
			//check that there is only one decimal point
			if (input[i] == 46) {  
				dotcount++;
				if (dotcount != 1) {
					return false;
				}
			}
			//check  that it is a number/dot/negative sign     
			if (input[i] < 45|| input[i]>57 || input[i]==47) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool IsVariable (string input)
{
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise

	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters, however, are allowed.
	//TODO: complete this function

	//checking the first character in the variable name (_, a-z,A-Z)
	if ((input[0] == 95) || (input[0] < 91 && input[0]>64) || (input[0] > 96 && input[0] < 123)) {
		for (int i = 1; i < input.length(); i++) {
			//checking if the rest of the characters are not (_, a-z,A-Z,0-9)
			if (!(input[i] == 95 || (input[i] < 91 && input[i]>64) || (input[i] > 96 && input[i] < 123) || (input[i] > 47 && input[i] < 58))) {
				//if not return false
				return false;
			}  
		}
		return true;
	}
	else
		return false;
}

OpType ValueOrVariable (string input)
{
	// checks if the input string is a double value or a variable name
	// chand returns enum "OpType" (the enum is declared in the .h)

	//TODO: complete this function

	if (IsValue(input)) { 
		return VALUE_OP;
	}
	else if (IsVariable(input)) {
		return VARIABLE_OP;
	}
	else {
		return INVALID_OP;
	}

}
