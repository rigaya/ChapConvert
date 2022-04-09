//  -----------------------------------------------------------------------------------------
//    �g�� x264 �o��(GUI) Ex  v1.xx/2.xx by rigaya
//  -----------------------------------------------------------------------------------------
//   �\�[�X�R�[�h�ɂ���
//   �E���ۏ؂ł��B
//   �E�{�\�[�X�R�[�h���g�p�������Ƃɂ�邢���Ȃ鑹�Q�E�g���u���ɂ���rigaya�͐ӔC�𕉂��܂���B
//   �ȏ�ɗ������Ē�����ꍇ�A�{�\�[�X�R�[�h�̎g�p�A�����A���ρA�ĔЕz���s���Ē����č\���܂���B
//  -----------------------------------------------------------------------------------------

#ifndef _AUO_H_
#define _AUO_H_

#include <Windows.h>

const int   MAX_PATH_LEN          = 1024; //NTFS�ł�32768�����炵����...�������
const int   MAX_APPENDIX_LEN      = 63; //�K��

const int   MAX_CMD_LEN           = 8192; //�R�}���h���C���̍ő咷�͂悭�킩���

const DWORD AUDIO_BUFFER_DEFAULT  = 48000;
const DWORD AUDIO_BUFFER_MAX      = AUDIO_BUFFER_DEFAULT * 30;

enum {
	VIDEO_OUTPUT_DISABLED = -2,
	VIDEO_OUTPUT_RAW      = -1,
	VIDEO_OUTPUT_MP4      = 0,
	VIDEO_OUTPUT_MKV      = 1,
	VIDEO_OUTPUT_MPEG2    = 3,
};

static const char *const OUTPUT_FILE_EXT[]        = {  ".mp4",     ".mkv",     ".264" };
static const char *const OUTPUT_FILE_EXT_FILTER[] = { "*.mp4",    "*.mkv",    "*.264"    };
static const char *const OUTPUT_FILE_EXT_DESC[]   = { "mp4 file", "mkv file", "raw file" };

enum {
	MUXER_DISABLED = VIDEO_OUTPUT_DISABLED,
	MUXER_MP4      = VIDEO_OUTPUT_MP4,
	MUXER_MKV      = VIDEO_OUTPUT_MKV,
	MUXER_TC2MP4   = VIDEO_OUTPUT_MP4 + 2,
	MUXER_MPG      = VIDEO_OUTPUT_MPEG2,
	MUXER_MP4_RAW  = VIDEO_OUTPUT_MP4 + 4,
};

enum {
	AUO_RESULT_SUCCESS    = 0x0000,
	AUO_RESULT_ERROR      = 0x0001,
	AUO_RESULT_ABORT      = 0x0002,
	AUO_RESULT_WARNING    = 0x0004,
};
typedef DWORD AUO_RESULT;

typedef struct {
	WCHAR *text;
	DWORD value;
} PRIORITY_CLASS;

const DWORD AVIUTLSYNC_PRIORITY_CLASS = 0;

const PRIORITY_CLASS priority_table[] = {
	{L"AviutlSync",       AVIUTLSYNC_PRIORITY_CLASS   },
	{L"higher",           HIGH_PRIORITY_CLASS         },
	{L"high",             ABOVE_NORMAL_PRIORITY_CLASS },
	{L"normal",           NORMAL_PRIORITY_CLASS       },
	{L"low",              BELOW_NORMAL_PRIORITY_CLASS },
	{L"lower",            IDLE_PRIORITY_CLASS         },
	{L"",                 NORMAL_PRIORITY_CLASS       },
	{L"realtime(�񐄏�)", REALTIME_PRIORITY_CLASS     },
	{NULL,                0                           }
};

typedef struct {
	char   name[256]; //�t�H���g��(family name)
	double size;      //�t�H���g�T�C�Y
	int    style;     //�t�H���g�X�^�C��
} AUO_FONT_INFO;

void open_log_window(const char *savefile, int current_pass, int total_pass);

void write_log_auo_line_fmt(int log_type_index, const char *format, ... );
void write_log_auo_enc_time(const char *mes, DWORD time);

#endif //_AUO_H_
