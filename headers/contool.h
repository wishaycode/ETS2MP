#include <windows.h>
#include <stdio.h>

#define    c_Black 0            
#define    c_Blue 1 
#define    c_Green 2
#define    c_Cyan 3
#define    c_Red 4
#define    c_Magenta 5
#define    c_Brown 6
#define    c_LightGray 7
#define    c_DarkGray 8
#define    c_LightBlue 9
#define    c_LightGreen 10
#define    c_LightCyan 11
#define    c_LightRed 12
#define    c_LightMagenta 13
#define    c_Yellow 14
#define    c_White 15

char mask[] = "0123456789";

void sColor(int color)
{
    HANDLE hWND = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hWND, color);
}

int chCount(char arr[])
{
   for(int m = 0; m != 0xFFFFFF; m++) if(arr[m] == '\0') return m;
}

int __print(char str[])
{
    if(str[0] == '\0') return 0;

    for(int i = 0; i != chCount(str); i++)
    {
        int state = 0;
        int state2 = 0;

        if(str[i] == '^')
        {
            for(int k = 0; k != sizeof(mask); k++) if(str[i + 1] == mask[k]) {state = 1; 
                    for(int l = 0; l != sizeof(mask) - 4; l++) if(str[i + 2] == mask[l]) {state2 = 1; break;} break;}

            if(state2 == 1)
            { 
               int ch1 = str[i + 1] - 48;
               int ch2 = str[i + 2] - 48;
               int num2 = ch1 + ch2 + 9;

               sColor(num2);
               i = i + 3;
            }else if (state == 1){
               int num = str[i + 1] - 48;
               sColor(num);
               i = i + 2;
            }
        }
        printf("%c", str[i]);
    }
}
