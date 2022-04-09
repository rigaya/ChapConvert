//  -----------------------------------------------------------------------------------------
//    拡張 x264 出力(GUI) Ex  v1.xx/2.xx by rigaya
//  -----------------------------------------------------------------------------------------
//   ソースコードについて
//   ・無保証です。
//   ・本ソースコードを使用したことによるいかなる損害・トラブルについてrigayaは責任を負いません。
//   以上に了解して頂ける場合、本ソースコードの使用、複製、改変、再頒布を行って頂いて構いません。
//  -----------------------------------------------------------------------------------------

#include "ChapterRW.h"

#if defined(_WIN32) || defined(_WIN64)
#include <shlwapi.h>
#pragma comment (lib, "shlwapi.lib")
#else
#include <sys/types.h>
#include <sys/stat.h>

bool PathFileExists(const char *filepath) {
    struct stat st;
    return 0 == stat(filepath, &st);
}

static inline const char *PathFindExtensionA(const char *path) {
    return strrchr(basename(path), '.');
}
#endif


//ファイル名(拡張子除く)の後ろに文字列を追加する
static inline void apply_appendix(char *new_filename, size_t new_filename_size, const char *orig_filename, const char *appendix) {
    if (new_filename != orig_filename)
        strcpy_s(new_filename, new_filename_size, orig_filename);
    strcpy_s(PathFindExtensionA(new_filename), new_filename_size - (PathFindExtensionA(new_filename) - new_filename), appendix);
}
#if defined(_WIN32) || defined(_WIN64)
static inline void apply_appendix(WCHAR *new_filename, size_t new_filename_size, const WCHAR *orig_filename, const WCHAR *appendix) {
    if (new_filename != orig_filename)
        wcscpy_s(new_filename, new_filename_size, orig_filename);
    wcscpy_s(PathFindExtensionW(new_filename), new_filename_size - (PathFindExtensionW(new_filename) - new_filename), appendix);
}
#endif //#if defined(_WIN32) || defined(_WIN64)

int main(int argc, char **argv) {
    if (argc == 1) {
        fprintf(stderr, "チャプターファイルをドラッグ&ドロップしてください。\n");
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        if (!PathFileExists(argv[i])) {
            fprintf(stderr, "チャプターファイル %s が存在しません。\n", PathFindFileName(argv[i]));
        } else {

            int sts = AUO_CHAP_ERR_NONE;
            ChapterRW chapParser;
            if (AUO_CHAP_ERR_NONE == (sts = chapParser.read_file(argv[i], CODE_PAGE_UNSET, 0.0))) {
                char new_chap_name[1024] = { 0 };
                apply_appendix(new_chap_name, _countof(new_chap_name), argv[i], (chapParser.file_chapter_type() == CHAP_TYPE_NERO) ? "_apple.txt" : "_nero.txt");
                chapParser.add_dummy_chap_zero_pos();
                chapParser.write_file(new_chap_name, CHAP_TYPE_ANOTHER, false);
            }
            fprintf(stderr, "%s: %s\n", (sts == AUO_CHAP_ERR_NONE) ? "成功" : "失敗", PathFindFileName(argv[i]));
        }
    }
    return 0;
}
