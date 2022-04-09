﻿// -----------------------------------------------------------------------------------------
// ChapConvert by rigaya
// -----------------------------------------------------------------------------------------
// The MIT License
//
// Copyright (c) 2022 rigaya
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// ------------------------------------------------------------------------------------------

#ifndef __CHAP_CONVERT_VERSION_H__
#define __CHAP_CONVERT_VERSION_H__

#ifdef DEBUG
#define VER_DEBUG   VS_FF_DEBUG
#define VER_PRIVATE VS_FF_PRIVATEBUILD
#else
#define VER_DEBUG   0
#define VER_PRIVATE 0
#endif

#define VER_FILEVERSION          0,1,0,0
#define VER_STR_FILEVERSION      "1.00"
#define VER_TSTR_FILEVERSION  _T("1.00")

#define VER_STR_COMMENTS         "Chapter format conversion"
#define VER_STR_COMPANYNAME      ""
#define VER_STR_FILEDESCRIPTION  "ChapConvert"
#define VER_STR_INTERNALNAME     "ChapConvert"
#define VER_STR_ORIGINALFILENAME "ChapConvert.exe"
#define VER_STR_LEGALCOPYRIGHT   "ChapConvert by rigaya"
#define VER_STR_PRODUCTNAME      "ChapConvert"
#define VER_PRODUCTVERSION       VER_FILEVERSION
#define VER_STR_PRODUCTVERSION   VER_STR_FILEVERSION

#endif //__CHAP_CONVERT_VERSION_H__