# micview

A simple Micro Painter image viewer for Atari 8-bit systems, written in CC65.

## Usage

### Atari DOS 2.x / MyDOS

```
SELECT ITEM OR RETURN FOR MENU
L
LOAD FROM WHAT FILE?
MICVIEW.COM
MICVIEW--FILENAME WITH DEVICESPEC?
D2:PICTURE.MIC
```


### SpartaDOS / DOS XL / OS/A+ / XDOS

```
micview D2:PICTURE.MIC
```

Where D2: is a valid device. Any valid device must be specified.

Once the picture is displayed, any key will return you to DOS.

## Author

Thomas Cherryhomes <thom.cherryhomes at gmail.com>

