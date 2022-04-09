
# ChapConvert
[ì˙ñ{åÍî≈ÇÕÇ±ÇøÇÁÅÑÅÑ](./Readme.ja.md)  
Converts chapter file formats.

## System Requirements
Windows 8.1/10/11 (x86/x64)

## Precautions for using ChapConvert
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.

## Usage
DrapDrop chapter file or run command as below.

```
ChapConvert.exe [options] <chapter file1> [<chapter file2>][...]
```

### Options
#### -f,--format &lt;string&gt;  
  output chapter format (default: another)
  ```
    another   ... convert to another format (nero->apple, apple->nero)
    nero      ... convert to nero format (ansi)
    nero_utf8 ... convert to nero format (utf8)
    apple     ... convert to apple format (utf8)
  ```

#### --format-in &lt;string&gt;  
  input chapter format (default: auto)
  ```
    nero      ... nero format (ansi)
    nero_utf8 ... nero format (utf8)
    apple     ... apple format (utf8)
    matroska  ... matroska format (utf8)
  ```

#### --cp-in &lt;string&gt;  
   input codepage (default: auto)
  ```
    ansi, utf8, sjis, eucjp, iso2022jp, utf16le, utf16be
  ```


## Samples of each chapter format
### nero format  
```
CHAPTER01=00:00:39.706
CHAPTER01NAME=chapter-1
CHAPTER02=00:01:09.703
CHAPTER02NAME=chapter-2
CHAPTER03=00:01:28.288
CHAPTER03NAME=chapter-3
```

### apple format (should be in utf-8)  
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

### matroska format (should be in utf-8)  
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

## Updates
### 2022.04.09
- Add options to set in/out chapter format and input codepage.

### 2012.05.20
- Initial Release