#include <iostream>
#include "clsMainScreen.h"
#include"clsLoginScreen.h"
#include<ctime>

int main()

{
   

    while(true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;

        }

        
      }
   
  
    return 0;
}