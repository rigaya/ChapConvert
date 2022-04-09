
# ChapConvert

�`���v�^�[�t�@�C����nero�`�� <-> apple�`���𑊌ݕϊ����܂��B

## �����
Windows 8.1/10/11 (x86/x64)

## ChapConvert �g�p�ɂ������Ă̒��ӎ���
���ۏ؂ł��B���ȐӔC�Ŏg�p���Ă��������B
ChapConvert���g�p�������Ƃɂ��A�����Ȃ鑹�Q�E�g���u���ɂ��Ă��ӔC�𕉂��܂���B

## �g�p���@
�ϊ��������`���v�^�[�t�@�C�����h���b�O�h���b�v���邩�A���L�̂悤�ɃR�}���h�����s���܂��B

```
ChapConvert.exe [options] <chapter file1> [<chapter file2>][...]
```
### �I�v�V����
#### -f,--format &lt;string&gt;  
  �o�̓`���v�^�[�t�@�C���̃t�H�[�}�b�g���w�肵�܂��B (�f�t�H���g: another)
  ```
    another   ... convert to another format (nero->apple, apple->nero)
    nero      ... convert to nero format (ansi)
    nero_utf8 ... convert to nero format (utf8)
    apple     ... convert to apple format (utf8)
  ```

#### --format-in &lt;string&gt;  
  ���̓`���v�^�[�t�@�C���̃t�H�[�}�b�g���w�肵�܂��B (�f�t�H���g: auto)
  ```
    nero      ... nero�`�� (ansi)
    nero_utf8 ... nero�`�� (utf8)
    apple     ... apple format (utf8)
    matroska  ... matroska format (utf8)
  ```

#### --cp-in &lt;string&gt;  
   ���̓`���v�^�[�t�@�C���̕����R�[�h���w�肵�܂��B (�f�t�H���g: auto)  
   �`���v�^�[�̕����R�[�h������ȏꍇ�ɂ��̃I�v�V�����ŕύX���܂��B
  ```
    ansi, utf8, sjis, eucjp, iso2022jp, utf16le, utf16be
  ```

## �`���v�^�[�̊e�`���̗�
### nero�`��  
```
CHAPTER01=00:00:39.706
CHAPTER01NAME=chapter-1
CHAPTER02=00:01:09.703
CHAPTER02NAME=chapter-2
CHAPTER03=00:01:28.288
CHAPTER03NAME=chapter-3
```

### apple�`�� (utf-8)  
```
<?xml version="1.0" encoding="UTF-8" ?>
  <TextStream version="1.1">
   <TextStreamHeader>
    <TextSampleDescription>
    </TextSampleDescription>
  </TextStreamHeader>
  <TextSample sampleTime="00:00:39.706">chapter-1</TextSample>
  <TextSample sampleTime="00:01:09.703">chapter-2</TextSample>
  <TextSample sampleTime="00:01:28.288">chapter-3</TextSample>
  <TextSample sampleTime="00:01:28.289" text="" />
</TextStream>
```

### matroska�`�� (utf-8)  
[Other Samples&gt;&gt;](https://github.com/nmaier/mkvtoolnix/blob/master/examples/example-chapters-1.xml)
```
<?xml version="1.0" encoding="UTF-8"?>
<Chapters>
  <EditionEntry>
    <ChapterAtom>
      <ChapterTimeStart>00:00:00.000</ChapterTimeStart>
      <ChapterDisplay>
        <ChapterString>chapter-0</ChapterString>
      </ChapterDisplay>
    </ChapterAtom>
    <ChapterAtom>
      <ChapterTimeStart>00:00:39.706</ChapterTimeStart>
      <ChapterDisplay>
        <ChapterString>chapter-1</ChapterString>
      </ChapterDisplay>
    </ChapterAtom>
    <ChapterAtom>
      <ChapterTimeStart>00:01:09.703</ChapterTimeStart>
      <ChapterDisplay>
        <ChapterString>chapter-2</ChapterString>
      </ChapterDisplay>
    </ChapterAtom>
    <ChapterAtom>
      <ChapterTimeStart>00:01:28.288</ChapterTimeStart>
      <ChapterTimeEnd>00:01:28.289</ChapterTimeEnd>
      <ChapterDisplay>
        <ChapterString>chapter-3</ChapterString>
      </ChapterDisplay>
    </ChapterAtom>
  </EditionEntry>
</Chapters>
```

## ����
Apple�`���̃`���v�^�[�X�g���[���́u�����v������ƑΉ����܂���B
���g�p��A���ɖ��͂Ȃ��Ǝv���܂��B(iPhone, iTunes, LAV Splitter�Ŋm�F)

Apple�`���ł͍Ō�ɂ���Ȃ��񂶂�
```
<TextSample sampleTime="00:23:39.518" text="" />
```
�`���v�^�[�X�g���[���̒��������܂��B

�\�ȏꍇ�A�����ɓ���̒���������̂��]�܂����ł��B
�������A����ChapConvert�ŕϊ�����ꍇ�A����̒�����m�邷�ׂ͂���܂���B
�����ŁA�Ō�̃`���v�^�[ + 1ms���`���v�^�[�X�g���[���̒����Ƃ��Ă��܂��B
����Ŏ��g�p��A���ɖ��͂Ȃ��ł��傤�B
�ǂ����Ă��C�ɂȂ�l�͂��Ƃ���ύX���Ă��������B

## �X�V����
### 2022.04.09
- VS2022�Ɉڍs�B
- ���o�͂̃`���v�^�[�t�@�C���`�����w�肷��I�v�V������ǉ��B
- ���͕����R�[�h���w�肷��I�v�V������ǉ��B

2012.05.20
  �؂�o���A�ꕔ����