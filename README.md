# Kazan
## 概要
 xv6をverilator上で実行することができるRV64IMAのプロセッサ。<br>
 以下の特徴を持ちます。<br>
 - OoOな命令実行
 - 4命令同時フェッチ
 - Sv39によるアドレス変換
 - ノンブロッキングキャッシュ
 - ノンブロッキングTLB

## 環境
```
$ verilator --version
Verilator 5.039 devel rev v5.038-19-gcefe1845d

```

## デモ映像
 実行が重すぎるのでデモ映像 => https://www.youtube.com/watch?v=3dBjziGlqU8


## 実行方法
 Verilatorを入れた上で以下のコマンドを実行.
```
$ cd src
$ make run
```

## xv6のコンパイル方法
 以下のコマンドでコンパイル&メモリで読み込む位置にhexファイルにして配置.
```
$ cd xv6-riscv-revised
$ make qemu
$ cd ..
$ cp xv6-riscv-revised/kernel/kernel kernel/elf/kernel
$ cd kernel 
$ ./elf2hex.sh
```

