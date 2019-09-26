#pragma once
#include<windows.h>
#include<stdio.h>
#include <string.h>
#include<algorithm>
#include<cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <codecvt>
#include <assert.h>
/*
 * 将路径fpath所指的文件从各种编码格式，转换为ANSI格式
 *
 * Copyright (c) 2013 赵子清， All rights reserved.
 *
 */

#define CODE_FORMAT_ANSI        1
#define CODE_FORMAT_UTF8        2
#define CODE_FORMAT_UNICODE_LE  3
#define CODE_FORMAT_UNICODE_BE  4

typedef int ErrorCode;
#define    ERR_OK                  0
#define    ERR_FILE_OPEN_FAILED    1001

#define SWAP16(x) \
    ((((x) & 0x00ff) << 8) | \
    (((x) & 0xff00) >> 8) )

#define SWAP32(x) \
    ((((x) & 0x000000ff) << 24) | \
    (((x) & 0x0000ff00) <<  8) | \
    (((x) & 0x00ff0000) >>  8) | \
    (((x) & 0xff000000) >> 24) )

#define SAFE_DELETE(x) if((x)!=0) {delete[] (x); (x) = 0; }

ErrorCode  ConvertFormat(const char* fpath)
{
#ifdef _MSC_VER
	assert(fpath != 0);

	FILE* fp = ::fopen(fpath, "rb");
	if (fp == NULL)
		return ERR_FILE_OPEN_FAILED;

	int fmtFlag;
	int fmt = CODE_FORMAT_ANSI;
	::fread(&fmtFlag, sizeof(int), 1, fp);
	::fclose(fp);

	fmtFlag = SWAP32(fmtFlag);
	if ((fmtFlag & 0xffffff00) == 0xefbbbf00)
		fmt = CODE_FORMAT_UTF8;
	else if ((fmtFlag & 0xffff0000) == 0xfffe0000)
		fmt = CODE_FORMAT_UNICODE_LE;
	else if ((fmtFlag & 0xffff0000) == 0xfeff0000)
		fmt = CODE_FORMAT_UNICODE_BE;


	if (fmt == CODE_FORMAT_ANSI)
		return ERR_OK;

	fp = ::fopen(fpath, "rb");
	char* txt = 0;
	wchar_t* wtxt = 0;
	long flen = 0L;
	::fseek(fp, 0L, SEEK_END);
	flen = ftell(fp);
	::rewind(fp);
	if (fmt == CODE_FORMAT_UTF8)
	{
		txt = new char[flen + 1];
		::fread(txt, 1, flen, fp);
		txt[flen] = '\0';
	}
	else if (fmt == CODE_FORMAT_UNICODE_LE || fmt == CODE_FORMAT_UNICODE_BE)
	{
		wtxt = new wchar_t[flen / 2 + 1];
		::fread(wtxt, 2, flen / 2, fp);
		if (fmt == CODE_FORMAT_UNICODE_BE)
		{
			for (int i = 0; i < flen / 2; i++)
				wtxt[i] = SWAP16(wtxt[i]);
		}
		wtxt[flen / 2] = L'\0';
	}

	::fclose(fp);

	int nLen;
	wchar_t* pwstr = 0;
	char* pstr = 0;
	switch (fmt)
	{
	case CODE_FORMAT_UTF8:
		nLen = ::MultiByteToWideChar(CP_UTF8, 0, txt + 3, -1, NULL, 0);
		pwstr = new wchar_t[nLen + 1];
		nLen = ::MultiByteToWideChar(CP_UTF8, 0, txt + 3, -1, pwstr, nLen);
		nLen = ::WideCharToMultiByte(CP_ACP, 0, pwstr, -1, NULL, 0, NULL, NULL);
		pstr = new char[nLen];
		::memset(pstr, 0, nLen);
		nLen = ::WideCharToMultiByte(CP_ACP, 0, pwstr, -1, pstr,
			nLen, NULL, NULL);
		break;
	case CODE_FORMAT_UNICODE_LE:
	case CODE_FORMAT_UNICODE_BE:
		nLen = ::WideCharToMultiByte(CP_ACP, 0, wtxt + 1, -1, NULL, 0, NULL, NULL);
		pstr = new char[nLen];
		::memset(pstr, 0, nLen);
		nLen = ::WideCharToMultiByte(CP_ACP, 0, wtxt + 1, -1, pstr,
			nLen, NULL, NULL);
		break;
	default:
		break;
	}

	fp = ::fopen(fpath, "wb");
	::fwrite(pstr, 1, nLen - 1, fp);
	::fclose(fp);

	SAFE_DELETE(txt);
	SAFE_DELETE(wtxt);
	SAFE_DELETE(pstr);
	SAFE_DELETE(pwstr);

#endif

	return ERR_OK;
}