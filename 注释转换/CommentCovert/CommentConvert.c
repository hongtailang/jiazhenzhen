#define _CRT_SECURE_NO_WARNINGS
#include "CommentConvert.h"

//状态全局变量
STATE g_state = NUL_STATE;
void DoNulState(FILE *pfRead, FILE *pfWrite)//fgetc fputc ongetc ungetc
{
	int first = 0;
	int second = 0;
	first = fgetc(pfRead);
	switch (first)
	{
	case '/':
		second = fgetc(pfRead);
		if (second == '*')
		{
			fputc('/', pfWrite);
			fputc('/', pfWrite);
			g_state = C_STATE;
		}
		else if (second == '/')
		{
			fputc(first, pfWrite);
			fputc(second, pfWrite);
			g_state = CPP_STATE;
		}
		else
		{
			fputc(first, pfWrite);
			fputc(second, pfWrite);
		}
		break;
	case EOF:
		g_state = END_STATE;
		break;
	default:
		fputc(first, pfWrite);
		break;
	}
}
void DoCState(FILE *pfRead, FILE *pfWrite)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfRead);
	switch (first)
	{
	case '*':
		second = fgetc(pfRead);
		if (second == '/')//舍弃*/
		{
			fputc('\n', pfWrite);
			g_state = NUL_STATE;
		}
		else
		{
			fputc(first, pfWrite);
			ungetc(second, pfRead);
		}
		break;
	case '\n':
		fputc(first, pfWrite);
		fputc('/', pfWrite);
		fputc('/', pfWrite);
		break;
	case 'EOF':
		g_state = END_STATE;
		break;
	default:
		fputc(first, pfWrite);
		break;
	}
}
void DoCppState(FILE *pfRead, FILE *pfWrite)
{
	int first = 0;
	first = fgetc(pfRead);
	switch (first)
	{
	case '\n':
		fputc(first, pfWrite);
		g_state = NUL_STATE;
		break;
	case EOF:
		g_state = END_STATE;
		break;
	default:
		fputc(first, pfWrite);
	}
}
void DoConvertWork(char *readfile, char *writefile)//打开文件并实现转换
{
	FILE *pfRead = NULL;
	FILE *pfWrite = NULL;
	pfRead = fopen(readfile, "r");
	if (pfRead == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	pfWrite = fopen(writefile, "w");
	printf("转换开始\n");
	if (pfWrite == NULL)
	{
		fclose(pfRead);
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	//转换
	while (g_state!=END_STATE)
	{
		switch (g_state)
		{
		case NUL_STATE:
			DoNulState(pfRead, pfWrite);
			break;
		case C_STATE:
			DoCState(pfRead, pfWrite);
			break;
		case CPP_STATE:
			DoCppState(pfRead, pfWrite);
			break;
		case END_STATE:
			break;
		default:
			break;
		}
	}
	switch (g_state)
	{
	case NUL_STATE:
		break;
	case C_STATE:
		break;
	case CPP_STATE:
		break;
	case END_STATE:
		break;
	default:
		break;
	}
	//转换完成后
	fclose(pfRead);
	fclose(pfWrite);
}
void CommentConvert()
{
	DoConvertWork(READ_FILE_NAME, WRITE_FILE_NAME);
}