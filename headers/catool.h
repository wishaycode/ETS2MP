/*
 * catool.h
 * Char array tool.
 * 
 * Copyright 2018 
 ** Korobov A. 
 *   <aokorobov@mail.ru>
 *   vk.com/aokorobov
 ** Buzlaev A.
 *   vk.com/divnull
 *   <testest@mail.ru>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * Version: 1.0
 * 14.05.2018
 * + Added func length
 * + Added func swap
 * + Added func reverse
 * + Added func debug
 * + Added func find
 * + Added func cpos
 * + Added func clr
 * 
 * Version: 1.1
 * 16.06.2018
 * + Added func slength (Fixed 20.06)
 * + Added func cut
 * + Added func cat
 * + Added func repls
 */

#include <stdio.h>

/************************************PROTOTYPES***********************************/
int ctl_length(char* aPtr, int size);
int ctl_slength(char str[], int size);
void ctl_swap(char* elem1, char* elem2);
void ctl_reverse(char* aPtr, int size);
void ctl_debug(char* aPtr, int size);
int ctl_find(char* aPtr, int size, char str[], int ssize, int entry); //fix it!
int ctl_cpos(char* aPtr, int size, char chr, int entry);
void ctl_clr(char* aPtr, int size);
void ctl_cut(char* aPtr, int size, int start, int end);
int ctl_cat(char* srcPtr, int size, char* dest, int dsize, int bytes);
int ctl_repls(char* aPtr, int size, char src, char dest, int entry);
/*********************************************************************************/

//Length
int ctl_length(char* aPtr, int size) 
{ 
    int length = 0; 
    for(aPtr; aPtr != aPtr + size; aPtr++) 
    { 
        if(*aPtr == 0) return length; 
        length++; 
    } 
    return length; 
}

//String Length
int ctl_slength(char str[], int size)
{
    for(int i = 0; i != size; i++) if(str[i] == 0) return i - 1;
    return 0;
}

//Swap 
void ctl_swap(char* elem1, char* elem2) 
{ 
    int tmp = *elem1; 
    *elem1 = *elem2; 
    *elem2 = tmp; 
}

//Reverse
void ctl_reverse(char* aPtr, int size) 
{ 
    int length = ctl_length(aPtr, size); 
    for(int i = 0; i != length / 2; i++) 
    { 
        char* ptr = aPtr + i; 
        char* ptre = (aPtr + length) - i; 
        ctl_swap(ptre, ptr); 
    } 
}

//Debug 
void ctl_debug(char* aPtr, int size) 
{ 
    printf("\n"); 
    for(int i = 0; i != size; i++) 
    { 
        char* ofs = aPtr + i; 
        if(*ofs != 0) printf("\n(%d)%c[%d]", i, *ofs, *ofs); 
        else printf("\n(%d)NULL[%d]", i, *ofs); 
    } 
}

//Char Position
int ctl_cpos(char* aPtr, int size, char chr, int entry)
{
    int length = ctl_length(aPtr, size);
    int encnt = 0;
    
    for(int i = 0; i != length; i++)
    {
        char* ptr = aPtr + i;
        if(*ptr == chr) 
        {
            if(encnt == entry) return i;
            encnt++;
        }
    }
    return -1;
}

//Clear
void ctl_clr(char* aPtr, int size)
{
    for(int i = 0; i != size; i++)
    {
        char* ptr = aPtr + i;
        *ptr = 0;
    }
}

//Find
int ctl_find(char* aPtr, int size, char str[], int ssize, int entry)
{
    int length = ctl_length(aPtr, size);
    int slength = ctl_slength(str, ssize);
    if(slength > length) return -1;
    int encnt = 0;
    
    for(int i = 0; i != length; i++)
    {
        char* ptr = aPtr + i;
        
        //... fix it!!!
    }
}

//Cut
void ctl_cut(char* aPtr, int size, int start, int end)
{
	int length = ctl_length(aPtr, size);
	
	for(int i = start; i != end - 1; i++)
    {
		if(i == length) break;
		char* ptr = aPtr + i;
		*ptr = 0;
		ctl_swap(ptr, ptr + (end - 2));
	}
}

//Cat
int ctl_cat(char* dest, int dsize, char* src, int size, int bytes)
{
	//if((dsize - ctl_length(dest, dsize)) < bytes) return -1;
	int cbytes = 0;
	int destLength = ctl_length(dest, dsize);
	int srcLength = ctl_length(src, size);
	
	if(bytes > dsize - destLength) return -1;
	
	for(int i = 0; i != bytes; i++)
	{
		if(i == srcLength + 1) break;
		char* dptr = (dest + destLength) + i;
		char* sptr = src + i;
		*dptr = *sptr;
		cbytes++;
	}
	return cbytes;
}

//Replace Symbol
int ctl_repls(char* aPtr, int size, char src, char dest, int entry)
{
	int length = ctl_length(aPtr, size);
	int cbytes = 0;
	
	for(int i = 0; i != length; i++)
	{
		if(cbytes == entry) return cbytes;
		
		char* ptr = aPtr + i;
		if(*ptr == src) 
		{
			*ptr = dest;
			cbytes++;
		}
	}
	return cbytes;
}
