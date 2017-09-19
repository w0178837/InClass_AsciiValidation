
//The following method prevents users from crashing a program using //input such as ‘ctrl z’.

//It is a dirty method because it is a mechanism that interacts directly with the user

#include <iostream>
#include <cstdlib>

#include <string>

#include <stdio.h>

#include <conio.h>

#include <stdlib.h>


int main() {
    std::cout << "Hello, World!" << std::endl;





    bool inputMechanism(string* inputString)
    {
        char tempKey;
        const static int maxLineLength = 20;

        do{
            tempKey = _getch();
            if((tempKey >= 32 && tempKey <= 126))
            {
                //When valid character pressed, accept and print on screen
                if(maxLineLength > (*inputString).length())
                {
                    (*inputString) += tempKey;
                    printf("%c", tempKey);
                }
            }
            else if(tempKey == 8)
            {
                //If backspace pressed, pop character off string and erase from screen
                if((*inputString).length() > 0)
                {
                    (*inputString).erase((*inputString).length() - 1, 1);
                    printf("\b \b");
                }
            }
            else if(tempKey == -32)
            {
                //Drop off any arrow key presses using another getch
                _getch();
            }
        } while(tempKey != 13);

        //Drop a line
        printf("\n");

        return true;
    }

    return 0;
}