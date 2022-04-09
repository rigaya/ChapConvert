
# ChapConvert

チャプターファイルのnero形式 <-> apple形式を相互変換します。

## 動作環境
Windows 8.1/10/11 (x86/x64)

## ChapConvert 使用にあたっての注意事項
無保証です。自己責任で使用してください。
ChapConvertを使用したことによる、いかなる損害・トラブルについても責任を負いません。

## 使用方法
変換したいチャプターファイルをドラッグドロップするか、下記のようにコマンドを実行します。

```
ChapConvert.exe [options] <chapter file1> [<chapter file2>][...]
```
### オプション
#### -f,--format &lt;string&gt;  
  出力チャプターファイルのフォーマットを指定します。 (デフォルト: another)
  ```
    another   ... convert to another format (nero->apple, apple->nero)
    nero      ... convert to nero format (ansi)
    nero_utf8 ... convert to nero format (utf8)
    apple     ... convert to apple format (utf8)
  ```

#### --format-in &lt;string&gt;  
  入力チャプターファイルのフォーマットを指定します。 (デフォルト: auto)
  ```
    nero      ... nero形式 (ansi)
    nero_utf8 ... nero形式 (utf8)
    apple     ... apple format (utf8)
    matroska  ... matroska format (utf8)
  ```

#### --cp-in &lt;string&gt;  
   入力チャプターファイルの文字コードを指定します。 (デフォルト: auto)  
   チャプターの文字コードが特殊な場合にこのオプションで変更します。
  ```
    ansi, utf8, sjis, eucjp, iso2022jp, utf16le, utf16be
  ```

## チャプターの各形式の例
### nero形式  
```
CHAPTER01=00:00:39.706
CHAPTER01NAME=chapter-1
CHAPTER02=00:01:09.703
CHAPTER02NAME=chapter-2
CHAPTER03=00:01:28.288
CHAPTER03NAME=chapter-3
```

### apple形式 (utf-8)  
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

### matroska形式 (utf-8)  
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

## 制限
Apple形式のチャプターストリームの「長さ」が動画と対応しません。
実使用上、特に問題はないと思います。(iPhone, iTunes, LAV Splitterで確認)

Apple形式では最後にこんなかんじで
```
<TextSample sampleTime="00:23:39.518" text="" />
```
チャプターストリームの長さを入れます。

可能な場合、ここに動画の長さを入れるのが望ましいです。
しかし、このChapConvertで変換する場合、動画の長さを知るすべはありません。
そこで、最後のチャプター + 1msをチャプターストリームの長さとしています。
これで実使用上、特に問題はないでしょう。
どうしても気になる人はあとから変更してください。

## 更新履歴
### 2022.04.09
- VS2022に移行。
- 入出力のチャプターファイル形式を指定するオプションを追加。
- 入力文字コードを指定するオプションを追加。

2012.05.20
  切り出し、一部改変