#define _CRT_SECURE_NO_WARNINGS
#ifndef  __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__
#include<stdio.h>
#include<stdlib.h>
#define READ_FILE_NAME "input.c"
#define WRITE_FILE_NAME "output.c"
typedef enum STATE
{
	NUL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
}STATE;

void DoConvertWork(char *readfile,char *writefile);
void CommentConvert();
void DoNulState();
void DoCState();
void DoCppState();
#endif  //__COMMENT_CONVERT_H__