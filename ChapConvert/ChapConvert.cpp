// -----------------------------------------------------------------------------------------
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

#include <filesystem>
#include "ChapConvert_version.h"
#include "rgy_chapter.h"
#include "rgy_filesystem.h"
#include "rgy_codepage.h"
#include "rgy_util.h"

const TCHAR *typeToStr(ChapType type) {
    switch (type) {
    case CHAP_TYPE_ANOTHER:   return _T("another");
    case CHAP_TYPE_NERO:      return _T("nero");
    case CHAP_TYPE_APPLE:     return _T("apple");
    case CHAP_TYPE_MATROSKA:  return _T("matroska");
    case CHAP_TYPE_UNKNOWN:
    default:                  return _T("unknown");
    }
}

ChapType typeFromStr(const TCHAR *str, bool& convertToNeroUTF8) {
    if (_tcsicmp(str, _T("another"))   == 0) return CHAP_TYPE_ANOTHER;
    if (_tcsicmp(str, _T("apple"))     == 0) return CHAP_TYPE_APPLE;
    if (_tcsicmp(str, _T("matroska"))  == 0) return CHAP_TYPE_MATROSKA;
    if (_tcsicmp(str, _T("nero"))      == 0) { convertToNeroUTF8 = false; return CHAP_TYPE_NERO; }
    if (_tcsicmp(str, _T("nero_utf8")) == 0) { convertToNeroUTF8 = true;  return CHAP_TYPE_NERO; }
    return CHAP_TYPE_UNKNOWN;
}

void print_help() {
    _ftprintf(stdout,
        _T("ChapConvert ") VER_TSTR_FILEVERSION _T("\n")
        _T("\n")
        _T("Usage\n")
        _T("ChapConvert.exe [options] <chapter file1> [<chapter file2>][...]\n")
        _T("\n")
        _T("Options\n")
        _T("-f,--format <string>    output chapter format (default: another)\n")
        _T("    another   ... convert to another format (nero->apple, apple->nero)\n")
        _T("    nero      ... convert to nero format (ansi)\n")
        _T("    nero_utf8 ... convert to nero format (utf8)\n")
        _T("    apple     ... convert to apple format (utf8)\n")
        _T("\n")
        _T("   --format-in <string>  input chapter format (default: auto)\n")
        _T("    nero      ... nero format (ansi)\n")
        _T("    nero_utf8 ... nero format (utf8)\n")
        _T("    apple     ... apple format (utf8)\n")
        _T("    matroska  ... matroska format (utf8)\n")
        _T("\n")
        _T("   --cp-in  <string>     input codepage (default: auto)\n")
        _T("    ansi, utf8, sjis, eucjp, iso2022jp, utf16le, utf16be\n")
    );
}

int _tmain(int argc, const TCHAR **argv) {
    if (argc == 1) {
        _ftprintf(stderr, _T("target chapter file not specified.\n"));
        print_help();
        return 1;
    }
    ChapType convertFrom         = CHAP_TYPE_UNKNOWN;
    bool     convertFromNeroUTF8 = false;
    ChapType convertTo           = CHAP_TYPE_ANOTHER;
    bool     convertToNeroUTF8   = false;
    uint32_t inputCP             = CODE_PAGE_UNSET;

    int iarg = 1;
    for (; iarg < argc-1; iarg++) {
        if (_tcscmp(argv[iarg], _T("-h")) == 0) {
            print_help();
            return 0;
        } else if (
               _tcscmp(argv[iarg], _T("-f")) == 0
            || _tcscmp(argv[iarg], _T("--format")) == 0) {
            iarg++;
            convertTo = typeFromStr(argv[iarg], convertToNeroUTF8);
            if (convertTo == CHAP_TYPE_UNKNOWN) {
                _ftprintf(stderr, _T("invalid output format: %s.\n"), argv[iarg]);
                return 1;
            }
        } else if (_tcscmp(argv[iarg], _T("--format-in")) == 0) {
            iarg++;
            convertFrom = typeFromStr(argv[iarg], convertFromNeroUTF8);
            if (convertFrom == CHAP_TYPE_UNKNOWN) {
                _ftprintf(stderr, _T("invalid input format: %s.\n"), argv[iarg]);
                return 1;
            }
        } else if (_tcscmp(argv[iarg], _T("--cp-in")) == 0) {
            iarg++;
            inputCP = codepage_from_str(tchar_to_string(argv[iarg]).c_str());
            if (inputCP == CODE_PAGE_UNSET) {
                _ftprintf(stderr, _T("invalid input code page: %s.\n"), argv[iarg]);
                return 1;
            }
        }
    }

    if (convertFromNeroUTF8) {
        inputCP = CODE_PAGE_UTF8;
    }

    for (; iarg < argc; iarg++) {
        const auto chap_name = argv[iarg];
        if (!rgy_file_exists(chap_name)) {
            _ftprintf(stderr, _T("chapter file \"%s\" does not exist.\n"), chap_name);
        } else {
            int sts = AUO_CHAP_ERR_NONE;
            ChapterRW chapParser;
            if ((sts = chapParser.read_file(chap_name, inputCP, 0.0)) != AUO_CHAP_ERR_NONE) {
                _ftprintf(stderr, _T("Failed to parse %s\n"), chap_name);
            } else {
                const auto chap_path = std::filesystem::path(chap_name);
                auto new_chap = chap_path.parent_path();
                new_chap /= chap_path.stem();
                new_chap += _T("_");
                new_chap += typeToStr(chapParser.get_out_chapter_type(convertTo));
                new_chap += chap_path.extension();
                chapParser.add_dummy_chap_zero_pos();
                chapParser.write_file(new_chap.c_str(), convertTo, convertToNeroUTF8);
                _ftprintf(stderr, _T("Convert %s (%s) -> %s (%s)\n"),
                    chap_name, typeToStr(chapParser.file_chapter_type()),
                    new_chap.filename().c_str(), typeToStr(chapParser.get_out_chapter_type(convertTo)));
            }
        }
    }
    return 0;
}
